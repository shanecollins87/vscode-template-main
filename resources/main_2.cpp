/*******************************************************************************************
*
*  CA1 - Raylib Application - SoftwareEngineering_D00189801_ShaneCollins
*
********************************************************************************************/




#include "raylib.h" // Calls the raylib Libary or in my case sometimes does it's own thing and calls it
#define NUM_FRAMES  3       // Number of frames (rectangles) for the button sprite texture

//#include <iostream> //std::cout<<"logostate"<<framesCounter<<std::endl;


// Types and Structures Definition
//------------------------------------------------------------------------------------------
typedef enum GameScreen { LOGO = 0, PRESCREEN = 1,SCENEDIVIDER_1 = 2, PLAYGAME = 3, FALLING = 4, GAMEOVER = 5 } GameScreen;



int main() {
    const int screenWidth{1920};
    const int screenHeight{1080};
    const int width{0};
    const int height{0};
    int gravity (1);
    int posY{screenHeight-height};
    int velocity{-10};
  
    //float framewidth = (float)(screenWidth);
    //Font GetFontDefault(void);


    InitWindow(screenWidth, screenHeight, "CA1 Raylib Application_D00189801"); //Calls the window / named screen 
    InitAudioDevice(); // Calls and initialises the Audio I have selected for this piece - 

    GameScreen currentScreen = LOGO;
 
 // TODO: Initialize all required variables and load all required data here!

int framesCounter = 0;          // Useful to count frames
 
 //--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 
 //  Load - Elements you wish to load on screen

 //--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

 // Audio

 //--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    // Loads desired Audio 

    Sound introsound = LoadSound ("resources/audio/introsound.wav"); // (String to Load Sounds/ Wav files required for Game)
    Sound trainsound = LoadSound ("resources/audio/trainsound.wav");
    Sound leapoffaithsound = LoadSound ("resources/audio/leapoffaithsound.wav");
    Sound fxButton = LoadSound ("resources/audio/fxButton.wav");
    Sound deadspiderman = LoadSound ("resources/audio/deadspiderman.wav");
    Music music = LoadMusicStream("resources/audio/introsound.wav"); // Plays intro sound without prompt from user input, i.e. no key pressed to start
    SetSoundVolume(introsound, 0.2f);
    PlayMusicStream(music);
    music.looping = false;
    bool pause = false; // Desired Audio paused
    //float timePlayed = 0.0f;

    //--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    // Visual Elements

    //--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// Calls and draws the Bg short for Background;
    Texture2D bg = LoadTexture ("resources/trainstation_Bg.png"); //(String to Load the likes of .png files required for Game)
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
    milesLogoRec.x = 0;
    milesLogoRec.y = 0; 
    Vector2 milesLogoPos;
    milesLogoPos.x = screenWidth/2 - milesLogoRec.width/2;
    milesLogoPos.y = screenHeight -  milesLogoRec.height;

    // Calls and draws the Spiderman Logo;
    Texture2D spiderLogo2 = LoadTexture ("resources/spiderLogo2.png");
    Rectangle spiderLogo2Rec;
    spiderLogo2Rec.width =  spiderLogo2.width;
    spiderLogo2Rec.height = spiderLogo2.height;
    spiderLogo2Rec.x = 0;
    spiderLogo2Rec.y = 0; 
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
   

    // Calls and draws spidermanGameOver Image;
    Texture2D spidermanGameOver = LoadTexture ("resources/spidermanGameOver.png");
    Rectangle spidermanGameOverRec;
    spidermanGameOverRec.width =  spidermanGameOver.width;
    spidermanGameOverRec.height = spidermanGameOver.height;
    spidermanGameOverRec.x = 0;
    spidermanGameOverRec.y = 0; 
    Vector2 spidermanGameOverPos;
    spidermanGameOverPos.x = screenWidth - spidermanGameOverRec.width;
    spidermanGameOverPos.y = screenHeight -  spidermanGameOverRec.height;
  
  
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// Main Game Loop

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// Update - Insert main variables here

    SetTargetFPS(60); // Set our game to run at 60 frames-per-minute
       
        while(!WindowShouldClose()){ // Informs the program that if there is no intention to close the window it should stay open, i.e not hitting a close button or Esc key etc. whats in the loop will run

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//  Game / Scene Logic Begin at LOGO - move logically in order given end Game Over 

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

switch(currentScreen)
        {
            case LOGO:
            {
                // TODO: Update SCENEDIVIDER screen variables here!

                framesCounter++;    // Count frames

                // Wait for 2 seconds (120 frames) before jumping to PRESCREEN/ splash screen 
                if (framesCounter > 120)
                {
                    currentScreen = PRESCREEN;
                    
                }
                   
            } break;

            case PRESCREEN:
            {
                // TODO: Update TITLE screen variables here!

            // Calls and plays the chosen core Audio - Pheilean - Do You Know;
                    if(IsKeyPressed(KEY_ENTER)) 
               {
                      pause = !pause;

                      PlaySound(introsound);
                      if (pause) PauseMusicStream(music);
                      else PlayMusicStream(music);

               }

                // Press enter to change to PLAYGAME screen
                if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP)) //
                {
                    currentScreen = PLAYGAME;
                }

                   


            } break;

    case SCENEDIVIDER_1:
            {
                // TODO: Update LOGO screen variables here!

                framesCounter++;    // Count frames

                // Wait for 2 seconds (120 frames) before jumping to PRESCREEN 
                if (framesCounter > 120)
                {
                    currentScreen = LOGO;
                    
                }
                   
            } break;



            case PLAYGAME:
            {
                // TODO: Update GAMEPLAY screen variables here!

                // Press enter to change to GAMEOVER screen
                if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
                {
                    currentScreen = FALLING;
                }

                  // Calls and plays the chosen Audio - trainsound

                    if(IsKeyPressed(KEY_SPACE)) 
               {
                      pause = !pause;

                      PlaySound(trainsound);
                      if (pause) PauseMusicStream(music);
                      else PlayMusicStream(music);

               }


            } break;
               case FALLING:
            {
                // TODO: Update GAMEPLAY screen variables here!
             
             
                // Press enter to change to GAMEOVER screen
                if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
                {
                    currentScreen = GAMEOVER;
                }


                  // Calls and plays the chosen Audio - leapoffaith

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
             
                
                    // Calls and draws the Miles Morales Spiderman Logos;
                    DrawTextureRec(spiderLogo2, spiderLogo2Rec, spiderLogo2Pos, WHITE); // Official Logo / Title
                    DrawTextureRec(milesLogo, milesLogoRec, milesLogoPos, WHITE);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

                //  Redundant Code - I developed the code further and made this

                   // DrawText("Spider-Man: Into the Spider-verse", 280, 80, 80, MAROON); // Content TITLE In this case it's Spider-Man: Into the Spider-verse, colour red

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//  raylib [textures] example - sprite button - Example used and sourced from - https://www.raylib.com/examples.html 

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    
    // DrawTextureRec(redButton, redButtonRec, redButtonPos, WHITE);
     DrawTextureRec(redButton, redButtonRec, redButtonPos, WHITE);
     DrawText("Play Game", 815, 957, 50, WHITE); // Content TITLE In this case it's Spider-Man: Into the Spider-verse, colour red

    // Define frame rectangle for drawing
    float frameHeight = (float)redButton.height/NUM_FRAMES;
    Rectangle sourceRec = { 0, 0, (float)redButton.width, frameHeight };

    // Define button bounds on screen
    Rectangle btnBounds = { screenWidth/2.0f - redButton.width/2.0f, screenHeight/2.0f - redButton.height/NUM_FRAMES/2.0f, (float)redButton.width, frameHeight };

    int btnState = 0;               // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
    bool btnAction = false;         // Button action should be activated

    Vector2 mousePoint = { 0.0f, 0.0f };

    //----------------------------------------------------------------------------------
        mousePoint = GetMousePosition();
        btnAction = false;

        // Check button state
        if (CheckCollisionPointRec(mousePoint, btnBounds))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btnState = 2;
            else btnState = 1;

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnAction = true;
        }
        else btnState = 0;

        if (btnAction)
        {
           PlaySound(fxButton);

          //TODO: Any desired action
         }

        // Calculate button frame rectangle to draw depending on button state
        sourceRec.y = btnState*frameHeight;
        //----------------------------------------------------------------------------------

  
   
                //Audio

                    PlayMusicStream(music);

                    // Calls and plays the Miles Falling Audio - Leap of Faith Clip;
                    if(IsKeyPressed(KEY_SPACE)) 
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

                 //Visuals

                     DrawTextureRec(bg, bgRec, bgPos, WHITE);
                    
                
                      
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

    //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

                //  Redundant Code - I developed the code further and made this

                   // DrawTextureRec(milesLogo, milesLogoRec, milesLogoPos, WHITE);
                   // DrawText("Press Enter to Play Game", 200, 220, 20, BLACK); // Informs player/ user to press enter to Start Game
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


    
     } break; 
                case FALLING:
                {
                    // TODO: Draw PRESCREEN screen here - Splash screen 

                     
                     DrawTextureRec(cityScene, citySceneRec, cityScenePos, WHITE);
                     DrawTextureRec(spidermanFall, spidermanFallRec, spidermanFallPos, WHITE);
                    
                   

                       // Calls and plays the Miles Falling Audio - Leap of Faith Clip;
                    if(IsKeyPressed(KEY_ENTER)) 
               {
                      pause = !pause;

                      PlaySound(leapoffaithsound);
                      if (pause) PauseMusicStream(music);
                      else PlayMusicStream(music);
               }      


               
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

                //  Redundant Code - I developed the code further and made this

                   //  DrawText("FALLING", 200, 220, 20, BLACK); // Informs player/ user to press enter to Start Game 
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


    } break;
    case GAMEOVER:
                {

                     DrawRectangle(0, 0, screenWidth, screenHeight, BLACK);
                     framesCounter++;    // Count frames

                // Wait for 1 seconds (60 frames) before jumping to PRESCREEN  - Game is set at 60 FPS
                if (framesCounter >60)
                {
                     // TODO: Draw GAMEOVER screen here - Black screen with KingPin RED Text Play Again
                    DrawRectangle(0, 0, screenWidth, screenHeight, BLACK);
                    DrawTextureRec(spidermanGameOver, spidermanGameOverRec, spidermanGameOverPos, WHITE);
                    DrawText("GAME OVER", 650, 950, 100, WHITE);
                    
                    
                }
                if (framesCounter >120)
                {
                     // TODO: Draw GAMEOVER screen here - Black screen with KingPin RED Text Play Again
                    DrawRectangle(0, 0, screenWidth, screenHeight, BLACK);
                    DrawTextureRec(blankButton, blankButtonRec, blankButtonPos, WHITE);
                    DrawTexture(kingpinGameOver, 0, 0, RED);
                    DrawTextureRec(blankButton, blankButtonRec, blankButtonPos, WHITE);
                    DrawText("GAME OVER", 567, 650, 125, WHITE);
                    DrawText("PLAY AGAIN?", 725, 925, 50, RED);
                    
                }
                    

                    // Audio
                    
                    
                   

                     // Calls and plays the King Pin Audio - deadspiderman Clip;
                    if(IsKeyPressed(KEY_SPACE)) 
               {
                      pause = !pause;

                      PlaySound(deadspiderman);
                      if (pause) PauseMusicStream(music);
                      else PlayMusicStream(music);
               }     
         




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
UnloadTexture(spidermanGameOver);




//StopSoundMulti();       // We must stop the buffer pool before unloading


// Unload  Sound - good practice to unload sound data  -  better for memory.
UnloadSound(introsound);
UnloadSound(trainsound);
UnloadSound(leapoffaithsound);
UnloadSound(deadspiderman);
UnloadSound(fxButton);
UnloadMusicStream(music);


// De- initilization - x will close, 
CloseAudioDevice(); // Closes Audio device
CloseWindow(); // Closes window and OpenGL context

return 0; // We return to Zero


         }
          
