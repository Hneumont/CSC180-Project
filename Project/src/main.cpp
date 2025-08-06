#include "libs/raylib/raylib.h"
//#include "libs/raylib/raymath.h"
#include "libs/raylib/rcamera.h"
#include <array>
#include <string>
#define RAYGUI_IMPLEMENTATION
#include "libs/raygui.h"

// Quick Center Functions
std::array<int, 2> GetScreenCenter(){
    int x = GetScreenWidth()/2;
    int y = GetScreenHeight()/2;
    std::array<int,2> pos = {x,y};
    return pos;
}
int hCenter(){
    return GetScreenWidth()/2;
}
int vCenter(){
    return GetScreenHeight()/2;
}
// Quick Center Functions

int main(void){
    const int screenWidth = 1080;
    const int screenHeight = 720;
    //GetScreenHeight/Width return window Height/Width NOT monitor size.
    Color bgColor = BLACK;
    bool showMessageBox = true; //test gui implementation
    const std::string stydir = "styles/";
    std::string styarr[15] ={"default","lavanda","terminal","amber","ashes","bluish","candy","cherry","cyber","dark","enefete","genesis","jungle","rltech","sunny"};
    std::string stylename = styarr[2];
    std::string styfull = stydir+stylename+"/style_"+stylename+".rgs";

    InitWindow(screenWidth, screenHeight, "Test Window");
    GuiLoadStyle(styfull.c_str());


    std::string debugmsg;

    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(bgColor);
            if (GuiButton((Rectangle){ 24, 24, 120, 30 }, "#191#Show Message")) showMessageBox = true;

            if (showMessageBox)
            {
                int result = GuiMessageBox((Rectangle){ 85, 70, 600, 100 },
                    "#191#Message Box", "This is a message box", "Option 1/;Yes;Option 2/;No"); //; and \n work to make a new button

                // result is reset to -1 every frame, thus >= is neccessary inplace of != 0
                if (result >= 0) debugmsg = std::to_string(result); //button index -> text, index changes when a button is clicked
                else if (result == 0) showMessageBox = false; // 0 = x Icon on top right of message box
            }
            //DrawText(debugmsg.c_str(), screenWidth/2, screenHeight/2, 90, WHITE); //position x, position y, font-size, color
            DrawText(debugmsg.c_str(), GetScreenCenter()[0], GetScreenCenter()[1], 90, WHITE);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
