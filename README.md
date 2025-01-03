# SFML Snake Game

## Overview
This is a simple Snake Game built using **SFML** (Simple and Fast Multimedia Library) and C++. The game allows you to control a snake that grows in length as it eats apples, while avoiding collisions with itself or the game boundaries.

## Features
- Classic snake gameplay
- Dynamic snake movement
- Visual assets for snake and apples
- Game-over detection

## Prerequisites
To build and run this project, you'll need:

1. **SFML Library**: Install SFML 2.5.1 or later. You can download it from the [SFML website](https://www.sfml-dev.org/download.php).
2. **Visual Studio**: The project is configured for Visual Studio. You can download it [here](https://visualstudio.microsoft.com/).
3. A C++17 or later compiler.

## Setup Instructions

1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/sfml-snake-game.git
   cd sfml-snake-game
   ```

2. Install SFML:
   - Follow the instructions on the [SFML website](https://www.sfml-dev.org/tutorials/2.5/start-vc.php) to set up SFML in Visual Studio.

3. Open the `SFML.sln` file in Visual Studio.

4. Build the project:
   - Select `Release` mode for the best performance.
   - Press `Ctrl + Shift + B` to build the project.

5. Run the game:
   - Press `F5` to start the game.

## Folder Structure
```
.
├── imgui/                  # UI library (if applicable)
├── libraries/             # Additional libraries (if applicable)
├── SFML/                  # SFML-related files
├── assets/                # Assets for the game
│   ├── apple.png          # Apple texture
│   └── arial.ttf          # Font file
├── main.cpp               # Main source code
├── SFML.sln               # Visual Studio solution file
├── SFML.vcxproj           # Visual Studio project file
├── SFML.vcxproj.filters   # Visual Studio project filters
├── .gitignore             # Git ignore file
└── README.md              # Project documentation
```

## How to Play
1. Use the arrow keys to control the snake's movement.
2. Collect apples to grow the snake.
3. Avoid colliding with the walls or the snake's own body.
4. The game ends when a collision occurs.

## Contributing
Contributions are welcome! Feel free to fork this repository and submit a pull request with improvements or bug fixes.

## License
This project is licensed under the [MIT License](LICENSE).

## Acknowledgments
- **SFML** for providing an easy-to-use multimedia library.
- Inspiration from the classic Snake Game.

## Contact
For any questions or feedback, feel free to reach out:
- Email: your-email@example.com
- GitHub: [your-username](https://github.com/your-username)
