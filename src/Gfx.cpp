/**
* @file Gfx.cpp
* @author Hudson Schumaker
* @brief Defines the Gfx class.
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
#include "../include/Gfx.h"

Gfx::~Gfx() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
}

Gfx* Gfx::getInstance() {
    if (instance == nullptr) {
        instance = new Gfx();
    }

    return instance;
}

void Gfx::setGfxContext() {
    // Initialize SDL2
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("ERROR: SDL2 initialization failed: %s\n", SDL_GetError());
        return;
    }

    // Create window (PS2 resolution)
    window = SDL_CreateWindow(
        "",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        Defs::SCREEN_WIDTH, Defs::SCREEN_HEIGHT, // PS2 resolution
        SDL_WINDOW_SHOWN
    );

    if (!window) {
        printf("ERROR: Window creation failed: %s\n", SDL_GetError());
        SDL_Quit();
        return;
    }

    // Create renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("ERROR: Renderer creation failed: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return;
    }

    // Initialize SDL_image
    if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) == 0) {
        printf("ERROR: SDL_image initialization failed: %s\n", IMG_GetError());
        return;
    }

    // Initialize SDL_ttf
    if (TTF_Init() == -1) {
        printf("ERROR: SDL_ttf initialization failed: %s\n", TTF_GetError());
        return;
    }
}

SDL_Texture* Gfx::loadTexture(const char* filePath) {
    FILE* file = fopen(filePath, "rb");
    if (!file) {
        printf("ERROR: fopen failed!\n");
        return nullptr;
    }

    SDL_RWops* rw = SDL_RWFromFP(file, SDL_TRUE); // SDL_TRUE = auto close
    if (!rw) {
        printf("ERROR: SDL_RWFromFP failed!\n");
        fclose(file);
        return nullptr;
    }

    SDL_Surface* surface = IMG_Load_RW(rw, 1); // 1 = auto free rw
    if (!surface) {
        printf("ERROR: IMG_Load_RW failed: %s\n", IMG_GetError());
        return nullptr;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

Dimension<int> Gfx::getTextureSize(SDL_Texture* texture) {
    Dimension<int> size = { 0, 0 };
    SDL_QueryTexture(texture, NULL, NULL, &size.w, &size.h);

    return size;
}

SDL_Rect Gfx::getTextureBounds(SDL_Texture* texture) {
    Dimension<int> size = { 0, 0 };
    SDL_QueryTexture(texture, NULL, NULL, &size.w, &size.h);
    SDL_Rect rect = { 0, 0, size.w, size.h };

    return rect;
}

SDL_Window* Gfx::getWindow() {
    return window;
}

SDL_Renderer* Gfx::getRenderer() {
    return renderer;
}
