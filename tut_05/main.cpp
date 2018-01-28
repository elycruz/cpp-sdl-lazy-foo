#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using std::cout;
using FString = std::string;
const int SCREEN_WIDTH = 610;
const int SCREEN_HEIGHT = 377;

SDL_Window* gWindow;
SDL_Surface* gScreenSurface;
SDL_Surface* gHelloWorld;
SDL_Surface* gKeyPressSurfaces = nullptr;
int gSupportedImageFlags = IMG_INIT_JPG|IMG_INIT_PNG;

enum KeyPressSurfaces {
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_TOTAL
};

SDL_Surface* loadSurface (FString const& filePath) {
    SDL_Surface* loadedSurface = IMG_Load(filePath.c_str());
    if (!loadedSurface) {
        printf("Unable to load image %s!  IMG_Load Error: %s\n",
               filePath.c_str(), IMG_GetError()
        );
    }
    return loadedSurface;
}

int quitTut () {
    SDL_FreeSurface( gHelloWorld );
    gHelloWorld = nullptr;

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

    if ((IMG_Init(gSupportedImageFlags)&gSupportedImageFlags) != gSupportedImageFlags) {
        printf("IMG_Init: Failed to init required jpg and png support!\n");
        printf("IMG_Init: %s\n", IMG_GetError());
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
    gHelloWorld = loadSurface("../mandelbrot_set.bmp");
    return gHelloWorld != nullptr;
}

int main() {
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

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            quit = e.type == SDL_QUIT;
            SDL_BlitSurface(gHelloWorld, nullptr, gScreenSurface, nullptr);
            SDL_UpdateWindowSurface(gWindow);

        }
    }

    return quitTut();
}
