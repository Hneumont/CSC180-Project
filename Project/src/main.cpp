#include "libs/raylib/raylib.h"
//#include "libs/raylib/raymath.h"
#include "libs/raylib/rcamera.h"
#include <algorithm>
#include <array>
#include <string.h>
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

int* typedkeys = new int[8];
void addInput(int inInt){
    int* newarr = new int[sizeof(typedkeys)+1];
    std::copy(typedkeys, typedkeys, newarr);
    newarr[sizeof(newarr)-1] = inInt;
    typedkeys = newarr;
}

bool WindowOpen = true;

int main(void){
    const int screenWidth = 1080;
    const int screenHeight = 720;
    //GetScreenHeight/Width return window Height/Width NOT monitor size.
    Color bgColor = BLACK;
    const std::string stydir = "styles/";
    std::string styarr[15] ={"default","lavanda","terminal","amber","ashes","bluish","candy","cherry","cyber","dark","enefete","genesis","jungle","rltech","sunny"};
    std::string stylename = styarr[1];
    std::string styfull = stydir+stylename+"/style_"+stylename+".rgs";

    InitWindow(screenWidth, screenHeight, "Test Window");
    GuiLoadStyle(styfull.c_str());


    std::string debugmsg;
    std::string inputText;
    char* in = new char[255];


    while(WindowOpen){
        BeginDrawing();
        ClearBackground(bgColor);

            if(IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_KP_ENTER)){ //key checks here can be replaced by throwing GuiTextBox in the if statement
                inputText = "\n"+std::string(in); // \n cannot be added after, but adding it before causes an incorrect shift
                in = new char[inputText.size()]; //resized char array to be text size
                strcpy(in,inputText.c_str()); // c_str() returns a const, const can't be used in GuiTextBox
            }
            GuiTextBox((Rectangle){(float)hCenter(),(float)vCenter(),255,255},in, 200, true); //font size doesn't seem to affect anything


            GuiDrawRectangle(Rectangle{0,0,screenWidth,screenHeight},0,WHITE,LIGHTGRAY);
            int result = GuiMessageBox((Rectangle){ 0, 0, screenWidth, 75 },
                "", "", "Save;Load"); // ';' and '\n' work to make a new button

            // result is reset to -1 every frame, thus >= is neccessary inplace of != 0
            if (result != 0 and result != -1) debugmsg = std::to_string(result); //button index -> text, index changes when a button is clicked
            else if (result == 0) WindowOpen = false; // 0 = x Icon on top right of message box

            if (GetKeyPressed() <= 96 and GetKeyPressed() >= 39) { //check keycode values in raylib.h
                //debugmsg += std::to_string(GetKeyPressed());
                addInput(GetKeyPressed());
            } // could be useful to make a custom text box rather than using the seemingly broken default one.
            //position x, position y, font-size, color
            debugmsg = "";
            for (range-declaration : range-expression) {

            }
            DrawText(debugmsg.c_str(), 0, vCenter(), 90, BLACK);
        EndDrawing();
        if (WindowShouldClose()) WindowOpen = false;
    }
    CloseWindow();
    return 0;
}
