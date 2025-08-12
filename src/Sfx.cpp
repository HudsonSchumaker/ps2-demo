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
    // PS2-optimized audio settings
    // MIX_DEFAULT_FORMAT: Usually 16-bit signed, good for PS2
    // 2: Stereo channels
    // 3096: Larger buffer for PS2's slower I/O and processing
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 3096) < 0) {
        printf("ERROR: Mixer initialization failed: %s\n", Mix_GetError());
        return;
    }
    Mix_AllocateChannels(4); // Limit to 4 simultaneous sound effects
}

Mix_Chunk* Sfx::loadSound(const char* filePath) {
    FILE* file = fopen(filePath, "rb");
    if (!file) {
        printf("ERROR: fopen failed for sound: %s\n", filePath);
        return nullptr;
    }

    SDL_RWops* rw = SDL_RWFromFP(file, SDL_TRUE); // SDL_TRUE = auto close
    if (!rw) {
        printf("ERROR: SDL_RWFromFP failed for sound!\n");
        fclose(file);
        return nullptr;
    }

    Mix_Chunk* chunk = Mix_LoadWAV_RW(rw, 1); // 1 = auto free rw
    if (!chunk) {
        printf("ERROR: Mix_LoadWAV_RW failed: %s\n", Mix_GetError());
        return nullptr;
    }

    return chunk;
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

void Sfx::playMusic(const char* filePath) {
    playMusic(filePath, -1);
}

void Sfx::playMusic(const char* filePath, int loop) {
    // Free existing music if loaded
    if (music) {
        Mix_FreeMusic(music);
        music = nullptr;
    }
    
    FILE* file = fopen(filePath, "rb");
    if (!file) {
        printf("ERROR: fopen failed for music: %s\n", filePath);
        return;
    }

    SDL_RWops* rw = SDL_RWFromFP(file, SDL_TRUE); // SDL_TRUE = auto close
    if (!rw) {
        printf("ERROR: SDL_RWFromFP failed for music!\n");
        fclose(file);
        return;
    }
    
    // Load music file using RWops
    music = Mix_LoadMUS_RW(rw, 1); // 1 = auto free rw
    if (!music) {
        printf("ERROR: Failed to load music: %s\n", Mix_GetError());
        return;
    }
    
    // Play music with specified loop count (-1 for infinite loop)
    if (Mix_PlayMusic(music, loop) < 0) {
        printf("ERROR: Failed to play music: %s\n", Mix_GetError());
    }
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
