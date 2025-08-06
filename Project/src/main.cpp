#include "libs/raylib/raylib.h"
//#include "libs/raylib/raymath.h"
#include "libs/raylib/rcamera.h"
#include <string>
#define RAYGUI_IMPLEMENTATION
#include "libs/raygui.h"

int main(void){
    const int screenWidth = 1080;
    const int screenHeight = 720;
    Color bgColor = BLACK;
    bool showMessageBox = true; //test gui implementation
    const std::string stydir = "styles/";
    std::string styarr[15] ={"default","lavanda","terminal","amber","ashes","bluish","candy","cherry","cyber","dark","enefete","genesis","jungle","rltech","sunny"};
    std::string stylename = styarr[2];
    std::string styfull = stydir+stylename+"/style_"+stylename+".rgs";

    InitWindow(screenWidth, screenHeight, "Test Window");
    //loaded from filename:
    // styles/[stylename]/[style.rgs file]
    GuiLoadStyle(styfull.c_str());
    //GuiLoadStyle("styles/lavanda/style_lavanda.rgs");

    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(bgColor);
            if (GuiButton((Rectangle){ 24, 24, 120, 30 }, "#191#Show Message")) showMessageBox = true;

            if (showMessageBox)
            {
                int result = GuiMessageBox((Rectangle){ 85, 70, 600, 100 },
                    "#191#Message Box", "ewwwwwwwwwwwwwwwwwwwwwwwwwwwwww", "What the dog doin?;Megaman drops January 7th!");

                if (result >= 0) showMessageBox = false;
            }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
