# cpp_lazy_foo_sdl2

## Tut-05

## Note
To get SDL2 and SDL2_image working on windows with Visual Studio (quick fix)
 clone 'kitware/CMake' and point your 'CMAKE_MODULE_PATH' to the kitware/CMake/Modules path

## Notes:

### Configuration
Put local cmake variables in './Env.cmake'

**Example:**
```
set(CMAKE_MODULE_PATH g:/github/CMake/Modules)
set(SDL2_LIBRARY_TEMP g:/mingw_libs/SDL2-2.0.7/x86_64-w64-mingw32/lib)
set(SDL2_DIR g:/mingw_libs/SDL2-2.0.7)
set(SDL2_INCLUDE_DIR SDL2_LIBRARY_TEMP)
```

- Included './FindSDL2.cmake' is not required though kept here in-case a user needs it (see blog referenced
 in references pertaining to this file).

## References:
- https://trenki2.github.io/blog/2017/06/02/using-sdl2-with-cmake/@refe
