/**
* @file Input.h
* @author Hudson Schumaker
* @brief Defines the Input class.
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
#pragma once
#include "../src/Pch.h"

class Input {
private:
    inline static Input* instance = nullptr;
    SDL_GameController* controller = nullptr;
    Input() = default;

public:
    ~Input();
    static Input* getInstance();
    void setInputContext();

    SDL_GameController* getController() const;
};
