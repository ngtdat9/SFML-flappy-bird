# 🐦 Flappy Bird Clone

Welcome to **Flappy Bird Clone**, a C++ game built with the SFML library. This game replicates the classic Flappy Bird experience: control a bird, dodge pipes, and beat your high score!

---

## 🎮 Features

- Smooth gameplay with gravity-based physics.
- Randomly generated pipes for endless challenge.
- State-based architecture (splash, menu, gameplay, game over).
- Simple, clean graphics inspired by the original game.
- High score tracking between sessions.

---

## 🛠️ Tech Stack

- **Language**: C++
- **Graphics & Input**: [SFML](https://www.sfml-dev.org/)
- **Build System**: CMake or your preferred compiler.

---

## 🚀 How to Build & Run

1. **Clone this repository**:
   ```bash
   git clone https://github.com/yourusername/flappy-bird-clone.git
   cd flappy-bird-clone
   ```

2. **Install SFML** (if not already):
   - On Ubuntu:
     ```bash
     sudo apt-get install libsfml-dev
     ```
   - On macOS (using Homebrew):
     ```bash
     brew install sfml
     ```
   - On Windows: Download from the [SFML website](https://www.sfml-dev.org/download.php).

3. **Build the project**:
   ```bash
   g++ -o flappybird main.cpp Game.cpp GameState.cpp MainMenuState.cpp SplashState.cpp GameOverState.cpp StateMachine.cpp InputManager.cpp Land.cpp Pipe.cpp Bird.cpp Collision.cpp displayHUD.cpp AssetManager.cpp -lsfml-graphics -lsfml-window -lsfml-system
   ```

4. **Run the game**:
   ```bash
   ./flappybird
   ```

---

## 🎮 How to Play

- **Start**: Click the **Play** button in the main menu.
- **Gameplay**: Click anywhere to make the bird flap.
- **Goal**: Navigate through gaps in the pipes.
- **Score**: Increases by 1 each time you pass a set of pipes.
- **Game Over**: If you hit a pipe or the ground, game over. Click "Play Again" to restart!

---

## 📂 Project Structure

```
.
├── AssetManager.h/.cpp
├── Bird.h/.cpp
├── Collision.h/.cpp
├── DEFINITIONS.h
├── displayHUD.h/.cpp
├── Game.h/.cpp
├── GameState.h/.cpp
├── GameOverState.h/.cpp
├── Land.h/.cpp
├── MainMenuState.h/.cpp
├── Pipe.h/.cpp
├── SplashState.h/.cpp
├── State.h
├── StateMachine.h/.cpp
├── main.cpp
└── assets/
```

---

## 🎨 Assets

- **Backgrounds, bird, pipes, and buttons** are in `assets/res/`.
- **Font**: Flappy Bird-style font in `assets/fonts/`.

---

## 💡 Ideas for Future Improvements

- Add pause menu.
- Add sound effects and music.
- Support for mobile (touch) input.
- Add more animations (flap animation, ground movement).

---

## 🤝 Contributing

Pull requests and issues are welcome! Let’s make this clone even better together.

---

## 📄 License

This project is for **educational purposes only** and is **not affiliated** with the original Flappy Bird game.

---

Enjoy playing and hacking on this project! 🚀
