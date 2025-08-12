/**
* @file SplashScreen.cpp
* @author Hudson Schumaker
* @brief Implements the SplashScreen class.
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "../include/Dimension.h"
#include "../include/SplashScreen.h"

SplashScreen::SplashScreen() : Scene() {}
SplashScreen::~SplashScreen() {
    unload();
}

void SplashScreen::load() {
    char path[] = "cdrom0:\\DATA\\LOGO.PNG;1";
    logoTexture = Gfx::getInstance()->loadTexture(path);
    if (!logoTexture) {
        printf("ERROR: Failed to load logo texture!\n");
    }

    Dimension<int> size = Gfx::getInstance()->getTextureSize(logoTexture);
    rect = {
        Defs::SCREEN_H_WIDTH - (size.w / 2) - 20,  // x
        Defs::SCREEN_H_HEIGHT - (size.h / 2) - 20, // y
        256,                                       // w
        64                                         // h
    };
    isRunning = true;
}

short SplashScreen::run() {
    while (isRunning) {
        input();
        update();
        render();
    }
    return exit;
}

void SplashScreen::input() {
    SDL_Event sdlEvent;
    while (SDL_PollEvent(&sdlEvent)) {
        switch (sdlEvent.type) {
            case SDL_QUIT:
                isRunning = false;
                exit = EXIT;
                break;
        }
    }
}

void SplashScreen::update() {
    static char times = 0;
    SDL_Delay(1000);
    times++;
    if (times > 6) {
        isRunning = false;
    }
}

void SplashScreen::render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, logoTexture, NULL, &rect);
    SDL_RenderPresent(renderer);
}

void SplashScreen::unload() {
    isLoaded = false;
    SDL_DestroyTexture(logoTexture);
}
