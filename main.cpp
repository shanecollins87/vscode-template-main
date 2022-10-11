#include "raylib.h"

int main() {
    const int windowWidth{500};
    const int windowHeight{500};
    const int width{50};
    const int height{50};
    int gravity (1);


    int posY{windowHeight-height};
    int velocity{-10};


    InitWindow(windowWidth, windowHeight, "Shane's Window");
    Texture2D scarfy =  LoadTexture("resources/scarfy.png");
    Rectangle scarfyRec;
    scarfyRec.width = scarfy.width/6;
    scarfyRec.height = scarfy.height;
   // scarfyRec.x = 0;
    scarfyRec.y = 0; 
    Vector2 scarfyPos;
    scarfyPos.x = windowWidth/2 - scarfyRec.width/2;
    scarfyPos.y = windowHeight - scarfyRec.height;


    SetTargetFPS(60);
        while(!WindowShouldClose()){
    BeginDrawing();
    DrawTextureRec(scarfy, scarfyRec, scarfyPos, WHITE);
    DrawRectangle(windowWidth/2, posY, width, height, GREEN);

    if(IsKeyPressed(KEY_SPACE))
    {
    velocity -= 10;
    }
    posY += velocity;
    velocity += gravity;

    
    ClearBackground(WHITE);
    EndDrawing();
    
}

/* constant - fixed not changeable great for Window Height / width 
const int windowHeight{500};
const int windowHeight{400};
*/

// good practice to unload better for memeory
UnloadTexture(scarfy);

// x will close, 
CloseWindow();
}
