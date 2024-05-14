# https://trenki2.github.io/blog/2017/06/02/using-sdl2-with-cmake/
# https://github.com/llanillo/clion-cmake-sdl2-template/tree/main
cmake_minimum_required(VERSION 3.7)

project(SDL2Test)

#option(SDL_IMGUI_OPENGL "imgui opengl library" ON)
#option(SDL_IMGUI_OPENGL "imgui opengl library" OFF FORCE)
#set(SDL_IMGUI_OPENGL ON CACHE BOOL "imgui opengl library")
#for opengl
set(SDL_IMGUI_OPENGL OFF CACHE BOOL "imgui opengl library" FORCE)
#for sdl
set(SDL_IMGUI ON CACHE BOOL "imgui sdl library" FORCE)

#set(MAIN_FILE src/main.cpp)
#set(MAIN_FILE src/hello.cpp)
#set(MAIN_FILE src/sdl2_opengl.cpp)
#set(MAIN_FILE src/sdl2_opengl_imgui.cpp)
set(MAIN_FILE src/sdl2_renderer_imgui.cpp)

#set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)
set(SDL2_PATH "${CMAKE_CURRENT_LIST_DIR}/SDL2")

set(IMGUI_PATH "${CMAKE_CURRENT_LIST_DIR}/imgui")

message("CHECK imgui opengl: " ${SDL_IMGUI_OPENGL})
if (SDL_IMGUI_OPENGL)
  #message("imgui opengl: " ${SDL_IMGUI_OPENGL})
  set(IMGUI_SRC
    ${IMGUI_PATH}/imgui.cpp
    ${IMGUI_PATH}/imgui_demo.cpp
    ${IMGUI_PATH}/imgui_draw.cpp
    ${IMGUI_PATH}/imgui_tables.cpp
    ${IMGUI_PATH}/imgui_widgets.cpp
    ${IMGUI_PATH}/backends/imgui_impl_sdl2.cpp
    ${IMGUI_PATH}/backends/imgui_impl_opengl3.cpp
  )
endif(SDL_IMGUI_OPENGL)

if (SDL_IMGUI)
  #message("imgui opengl: " ${SDL_IMGUI_OPENGL})
  set(IMGUI_SRC
    ${IMGUI_PATH}/imgui.cpp
    ${IMGUI_PATH}/imgui_demo.cpp
    ${IMGUI_PATH}/imgui_draw.cpp
    ${IMGUI_PATH}/imgui_tables.cpp
    ${IMGUI_PATH}/imgui_widgets.cpp
    ${IMGUI_PATH}/backends/imgui_impl_sdl2.cpp
    ${IMGUI_PATH}/backends/imgui_impl_sdlrenderer2.cpp
  )
endif(SDL_IMGUI)

set(IMGUI_INCLUDES
  ${IMGUI_PATH}
  ${IMGUI_PATH}/backends
)

#find_package(SDL2 REQUIRED)
#set(SDL_DIR "${CMAKE_CURRENT_LIST_DIR}/SDL2/x86_64-w64-mingw32")
set(SDL2_INCLUDE_DIR ${SDL2_PATH}/include)
set(SDL2_LIBRARIES ${SDL2_PATH}/lib/x64)

set(SDL2_LIBRARIES
  ${SDL2_PATH}/lib/x64/SDL2.lib
  ${SDL2_PATH}/lib/x64/SDL2main.lib #opengl
)

#EXECUTE
add_executable(${PROJECT_NAME} ${MAIN_FILE} ${IMGUI_SRC})
if (SDL_IMGUI_OPENGL OR SDL_IMGUI)
  include_directories(${IMGUI_INCLUDES})
endif()

# SDL INCLUDE
include_directories(${SDL2_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} opengl32)




#target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} )
#target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} gdi32 opengl32 imm32 )
#include_directories(${SDL2_INCLUDE_DIR})
#target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY})
#target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
#EXECUTE APP
#add_executable(${PROJECT_NAME} ${MAIN_FILE} ${imgui_src})
#target_link_libraries(${PROJECT_NAME} SDL2::SDL2 gdi32 opengl32 imm32 )
#find_package(SDL2 REQUIRED)
#include_directories(${SDL2_INCLUDE_DIRS})
#add_executable(SDL2Test Main.cpp)
#target_link_libraries(SDL2Test ${SDL2_LIBRARIES})