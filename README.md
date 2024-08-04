# dinosaur-game

A simple jumping dinosaur game in C++ that is inspired from T-Rex Runner game in Google Chrome

This is for me to learn and play around with C++ after a long time abandoning it

## Resources + Inspiration

- Basic example: https://www.youtube.com/watch?v=W9SfkPTn5BU
- Extracted version: https://github.com/congerh/dino?tab=readme-ov-file
- Source code: https://source.chromium.org/chromium/chromium/src/+/main:components/neterror/resources/offline-sprite-definitions.js

## Learning

- C++ OOP: Pass by reference, class composition, header vs cpp
- Basic game mechanics: C++ SFML, sprite loading, collision boxes

## Requirements

- cmake: `brew install cmake` (MacOS)
  - A cross-platform build system generator used to manage the build process of software projects

- vcpkg: `brew install vcpkg` (MacOS) and follow other instructions from brew's messages after brew finishes installing
  - A C/C++ package manager by Microsoft

## Run

**LEGACY**: 

- Must run `./build/Dinosaur` at the root of the project so that it can find `images`

**NOW**:

- `cmake --preset=default -DCMAKE_EXPORT_COMPILE_COMMANDS=1`: Prepare a build folder according to our preset
- `cmake --build ./build/`: Actually build our C/C++ files into target using our CMakeLists.txt
- `./build/Dinosaur`: Run our game executable

## Quick Demo

https://github.com/user-attachments/assets/fac2a9fe-9e61-4d7c-9ec3-3b296bf259d3
