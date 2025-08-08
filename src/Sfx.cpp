/**
* @file Sfx.cpp
* @author Hudson Schumaker
* @brief Implements the Sfx class.
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
#include "../include/Sfx.h"

Sfx::~Sfx() {
    Mix_FreeMusic(music);
    Mix_HaltChannel(-1);
    Mix_CloseAudio();
    Mix_Quit();
}

Sfx* Sfx::getInstance() {
    if (instance == nullptr) {
        instance = new Sfx();
    }

    return instance;
}

void Sfx::setSfxContext() {
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) < 0) {
        printf("ERROR: Mixer initialization failed: %s\n", Mix_GetError());
        return;
    }
}

Mix_Chunk* Sfx::loadSound(const std::string& filePath) {
    return Mix_LoadWAV(filePath.c_str());
}

int Sfx::playSound(Mix_Chunk* sound) {
    return playSound(sound, 0);
}

int Sfx::playSound(Mix_Chunk* sound, int loop) {
    return Mix_PlayChannel(-1, sound, loop);
}

void Sfx::stopSound(int channel) {
    Mix_HaltChannel(channel);
}

void Sfx::stopSound(int channel, int delay) {
    Mix_FadeOutChannel(channel, delay);
}

void Sfx::pauseSound(int channel) {
    Mix_Pause(channel);
}

void Sfx::unPauseSound(int channel) {
    Mix_Resume(channel);
}

void Sfx::playMusic(const std::string& filePath, int loop) {
    // TODO: Implement music loading and playing
}

void Sfx::stopMusic() {
    Mix_HaltMusic();
}

void Sfx::stopMusic(int delay) {
    Mix_FadeOutMusic(delay);
}

void Sfx::pauseMusic() {
    Mix_PauseMusic();
}

void Sfx::unPauseMusic() {
    Mix_ResumeMusic();
}
