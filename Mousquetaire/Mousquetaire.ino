#include <Gamebuino-Meta.h>
#define GAMEMAKERS 0
#define TITLESCREEN 1
#define SELECTNBPLAYER 2
#define SELECTOPTIONS 3
#define COUNTER3 4
#define COUNTER2 5
#define COUNTER1 6
#define FIGHT 7
#define RESULT 8
#define RUN 9
#define WINNER 10

#define CONTROLSP1 96
#define CONTROLSP2 97
#define CREDITS 98
#define MENU 99

#define SCREENHEIGHT 64
#define SCREENWIDTH 80



//###########################
//##### INFO Global #########
//###########################
typedef struct{
  int gameStatus; 
  int globalTimer;
  int nbPlayer;
  int difficulty;
  int stage;
  int moveBackgroundSpeed;
  int typeGame;
  int pause;
  int menuOption;
}GameInfo;
GameInfo game;

//###############################
//##### INFO Background #########
//###############################
typedef struct{
  int x; 
  int y;
}BkgInfo;
BkgInfo background1a;
BkgInfo background1b;
BkgInfo background2a;
BkgInfo background2b;
BkgInfo background2c;
BkgInfo background2d;
BkgInfo background2e;
BkgInfo background2f1;
BkgInfo background2f2;
BkgInfo background3a;
BkgInfo background3b;

//###########################
//##### INFO Player #########
//###########################
typedef struct{
  int x; 
  int y;
  int type;
  int action;
  int anim;
} PlayerInfo;
PlayerInfo player1;
PlayerInfo player2;

typedef struct {
  bool btnUP_pressed;
  bool btnDOWN_pressed;
  bool btnLEFT_pressed;
  bool btnRIGHT_pressed;
  bool btnA_pressed;
  bool btnB_pressed;
  int btnUP_repeat;
  int btnDOWN_repeat;
  int btnLEFT_repeat;
  int btnRIGHT_repeat;
  int btnA_repeat;
  int btnB_repeat;
}VirtualPad;
VirtualPad padPlayer2;

typedef struct {
  int selectedAction;
  int currentStrategy;
}iaVar;
iaVar iaData;


typedef struct {
  int8_t weapon;
  int8_t bonus;
  int8_t playerDamage;
  int8_t music;
}SoundInfo;
SoundInfo sounds;


int strategies[5][10];



//###########################
//##### Game Setup ##########
//###########################
void setup(){
  gb.begin();
  game_init();
  game_initBackground();
  game_initPlayers();
  ennemy_initIA();
  gb.pickRandomSeed();
  loop();
}


//###########################
//##### Game Loop ###########
//###########################
void loop(){
  while(1){
    if(gb.update()){
      game_manageGlobalCounter();
      
      switch ( game.gameStatus )
      {
         //####################################
         case GAMEMAKERS:
            outputScreen_gamemakers();
            button_check(GAMEMAKERS);
            break;

         //#################################### 
         case TITLESCREEN:
            outputScreen_clear();
            outputScreen_title();
            button_check(TITLESCREEN);
            break;

         //####################################  
         case SELECTNBPLAYER:
            outputScreen_clear();
            outputScreen_selectNbPlayer();
            button_check(SELECTNBPLAYER);
            break;

         //####################################  
         case SELECTOPTIONS:
            outputScreen_clear();
            outputScreen_selectOptions();
            button_check(SELECTOPTIONS);
            break;

         //####################################  
         case COUNTER3:
            outputScreen_clear();
            button_check(COUNTER3);
            if(game.typeGame<2){
              outputScreen_training();
            }else{
              outputScreen_game();
            }
            outputScreen_counter("3");
            break;

         //####################################  
         case COUNTER2:
            outputScreen_clear();
            button_check(COUNTER2);
            if(game.typeGame<2){
              outputScreen_training();
            }else{
              outputScreen_game();
            }
            outputScreen_counter("2");
            break;

         //####################################  
         case COUNTER1:
            outputScreen_clear();
            button_check(COUNTER1);
            ennemy_ia();
            if(game.typeGame<2){
              outputScreen_training();
            }else{
              outputScreen_game();
            }
            outputScreen_counter("1");
            break;

         //####################################  
         case FIGHT:
            outputScreen_clear();
            ennemy_ia();
            button_check(FIGHT);
            if(game.typeGame<2){
              outputScreen_training();
            }else{
              outputScreen_game();
            }
            break;

         //####################################  
         case RESULT:
            outputScreen_clear();
            if(game.typeGame<2){
              outputScreen_training();
            }else{
              outputScreen_game();
            }
            break;
            
         //####################################  
         case RUN:
            outputScreen_clear();
            if(game.typeGame<2){
              outputScreen_runTraining();
            }else{
              outputScreen_run();
            }
            break;

         //####################################  
         case WINNER:
            outputScreen_clear();
            outputScreen_winner();
            button_check(WINNER);
            break;

         //#################################### 
         case CONTROLSP1:
            outputScreen_clear();
            outputScreen_controlP1();
            button_check(CONTROLSP1);
            break;

         //#################################### 
         case CONTROLSP2:
            outputScreen_clear();
            outputScreen_controlP2();
            button_check(CONTROLSP2);
            break;

         //#################################### 
         case CREDITS:
            outputScreen_clear();
            outputScreen_credits();
            button_check(CREDITS);
            break;
                        
         //####################################  
         case MENU:
            outputScreen_clear();
            outputScreen_menu();
            button_check(MENU);
            break;

         //####################################                     
         default:
            game.gameStatus = GAMEMAKERS;
            break;
      }
    }  
  }
}


