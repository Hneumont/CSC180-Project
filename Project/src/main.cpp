#include "libs/raylib/raylib.h"
//#include "C://raylib/raylib/src/raymath.h"
#include "libs/raylib/rcamera.h"
#define RAYGUI_IMPLEMENTATION
#include "libs/raygui.h"

int main(void){
    const int screenWidth = 1080;
    const int screenHeight = 720;
    bool showMessageBox = true;

    InitWindow(screenWidth, screenHeight, "TEST WINDOW");

    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(LIGHTGRAY);
            if (GuiButton((Rectangle){ 24, 24, 120, 30 }, "#191#Show Message")) showMessageBox = true;

            if (showMessageBox)
            {
                int result = GuiMessageBox((Rectangle){ 85, 70, 600, 100 },
                    "#191#Message Box", "ewwwwwwwwwwwwwwwwwwwwwwwwwwwwww", "What the dog doin?;Megaman drops January 7th!");

                if (result >= 0) showMessageBox = false;
            }
        EndDrawing();
    }
}
