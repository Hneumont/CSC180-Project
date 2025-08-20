#include "libs/raylib/raylib.h"
//#include "libs/raylib/raymath.h"
#include "libs/raylib/rcamera.h"
#include <algorithm>
#include <array>
#include <string.h>
#include <string>
#define RAYGUI_IMPLEMENTATION
#include "libs/raygui.h"

//#include "keystr.h"

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

int* typedkeys = new int[0];
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
            if (IsKeyPressed(KEY_ENTER)) typedkeys = new int[0];
            bool caps;
            if (IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT)) caps = true;
            else caps = false;
// TEXT INPUT
            if(IsKeyPressed(KEY_A)){
                if(caps == true) debugmsg += "A";
                else debugmsg += "a";
            }
            if(IsKeyPressed(KEY_B)){
                if(caps) debugmsg += "B";
                else debugmsg += "b";
            }
            if(IsKeyPressed(KEY_C)){
                if(caps) debugmsg += "C";
                else debugmsg += "c";
            }
            if(IsKeyPressed(KEY_D)){
                if(caps) debugmsg += "D";
                else debugmsg += "d";
            }
            if(IsKeyPressed(KEY_E)){
                if(caps) debugmsg += "E";
                else debugmsg += "e";
            }
            if(IsKeyPressed(KEY_F)){
                if(caps) debugmsg += "F";
                else debugmsg += "f";
            }
            if(IsKeyPressed(KEY_G)){
                if(caps) debugmsg += "G";
                else debugmsg += "g";
            }
            if(IsKeyPressed(KEY_H)){
                if(caps) debugmsg += "H";
                else debugmsg += "h";
            }
            if(IsKeyPressed(KEY_I)){
                if(caps) debugmsg += "I";
                else debugmsg += "i";
            }
            if(IsKeyPressed(KEY_J)){
                if(caps) debugmsg += "J";
                else debugmsg += "j";
            }
            if(IsKeyPressed(KEY_K)){
                if(caps) debugmsg += "K";
                else debugmsg += "k";
            }
            if(IsKeyPressed(KEY_L)){
                if(caps) debugmsg += "L";
                else debugmsg += "l";
            }
            if(IsKeyPressed(KEY_M)){
                if(caps) debugmsg += "M";
                else debugmsg += "m";
            }
            if(IsKeyPressed(KEY_N)){
                if(caps) debugmsg += "N";
                else debugmsg += "n";
            }
            if(IsKeyPressed(KEY_O)){
                if(caps) debugmsg += "O";
                else debugmsg += "o";
            }
            if(IsKeyPressed(KEY_P)){
                if(caps) debugmsg += "P";
                else debugmsg += "p";
            }
            if(IsKeyPressed(KEY_Q)){
                if(caps) debugmsg += "Q";
                else debugmsg += "q";
            }
            if(IsKeyPressed(KEY_R)){
                if(caps) debugmsg += "R";
                else debugmsg += "r";
            }
            if(IsKeyPressed(KEY_S)){
                if(caps) debugmsg += "S";
                else debugmsg += "s";
            }
            if(IsKeyPressed(KEY_T)){
                if(caps) debugmsg += "T";
                else debugmsg += "t";
            }
            if(IsKeyPressed(KEY_U)){
                if(caps) debugmsg += "U";
                else debugmsg += "u";
            }
            if(IsKeyPressed(KEY_V)){
                if(caps) debugmsg += "V";
                else debugmsg += "v";
            }
            if(IsKeyPressed(KEY_W)){
                if(caps) debugmsg += "W";
                else debugmsg += "w";
            }
            if(IsKeyPressed(KEY_X)){
                if(caps) debugmsg += "X";
                else debugmsg += "x";
            }
            if(IsKeyPressed(KEY_Y)){
                if(caps) debugmsg += "Y";
                else debugmsg += "y";
            }
            if(IsKeyPressed(KEY_Z)){
                if(caps) debugmsg += "Z";
                else debugmsg += "z";
            }
        // Special Input
            if(IsKeyPressed(KEY_ENTER)){
                debugmsg += '\n';
            }
            if (IsKeyPressed(KEY_BACKSPACE)){
                if (!debugmsg.empty()) debugmsg.erase(debugmsg.size()-1);
            }
// TEXT INPUT END
            DrawText(debugmsg.c_str(), 0, 75, 90, BLACK);
        EndDrawing();
        if (WindowShouldClose()) WindowOpen = false;
    }
    CloseWindow();
    return 0;
}
