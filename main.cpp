#include <stdexcept>
#include <sstream>
#include <string>
#include <iomanip>

#include "raylib.h"

using namespace std;

/* ----------------------------------------------------------------------------
Constants
----------------------------------------------------------------------------- */

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 450;

/**
Computes a Y coordinate from the bottom of the screen.
*/
#define FROM_BOTTOM(y) (SCREEN_HEIGHT - ( y ) )

/* ----------------------------------------------------------------------------
Rocket variables
----------------------------------------------------------------------------- */

Texture2D rocketTexture;

/* ----------------------------------------------------------------------------
Gameplay state
----------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
Terrain variables
----------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
Stage init functions
----------------------------------------------------------------------------- */

/**
Sets current stage to preflight.
*/
void StartPreflightStage()
{
}

/**
Sets current stage to launch.
*/
void StartLaunchStage()
{
}

/**
Sets current stage to roll.
*/
void StartRollStage()
{
}

/**
Sets current stage to manual control.
*/
void StartManualStage()
{
}

/**
Sets current stage to success.
*/
void StartSuccessStage()
{
}

/**
Sets current stage to failure.
*/
void StartFailureStage()
{
}

/* ----------------------------------------------------------------------------
Stage update functions
----------------------------------------------------------------------------- */

/**
Runs logic for a single frame during the preflight stage.
*/
void RunPreflightStageFrame()
{
}

/**
Runs logic for a single frame during the launch stage.
*/
void RunLaunchStageFrame(float deltaTimeSec)
{
}

/**
Runs logic for a single frame during the roll stage.
*/
void RunRollStageFrame(float deltaTimeSec)
{
}

/**
Runs logic for a single frame during the manual control stage.
*/
void RunManualStageFrame(float deltaTimeSec)
{
}

/**
Runs logic for a single frame of either success or failure states.
*/
void RunEndGameStage()
{
}

/* ----------------------------------------------------------------------------
Drawing functions
----------------------------------------------------------------------------- */

/**
Draw the rocket based on its current position.
*/
void DrawRocket()
{
    DrawTexture(rocketTexture, 100, 100, WHITE);
}

/**
Draw the ground, water, and landing boat.
*/
void DrawEnvironment()
{
}

/**
Draw text indicating current state of flight.
*/
void DrawCurrentStageText()
{
}

/**
Draw statistics and UI elements.
*/
void DrawHud()
{
    DrawText("Hello world!", 100, 175, 24, BLUE);
}

/**
Program entry point.
*/
int main(void)
{
    /* ------------------------------------------------------------------------
    Initialization
    ------------------------------------------------------------------------- */

    // Scale things for high DPI monitors so we can see it
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);

    // Setup the application window
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Rocket Lander");

    // Set game to run at 60 frames-per-second
    SetTargetFPS(60);

    // Create a basic 2D camera
    Camera2D camera;
    camera.offset = { 0, 0 };
    camera.rotation = 0;
    camera.target = { 0, 0 };
    camera.zoom = 1.0f;

    // Load rocket texture
    rocketTexture = LoadTexture("rocket.png");
    if (!rocketTexture.id)
        throw new runtime_error("Failed to load rocket texture.");

    /* ------------------------------------------------------------------------
    Main loop
    ------------------------------------------------------------------------- */

    while (!WindowShouldClose()) {

        /* ------------------------------------------------------------------------
        Update frame

        Run any logic to compute the state of this frame, such
        as user input, game state, and physics computations.
        ------------------------------------------------------------------------- */

        /* ------------------------------------------------------------------------
        Draw frame

        Draw any objects in the world or text on the screen based on their current
        position/state.
        ------------------------------------------------------------------------- */

        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode2D(camera);
        DrawRocket();
        DrawEnvironment();
        EndMode2D();

        DrawHud();

        EndDrawing();
    }

    // Close window and OpenGL context
    CloseWindow();

    return 0;
}
