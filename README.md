# SDL3 CMake + Git Modules Starter

## Quickstart

```sh
git clone git@github.com:wiredmatt/sdl3-cmake-modules.git --depth=1 --recurse-submodules
cmake -B build && cmake --build build && ./build/my_game
```

## Setting the target version for the libraries

By default this repository assumes you're working with the latest code available in the main branch of each library. If you are not, modify the file [.gitmodules](./.gitmodules), and set the `branch` property of each entry to point to the version you want to work with, like so:

```ini
[submodule "vendor/SDL"]
	path = vendor/SDL
	url = git@github.com:libsdl-org/SDL.git
	branch = release-3.2.8 # set this to whatever version you want.
```

## Updating the libraries

```sh
git submodule update --remote # remember to rebuild the project after updating!
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
