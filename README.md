# SDL3 CMake + Git Modules Starter

## Quickstart

```sh
git clone git@github.com:wiredmatt/sdl3-cmake-modules.git --depth=1 --recurse-submodules
cmake -B build && cmake --build build && ./build/my_game
```

## Adding more libraries

### 1. Cloning the library

```sh
cd vendor
git submodule add <<library_url>>
```

### 2. Including the library in the vendor project

First, add the following line to [vendor/CMakeLists.txt](./vendor/CMakeLists.txt) (below the other `add_subdirectory` lines).

```c
add_subdirectory(NewLibrary EXCLUDE_FROM_ALL)
```

And then modify the final line of the file, like so:

```C
target_link_libraries(vendor INTERFACE SDL3_image::SDL3_image SDL3::SDL3 NewLibrary::NewLibrary)
```

### 3. Re-build so it gets picked up

```C
cmake -B build && cmake
```

### Include it

```c++
#include "SDL3/SDL.h"
#include "NewLibrary/NewLibrary.h"

int main()
{
    SDL_Log("%s", "Hello World!");
    return 0;
}
```
