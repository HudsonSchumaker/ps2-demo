# PS2 Game Demo

This project is a PlayStation 2 game demo built using the PS2Dev toolchain, SDL2 port for PS2, and C++17. It demonstrates native PS2 graphics, audio, and input handling, and is designed to run on real PS2 hardware or emulators.

## Features
- Native PS2 graphics using gsKit and SDL2
- Audio playback via SDL2_mixer and audsrv
- Controller input via padlib
- Optimized for PS2 memory and VRAM constraints
- Custom scene management and splash/title screens

## Project Structure
```
assets/           # Game assets (images, etc.)
bin/              # Compiled ELF and ISO files
build/            # Object files
include/          # C++ header files
dvdrom/           # ISO build root (BOOT.ELF, SYSTEM.CNF, DATA)
src/              # C++ source files
Makefile          # Build script for PS2Dev toolchain
Dockerfile        # Docker setup for PS2Dev environment
docker-compose.yaml # Compose file for interactive development
```

## Build Instructions

### Prerequisites
- Docker installed
- (Optional) Real PS2 hardware or emulator (e.g., PCSX2)

### Build with Docker
1. Build the Docker image:
   ```sh
   docker-compose build
   ```
2. Start an interactive shell:
   ```sh
   docker-compose run ps2game-shell
   ```
3. Inside the container, build the game:
   ```sh
   make
   ```
   - This produces `bin/ps2game.elf` and `bin/ps2game.iso`.

### Run on Emulator
- Use `bin/ps2game.elf` or `bin/ps2game.iso` with your PS2 emulator (e.g., PCSX2).

## Cleaning Up
- Remove build artifacts and ISO:
  ```sh
  make clean-iso
  ```

## Key Dependencies
- [ps2sdk](https://github.com/ps2dev/ps2sdk)
- [gsKit](https://github.com/ps2dev/gsKit)
- [SDL2 port for PS2](https://github.com/ps2dev/ps2sdk-ports/tree/master/sdl)
- padlib, audsrv, modplug, freetype, png, zlib

## License
This project is released under the MIT License.
