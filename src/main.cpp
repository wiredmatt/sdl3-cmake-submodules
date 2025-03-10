#define SDL_MAIN_USE_CALLBACKS
#include <SDL3/SDL_main.h>
#include "SDL3/SDL.h"
#include <SDL3_ttf/SDL_ttf.h>
#include <SDL3_mixer/SDL_mixer.h>

const int TARGET_FPS = 60;
const Uint32 TARGET_FRAME_TIME = 1000 / TARGET_FPS; // milliseconds

Uint32 frameStart;
Uint32 frameTime;

SDL_Window *window;
SDL_Renderer *renderer;

SDL_AppResult SDL_AppInit(void **appstate, int argc, char **argv)
{
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS | SDL_INIT_GAMEPAD))
    {
        SDL_Log("Error initializing SDL: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    window = SDL_CreateWindow("Game", 640, 480, 0);
    if (!window)
    {
        SDL_Log("Error creating window: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    renderer = SDL_CreateRenderer(window, 0);
    if (!renderer)
    {
        SDL_Log("Error creating renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *appstate, SDL_AppResult result)
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    TTF_Quit();

    Mix_CloseAudio();
    Mix_Quit();

    SDL_Quit();
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
{
    if (event->type == SDL_EVENT_QUIT)
        return SDL_APP_SUCCESS;

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void *appstate)
{
    SDL_SetRenderDrawColor(renderer, 100, 149, 237, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    // add custom draw calls here
    SDL_RenderPresent(renderer);

    // frame limiter
    frameTime = SDL_GetTicks() - frameStart;
    if (frameTime < TARGET_FRAME_TIME)
    {
        SDL_Delay(TARGET_FRAME_TIME - frameTime);
    }
    frameStart = SDL_GetTicks();

    return SDL_APP_CONTINUE;
}