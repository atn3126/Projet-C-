#include "MainSDLWindow.hpp"

MainSDLWindow::MainSDLWindow() {
    this->renderer = NULL;
    this->window = NULL;
}

MainSDLWindow::~MainSDLWindow() {
    if (this->renderer != NULL) SDL_DestroyRenderer(this->renderer);
    if (this->window != NULL) SDL_DestroyWindow(this->window);
    SDL_Quit();
}

SDL_Renderer* MainSDLWindow::GetRenderer() {
    return this->renderer;
}

int MainSDLWindow::Init(const char* name, int width, int height) {
    // Init SDL:
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", SDL_GetError());
        return EXIT_FAILURE;
    }

    // Init the main SDL window:
    Uint32 window_flags = 0;
    this->window = SDL_CreateWindow(name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        width, height,
        window_flags);
    if (this->window == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", SDL_GetError());
        return EXIT_FAILURE;
    }

    // Init renderer within the main SDL window:
    Uint32 renderer_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
    this->renderer = SDL_CreateRenderer(window, -1, renderer_flags);
    if (this->renderer == NULL) {
        printf("SDL2 error while creating renderer : %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    // Fill renderer background:
    SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
    SDL_RenderClear(this->renderer);
    SDL_RenderPresent(this->renderer);
    return EXIT_SUCCESS;
}