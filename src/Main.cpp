#include "Pch.h"
#include "../include/Gfx.h"
#include "../include/Sfx.h"
#include "../include/Input.h"
#include "../include/Menu.h"
#include "../include/TitleScreen.h"
#include "../include/SceneManager.h"
#include "../include/SplashScreen.h"

void setUp() {
    // Initialize PS2 systems
    SifInitRpc(0);

    Gfx::getInstance()->setGfxContext();
    Sfx::getInstance()->setSfxContext();
    Input::getInstance()->setInputContext();
}

void init() {
    setUp();
    SceneManager::getInstance()->addScene("SplashScreen", std::make_unique<SplashScreen>());
    SceneManager::getInstance()->addScene("TitleScreen", std::make_unique<TitleScreen>());
    SceneManager::getInstance()->addScene("Menu", std::make_unique<Menu>());
}

int main(int argc, char *argv[]) {
    init();
    SceneManager::getInstance()->loadSceneAsync("SplashScreen");

    return 0;
}
