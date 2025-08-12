/**
* @file Input.cpp
* @author Hudson Schumaker
* @brief Implements the Input class.
* @version 1.0.0
*
* Dodoi-Engine-PS2 is a game engine developed by Dodoi-Lab.
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
#include "../include/Input.h"

Input::~Input() {
    if (controller) {
        SDL_GameControllerClose(controller);
        controller = nullptr;
    }
}

Input* Input::getInstance() {
    if (instance == nullptr) {
        instance = new Input();
    }
    return instance;
}

void Input::setInputContext() {
    // Initialize SDL game controller
    if (SDL_InitSubSystem(SDL_INIT_GAMECONTROLLER | SDL_INIT_HAPTIC) < 0) {
        printf("ERROR: SDL_InitSubSystem failed: %s\n", SDL_GetError());
        return;
    }

    controller = SDL_GameControllerOpen(0);
    if (!controller) {
        printf("ERROR: SDL_GameControllerOpen failed: %s\n", SDL_GetError());
    }
}

SDL_GameController* Input::getController() const { return controller; }
