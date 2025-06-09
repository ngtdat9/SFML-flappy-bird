cmake_minimum_required(VERSION 3.16)
project(FlappyBird)

set(CMAKE_CXX_STANDARD 17)

# Set path to SFML 2.5
set(SFML_DIR "/opt/homebrew/opt/sfml@2/lib/cmake/SFML")
find_package(SFML 2.5 REQUIRED COMPONENTS graphics window system)

# Include headers in src/
include_directories(include)


# Gather all .cpp and .hpp files from src/ folder
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp src/*.h)

# Create executable
add_executable(FlappyBird ${SOURCES}
        src/main.cpp
        src/Game.cpp
        src/StateMachine.cpp
        src/AssetManager.cpp
        src/InputManager.cpp
        src/SplashState.cpp
        src/MainMenuState.cpp
        src/GameState.cpp
        src/GameOverState.cpp
        src/Land.cpp
        include/Land.h
        include/Collision.h
        src/Collision.cpp
        include/displayHUD.h
        src/displayHUD.cpp)

# Link SFML libraries
target_link_libraries(FlappyBird sfml-graphics sfml-window sfml-system)