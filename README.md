# 🐍 Snake Game (Console)

A classic Snake game for the terminal, written in C++. Now split into multiple files and fully **cross-platform** — it runs on Windows, Linux, and macOS.

## 📋 Description

This is a text-based Snake game that renders directly in the terminal using ASCII characters. The player controls a snake (`O` head, `o` tail) around a bordered grid, eating fruit (`F`) to grow longer and increase the score.

**Current behavior:**
- The fruit is drawn on the grid as `F`.
- The snake **wraps around the edges** of the screen instead of dying when it hits a wall.
- Self-collision (running into its own tail) is **currently disabled** in the code (commented out), so the snake cannot die by touching itself.
- The game currently has **no way to end** other than closing the program — the collision/game-over checks exist in the code but are commented out.

## 🎯 Scope

This project is a minimal, educational implementation of Snake intended to demonstrate core game-loop concepts in C++, split across multiple files for clarity. It covers:

- A `Setup → Draw → Input → Logic` game loop, encapsulated in a `Game` class
- A `Platform` module that abstracts OS differences (input handling, screen clearing) so the same game code runs everywhere
- Real-time (non-blocking) keyboard input on both Windows (`conio.h`) and Linux/macOS (raw-mode `termios`)
- Simple 2D grid movement, wrapping, and array-based tail tracking
- Fruit spawning, collision detection with fruit, and score tracking

**Out of scope / not currently included:**
- Proper game-over conditions (wall or self-collision)
- Speed control / difficulty scaling
- Menus, pause functionality, high scores, or save/load
- Graphics beyond plain text/ASCII

## 📁 File Structure

```
snake_game/
├── include/
│   ├── Game.h          # Game class declaration
│   └── Platform.h       # Cross-platform input/screen function declarations
├── src/
│   ├── Game.cpp          # Game class implementation (Setup, Draw, Input, Logic)
│   ├── Platform.cpp     # Windows vs Linux/macOS implementations
│   └── main.cpp          # Entry point
├── CMakeLists.txt        # Cross-platform build config
└── README.md
```

### Why split this way?

| File | Responsibility |
|---|---|
| `Platform.h` / `Platform.cpp` | Everything OS-specific: clearing the screen and reading keys without blocking. Windows uses `conio.h`; Linux/macOS use `termios` raw mode + non-blocking `read()`. This is the **only** place `#ifdef _WIN32` appears. |
| `Game.h` / `Game.cpp` | All game state and rules (movement, fruit, score, wrapping). Contains no OS-specific code — it only calls the `Platform` functions. |
| `main.cpp` | Seeds the random number generator, sets up/tears down terminal input, and runs the game. |

## 🛠️ Requirements

- A C++11 (or later) compiler:
  - **Windows:** MinGW (g++) or MSVC / Visual Studio
  - **Linux:** g++ or clang++
  - **macOS:** clang++ (Xcode Command Line Tools) or g++
- CMake 3.10+ (optional, but recommended for building)

## ⚙️ Compilation

### Option 1: CMake (recommended, works on all platforms)

```bash
mkdir build && cd build
cmake ..
cmake --build .
```

This produces a `snake` (or `snake.exe` on Windows) executable in the `build/` directory.

### Option 2: Direct compiler invocation

**Linux / macOS:**
```bash
g++ -std=c++11 -Iinclude src/main.cpp src/Game.cpp src/Platform.cpp -o snake
```

**Windows (MinGW):**
```bash
g++ -std=c++11 -Iinclude src/main.cpp src/Game.cpp src/Platform.cpp -o snake.exe
```

## ▶️ Usage

```bash
./snake       # Linux / macOS
snake.exe     # Windows
```

> 💡 On Linux/macOS, run this in a real terminal (not through an IDE's non-interactive output pane), since it relies on raw terminal input.

## 🎮 Controls

| Key | Action     |
|-----|------------|
| `w` | Move Up    |
| `s` | Move Down  |
| `a` | Move Left  |
| `d` | Move Right |
| `x` | (Reserved — game-over trigger currently disabled) |

## 🍎 Gameplay

- The snake starts in the middle of a `50 x 20` grid.
- A fruit (`F`) spawns at a random location.
- Move the snake onto the fruit to:
  - Increase the score by `10`
  - Grow the snake's tail by one segment
  - Spawn a new fruit at a random location
- The snake wraps to the opposite side of the grid when it crosses an edge.
- The current score is displayed below the grid after every frame.

## 🔧 Known Limitations / Possible Improvements

- Enable the commented-out boundary and self-collision checks in `Game::Logic()` to allow the game to actually end.
- Add a frame-rate delay (e.g., a portable `sleep`) to control snake speed — currently the loop runs as fast as possible.
- Difficulty scaling (speed increases as score grows).
- Restore terminal settings on abnormal exit (e.g., `Ctrl+C`) using a signal handler, so `ResetInput()` always runs.

## 📝 License

This project is free to use and modify for personal or educational purposes.
