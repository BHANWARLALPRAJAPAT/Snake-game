# 🐍 Snake Game (Console)

A classic Snake game built in C++ for the Windows console, using `conio.h` for real-time keyboard input.

## 📋 Description

This is a text-based Snake game that renders directly in the terminal using ASCII characters. The player controls a snake (`O` for the head, `o` for the tail) that moves around a bordered grid, eating fruit (`F`) to grow longer and increase the score.

**Current behavior:**
- The fruit is now visibly drawn on the grid as `F`.
- The snake **wraps around the edges** of the screen instead of dying when it hits a wall.
- Self-collision (running into its own tail) is **currently disabled** in the code (commented out), so the snake cannot die by touching itself.
- As a result, the game currently has **no way to end** other than closing the program — the collision/game-over checks exist in the code but are commented out.

## 🎯 Scope

This project is a minimal, educational implementation of Snake intended to demonstrate core game-loop concepts in C++. It covers:

- A basic `Setup → Draw → Input → Logic` game loop structure
- Real-time (non-blocking) keyboard input using `conio.h`
- Console-based rendering with `system("cls")` and ASCII characters
- Simple 2D grid movement, wrapping, and array-based tail tracking
- Fruit spawning, collision detection with fruit, and score tracking

**Out of scope / not currently included:**
- Proper game-over conditions (wall or self-collision)
- Cross-platform support (Windows-only due to `conio.h`)
- Speed control / difficulty scaling
- Menus, pause functionality, high scores, or save/load
- Graphics beyond plain text/ASCII

This project is meant as a learning exercise and a base to extend, not a full-featured game.

## 🛠️ Requirements

- Windows OS (uses `conio.h` and `system("cls")`, which are Windows-specific)
- A C++ compiler (e.g., MinGW, MSVC / Visual Studio)

> ⚠️ This program will **not compile on Linux or macOS** without modification, since `conio.h` is not available on those platforms.

## ⚙️ Compilation

Using g++ (MinGW on Windows):

```bash
g++ snake.cpp -o snake.exe
```

Or open and build the project in Visual Studio.

## ▶️ Usage

Run the compiled executable:

```bash
snake.exe
```

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
- A fruit (`F`) spawns at a random location and is now rendered on the grid.
- Move the snake onto the fruit to:
  - Increase the score by `10`
  - Grow the snake's tail by one segment
  - Spawn a new fruit at a random location
- The snake wraps to the opposite side of the grid when it crosses an edge.
- The current score is displayed below the grid after every frame.

## 📁 File Structure

```
.
├── snake.cpp    # Main source code
└── README.md    # Project documentation
```

## 🔧 Known Limitations / Possible Improvements

- Enable the commented-out boundary and self-collision checks in `Logic()` to allow the game to actually end.
- Add a frame-rate delay (e.g., `Sleep()`) to control snake speed — currently the loop runs as fast as possible.
- Cross-platform support by replacing `conio.h` and `system("cls")` with a portable input/clear-screen solution.
- Difficulty scaling (speed increases as score grows).

## 📝 License

This project is free to use and modify for personal or educational purposes.