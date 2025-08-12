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
    std::string currentSceneName = sceneName;
    
    while (!currentSceneName.empty()) {
        printf("Attempting to load scene: '%s'\n", currentSceneName.c_str());
        // Display a loading screen while the scene is loading
        displayLoadingScreen();

        // Check if the scene exists
        if (scenes.find(currentSceneName) == scenes.end()) {
            printf("ERROR: Scene '%s' not found in scene map.\n", currentSceneName.c_str());
            printf("Available scenes: ");
            for (const auto& pair : scenes) {
                printf("'%s' ", pair.first.c_str());
            }
            printf("\n");
            break;
        }

        Scene* scene = scenes[currentSceneName].get();
        scene->loadAsync();
        // Wait for the scene to finish loading
        scene->waitForLoad();

        printf("Scene '%s' loaded successfully.\n", currentSceneName.c_str());
        auto exitCode = scene->run();
        printf("Scene '%s' finished with exit code: %d\n", currentSceneName.c_str(), exitCode);
        
        std::string nextSceneName = scene->getNextScene();
        printf("Next scene from current scene: '%s'\n", nextSceneName.c_str());
        // Unload the current scene to free memory
        scene->freeResources();
        printf("Scene '%s' unloaded successfully.\n", currentSceneName.c_str());

        if (exitCode == EXIT) {
            printf("Exit code received, stopping scene manager.\n");
            break;
        }
        
        // Get the next scene name and continue the loop
        currentSceneName = nextSceneName;
        printf("Next scene to load: '%s'\n", currentSceneName.c_str());
    }
    printf("Scene manager finished.\n");
}

void SceneManager::addScene(const std::string& sceneName, std::unique_ptr<Scene> scene) {
    scenes[sceneName] = std::move(scene);
}
