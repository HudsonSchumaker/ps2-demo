/**
* @file SceneManager.cpp
* @author Hudson Schumaker
* @brief Implements the SceneManager class.
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
#include "../include/SceneManager.h"

SceneManager* SceneManager::getInstance() {
    if (instance == nullptr) {
        instance = new SceneManager();
    }

    return instance;
}

void SceneManager::displayLoadingScreen() {
    auto renderer = Gfx::getInstance()->getRenderer();
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red for test
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

void SceneManager::loadSceneAsync(const std::string& sceneName) {
    // Display a loading screen while the scene is loading
    displayLoadingScreen();

    // Check if the scene exists
    if (scenes.find(sceneName) == scenes.end()) {
        return;
    }

    Scene* scene = scenes[sceneName].get();
    scene->loadAsync();
    // Wait for the scene to finish loading
    scene->waitForLoad();

    auto exitCode = scene->run();
	if (exitCode == EXIT) {
		return;
	}
    // Load the next scene
    std::string nextSceneName = scene->getNextScene();
    if (!nextSceneName.empty()) {
        loadSceneAsync(nextSceneName);
    }
}

void SceneManager::addScene(const std::string& sceneName, std::unique_ptr<Scene> scene) {
    scenes[sceneName] = std::move(scene);
}
