#include "Pch.h"
#include "../include/Gfx.h"
#include "../include/Sfx.h"
#include "../include/TitleScreen.h"
#include "../include/SceneManager.h"
#include "../include/SplashScreen.h"

void setUp() {
    // Initialize PS2 systems
    SifInitRpc(0);
    printf("PS2 systems initialized.\n");

    // Initialize graphics context
    Gfx::getInstance()->setGfxContext();

    // Initialize msound effects context
    Sfx::getInstance()->setSfxContext();
}

void init() {
    setUp();
    SceneManager::getInstance()->addScene("SplashScreen", std::make_unique<SplashScreen>());
    SceneManager::getInstance()->addScene("TitleScreen", std::make_unique<TitleScreen>());
}

int main(int argc, char *argv[]) {
    init();
    SceneManager::getInstance()->loadSceneAsync("SplashScreen");

    return 0;
}
