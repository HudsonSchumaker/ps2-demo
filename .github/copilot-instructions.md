# Copilot Instructions for PS2 Game Development

<!-- Use this file to provide workspace-specific custom instructions to Copilot. For more details, visit https://code.visualstudio.com/docs/copilot/copilot-customization#_use-a-githubcopilotinstructionsmd-file -->

## Project Context
This is a PlayStation 2 game development project using:
- PS2Dev toolchain for PlayStation 2 development
- SDL2 port for PS2 for graphics, audio, and input handling
- C++ as the primary programming language
- Custom Makefile for PS2-specific compilation

## Development Guidelines
- Use PS2-specific libraries and functions when available
- Follow PS2 memory constraints and optimization practices
- Leverage SDL2 for cross-platform compatibility where possible
- Use EE (Emotion Engine) specific optimizations when needed
- Consider VRAM limitations and optimize texture usage
- Follow PS2Dev naming conventions and coding standards

## Key Dependencies
- ps2sdk for PlayStation 2 system libraries
- SDL2 port for PS2 for multimedia functionality
- gsKit for Graphics Processing Unit (GPU) operations
- padlib for controller input handling
- c++ 17 standard library for C++ features

## Build System
- Use the provided Makefile for building
- Target the PlayStation 2 EE (Emotion Engine) processor
- Generate ELF files compatible with PS2 hardware/emulators