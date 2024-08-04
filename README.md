# dinosaur-game

A simple jumping dinosaur game in C++

This is for me to learn and play around with C++ again after a while

## Resources + Inspiration

- https://www.youtube.com/watch?v=W9SfkPTn5BU
- https://www.youtube.com/watch?v=JGfuUhcp0dE
- https://github.com/congerh/dino?tab=readme-ov-file
- https://source.chromium.org/chromium/chromium/src/+/main:components/neterror/resources/offline-sprite-definitions.js

## Learning

- C++ OOP: Pass by reference, class composition, header vs cpp
- Basic game mechanics: C++ SFML, sprite loading, collision boxes

## Requirements

- cmake: `brew install cmake` (MacOS)
  - A cross-platform build system generator used to manage the build process of software projects

- vcpkg: `brew install vcpkg` (MacOS) and follow other instructions from brew's messages after brew finishes installing
  - A C/C++ package manager by Microsoft

## Run

**LEGACY**: Must run `./build/Dinosaur` at the root of the project so that it can find `images`

**NOW**:

- `cmake --preset=default -DCMAKE_EXPORT_COMPILE_COMMANDS=1`: Prepare a build folder according to our preset
- `cmake --build ./build/`: Actually build our C/C++ files into target using our CMakeLists.txt
- `./build/Dinosaur`: Run our game executable

## Quick Demo

https://github.com/user-attachments/assets/582872d9-c223-4d93-8977-70f9a870ee96
