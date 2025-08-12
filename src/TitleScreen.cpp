/**
* @file TitleScreen.cpp
* @author Hudson Schumaker
* @brief Implements the TitleScreen class.
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "TitleScreen.h"
#include "Sfx.h"

TitleScreen::TitleScreen() : Scene() {}
TitleScreen::~TitleScreen() {
	unload();
}

void TitleScreen::load() {
	nextScene = "Menu";
    char bg_path[] = "cdrom0:\\DATA\\BG512.PNG;1";
	background = Gfx::getInstance()->loadTexture(bg_path);
	rect = {
		0,    // x
		0,    // y
		512,  // w
		512   // h
	};

    char space_path[] = "cdrom0:\\DATA\\SPCBAR.PNG;1";
	spacebarStart = Gfx::getInstance()->loadTexture(space_path);
	rectSpacebarStart = Gfx::getInstance()->getTextureBounds(spacebarStart);

	bate = Sfx::getInstance()->loadSound("cdrom0:\\DATA\\BATE.MP3;1");

	isRunning = true;
}

short TitleScreen::run() {
	char bate_path[] = "cdrom0:\\DATA\\INTRO.MP3;1";
	Sfx::getInstance()->playMusic(bate_path, 0);
	while (isRunning) {
		input();
		update();
		render();
	}
	return exit;
}

void TitleScreen::input() {
	SDL_Event sdlEvent;
	while (SDL_PollEvent(&sdlEvent)) {
		switch (sdlEvent.type) {
		case SDL_KEYDOWN:
			if (sdlEvent.key.keysym.sym == SDLK_SPACE) {
				isRunning = false;
				exit = NEXT;
			}
			break;

		case SDL_QUIT:
			isRunning = false;
			exit = EXIT; 
			break;
		}
	}
}

void TitleScreen::update() {
	float dt = calculateDeltaTime();

}

void TitleScreen::render() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, background, NULL, &rect);

	SDL_Rect rectSpace = {
		100,
		190 + static_cast<int>(speed * SDL_sin(SDL_GetTicks() * (Defs::PI / 1600.0f))),
		rectSpacebarStart.w,
		rectSpacebarStart.h
	};
	SDL_RenderCopy(renderer, spacebarStart, NULL, &rectSpace);
	SDL_RenderPresent(renderer);
}

void TitleScreen::unload() {
	isLoaded = false;
	SDL_DestroyTexture(background);
	SDL_DestroyTexture(spacebarStart);
}
