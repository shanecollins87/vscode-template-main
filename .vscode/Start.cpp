/*******************************************************************************************
*
*  
*
********************************************************************************************/

#include "raylib.h"
//#include "setup.h"


#define NUM_FRAMES 3       // Number of frames (rectangles) for the button sprite texture
//#include "stdlib.h"

//#include <iostream> //std::cout<<"logostate"<<framesCounter<<std::endl;


// Types and Structures Definition
//------------------------------------------------------------------------------------------
typedef enum GameScreen { LOGO = 0, PRESCREEN = 1, PLAYGAME = 2, FALLING = 3, GAMEOVER = 4 } GameScreen;

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------

    // Initialization
    //--------------------------------------------------------------------------------------
   int main() {
    const int screenWidth{1920};
    const int screenHeight{1080};
   // const int width{0};
    const int height{0};
    int gravity (1);
    int posY{screenHeight-height};
    int velocity{-10};
    //float framewidth = (float)(screenWidth);
    //Font GetFontDefault(void);

    GameScreen currentScreen = LOGO;


//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 
 //  Load - Elements you wish to load on screen

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

 // Audio

    // Loads desired Audio 

    Sound introsound = LoadSound ("resources/audio/introsound.wav"); // (String to Load Sounds/ Wav files required for Game)
    Sound trainsound = LoadSound ("resources/audio/trainsound.wav");
    Sound leapoffaithsound = LoadSound ("resources/audio/leapoffaithsound.wav");
    Sound fxButton = LoadSound ("resources/audio/fxButton.wav");
    Music music = LoadMusicStream("resources/audio/introsound.wav"); // Plays intro sound without prompt from user input, i.e. no key pressed to start
    SetSoundVolume(introsound, 0.2f);
    PlayMusicStream(music);
    music.looping = true;
    bool pause = false; // Desired Audio paused
    //float timePlayed = 0.0f;

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------   

    // Visual Elements  -  Load - Elements you wish to load on screen



// Calls and draws the Miles Morales Spiderman Logo;


// Calls and draws the Bg short for Background;
    Texture2D bg = LoadTexture ("resources/train_bg.png"); //(String to Load the likes of .png files required for Game)
    Rectangle bgRec;
    bgRec.width =  bg.width;
    bgRec.height = bg.height;
    bgRec.x = 0;
    bgRec.y = 0; 
    Vector2 bgPos;
    bgPos.x = screenWidth - bgRec.width;
    bgPos.y = screenHeight - bgRec.height;

// Calls and draws the Miles Morales Spiderman Logo;

    Texture2D milesLogo = LoadTexture ("resources/milesLogo.png");
    Rectangle milesLogoRec;
    milesLogoRec.width =  milesLogo.width;
    milesLogoRec.height = milesLogo.height;
    milesLogoRec.x = 0/4;
    milesLogoRec.y = 0/4; 
    Vector2 milesLogoPos;
    milesLogoPos.x = screenWidth/2 - milesLogoRec.width/2;
    milesLogoPos.y = screenHeight -  milesLogoRec.height;

    // Calls and draws the Spiderman Logo;
    Texture2D spiderLogo2 = LoadTexture ("resources/spiderLogo2.png");
    Rectangle spiderLogo2Rec;
    spiderLogo2Rec.width =  spiderLogo2.width;
    spiderLogo2Rec.height = spiderLogo2.height;
    spiderLogo2Rec.x = 0/4;
    spiderLogo2Rec.y = 0/4; 
    Vector2 spiderLogo2Pos;
    spiderLogo2Pos.x = screenWidth/2 - spiderLogo2Rec.width/2;
    spiderLogo2Pos.y = screenHeight -  spiderLogo2Rec.height;

// Calls and draws The King Pin;
    Texture2D kingPin = LoadTexture ("resources/kingPin.png");
    Rectangle kingPinRec;
    kingPinRec.width =  kingPin.width;
    kingPinRec.height = kingPin.height;
    kingPinRec.x = 0;
    kingPinRec.y = 0; 
    Vector2 kingPinPos;
    kingPinPos.x = screenWidth - kingPinRec.width;
    kingPinPos.y = screenHeight -  kingPinRec.height;
    
// Calls, Loads and draws kingpinGameOver Image;
    Texture2D kingpinGameOver = LoadTexture ("resources/kingpinGameOver.png");
    Rectangle kingpinGameOverRec;
    kingpinGameOverRec.width =  kingPin.width/1;
    kingpinGameOverRec.height = kingPin.height;
    kingpinGameOverRec.x = 0;
    kingpinGameOverRec.y = 0; 
    Vector2 kingpinGameOverPos;
    kingpinGameOverPos.x = screenWidth - kingpinGameOverRec.width;
    kingpinGameOverPos.y = screenHeight -  kingpinGameOverRec.height;

    // Calls and draws blankButton Image;
    Texture2D blankButton = LoadTexture ("resources/blankButton.png");
    Rectangle blankButtonRec;
    blankButtonRec.width =  blankButton.width;
    blankButtonRec.height = blankButton.height;
    blankButtonRec.x = 0;
    blankButtonRec.y = 0; 
    Vector2 blankButtonPos;
    blankButtonPos.x = screenWidth - blankButtonRec.width;
    blankButtonPos.y = screenHeight -  blankButtonRec.height;

     // Calls and draws redButton Image;
    Texture2D redButton = LoadTexture ("resources/redButton.png");
    Rectangle redButtonRec;
    redButtonRec.width =  redButton.width;
    redButtonRec.height = redButton.height;
    redButtonRec.x = 0;
    redButtonRec.y = 0; 
    Vector2 redButtonPos;
    redButtonPos.x = screenWidth - redButtonRec.width;
    redButtonPos.y = screenHeight -  redButtonRec.height;
  
  

 // Calls and draws cityScene Image;
    Texture2D cityScene = LoadTexture ("resources/cityScene.png");
    Rectangle citySceneRec;
    citySceneRec.width =  cityScene.width;
    citySceneRec.height = cityScene.height;
    citySceneRec.x = 0/2;
    citySceneRec.y = 0; 
    Vector2 cityScenePos;
    cityScenePos.x = screenWidth - citySceneRec.width;
    cityScenePos.x = screenWidth - citySceneRec.width;
    cityScenePos.x = screenWidth - citySceneRec.width;
    cityScenePos.y = screenHeight -  citySceneRec.height;
  
   // Calls and draws spidermanFall Image;
    Texture2D spidermanFall = LoadTexture ("resources/spidermanFall.png");
    Rectangle spidermanFallRec;
    spidermanFallRec.width =  spidermanFall.width;
    spidermanFallRec.height = spidermanFall.height;
    spidermanFallRec.x = 0;
    spidermanFallRec.y = 0; 
    Vector2 spidermanFallPos;
    spidermanFallPos.x = screenWidth - spidermanFallRec.width;
    spidermanFallPos.y = screenHeight -  spidermanFallRec.height;
   // spidermanFall .x = screenWidth - spidermanFallRec.width;
   // spidermanFall .y = screenHeight - spidermanFallRec.height;
  


//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


 
 // TODO: Initialize all required variables and load all required data here!

int framesCounter = 0;          // Useful to count frames

    InitWindow(screenWidth, screenHeight, "CA1 Raylib Application_D00189801"); //Calls the window / named screen 
    InitAudioDevice(); // Calls the Audio you have selected for this piece - 

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    
    while(!WindowShouldClose()){ // Informs the program that if there is no intention to close the window it should stay open, i.e not hitting a close button or Esc key etc. whats in the loop will run
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 //  Game / Scene Logic Begin at LOGO - move logically in order given end Game Over 
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

currentScreen = LOGO;


switch(currentScreen)
        {
            case LOGO:
            {
                // TODO: Update LOGO screen variables here!

                framesCounter++;    // Count frames

                // Wait for 2 seconds (120 frames) before jumping to PRESCREEN 
                if (framesCounter > 20)
                {
                    currentScreen = PRESCREEN;
                    
                }
                   
            } break;

            case PRESCREEN:
            {
                // TODO: Update TITLE screen variables here!

                // Press enter to change to PLAYGAME screen
                if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP)) //
                {
                    currentScreen = PLAYGAME;
                }

    // Calls and plays the fxButton Audio - short cricket type sound, lets user know itsbeen clicked;
                    if(IsKeyPressed(KEY_ENTER)) 
               {
                      pause = !pause;

                      PlaySound(fxButton);
                      if (pause) PauseMusicStream(music);
                      else PlayMusicStream(music);

               }
               
       

            } break;
            case PLAYGAME:
            {
                // TODO: Update GAMEPLAY screen variables here!

                // Press enter to change to FALLING screen
                if (framesCounter > 40)

                if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
                {

                    currentScreen = FALLING;
                }
            } break;
            

               case FALLING:
            {
                // TODO: Update GAMEPLAY screen variables here!
                //std::cout<<"PLAYGAME"<<std::endl;
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

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 
 //  Load - Elements you wish to load on screen

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------   



    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(WHITE);

                // PRESCREEN ELEMENTS
                    // VISUAL
                    DrawRectangle(0, 0, screenWidth, screenHeight, BLACK); // Draws a Black 
                    // Calls and draws the Miles Morales Spiderman Logos;
                    DrawTextureRec(spiderLogo2, spiderLogo2Rec, spiderLogo2Pos, WHITE); // Official Logo / Title
                    DrawTextureRec(milesLogo, milesLogoRec, milesLogoPos, WHITE);
                    DrawTextureRec(redButton, redButtonRec, redButtonPos, WHITE);
                    DrawText("Play Game", 815, 950, 50, WHITE); // Content TITLE In this case it's Spider-Man: Into the Spider-verse, colour red5
                    // DrawText("Spider-Man: Into the Spider-verse", 280, 80, 80, WHITE); // Content TITLE In this case it's Spider-Man: Into the Spider-verse, colour White - Decided to use offical Logo

                    // AUDIO

                // Calls and plays the Miles Falling Audio - Leap of Faith Clip;
                    if(IsKeyPressed(KEY_SPACE)) 
               {
                      pause = !pause;

                      PlaySound(introsound);
                      if (pause) PauseMusicStream(music);
                      else PlayMusicStream(music);

               }

                     // GAME OVER ELEMENTS
// VISUAL
                  

                    // AUDIO




      
        EndDrawing();
        //----------------------------------------------------------------------------------
    

 



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

    
    
    DrawTextureV(kingPin, (Vector2) {screenWidth/1, screenHeight/1}, WHITE);

    //system("pause"); 
    EndDrawing();
 //----------------------------------------------------------------------------------
  
}



//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

 // Unload  Visuals - good practice to unload visual data - better for memory
 
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//UnloadTexture(bg);
UnloadTexture(milesLogo);
UnloadTexture(kingPin);
UnloadTexture(kingpinGameOver);
UnloadTexture(redButton);
UnloadTexture(blankButton);
UnloadTexture(cityScene);
UnloadTexture(spidermanFall);
UnloadTexture(spiderLogo2);
 


//--------------------------------------------------------------------------------------

//StopSoundMulti();       // We must stop the buffer pool before unloading

//--------------------------------------------------------------------------------------

// Unload  Sound - good practice to unload sound data  -  better for memory
UnloadSound(introsound);
UnloadSound(trainsound);
UnloadSound(leapoffaithsound);
UnloadSound(fxButton);
UnloadMusicStream(music);
 

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
 }
    return 0;
   }
            
    
