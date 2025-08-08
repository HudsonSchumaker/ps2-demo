/**
* @file SceneManager.h
* @author Hudson Schumaker
* @brief Defines the SceneManager class.
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
#include "Scene.h"
#include "../src/Pch.h"

/**
 * @class SceneManager
 * @brief Manages the lifecycle of game scenes.
 *
 * The SceneManager class is responsible for managing the lifecycle of game scenes.
 * It provides methods to add scenes, load scenes asynchronously, and get the instance of the SceneManager.
 * It uses the Singleton design pattern.
 */
class SceneManager {
private:
    inline static SceneManager* instance = nullptr;

    /**
    * @brief Map of scene names to unique pointers of Scene objects.
    */
    std::map<std::string, std::unique_ptr<Scene>> scenes;

    SceneManager() = default;
    void displayLoadingScreen();

public:
    ~SceneManager() = default;

    /**
    * @brief Returns the singleton instance of SceneManager.
    * @return SceneManager* The singleton instance of SceneManager.
    */
    static SceneManager* getInstance();

    /**
    * @brief Adds a scene to the SceneManager.
    *
    * @param sceneName The name of the scene.
    * @param scene The unique pointer to the Scene object.
    */
    void addScene(const std::string& sceneName, std::unique_ptr<Scene> scene);

    /**
    * @brief Loads a scene asynchronously.
    * @param sceneName The name of the scene to load.
    */
    void loadSceneAsync(const std::string& sceneName);
};