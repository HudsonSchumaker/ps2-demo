# PS2 Game Development Makefile with native PS2 graphics and C++
# This Makefile is designed to work inside the ps2dev Docker container
# Include PS2SDK rules FIRST

EE_BIN = bin/ps2game.elf
EE_OBJS = build/Main.o build/Gfx.o build/Sfx.o build/Input.o build/Scene.o build/SceneManager.o build/SplashScreen.o build/TitleScreen.o build/Menu.o
# PS2SDK and compiler settings - use native PS2 graphics libraries
EE_LIBS := -L${PS2DEV}/gsKit/lib -L${PS2SDK}/ports/lib -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -lxmp -lpng -lz -lfreetype -lpatches -lgskit -ldmakit -lps2_drivers -lmodplug -laudsrv -lpad -lstdc++ -latomic -lc
EE_INCS := -I${PS2SDK}/ports/include -I./include
EE_CFLAGS += -DPS2 -Dmain=SDL_main -DHAVE_SDL2
EE_CXXFLAGS = $(EE_CFLAGS) -std=c++17


include $(PS2SDK)/samples/Makefile.pref
include $(PS2SDK)/samples/Makefile.eeglobal

# Create build directory and custom object compilation rules
build/%.o: src/%.cpp
	@mkdir -p build
	$(EE_CXX) $(EE_CXXFLAGS) $(EE_INCS) -c $< -o $@

# ISO creation variables and rules AFTER includes
ISO_DIR = dvdrom
ISO_FILE = bin/ps2game.iso

$(ISO_FILE): $(EE_BIN)
	@mkdir -p $(ISO_DIR)/DATA
	@mkdir -p $(dir $(ISO_FILE))
	@cp $(EE_BIN) $(ISO_DIR)/BOOT.ELF
	@cp -r assets/* $(ISO_DIR)/DATA/ 2>/dev/null || true
	@echo "BOOT2 = cdrom0:\\BOOT.ELF;1" > $(ISO_DIR)/SYSTEM.CNF
	@echo "VER = 1.00" >> $(ISO_DIR)/SYSTEM.CNF
	@echo "VMODE = PAL" >> $(ISO_DIR)/SYSTEM.CNF
	@mkisofs -l -o $(ISO_FILE) $(ISO_DIR)

iso: $(ISO_FILE)

clean-iso:
	rm -rf $(ISO_DIR) $(ISO_FILE)

.PHONY: iso clean-iso
