/**
* @file Menu.cpp
* @author Hudson Schumaker
* @brief Implements the Menu class.
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "../include/Menu.h"
#include "../include/Sfx.h"
#include "../include/Input.h"

Menu::Menu() : Scene() {}
Menu::~Menu() {
	unload();
}

void Menu::load() {
	nextScene = "Board";
    char bg_path[] = "cdrom0:\\DATA\\GREEN.PNG;1";
	background = Gfx::getInstance()->loadTexture(bg_path);
	rect = {
		0,    // x
		0,    // y
		512,  // w
		512   // h
	};

    char bate_path[] = "cdrom0:\\DATA\\OK.WAV;1";
	okSFX = Sfx::getInstance()->loadSound(bate_path);

	isRunning = true;
}


short Menu::run() {
	Sfx::getInstance()->playSound(okSFX, 0);
	    printf("#######################################################Played sound\n");
	while (isRunning) {
		input();
		update();
		render();
	}
	return exit;
}

void Menu::input() {
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

void Menu::update() {
	float dt = calculateDeltaTime();

}

void Menu::render() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, background, NULL, &rect);


	SDL_RenderPresent(renderer);
}


void Menu::unload() {
	isLoaded = false;
	Mix_FreeChunk(okSFX);
	SDL_DestroyTexture(background);
}
