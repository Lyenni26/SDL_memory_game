# 🧠 Memory & Trajectory Puzzle Game in C (SDL2)

A 2D mental calculation and spatial memory game developed in **C** using the **SDL2** multimedia library suite. Built within Code::Blocks, the game leverages `SDL2_image` and `SDL2_ttf` for graphical rendering, custom fonts, and real-time state management.

---

## 🎮 Game Rules & Mechanics

The game challenges spatial memory and mental raycasting on an $N \times N$ discrete grid containing $M$ oriented diagonals:

1. **Memorization Phase:**
   - The grid displays $M$ diagonals distributed across specific cells.
   - The player must memorize the exact orientation of each diagonal (`/` or `\`) before they are hidden by the machine.

2. **Trajectory Prediction Phase:**
   - The machine provides a starting entry point and initial direction for a moving ball.
   - The player must predict the complete path of the ball through the invisible obstacles.
   - Every time the ball strikes a diagonal obstacle, it deflects at a $90^\circ$ angle based on the obstacle's orientation:
     - A `/` diagonal reflects horizontal trajectories vertically and vice-versa ($\rightarrow$ becomes $\uparrow$ or $\downarrow$).
     - A `\` diagonal reflects the trajectory along the opposite perpendicular axis.
   - The player selects the correct exit point or endpoint of the trajectory to succeed.

---

## ✨ Features

- **Game Modes & Navigation:**
  - **Player Mode (`Playermode`):** Manual trajectory prediction against hidden diagonals.
  - **Machine Mode (`Machinemode`):** Automated simulation and path demonstration.
  - **Record Mode (`Recordmode`):** Performance history and high-score table.
  - In-game pause menu (`Continue`, `Replay`, `Menu`).
  - Clear victory (`You Won`) and defeat (`Game Over`) conditions.

- **Engine & Technical Implementation:**
  - Procedural generation and placement of diagonal obstacles.
  - Exact $90^\circ$ reflection vector calculation and raycasting logic.
  - Responsive mouse input handling with hover state detection.
  - Hardware-accelerated 2D rendering through SDL2 and SDL2_image.

---

## 🗂️ Project Structure

```text
├── image/               # Graphical assets (buttons, icons, UI screens)
├── bib.h                # Core data structures and game logic prototypes
├── SDL_draw.h           # Visual rendering headers and graphical primitives
├── fcts.c               # Grid initialization, obstacle memory, and ray-tracing logic
├── SDL_functions.c      # Window management, SDL event handling, and rendering loops
├── main.c               # Application entry point and primary event loop
└── V3.cbp               # Code::Blocks project configuration file
```

---

## 🛠️ Tech Stack

- **Language:** C (C99 / C11)
- **Multimedia Engine:** [SDL2](https://www.libsdl.org/)
- **Extensions:**
  - `SDL2_image` (Sprite and UI element rendering)
  - `SDL2_ttf` (Dynamic score and text typography)
- **Toolchain:** Code::Blocks / MinGW (GCC)

---

## 🚀 Build & Execution

### Option 1: Code::Blocks (Recommended)

1. Open `V3.cbp` in Code::Blocks.
2. Verify that **Project Build Options** point to your local SDL2 include and library directories (`SDL2`, `SDL2_image`, `SDL2_ttf`).
3. Ensure the required runtime libraries (`SDL2.dll`, `SDL2_image.dll`, `SDL2_ttf.dll`) reside in the working directory.
4. Press **F9** (*Build and Run*).

### Option 2: Command Line (MinGW / GCC on Windows)

```bash
gcc -o MemoryGame.exe main.c fcts.c SDL_functions.c -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf
./MemoryGame.exe
```