/**
* @file SplashScreen.h
* @author Hudson Schumaker
* @brief Defines the SplashScreen class.
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "Scene.h"

/**
* @class SplashScreen
* @brief The SplashScreen class.
*/
class SplashScreen final : public Scene {
private:
	SDL_Texture* logoTexture = nullptr;
	SDL_Rect rect = { 0, 0, 0, 0 };

	void load() override;
	void input() override;
	void update() override;
	void render() override;
	void unload() override;

public:
	SplashScreen();
	~SplashScreen();

	short run() override;
};
