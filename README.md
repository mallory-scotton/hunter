
# 🦆 MyHunter

<p align="center">
  <img src="assets/logo.png" alt="MyHunter Logo" width="300"/>
</p>

<p align="center">
  <strong>A faithful recreation of the classic Duck Hunt game using CSFML</strong>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c" alt="Language">
  <img src="https://img.shields.io/badge/Graphics-CSFML-green?style=for-the-badge" alt="CSFML">
  <img src="https://img.shields.io/badge/Platform-Linux-orange?style=for-the-badge&logo=linux" alt="Platform">
  <img src="https://img.shields.io/badge/License-MIT-yellow?style=for-the-badge" alt="License">
</p>

---

## 📋 Project Overview

MyHunter is a modern C implementation of the classic Nintendo Duck Hunt game, built using the CSFML (Simple and Fast Multimedia Library for C). The project recreates the nostalgic gameplay experience with enhanced features including controller support, multiple game modes, and smooth animations.

This project was developed as part of an EPITECH assignment, demonstrating proficiency in C programming, game development fundamentals, event handling, and multimedia programming with CSFML.

### 🎯 Key Objectives
- Recreate the core mechanics of Duck Hunt
- Implement smooth sprite animations and game physics
- Support multiple input methods (mouse, keyboard, controller)
- Create an intuitive menu system
- Maintain 60 FPS performance

## ✨ Features

### 🎮 Game Modes
- **Single Player**: Classic duck hunting experience
- **Two Player**: Cooperative gameplay (in development)
- **Menu System**: Interactive sprite-based navigation

### 🎨 Graphics & Animation
- High-quality sprite sheets and animations
- Smooth duck flight patterns with realistic physics
- Dynamic crosshair system with multiple weapon types
- Parallax scrolling backgrounds
- Real-time HUD with score and ammunition display

### 🕹️ Input Support
- **Mouse & Keyboard**: Traditional PC controls
- **Game Controller**: Full joystick support with configurable sensitivity
- **Hybrid Controls**: Seamless switching between input methods

### 🎵 Audio System
- Background music and sound effects
- Gunshot and duck interaction sounds
- Menu navigation audio feedback
- *(Note: Currently experiencing hardware compatibility issues)*

### 📊 Game Mechanics
- **Ammunition System**: Limited shots per round
- **Scoring System**: Point-based progression
- **Difficulty Scaling**: Adaptive challenge levels
- **Duck AI**: Random movement patterns and behaviors

## 🖼️ Gallery

![Demo GIF](screenshots/hunter.gif)

*MyHunter gameplay demonstration*

## 🔧 Installation

### Prerequisites

Ensure you have the following dependencies installed on your system:

```bash
# Ubuntu/Debian
sudo apt-get update
sudo apt-get install libcsfml-dev gcc make

# Arch Linux
sudo pacman -S csfml gcc make

# Fedora
sudo dnf install CSFML-devel gcc make
```

### Building from Source

1. **Clone the repository:**
   ```bash
   git clone https://github.com/mallory-scotton/hunter.git
   cd hunter
   ```

2. **Compile the project:**
   ```bash
   make
   ```

3. **Run the game:**
   ```bash
   ./my_hunter
   ```

## 🎮 Usage

### Controls

#### Mouse & Keyboard
- **Mouse Movement**: Aim crosshair
- **Left Click**: Shoot
- **Arrow Keys**: Navigate menus
- **Enter**: Select menu option
- **Escape**: Return to menu/Exit game

#### Controller (if connected)
- **Left Stick**: Aim and navigate
- **Right Trigger**: Shoot
- **D-Pad**: Menu navigation
- **A Button**: Select

### Command Line Options

```bash
./my_hunter -h    # Display help information
```

## 🏗️ Build Instructions

### Development Build

```bash
make                 # Standard build
make clean          # Remove object files
make fclean         # Remove all generated files
make re             # Clean rebuild
```

### Project Structure

```
hunter/
├── src/                    # Source code
│   ├── main.c             # Application entry point
│   ├── init.c             # Game initialization
│   ├── loop.c             # Main game loop
│   ├── window.c           # Window management
│   ├── hud.c              # HUD rendering
│   ├── events/            # Event handling system
│   ├── functions/         # Game mechanics
│   ├── gamemode/          # Game mode implementations
│   └── util/              # Utility functions
├── include/               # Header files
│   ├── engine.h           # Main engine header
│   ├── types.h            # Type definitions
│   ├── config.h           # Game configuration
│   └── defs.h             # Game constants
├── assets/                # Game assets
│   ├── *.png             # Sprite sheets and textures
│   ├── audio/            # Sound effects and music
│   └── crosshair/        # Crosshair variants
└── Makefile              # Build configuration
```

### Compilation Details

- **Compiler**: GCC with debugging flags (`-g3`)
- **Libraries**: CSFML (graphics, system, window, audio)
- **Standards**: C99 compatible
- **Platform**: Linux (tested on Ubuntu, Arch, Fedora)

## 🔗 Dependencies

| Library | Version | Purpose |
|---------|---------|---------|
| CSFML-Graphics | 2.5+ | Rendering and sprites |
| CSFML-System | 2.5+ | System utilities |
| CSFML-Window | 2.5+ | Window management |
| CSFML-Audio | 2.5+ | Sound system |
| libc | Standard | Memory management |
| libm | Standard | Mathematical functions |

## 📄 License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.

```
MIT License
Copyright (c) 2024 Tekyo Drift
```

## 🤝 Contributing

We welcome contributions! Please read our [Contributing Guidelines](CONTRIBUTING.md) before submitting pull requests.

### Development Process
1. Fork the repository
2. Create a feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

### Code Standards
- Follow the existing code style
- Comment complex algorithms
- Ensure compatibility with CSFML 2.5+
- Test on multiple Linux distributions

## 📧 Contact

**Mallory Scotton**  
📧 Email: [mscotton.pro@gmail.com](mailto:mscotton.pro@gmail.com)  
🐙 GitHub: [@mallory-scotton](https://github.com/mallory-scotton)

## 🎊 Acknowledgments

- **Development**: Mallory Scotton
- **Testing**: MS, NF, HC, OM, RO
- **Assets**: Custom sprites and Nintendo-inspired sounds
- **Framework**: CSFML Library
- **Institution**: EPITECH

---

<p align="center">
  <em>🎯 Coded with ❤️ and precision targeting</em><br>
  <em>© 2024 MyHunter Project - Happy Hunting!</em>
</p>
