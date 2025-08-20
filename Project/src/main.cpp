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
            bool caps;
            if (IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT)) caps = true;
            else caps = false;
// TEXT INPUT
            if( IsKeyPressedRepeat(KEY_A) || IsKeyPressed(KEY_A)){
                if(caps == true) debugmsg += "A";
                else debugmsg += "a";
            }
            if( IsKeyPressedRepeat(KEY_B) || IsKeyPressed(KEY_B)){
                if(caps) debugmsg += "B";
                else debugmsg += "b";
            }
            if( IsKeyPressedRepeat(KEY_C) || IsKeyPressed(KEY_C)){
                if(caps) debugmsg += "C";
                else debugmsg += "c";
            }
            if( IsKeyPressedRepeat(KEY_D) || IsKeyPressed(KEY_D)){
                if(caps) debugmsg += "D";
                else debugmsg += "d";
            }
            if( IsKeyPressedRepeat(KEY_E) || IsKeyPressed(KEY_E)){
                if(caps) debugmsg += "E";
                else debugmsg += "e";
            }
            if( IsKeyPressedRepeat(KEY_F) || IsKeyPressed(KEY_F)){
                if(caps) debugmsg += "F";
                else debugmsg += "f";
            }
            if( IsKeyPressedRepeat(KEY_G) || IsKeyPressed(KEY_G)){
                if(caps) debugmsg += "G";
                else debugmsg += "g";
            }
            if( IsKeyPressedRepeat(KEY_H) || IsKeyPressed(KEY_H)){
                if(caps) debugmsg += "H";
                else debugmsg += "h";
            }
            if( IsKeyPressedRepeat(KEY_I) || IsKeyPressed(KEY_I)){
                if(caps) debugmsg += "I";
                else debugmsg += "i";
            }
            if( IsKeyPressedRepeat(KEY_J) || IsKeyPressed(KEY_J)){
                if(caps) debugmsg += "J";
                else debugmsg += "j";
            }
            if( IsKeyPressedRepeat(KEY_K) || IsKeyPressed(KEY_K)){
                if(caps) debugmsg += "K";
                else debugmsg += "k";
            }
            if( IsKeyPressedRepeat(KEY_L) || IsKeyPressed(KEY_L)){
                if(caps) debugmsg += "L";
                else debugmsg += "l";
            }
            if( IsKeyPressedRepeat(KEY_M) || IsKeyPressed(KEY_M)){
                if(caps) debugmsg += "M";
                else debugmsg += "m";
            }
            if( IsKeyPressedRepeat(KEY_N) || IsKeyPressed(KEY_N)){
                if(caps) debugmsg += "N";
                else debugmsg += "n";
            }
            if( IsKeyPressedRepeat(KEY_O) || IsKeyPressed(KEY_O)){
                if(caps) debugmsg += "O";
                else debugmsg += "o";
            }
            if( IsKeyPressedRepeat(KEY_P) || IsKeyPressed(KEY_P)){
                if(caps) debugmsg += "P";
                else debugmsg += "p";
            }
            if( IsKeyPressedRepeat(KEY_Q) || IsKeyPressed(KEY_Q)){
                if(caps) debugmsg += "Q";
                else debugmsg += "q";
            }
            if( IsKeyPressedRepeat(KEY_R) || IsKeyPressed(KEY_R)){
                if(caps) debugmsg += "R";
                else debugmsg += "r";
            }
            if( IsKeyPressedRepeat(KEY_S) || IsKeyPressed(KEY_S)){
                if(caps) debugmsg += "S";
                else debugmsg += "s";
            }
            if( IsKeyPressedRepeat(KEY_T) || IsKeyPressed(KEY_T)){
                if(caps) debugmsg += "T";
                else debugmsg += "t";
            }
            if( IsKeyPressedRepeat(KEY_U) || IsKeyPressed(KEY_U)){
                if(caps) debugmsg += "U";
                else debugmsg += "u";
            }
            if( IsKeyPressedRepeat(KEY_V) || IsKeyPressed(KEY_V)){
                if(caps) debugmsg += "V";
                else debugmsg += "v";
            }
            if( IsKeyPressedRepeat(KEY_W) || IsKeyPressed(KEY_W)){
                if(caps) debugmsg += "W";
                else debugmsg += "w";
            }
            if( IsKeyPressedRepeat(KEY_X) || IsKeyPressed(KEY_X)){
                if(caps) debugmsg += "X";
                else debugmsg += "x";
            }
            if( IsKeyPressedRepeat(KEY_Y) || IsKeyPressed(KEY_Y)){
                if(caps) debugmsg += "Y";
                else debugmsg += "y";
            }
            if( IsKeyPressedRepeat(KEY_Z) || IsKeyPressed(KEY_Z)){
                if(caps) debugmsg += "Z";
                else debugmsg += "z";
            }
            if( IsKeyPressedRepeat(KEY_ZERO) || IsKeyPressed(KEY_ZERO)){
                if(caps) debugmsg += ")";
                else debugmsg += "0";
            }
            if( IsKeyPressedRepeat(KEY_NINE) || IsKeyPressed(KEY_NINE)){
                if(caps) debugmsg += "(";
                else debugmsg += "9";
            }
            if( IsKeyPressedRepeat(KEY_EIGHT || IsKeyPressed(KEY_EIGHT))){
                if(caps) debugmsg += "*";
                else debugmsg += "8";
            }
            if( IsKeyPressedRepeat(KEY_SEVEN) || IsKeyPressed(KEY_SEVEN)){
                if(caps) debugmsg += "&";
                else debugmsg += "7";
            }
            if( IsKeyPressedRepeat(KEY_SIX) || IsKeyPressed(KEY_SIX)){
                if(caps) debugmsg += "^";
                else debugmsg += "6";
            }
            if( IsKeyPressedRepeat(KEY_FIVE) || IsKeyPressed(KEY_FIVE)){
                if(caps) debugmsg += "%";
                else debugmsg += "5";
            }
            if( IsKeyPressedRepeat(KEY_FOUR) || IsKeyPressed(KEY_FOUR)){
                if(caps) debugmsg += "$";
                else debugmsg += "4";
            }
            if( IsKeyPressedRepeat(KEY_THREE) || IsKeyPressed(KEY_THREE)){
                if(caps) debugmsg += "#";
                else debugmsg += "3";
            }
            if( IsKeyPressedRepeat(KEY_TWO) || IsKeyPressed(KEY_TWO)){
                if(caps) debugmsg += "@";
                else debugmsg += "2";
            }
            if( IsKeyPressedRepeat(KEY_ONE) || IsKeyPressed(KEY_ONE)){
                if(caps) debugmsg += "!";
                else debugmsg += "1";
            }
            if( IsKeyPressedRepeat(KEY_MINUS) || IsKeyPressed(KEY_MINUS)){
                if(caps) debugmsg += "_";
                else debugmsg += "-";
            }
            if( IsKeyPressedRepeat(KEY_EQUAL) || IsKeyPressed(KEY_EQUAL)){
                if(caps) debugmsg += "+";
                else debugmsg += "=";
            }
            if( IsKeyPressedRepeat(KEY_LEFT_BRACKET) || IsKeyPressed(KEY_LEFT_BRACKET)){
                if(caps) debugmsg += "{";
                else debugmsg += "[";
            }
            if( IsKeyPressedRepeat(KEY_RIGHT_BRACKET) || IsKeyPressed(KEY_RIGHT_BRACKET)){
                if(caps) debugmsg += "}";
                else debugmsg += "]";
            }
            if( IsKeyPressedRepeat(KEY_BACKSLASH) || IsKeyPressed(KEY_BACKSLASH)){
                if(caps) debugmsg += "|";
                else debugmsg += "\\";
            }
            if( IsKeyPressedRepeat(KEY_SEMICOLON) || IsKeyPressed(KEY_SEMICOLON)){
                if(caps) debugmsg += ":";
                else debugmsg += ";";
            }
            if( IsKeyPressedRepeat(KEY_APOSTROPHE) || IsKeyPressed(KEY_APOSTROPHE)){
                if(caps) debugmsg += "\"";
                else debugmsg += "'";
            }
            if( IsKeyPressedRepeat(KEY_COMMA) || IsKeyPressed(KEY_COMMA)){
                if(caps) debugmsg += "<";
                else debugmsg += ",";
            }
            if( IsKeyPressedRepeat(KEY_PERIOD) || IsKeyPressed(KEY_PERIOD)){
                if(caps) debugmsg += ">";
                else debugmsg += ".";
            }
            if( IsKeyPressedRepeat(KEY_SLASH) || IsKeyPressed(KEY_SLASH)){
                if(caps) debugmsg += "?";
                else debugmsg += "/";
            }
            if( IsKeyPressedRepeat(KEY_GRAVE) || IsKeyPressed(KEY_GRAVE)){
                if(caps) debugmsg += "~";
                else debugmsg += "`";
            }
        // Special Input
            if( IsKeyPressedRepeat(KEY_ENTER) || IsKeyPressed(KEY_ENTER)){
                debugmsg += '\n';
            }
            if (IsKeyPressedRepeat(KEY_BACKSPACE) || IsKeyPressed(KEY_BACKSPACE)){
                if (!debugmsg.empty()) debugmsg.erase(debugmsg.size()-1);
            }
            if( IsKeyPressedRepeat(KEY_SPACE) || IsKeyPressed(KEY_SPACE)){
                debugmsg += " ";
            }
// TEXT INPUT END
            DrawText(debugmsg.c_str(), 0, 75, 70, BLACK);
        EndDrawing();
        if (WindowShouldClose()) WindowOpen = false;
    }
    CloseWindow();
    return 0;
}
