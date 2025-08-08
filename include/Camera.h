/**
* @file Camera.h
* @author Hudson Schumaker
* @brief Defines the Camera class.
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
#pragma once
#include "../src/Pch.h"

/**
* @class Camera
* @brief Used to define the viewport.
*/
class Camera final {
public:
    int x, y, w, h;
    SDL_Color color = { 32, 32, 32, 255 };

    Camera() : Camera(0, 0, 0, 0) {}
    Camera(int x, int y, int w, int h) {
        this->x = x;
        this->y = y;
        this->w = w;
        this->h = h;
    }

    ~Camera() = default;
};
