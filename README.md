
# Information:
  This has two type cmake and make build. Windows 64bt.

  CMakeLists.txt is work in progress and understanding.

  make use msys2 mingw64. Since I install Msys2


# SDL2 Files:
  This is for windows VS20XX

 - Download SDL2-devel
 - https://github.com/libsdl-org/SDL/releases/download/release-2.30.3/SDL2-devel-2.30.3-VC.zip

```
-Project
--build
--SDL2 (folder, release)
--imgui (folder, github)
```

# CMake Build:

```
mkdir build
cd build
```
  It make folder for the build
```
cmake ..
```
  Set Up Build tool by default VS20XX
```
cmake --build .
```
  Compile to execute application. Default Debug.

# Make:
```
make
```
  Compile to Execute Application.

```
./main
```
  Run Application.


# refs:
 - https://gist.github.com/jordandee/94b187bcc51df9528a2f
 - https://www.youtube.com/watch?v=H08t6gD1Y1E
