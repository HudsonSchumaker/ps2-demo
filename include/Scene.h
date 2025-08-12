/**
* @file Scene.h
* @author Hudson Schumaker
* @brief Defines the Scene class.
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
#include "Gfx.h"
#include "Camera.h"

/**
 * @class Scene
 * @brief Represents a game scene.
 *
 * The Scene class is an abstract base class that represents a game scene.
 * It provides methods to load, input, update, render, and unload the scene.
 * It also provides methods to calculate delta time, begin rendering, end rendering, and get the next scene.
 */
class Scene {
private:
    /**
    * @brief Future object for asynchronous loading.
    */
   // std::future<void> loadFuture;

    virtual void load() = 0;
    virtual void input() = 0;
    virtual void update() = 0;
    virtual void render() = 0;
    virtual void unload() = 0;

protected:
    Camera camera = { 0, 0, Defs::SCREEN_WIDTH, Defs::SCREEN_HEIGHT };
    SDL_Renderer* renderer = nullptr;
    Uint64 millisecsPreviousFrame = 0;
    float deltaTime = 0.0f;
    std::string nextScene = "TitleScreen";

    bool isRunning = false;
    bool isPaused = false;
    bool isLoaded = false;
    short exit = 0;

    float calculateDeltaTime();
    void beginRender();
    void endRender();

public:
    Scene();

    /**
    * @brief Virtual destructor for Scene.
    */
    virtual ~Scene() {}

    /**
    * @brief Runs the scene. Pure virtual function.
    * @return short The exit status of the scene.
    */
    virtual short run() = 0; // TODO: check if need to return a value

    /**
    * @brief Loads the scene asynchronously.
    */
    void loadAsync();

    /**
    * @brief Waits for the scene to finish loading.
    */
    void waitForLoad();

    /**
    * @brief Frees resources used by the scene.
    */
    void freeResources();

    /**
    * @brief Returns the name of the next scene.
    * @return const std::string& The name of the next scene.
    */
    const std::string& getNextScene() const;

    /**
    * @brief Returns whether the scene is loaded.
    * @return bool True if the scene is loaded, false otherwise.
    */
    bool getIsLoaded();
};
