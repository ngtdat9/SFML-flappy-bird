//
// Created by Mac của Đạt on 2/6/25.
//

#pragma once

#define SCREEN_WIDTH 650
#define SCREEN_HEIGHT 1030
#define SPLASH_STATE_SHOW_TIME 3.0
#define SPLASH_SCENE_BACKGROUND_FILEPATH "../assets/res/bird-splash.jpg"
#define MAIN_MENU_BACKGROUND_FILEPATH "../assets/res/sky.png"
#define GAME_TITLE_FILEPATH "../assets/res/title.png"
#define PLAY_BUTTON_FILEPATH "../assets/res/PlayButton.png"
#define GAME_BACKGROUND_FILEPATH "../assets/res/sky.png"
#define GAME_OVER_BACKGROUND_FILEPATH "../assets/res/sky.png"
#define PIPE_UP_FILEPATH "../assets/res/PipeUp.png"
#define PIPE_DOWN_FILEPATH "../assets/res/PipeDown.png"
#define SCORING_PIPE_FILEPATH "../assets/res/InvisibleScoringPipe.png"

#define LAND_FILEPATH "../assets/res/land.png"

#define BIRD_FILEPATH "../assets/res/bird-01.png"
#define BIRD_STATE_STILL 1
#define BIRD_STATE_FALL 2
#define BIRD_STATE_FLY 3
#define GRAVITY 350.0f
#define FLY_SPEED 350.0f
#define FLY_DURATION 0.25f

#define FLAPPY_FONT_FILEPATH "../assets/fonts/FlappyFont.ttf"
#define GAME_OVER_TITLE_FILEPATH "../assets/res/Game-Over-Title.png"
#define GAME_OVER_BODY_FILEPATH "../assets/res/Game-Over-Body.png"


#define PIPE_MOVE_SPEED 200.0f
#define PIPE_SPAWN_FREQUENCY 1.5f

//enumeration (0,1,2)
enum GameStates
{
    eReady, ePlaying, eGameOver
};

#define TIME_BEFORE_GAME_OVER 1.0f

