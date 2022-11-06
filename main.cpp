#include "raylib.h"


int main() {
    const int screenWidth{1920};
    const int screenHeight{1090};
    const int width{50};
    const int height{50};
    int gravity (1);
    int posY{screenHeight-height};
    int velocity{-10};


    InitWindow(screenWidth, screenHeight, "CA1 Raylib Application_D00189801"); //Calls the window/ screen
    InitAudioDevice(); //Calls the Audio you have selected for this piece

    
    //  Load - Elements you wish to load on screen

    // Visuals

// Calls and draws the Bg short for Background;
    Texture2D bg = LoadTexture ("resources/trainstation_Bg.png");
    Rectangle bgRec;
    bgRec.width =  bg.width/1;
    bgRec.height = bg.height;
    bgRec.x = 0;
    bgRec.y = 0; 
    Vector2 bgPos;
    bgPos.x = screenWidth/2 - bgRec.width/2;
    bgPos.y = screenHeight -  bgRec.height;

// Calls and draws the Miles Morales Spiderman Logo;
    Texture2D milesLogo = LoadTexture ("resources/milesLogo.png");
    Rectangle milesLogoRec;
    milesLogoRec.width =  bg.width/2;
    milesLogoRec.height = bg.height;
    milesLogoRec.x = 0;
    milesLogoRec.y = 0; 
    Vector2 milesLogoPos;
    milesLogoPos.x = screenWidth/4 - milesLogoRec.width/4;
    milesLogoPos.y = screenHeight -  milesLogoRec.height;

// Calls and draws The King Pin;
    Texture2D kingPin = LoadTexture ("resources/kingPin.png");
    Rectangle kingPinRec;
    kingPinRec.width =  kingPin.width;
    kingPinRec.height = kingPin.height;
    kingPinRec.x = 0/2;
    kingPinRec.y = 0/2; 
    Vector2 kingPinPos;
    kingPinPos.x = screenWidth - kingPinRec.width;
    kingPinPos.y = screenHeight -  kingPinRec.height;
    

    //Original Scarfy;
    Texture2D scarfy =  LoadTexture("resources/scarfy.png");
    Rectangle scarfyRec;
    scarfyRec.width = scarfy.width/1;
    scarfyRec.height = scarfy.height;
    scarfyRec.x = 0;
    scarfyRec.y = 0; 
    Vector2 scarfyPos;
    scarfyPos.x = screenWidth/2 - scarfyRec.width/1;
    scarfyPos.y = screenHeight - scarfyRec.height;



// Audio

    // Calls and plays Audio 

    Sound sound = LoadSound ("resources/audio/sound.wav");






// Update



    SetTargetFPS(60);
        while(!WindowShouldClose()){
    BeginDrawing();
    DrawTextureRec(scarfy, scarfyRec, scarfyPos, WHITE);
    DrawTextureRec(bg, bgRec, bgPos, WHITE);
    DrawTextureRec(milesLogo, milesLogoRec, milesLogoPos, WHITE);
    DrawTextureRec(kingPin, kingPinRec, kingPinPos, WHITE);
    DrawRectangle(screenWidth/2, posY, width, height, RED);

    // If the SPACE key is pressed Audio / sound will play
    if(IsKeyPressed(KEY_SPACE)) 
    {

        PlaySound(sound);

    }

// If the F key is pressed toggle to Full Screen
    if(IsKeyPressed(KEY_F)) 
    ToggleFullscreen ();


    {
    velocity -= 10;
    }
    posY += velocity;
    velocity += gravity;

    if(IsKeyPressed(KEY_SPACE))
    {
    velocity -= 10;
    }
    posY += velocity;
    velocity += gravity;

    
    ClearBackground(WHITE);
    DrawTextureV(kingPin, (Vector2) {screenWidth/1, screenHeight/1}, WHITE);
    EndDrawing();
    
}

/* constant - fixed not changeable great for Window Height / width 
const int windowHeight{500};
const int windowHeight{400};
*/

// Unload  Visuals - good practice to unload better for memeroy
UnloadTexture(scarfy);
UnloadTexture(bg);
UnloadTexture(milesLogo);
UnloadTexture(kingPin);

// Unload  Sound - good practice to unload better for memeroy
UnloadSound(sound);

// De- initilization - x will close, 
CloseAudioDevice();
CloseWindow();

return 0;
}
