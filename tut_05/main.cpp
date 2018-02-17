#include <iostream>
#include <array>
#include <SDL2/SDL.h>

using std::cout;
using FString = std::string;
const int SCREEN_WIDTH = 377;
const int SCREEN_HEIGHT = 377;

SDL_Window* gWindow;
SDL_Surface* gScreenSurface;
SDL_Surface* gHelloWorld;
SDL_Surface* gKeyPressSurfaces [5];
SDL_Surface* gCurrentSurface = nullptr;

enum KeyPressSurfaces {
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_TOTAL
};

SDL_Surface* loadSurface (const FString& filePath) {
    SDL_Surface* loadedSurface = SDL_LoadBMP(filePath.c_str());
    if (!loadedSurface) {
        printf("Unable to load image %s!  SDL_LoadBMP Error: %s\n",
               filePath.c_str(), SDL_GetError());
    }
    return loadedSurface;
}

void handleGameEvents (SDL_Event e) {
    //Select surfaces based on key press
    switch( e.key.keysym.sym ) {
        case SDLK_UP:
            gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ];
            break;
        case SDLK_DOWN:
            gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ];
            break;
        case SDLK_LEFT:
            gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ];
            break;
        case SDLK_RIGHT:
            gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ];
            break;
        default:
            gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ];
            break;
    }
}

void freeSurfaces (SDL_Surface* surfaces[]) {
    for (int i = 0; i < sizeof(surfaces); i += 1) {
        SDL_Surface* surface = surfaces[i];
        SDL_FreeSurface(surface);
        surfaces[i] = nullptr;
    }
}

int quitTut () {
    freeSurfaces(gKeyPressSurfaces);
    SDL_DestroyWindow( gWindow );
    gWindow = nullptr;
    SDL_Quit();
    return 0;
}

bool init () {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        cout << "SDL could not be initialized!  SDL Error"
             << SDL_GetError()
             << std::endl;
        return false;
    }

    gWindow = SDL_CreateWindow("SDL Tutorial",
                               SDL_WINDOWPOS_UNDEFINED,
                               SDL_WINDOWPOS_UNDEFINED,
                               SCREEN_WIDTH, SCREEN_HEIGHT,
                               SDL_WINDOW_SHOWN
    );

    if (!gWindow) {
        cout << "SDL Window could not be created.  SDL Error: "
             << SDL_GetError()
             << std::endl;
        return false;
    }

    gScreenSurface = SDL_GetWindowSurface(gWindow);

    SDL_FillRect(gScreenSurface, nullptr, SDL_MapRGB(gScreenSurface->format, 0xFF, 0xFF, 0xFF));

    SDL_UpdateWindowSurface(gWindow);

    return true;
}

bool loadMedia () {
    gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] =  loadSurface("../assets/press-some-arrows.bmp");
    gKeyPressSurfaces[KEY_PRESS_SURFACE_UP] =       loadSurface("../assets/up-arrow.bmp");
    gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] =    loadSurface("../assets/right-arrow.bmp");
    gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] =     loadSurface("../assets/left-arrow.bmp");
    gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] =     loadSurface("../assets/down-arrow.bmp");
    return gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] != nullptr;
}

int WinMain () {
    if (!init()) {
        cout << "Failed to initialize application.";
        return quitTut();
    }

    if (!loadMedia()) {
        cout << "Failed to load media.";
        return quitTut();
    }

    bool quit = false;
    SDL_Event e; // = nullptr;

    gCurrentSurface = gHelloWorld;

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            quit = e.type == SDL_QUIT;

            // Handle key presses
            handleGameEvents(e);

            // Blit surfaces
            SDL_BlitSurface(gCurrentSurface, nullptr, gScreenSurface, nullptr);
            SDL_UpdateWindowSurface(gWindow);
        }
    }

    return quitTut();
}
