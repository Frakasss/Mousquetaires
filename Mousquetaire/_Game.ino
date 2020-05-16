void game_init(){
  game.gameStatus = GAMEMAKERS;
  game.globalTimer = 0;
  game.nbPlayer = 1;
  game.difficulty = 1;
  game.stage =4 ;
  game.moveBackgroundSpeed = 2;
  game.typeGame=1;
  game.pause=0;
  game.menuOption=0;
}

void game_initBackground(){
  background1a.x = 0;
  background1a.y = 19;
  background1b.x = background1a.x + 200;
  background1b.y = 19;

  background2a.x = -160;
  background2a.y = 0;
  background2b.x = -80;
  background2b.y = 0;
  background2c.x = 0;
  background2c.y = 0;
  background2d.x = 80;
  background2d.y = 0;
  background2e.x = 160;
  background2e.y = 0;
  
  background2f1.x = 0;
  background2f1.y = 43;
  background2f2.x = 80;
  background2f2.y = 43;

  background3a.x = 0;
  background3a.y = 57;
  background3b.x = background3a.x + 80;
  background3b.y = 57;
}

void game_initPlayers(){
  player1.x = 16; 
  player1.y = 34;
  player1.type = 0;
  player1.action = 0;
  player1.anim = 0;

  player2.x = 38; 
  player2.y = 34;
  player2.type = 0;
  player2.action = 0;
  player2.anim = 3;
}

void game_manageGlobalCounter(){
  switch ( game.gameStatus ){
     //#################################### 
     case GAMEMAKERS:
        if(game.globalTimer<30){
          game.globalTimer = game.globalTimer +1;
        }else{
          game.globalTimer = 0;
          game.gameStatus = TITLESCREEN;
        }
        break;

     //####################################  
     case TITLESCREEN:
        if(game.globalTimer<30){
          game.globalTimer = game.globalTimer +1;
        }else{
          game.globalTimer = 0;
          game.gameStatus = SELECTNBPLAYER;
        }
        break;

     //####################################  
     case CONTROLSP1:
        break;

     //####################################  
     case CONTROLSP2:
        break;
        
     //####################################  
     case CREDITS:
        break;
        
     //####################################   
     case SELECTNBPLAYER:
        break;
        
     //####################################  
     case SELECTOPTIONS:
        break;

     //####################################  
     case COUNTER3:
        player1.anim = player1.anim+1;
        if(player1.anim>=10){player1.anim = 0;}
        player2.anim = player2.anim+1;
        if(player2.anim>=10){player2.anim = 0;}
        
        if(game.globalTimer<10-game.difficulty){
          game.globalTimer = game.globalTimer +1;
        }else{
          game.globalTimer = 0;
          game.gameStatus = COUNTER2;
        }
        break;

     //####################################  

     case COUNTER2:
        player1.anim = player1.anim+1;
        if(player1.anim>=10){player1.anim = 0;}
        player2.anim = player2.anim+1;
        if(player2.anim>=10){player2.anim = 0;}
        
        if(game.globalTimer<10-game.difficulty){
          game.globalTimer = game.globalTimer +1;
        }else{
          game.globalTimer = 0;
          game.gameStatus = COUNTER1;
          player1.anim = 0;
          player2.anim = 0;
        }
        break;

     //####################################  
     case COUNTER1:
        if(game.globalTimer<10-game.difficulty){
          game.globalTimer = game.globalTimer +1;
        }else{
          game.globalTimer = 0;
          game.gameStatus = FIGHT;
          player1.type = 2;
          player2.type = 2;
        }
        break;

     //####################################  
     case FIGHT:
        if(game.globalTimer<5){
          game.globalTimer = game.globalTimer +1;
        }else{
          game.globalTimer = 0;
          game.gameStatus = RESULT;
          if(player1.action == player2.action){
            player1.type = 2;
            player2.type = 2;
          }
          
          //P1 loser
          if(player1.action==0 && player2.action==1){player1.type = 3; player2.type = 2;}
          if(player1.action==1 && player2.action==2){player1.type = 3; player2.type = 2;}
          if(player1.action==2 && player2.action==0){player1.type = 3; player2.type = 2;}

          //P1 winner
          if(player1.action==0 && player2.action==2){player1.type = 2; player2.type = 3;}
          if(player1.action==1 && player2.action==0){player1.type = 2; player2.type = 3;}
          if(player1.action==2 && player2.action==1){player1.type = 2; player2.type = 3;}          
        }
        break;
        
     //####################################  
     case RESULT:
        if(game.globalTimer<6){
          game.globalTimer = game.globalTimer +1;
        }else{
          game.globalTimer = 0;
          ennemy_init();
          if(player2.type == 3){
            game.stage = game.stage + 1;
            if(game.stage>8){
              switch(game.typeGame){
                case 0:
                  game_initPlayers();
                  game.gameStatus = COUNTER3;
                  break;

                case 1:
                  game.globalTimer = 39;
                  player2.x = player2.x+40;
                  game.gameStatus = RUN;
                  break;

                case 2:
                  game.gameStatus = WINNER;
                  player1.action=2;
                  player1.type=0;
                  player2.x = player2.x+140;
                  break;
              }
            }else{
              switch(game.typeGame){
                case 0:
                  game_initPlayers();
                  game.gameStatus = COUNTER3;
                  break;

                case 1:
                  game.globalTimer = 39;
                  player2.x = player2.x+40;
                  game.gameStatus = RUN;
                  break;

                case 2:
                  game.globalTimer = 39;
                  player2.x = player2.x+40;
                  game.gameStatus = RUN;
                  break;
              }
            }
          }else{
            if(player1.type == 3){
              game.stage = game.stage - 1;
              if(game.stage<0){
                switch(game.typeGame){
                  case 0:
                    game_initPlayers();
                    game.gameStatus = COUNTER3;
                    break;
  
                  case 1:
                    game.globalTimer = 39;
                    player1.x = player1.x-40;
                    game.gameStatus = RUN;
                    break;
  
                  case 2:
                    game.gameStatus = WINNER;
                    player2.action=2;
                    player2.type=0;
                    player1.x = player1.x-140;
                    break;
                }
              }else{
                switch(game.typeGame){
                  case 0:
                    game_initPlayers();
                    game.gameStatus = COUNTER3;
                    break;
  
                  case 1:
                    game.globalTimer = 39;
                    player1.x = player1.x-40;
                    game.gameStatus = RUN;
                    break;
  
                  case 2:
                    game.globalTimer = 39;
                    player1.x = player1.x-40;
                    game.gameStatus = RUN;
                    break;
                }
              }
            }else{
              game_initPlayers();
              game.gameStatus = COUNTER3;
            }
          }
        }
        break;

     //####################################  
     case RUN:
        player1.anim = player1.anim+1;
        player2.anim = player2.anim+1;

     
          if(game.globalTimer>=0){
            game.globalTimer=game.globalTimer-game.moveBackgroundSpeed;
            if(player1.type == 3){
              background1a.x = background1a.x+(game.moveBackgroundSpeed-1);
              background1b.x = background1b.x+(game.moveBackgroundSpeed-1);
              if(background1a.x>=0){
                background1a.x=background1a.x-200;
                background1b.x=background1b.x-200;
              }
              
            
              background2a.x = background2a.x+(game.moveBackgroundSpeed);
              background2b.x = background2b.x+(game.moveBackgroundSpeed);
              background2c.x = background2c.x+(game.moveBackgroundSpeed);
              background2d.x = background2d.x+(game.moveBackgroundSpeed);
              background2e.x = background2e.x+(game.moveBackgroundSpeed);

              background2f1.x = background2f1.x+(game.moveBackgroundSpeed+1);
              background2f2.x = background2f2.x+(game.moveBackgroundSpeed+1);
              if(background2f1.x>=0){
                background2f1.x=background2f1.x-80;
                background2f2.x=background2f2.x-80;
              }              
            
              background3a.x = background3a.x+(game.moveBackgroundSpeed+1);
              background3b.x = background3b.x+(game.moveBackgroundSpeed+1);
              if(background3a.x>=0){
                background3a.x=background3a.x-80;
                background3b.x=background3b.x-80;
              }
              player1.x = player1.x + game.moveBackgroundSpeed;
              if(player1.anim>=10){player1.anim = 0;}
              if(player2.anim>=10){player2.anim = 0;}
              
            }else{
              if(player2.type == 3){
                background1a.x = background1a.x-(game.moveBackgroundSpeed-1);
                background1b.x = background1b.x-(game.moveBackgroundSpeed-1);
                if(background1b.x<=-120){
                  background1a.x = background1a.x+200;
                  background1b.x = background1b.x+200;
                }
              
                background2a.x = background2a.x-(game.moveBackgroundSpeed);
                background2b.x = background2b.x-(game.moveBackgroundSpeed);
                background2c.x = background2c.x-(game.moveBackgroundSpeed);
                background2d.x = background2d.x-(game.moveBackgroundSpeed);
                background2e.x = background2e.x-(game.moveBackgroundSpeed);

                background2f1.x = background2f1.x-(game.moveBackgroundSpeed+1);
                background2f2.x = background2f2.x-(game.moveBackgroundSpeed+1);
                if(background2f2.x<=0){
                  background2f1.x=background2f1.x+80;
                  background2f2.x=background2f2.x+80;
                } 
              
                background3a.x = background3a.x-(game.moveBackgroundSpeed+1);
                background3b.x = background3b.x-(game.moveBackgroundSpeed+1);
                if(background3b.x<=0){
                  background3a.x = background3a.x+80;
                  background3b.x = background3b.x+80;
                }

                player2.x = player2.x - game.moveBackgroundSpeed;
                if(player1.anim>=10){player1.anim = 0;}
                if(player2.anim>=10){player2.anim = 0;}
              }
            }
          }else{
            game.gameStatus = COUNTER3;
            game_initPlayers();
          }     
        break;

     //####################################  
     case WINNER:
        game.globalTimer = game.globalTimer + 1;
        if(game.globalTimer>500){
          game.globalTimer=0;
          game_init();
          game_initBackground();
          game_initPlayers();
          ennemy_initIA();
          gb.pickRandomSeed();
          game.gameStatus = TITLESCREEN;
        }
        break;

     //####################################  
     case MENU:
        break;

                          
     default:
        game.gameStatus = GAMEMAKERS;
        break;
  }
}


/*
//results
//easy: selected choice is shown during "1" and ia will not change / counter is displayed
//normal: selected choice is shown during "1" but ia can change / counter is displayed
//hard: selected choice is shown during "1" but ia can change / counter is not displayed
//hazardous: selected choice is not displayed before Fight / counter is not displayed 
*/
