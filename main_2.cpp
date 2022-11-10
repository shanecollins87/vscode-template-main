#include "raylib.h" // Calls the raylib Libary or in my case sometimes does it's own thing and calls it
//#include <iostream>
// Types and Structures Definition
//------------------------------------------------------------------------------------------
typedef enum GameScreen { LOGO = 0, PRESCREEN = 1, PLAYGAME = 2, FALLING = 3, GAMEOVER = 4 } GameScreen;




int main() {
    const int screenWidth{1920};
    const int screenHeight{1090};
    const int width{0};
    const int height{0};
    int gravity (1);
    int posX{screenWidth-width};
    int posY{screenHeight-height};
    int velocity{-10};
    float framewidth = (float)(screenWidth);


    InitWindow(screenWidth, screenHeight, "CA1 Raylib Application_D00189801"); //Calls the window / named screen 
    InitAudioDevice(); // Calls the Audio you have selected for this piece - 

    GameScreen currentScreen = LOGO;
 
 // TODO: Initialize all required variables and load all required data here!

int framesCounter = 0;          // Useful to count frames
 
 
 
 //  Load - Elements you wish to load on screen

 // Audio

    // Loads desired Audio 

    Sound introsound = LoadSound ("resources/audio/introsound.wav"); // (String to Load Sounds/ Wav files required for Game)
    Sound trainsound = LoadSound ("resources/audio/trainsound.wav");
    Sound leapoffaithsound = LoadSound ("resources/audio/leapoffaithsound.wav");

    Music music = LoadMusicStream("resources/audio/introsound.wav"); // Plays intro sound without prompt from user input, i.e. no key pressed to start
    SetSoundVolume(introsound, 0.2f);
    PlayMusicStream(music);
    music.looping = false;
    bool pause = false; // Desired Audio paused

    
    //  Load - Elements you wish to load on screen

    // Visual Elements

// Calls and draws the Bg short for Background;
    Texture2D bg = LoadTexture ("resources/trainstation_Bg.png"); //(String to Load Sounds/ Wav files required for Game)
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
    milesLogoRec.width =  bg.width;
    milesLogoRec.height = bg.height;
    milesLogoRec.x = 0/4;
    milesLogoRec.y = 0/4; 
    Vector2 milesLogoPos;
    milesLogoPos.x = screenWidth/2 - milesLogoRec.width/2;
    milesLogoPos.y = screenHeight -  milesLogoRec.height;

// Calls and draws The King Pin;
    Texture2D kingPin = LoadTexture ("resources/kingPin.png");
    Rectangle kingPinRec;
    kingPinRec.width =  kingPin.width;
    kingPinRec.height = kingPin.height;
    kingPinRec.x = 0/4;
    kingPinRec.y = 0/4; 
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
  


// Main Game Loop

// Update - Insert main variables here

    SetTargetFPS(60); // Set our game to run at 60 frames-per-minute
       
        while(!WindowShouldClose()){ // Informs the program that if there is no intention to close the window it should stay open, i.e not hitting a close button or Esc key etc. whats in the loop will run

//  Game / Scene Logic Begin at LOGO - move logically in order given end Game Over 

switch(currentScreen)
        {
            case LOGO:
            {
                // TODO: Update LOGO screen variables here!

                framesCounter++;    // Count frames
//std::cout<<"logostate"<<framesCounter<<std::endl;
                // Wait for 2 seconds (120 frames) before jumping to PRESCREEN 
                if (framesCounter > 20)
                {
                    currentScreen = PRESCREEN;
                    
                }
            } break;

            case PRESCREEN:
            {
                // TODO: Update TITLE screen variables here!
//std::cout<<"CurrentScreenstate"<<std::endl;
                // Press enter to change to PLAYGAME screen
                if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
                {
                    currentScreen = PLAYGAME;
                }
            } break;
            case PLAYGAME:
            {
                // TODO: Update GAMEPLAY screen variables here!
//std::cout<<"PLAYGAME"<<std::endl;
                // Press enter to change to GAMEOVER screen
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
    BeginDrawing();
 ClearBackground(WHITE);
 //DrawRectangle(50, 50, 50, 50, BLACK); // Draws a Black BG

 switch(currentScreen)
            {
                case PRESCREEN:
                {
                    // TODO: Draw SPIDERMAN LOGO on a black bg here.

                    DrawRectangle(0, 0, screenWidth, screenHeight, BLACK); // Draws a Black BG
                    DrawText("Spider-Man: Into the Spider-verse", 280, 80, 80, MAROON); // Content TITLE In this case it's Spider-Man: Into the Spider-verse, colour red
                    DrawTextureRec(redButton, redButtonRec, redButtonPos, WHITE);
                    DrawText("Play Game", 815, 950, 50, WHITE); // Content TITLE In this case it's Spider-Man: Into the Spider-verse, colour red
                    
                    // Calls and draws the Miles Morales Spiderman Logo;
                    DrawTextureRec(milesLogo, milesLogoRec, milesLogoPos, WHITE);

                    // Calls and plays the Miles Falling Audio - Leap of Faith Clip;
                    if(IsKeyPressed(KEY_N)) 
               {
                      pause = !pause;

                      PlaySound(introsound);
                      if (pause) PauseMusicStream(music);
                      else PlayMusicStream(music);

               }
                   
                 
                  

                
                } break; 
                case PLAYGAME:
                {
                    // TODO: Draw PRESCREEN screen here - Splash screen 

                     
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
        PlaySound(leapoffaithsound);
        if (pause) PauseMusicStream(music);
        else PlayMusicStream(music);

    }
     } break; 
                case FALLING:
                {
                    // TODO: Draw PRESCREEN screen here - Splash screen 

                     
                     DrawTextureRec(cityScene, citySceneRec, cityScenePos, WHITE);
                     DrawTextureRec(spidermanFall, spidermanFallRec, spidermanFallPos, WHITE);
                     DrawText("FALLING", 200, 220, 20, BLACK); // Informs player/ user to press enter to Start Game 
                   

                       // Calls and plays the Miles Falling Audio - Leap of Faith Clip;
                    if(IsKeyPressed(KEY_ENTER)) 
               {
                      pause = !pause;

                      PlaySound(leapoffaithsound);
                      if (pause) PauseMusicStream(music);
                      else PlayMusicStream(music);
               }      


    } break;
    case GAMEOVER:
                {
                    // TODO: Draw GAMEOVER screen here - Black screen with KingPin RED Text Play Again
                    DrawRectangle(0, 0, screenWidth, screenHeight, BLACK);
                    DrawTextureRec(blankButton, blankButtonRec, blankButtonPos, WHITE);
                    DrawTexture(kingpinGameOver, 0, 0, RED);
                   // DrawTextureRec(kingpinGameOver, kingpinGameOverRec, kingpinGameOverPos, RED);
                    DrawTextureRec(blankButton, blankButtonRec, blankButtonPos, WHITE);
                    DrawText("GAME OVER", 567, 650, 125, WHITE);
                    DrawText("PLAY AGAIN?", 725, 937, 50, RED);

                } break;
                default: break;
            }

;

   



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
UnloadTexture(kingpinGameOver);
UnloadTexture(redButton);
UnloadTexture(blankButton);
UnloadTexture(cityScene);
UnloadTexture(spidermanFall);




//StopSoundMulti();       // We must stop the buffer pool before unloading


// Unload  Sound - good practice to unload sound data  -  better for memory
UnloadSound(introsound);
UnloadSound(trainsound);
UnloadSound(leapoffaithsound);


// De- initilization - x will close, 
CloseAudioDevice(); // Closes Audio device
CloseWindow(); // Closes window and OpenGL context

return 0; // We return to Zero


         }
          
