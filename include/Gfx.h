/**
* @file Gfx.h
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
#pragma once
#include "Dimension.h"
#include "../src/Pch.h"

/**
* @class Gfx
* @brief The graphics hanlder class.
*
* This class provides functionality for creating and manipulating graphics.
*/
class Gfx final {
private:
    inline static Gfx* instance = nullptr;
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    Gfx() = default;

public:
    ~Gfx();
    static Gfx* getInstance();

    /**
    * @brief Initializes the SDL library and creates the SDL_Window and SDL_Renderer.
    */
    void setGfxContext();
    SDL_Window* getWindow();
    SDL_Renderer* getRenderer();

    /**
    * @brief Loads an image file into an SDL_Texture.
    * @param name The name (path) of the image file.
    * @return Pointer to the loaded SDL_Texture.
    */
    SDL_Texture* loadTexture(const char* filePath);

    /**
    * @brief Returns the size of an SDL_Texture.
    * @param texture Pointer to the SDL_Texture.
    * @return The size of the texture as a Dimension<int>.
    */
    Dimension<int> getTextureSize(SDL_Texture* texture);
    
    /**
    * @brief Returns the bounds of an SDL_Texture as an SDL_Rect.
    * @param texture Pointer to the SDL_Texture.
    * @return The bounds of the texture as an SDL_Rect.
    */
    SDL_Rect getTextureBounds(SDL_Texture* texture);
};
