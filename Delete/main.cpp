#include "raylib.h" // Calls the raylib Libary or in my case sometimes does it's own thing and calls it

// Types and Structures Definition
//------------------------------------------------------------------------------------------
typedef enum GameScreen { LOGO = 0, PRESCREEN, PLAYGAME, GAMEOVER } GameScreen;




int main() {
    const int screenWidth{1920};
    const int screenHeight{1090};
    //const int width{50};
    const int height{50};
    int gravity (1);
    int posY{screenHeight-height};
    int velocity{-10};


    InitWindow(screenWidth, screenHeight, "CA1 Raylib Application_D00189801"); //Calls the window / named screen 
    InitAudioDevice(); // Calls the Audio you have selected for this piece - 

GameScreen currentScreen = LOGO;
 
 // TODO: Initialize all required variables and load all required data here!

int framesCounter = 0;          // Useful to count frames
 
 
 
 //  Load - Elements you wish to load on screen

 // Audio

    // Loads desired Audio 

    Sound introsound = LoadSound ("resources/audio/introsound.wav");
    Sound trainsound = LoadSound ("resources/audio/trainsound.wav");
    Sound leapoffaithsound = LoadSound ("resources/audio/leappffaithsound.wav");

    Music music = LoadMusicStream("resources/audio/introsound.wav"); // Plays intro sound without prompt from user input, i.e. no key pressed to start
    SetSoundVolume(introsound, 0.2f);
    PlayMusicStream(music);
    music.looping = false;
    bool pause = false; // Desired Audio paused

    
    //  Load - Elements you wish to load on screen

    // Visual Elements

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
    




// Main Game Loop

// Update - Insert main variables here

switch(currentScreen)
        {
            case LOGO:
            {
                // TODO: Update LOGO screen variables here!

                framesCounter++;    // Count frames

                // Wait for 2 seconds (120 frames) before jumping to PRESCREEN 
                if (framesCounter > 120)
                {
                    currentScreen = PRESCREEN;
                }
            } break;
            case PRESCREEN:
            {
                // TODO: Update TITLE screen variables here!

                // Press enter to change to PLAYGAME screen
                if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
                {
                    currentScreen = PLAYGAME;
                }
            } break;
            case PLAYGAME:
            {
                // TODO: Update GAMEPLAY screen variables here!

                // Press enter to change to GAMEOVER screen
                if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
                {
                    currentScreen = GAMEOVER;
                }
            } break;
            case GAMEOVER:
            {
                // TODO: Update GAMEOVER screen variables here!

                // Press enter to return to PRESCREEN screen
                if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
                {
                    currentScreen = PRESCREEN;
                }
            } break;
            default: break;
        }
//----------------------------------------------------------------------------------

    SetTargetFPS(60); // Set our game to run at 60 frames-per-minute
       
        while(!WindowShouldClose()){ // Informs the program that if there is no intention to close the window it should stay open, i.e not hitting a close button or Esc key etc. whats in the loop will run

    BeginDrawing();
    ClearBackground(WHITE);

 switch(currentScreen)
            {
                case PRESCREEN:
                {
                    // TODO: Draw SPIDERMAN LOGO on a black bg here.

                    DrawRectangle(0, 0, screenWidth, screenHeight, BLACK); // Draws a Black BG
                    DrawText("Spider-Man: Into the Spider-verse", 20, 20, 40, RED); // Content TITLE In this case it's Spider-Man: Into the Spider-verse, colour red
                    // Calls and draws the Miles Morales Spiderman Logo;
                     //Texture2D milesLogo = LoadTexture ("resources/milesLogo.png");
                     Rectangle milesLogoRec;
                     milesLogoRec.width =  bg.width/2;
                     milesLogoRec.height = bg.height;
                     milesLogoRec.x = 0;
                     milesLogoRec.y = 0; 
                   //  Vector2 milesLogoPos;
                     milesLogoPos.x = screenWidth/4 - milesLogoRec.width/4;
                     milesLogoPos.y = screenHeight -  milesLogoRec.height;

                } break;
                case PLAYGAME:
                {
                    // TODO: Draw PRESCREEN screen here - Splash screen 

                     //DrawTextureRec(scarfy, scarfyRec, scarfyPos, WHITE);
                     //DrawRectangle(screenWidth/2, posY, width, height, RED);
                     DrawTextureRec(bg, bgRec, bgPos, WHITE);
                     DrawTextureRec(milesLogo, milesLogoRec, milesLogoPos, WHITE);
                     DrawText("Press Enter to Play Game", 200, 220, 20, BLACK); // Informs player/ user to press enter to Start Game 

     //Audio

     // If the SPACE key is pressed desired Audio / .wav file will play Pause/Resume .wav file playing
     if(IsKeyPressed(KEY_SPACE)) 
     {
         pause = !pause;

        PlaySound(trainsound);
        if (pause) PauseMusicStream(music);
        else PlayMusicStream(music);

     }
     // If the Enter key is pressed stop one .wav and play desired .wav file 
    if(IsKeyPressed(KEY_ENTER)) 
    {
        StopSound(introsound);
        PlaySound(leapoffaithsound);

    }
                   

    } break;
    case GAMEOVER:
                {
                    // TODO: Draw GAMEOVER screen here - Black screen with KingPin RED Text Play Again
                    DrawRectangle(0, 0, screenWidth, screenHeight, BLACK);
                    DrawTextureRec(kingPin, kingPinRec, kingPinPos, WHITE);
                    DrawText("PLAY AGAIN?", 120, 220, 20, RED);

                } break;
                default: break;
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

    
    //ClearBackground(RAYWHITE);
    DrawTextureV(kingPin, (Vector2) {screenWidth/1, screenHeight/1}, WHITE);
    EndDrawing();
    
}

/* constant - fixed not changeable great for Window Height / width 
const int windowHeight{500};
const int windowHeight{400};
*/

// Unload  Visuals - good practice to unload visual data - better for memory

UnloadTexture(bg);
UnloadTexture(milesLogo);
UnloadTexture(kingPin);

StopSoundMulti();       // We must stop the buffer pool before unloading


// Unload  Sound - good practice to unload sound data  -  better for memory
UnloadSound(introsound);
UnloadSound(trainsound);
UnloadSound(leapoffaithsound);


// De- initilization - x will close, 
CloseAudioDevice(); // Closes Audio device
CloseWindow(); // Closes window and OpenGL context

return 0; // We return to Zero
}
