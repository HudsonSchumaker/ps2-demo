/**
* @file TitleScreen.h
* @author Hudson Schumaker
* @brief Defines the TitleScreen class.
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "Scene.h"

class TitleScreen final : public Scene {
private:
	SDL_Texture* background = nullptr;
	SDL_Rect rect = { 0, 0, 0, 0 };

	short speed = 8;
	SDL_Texture* spacebarStart = nullptr;
	SDL_Rect rectSpacebarStart = { 0, 0, 0, 0 };
	Mix_Chunk* bate = nullptr;

	void load() override;
	void input() override;
	void update() override;
	void render() override;
	void unload() override;

public:
	TitleScreen();
	~TitleScreen();

	short run() override;
};
