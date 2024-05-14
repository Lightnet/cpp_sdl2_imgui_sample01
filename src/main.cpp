// #include <iostream>

// int main() {
//     std::cout << "Hello World!";
//     return 0;
// }

#include <SDL.h>
#include <cstdlib>
#include <iostream>

#undef main

int main()
{
    using std::cerr;
    using std::endl;

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        cerr << "SDL_Init Error: " << SDL_GetError() << endl;
        return EXIT_FAILURE;
    }

    SDL_Window* win = SDL_CreateWindow("Hello World!", 100, 100, 620, 387, SDL_WINDOW_SHOWN);
    if (win == nullptr) {
        cerr << "SDL_CreateWindow Error: " << SDL_GetError() << endl;
        return EXIT_FAILURE;
    }

    SDL_Renderer* renderer
        = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) {
        cerr << "SDL_CreateRenderer Error" << SDL_GetError() << endl;
        SDL_DestroyWindow(win);
        SDL_Quit();
        return EXIT_FAILURE;
    }

    // SDL_Surface* bmp = SDL_LoadBMP("../img/grumpy-cat.bmp");
    // if (bmp == nullptr) {
    //     cerr << "SDL_LoadBMP Error: " << SDL_GetError() << endl;
    //     SDL_DestroyRenderer(ren);
    //     SDL_DestroyWindow(win);
    //     SDL_Quit();
    //     return EXIT_FAILURE;
    // }

    // SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, bmp);
    // if (tex == nullptr) {
    //     cerr << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << endl;
    //     SDL_FreeSurface(bmp);
    //     SDL_DestroyRenderer(ren);
    //     SDL_DestroyWindow(win);
    //     SDL_Quit();
    //     return EXIT_FAILURE;
    // }
    // SDL_FreeSurface(bmp);

    // for (int i = 0; i < 20; i++) {
    //     SDL_RenderClear(ren);
    //     SDL_RenderCopy(ren, tex, nullptr, nullptr);
    //     SDL_RenderPresent(ren);
    //     SDL_Delay(100);
    // }

    // Event loop exit flag
    bool quit = false;

    // Event loop
    while(!quit)
    {
        SDL_Event e;

        // Wait indefinitely for the next available event
        SDL_WaitEvent(&e);

        // User requests quit
        if(e.type == SDL_QUIT)
        {
            quit = true;
        }

        // Initialize renderer color white for the background
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

        // Clear screen
        SDL_RenderClear(renderer);

        // Set renderer color red to draw the square
        SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);

        // Draw filled square
        //SDL_RenderFillRect(renderer, &squareRect);

        // Update screen
        SDL_RenderPresent(renderer);
    }

    //SDL_DestroyTexture(tex);
    SDL_DestroyRenderer(renderer );
    SDL_DestroyWindow(win);
    SDL_Quit();

    return EXIT_SUCCESS;
}