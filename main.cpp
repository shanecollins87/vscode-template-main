#include "raylib.h"

int main() {
    const int windowWidth{500};
    const int windowHeight{500};
    InitWindow(windowWidth, windowHeight, "Shane's Window");
    SetTargetFPS(60);
        while(!WindowShouldClose()){
    BeginDrawing();
    ClearBackground(WHITE);
    EndDrawing();
}
CloseWindow();

}
