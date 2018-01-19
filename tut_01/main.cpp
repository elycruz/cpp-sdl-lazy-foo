#include <iostream>
#include <SDL2/SDL.h>

using std::cout;

const int SCREEN_WIDTH = 610;
const int SCREEN_HEIGHT = 377;

SDL_Window* gWindow;
SDL_Surface* gScreenSurface;
SDL_Surface* gHelloWorld;

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
    gHelloWorld = SDL_LoadBMP("../mandelbrot_set.bmp");
    if (!gHelloWorld) {
        printf( "Unable to load image %s! SDL Error: %s\n", "../mandelbrot_set.bmp", SDL_GetError() );
        return false;
    }
    return true;
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
    SDL_BlitSurface(gHelloWorld, nullptr, gScreenSurface, nullptr);
    SDL_UpdateWindowSurface(gWindow);
    SDL_Delay(2000);
    return quitTut();
}
