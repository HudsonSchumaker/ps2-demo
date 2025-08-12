/**
* @file Menu.h
* @author Hudson Schumaker
* @brief Defines the Menu class.
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "Scene.h"
#include "../src/Pch.h"


class Menu final : public Scene {
private:
	SDL_Texture* background = nullptr;
	SDL_Rect rect = { 0, 0, 0, 0 };

    Mix_Chunk* okSFX = nullptr;

	void load() override;
	void input() override;
	void update() override;
	void render() override;
	void unload() override;

public:
	Menu();
	~Menu();

	short run() override;
};
