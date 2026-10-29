# 🧠 Memory Card Game in C (SDL2)

An interactive 2D Memory Card Game developed in **C** using the **SDL2** multimedia library suite. Built within the Code::Blocks IDE, the game leverages `SDL2_image` and `SDL2_ttf` extensions for custom texture rendering, typography, and interactive state management.

---

## 📸 Screenshots

<!-- Place your game screenshots in a "screenshots/" folder to display them here -->
<p align="center">
  <img src="screenshots/menu.png" width="45%" alt="Main Menu" />
  <img src="screenshots/gameplay.png" width="45%" alt="Gameplay Grid" />
</p>

---

## 🎮 Game Overview

The game follows classic memory matching mechanics:
- A grid of hidden, face-down cards is generated and shuffled randomly at the start of each round.
- The player reveals two cards per turn.
- If both cards match, they remain face-up. If they differ, they flip back face-down after a brief automatic delay.
- The objective is to uncover all pairs with optimal focus and accuracy.

---

## ✨ Features

- **Menus & Navigation States:**
  - Interactive main menu with hover/click button feedback (`Player mode`, `Machine mode`, `Record mode`).
  - Pause overlay accessible during active gameplay (`Continue`, `Replay`, `Menu`).
  - Dedicated end-game outcome screens: Victory (`You won`) and Defeat (`Game Over`).
  - High-score display screen (`Record table`).

- **Game Engine & Mechanics:**
  - Dynamic card shuffling and distribution algorithm.
  - Mouse coordinate tracking and real-time bounding-box click detection.
  - Automatic timer delay for non-matching card pairs.
  - 2D hardware-accelerated rendering pipeline via SDL2 and SDL2_image.

---

## 🗂️ Project Structure

```text
├── image/               # Graphical assets (cards, buttons, UI screens)
├── screenshots/         # Preview images for repository documentation
├── bib.h                # Game data structures and function prototypes
├── SDL_draw.h           # Graphical rendering prototypes and definitions
├── fcts.c               # Core game logic, state machines, and card arrays
├── SDL_functions.c      # SDL event loop, window handling, and texture management
├── main.c               # Application entry point and primary event loop
└── V3.cbp               # Code::Blocks project configuration file
```

---

## 🛠️ Tech Stack

- **Language:** C (C99 / C11 standards)
- **Rendering Engine:** [SDL2](https://www.libsdl.org/)
- **SDL2 Extensions:**
  - `SDL2_image` (PNG loading and texture surfaces)
  - `SDL2_ttf` (TrueType font rendering)
- **Development Toolchain:** Code::Blocks / GCC (MinGW)

---

## 🚀 Build & Execution

### Option 1: Using Code::Blocks (Recommended)

1. Open the project file: `V3.cbp`.
2. Verify that **Project Properties / Build Options** point to your local SDL2 include and library directories (`SDL2`, `SDL2_image`, `SDL2_ttf`).
3. Ensure runtime DLL files (`SDL2.dll`, `SDL2_image.dll`, `SDL2_ttf.dll`, etc.) are located in the executable folder or working directory.
4. Press **F9** (*Build and Run*).

### Option 2: Command Line (MinGW / GCC on Windows)

```bash
gcc -o MemoryGame.exe main.c fcts.c SDL_functions.c -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf
./MemoryGame.exe
```