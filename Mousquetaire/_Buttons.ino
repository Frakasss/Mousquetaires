void button_check(int typeCheck){
  switch(typeCheck){
     //####################################
     //########### Skip Logo ##############
     //####################################
     case GAMEMAKERS:
      if(gb.buttons.pressed(BUTTON_A)){
        game.globalTimer = 0;
        game.gameStatus=TITLESCREEN;
      }
     break;    
    
     //####################################
     //########### Skip title #############
     //####################################
     case TITLESCREEN:      
      if(gb.buttons.pressed(BUTTON_A)){
        game.globalTimer = 0;
        game.gameStatus=SELECTNBPLAYER;
      }
     break;   

     //####################################
     //########### Controls P1 ############
     //####################################
     case CONTROLSP1:      
      if(gb.buttons.pressed(BUTTON_A)){
        game.gameStatus=CONTROLSP2;
      }
     break; 

     //####################################
     //########### Controls P2 ############
     //####################################
     case CONTROLSP2:      
      if(gb.buttons.pressed(BUTTON_A)){
        game.nbPlayer = 1;
        game.gameStatus=SELECTNBPLAYER;
      }
     break;  

     //####################################
     //########### Credits ################
     //####################################
     case CREDITS:      
      if(gb.buttons.pressed(BUTTON_A)){
        game.nbPlayer = 1;
        game.gameStatus=SELECTNBPLAYER;
      }
     break;

     //###########################################################
     //############# Buttons select Nb Player ####################
     //###########################################################
     case SELECTNBPLAYER:      
      if(gb.buttons.pressed(BUTTON_A)){
        switch(game.nbPlayer){
          case 0:
          break;

          case 1:
            game.gameStatus=SELECTOPTIONS;
            break;

          case 2:
            game.gameStatus=SELECTOPTIONS;
            break;

          case 3:
            game.gameStatus=CONTROLSP1;
            break;

          case 4:
            game.gameStatus=CREDITS;
            break;
        }
      }

      if(gb.buttons.pressed(BUTTON_UP)){    
        game.nbPlayer = game.nbPlayer - 1;
        if(game.nbPlayer<=0){game.nbPlayer=4;}
      }

      if(gb.buttons.pressed(BUTTON_DOWN)){    
        game.nbPlayer = game.nbPlayer + 1;
        if(game.nbPlayer>=5){game.nbPlayer=1;}
      } 
      break;  

     //#############################################
     //############# SELECTOPTIONS ####################
     //#############################################
     case SELECTOPTIONS:
      if(gb.buttons.pressed(BUTTON_A)){
        game.gameStatus=COUNTER3;
      }
      
      if(gb.buttons.pressed(BUTTON_B)){
        game.difficulty = 1;
        game.gameStatus=SELECTNBPLAYER;
      }   
           
      if(gb.buttons.pressed(BUTTON_LEFT)){    
        game.difficulty = game.difficulty - 1;
        if(game.nbPlayer==1){
          if(game.difficulty<0){game.difficulty=3;}
        }
        if(game.nbPlayer==2){
          if(game.difficulty<1){game.difficulty=2;}
        }
      }

      if(gb.buttons.pressed(BUTTON_RIGHT)){    
        game.difficulty = game.difficulty + 1;
        if(game.nbPlayer==1){
          if(game.difficulty>3){game.difficulty=0;}
        }
        if(game.nbPlayer==2){
          if(game.difficulty>2){game.difficulty=1;}
        }  
      } 

      if(gb.buttons.pressed(BUTTON_UP)){    
        game.typeGame = game.typeGame - 1;
        if(game.typeGame<0){game.typeGame=2;}
      }

      if(gb.buttons.pressed(BUTTON_DOWN)){    
        game.typeGame = game.typeGame + 1;
        if(game.typeGame>2){game.typeGame=0;}
      } 
      break; 

     //##################################################
     //############# Buttons Player #####################
     //##################################################
     case COUNTER3:
      if(gb.buttons.pressed(BUTTON_MENU)){
        game.pause=COUNTER3;
        game.gameStatus=MENU;
      }else{
        player1.action = 0;
        player2.action = 0;
        switch(game.nbPlayer){
          case 1:
            if(gb.buttons.repeat(BUTTON_A,0) || gb.buttons.repeat(BUTTON_LEFT, 0)){
              player1.anim = 0;
              player1.action = 2; 
            }else{
              if(gb.buttons.repeat(BUTTON_B,0) || gb.buttons.repeat(BUTTON_RIGHT, 0)){
                player1.anim = 0;
                player1.action = 1;             
              }
            }
            
            if(padPlayer2.btnA_repeat>0 || padPlayer2.btnLEFT_repeat>0){
              player2.anim = 0;
              player2.action = 2; 
            }
      
            if(padPlayer2.btnB_repeat>0 || padPlayer2.btnRIGHT_repeat>0){
              player2.anim = 0;
              player2.action = 1;
            }
          break;
  
          case 2:
            if(gb.buttons.repeat(BUTTON_LEFT, 0)){
              player1.anim = 0;
              player1.action = 2; 
            }else{
              if(gb.buttons.repeat(BUTTON_RIGHT, 0)){
                player1.anim = 0;
                player1.action = 1;             
              }
            }
  
            if(gb.buttons.repeat(BUTTON_A,0)){ 
              player2.anim = 0;
              player2.action = 2; 
            }else{
              if(gb.buttons.repeat(BUTTON_B,0)){
                player2.anim = 0;
                player2.action = 1;             
              }
            }
          break;
        }
      }
      break;    

     //##################################################
     //############# Buttons Player #####################
     //##################################################
     case COUNTER2:
      if(gb.buttons.pressed(BUTTON_MENU)){
        game.pause=COUNTER3;
        game.gameStatus=MENU;
      }else{
        player1.action = 0;
        player2.action = 0;
        switch(game.nbPlayer){
          case 1:
            if(gb.buttons.repeat(BUTTON_A,0) || gb.buttons.repeat(BUTTON_LEFT, 0)){
              player1.anim = 0;
              player1.action = 2; 
            }else{
              if(gb.buttons.repeat(BUTTON_B,0) || gb.buttons.repeat(BUTTON_RIGHT, 0)){
                player1.anim = 0;
                player1.action = 1;             
              }
            }
            
            if(padPlayer2.btnA_repeat>0 || padPlayer2.btnLEFT_repeat>0){
              player2.anim = 0;
              player2.action = 2; 
            }
      
            if(padPlayer2.btnB_repeat>0 || padPlayer2.btnRIGHT_repeat>0){
              player2.anim = 0;
              player2.action = 1;
            }
          break;
  
          case 2:
            if(gb.buttons.repeat(BUTTON_LEFT, 0)){
              player1.anim = 0;
              player1.action = 2; 
            }else{
              if(gb.buttons.repeat(BUTTON_RIGHT, 0)){
                player1.anim = 0;
                player1.action = 1;             
              }
            }
  
            if(gb.buttons.repeat(BUTTON_A,0)){ 
              player2.anim = 0;
              player2.action = 2; 
            }else{
              if(gb.buttons.repeat(BUTTON_B,0)){
                player2.anim = 0;
                player2.action = 1;             
              }
            }
          break;
        }
      }
      break;


     //##################################################
     //############# Buttons Player #####################
     //##################################################
     case COUNTER1:
      if(gb.buttons.pressed(BUTTON_MENU)){
        game.pause=COUNTER3;
        game.gameStatus=MENU;
      }else{
        player1.action = 0;
        player2.action = 0;
        switch(game.nbPlayer){
          case 1:
            if(gb.buttons.repeat(BUTTON_A,0) || gb.buttons.repeat(BUTTON_LEFT, 0)){
              player1.anim = 0;
              player1.action = 2; 
            }else{
              if(gb.buttons.repeat(BUTTON_B,0) || gb.buttons.repeat(BUTTON_RIGHT, 0)){
                player1.anim = 0;
                player1.action = 1;             
              }
            }
            
            if(padPlayer2.btnA_repeat>0 || padPlayer2.btnLEFT_repeat>0){
              player2.anim = 0;
              player2.action = 2; 
            }
      
            if(padPlayer2.btnB_repeat>0 || padPlayer2.btnRIGHT_repeat>0){
              player2.anim = 0;
              player2.action = 1;
            }
          break;
  
          case 2:
            if(gb.buttons.repeat(BUTTON_LEFT, 0)){
              player1.anim = 0;
              player1.action = 2; 
            }else{
              if(gb.buttons.repeat(BUTTON_RIGHT, 0)){
                player1.anim = 0;
                player1.action = 1;             
              }
            }
  
            if(gb.buttons.repeat(BUTTON_A,0)){ 
              player2.anim = 0;
              player2.action = 2; 
            }else{
              if(gb.buttons.repeat(BUTTON_B,0)){
                player2.anim = 0;
                player2.action = 1;             
              }
            }
          break;
        }
      }
      break;


     //##################################################
     //############# Buttons Player #####################
     //##################################################
     case FIGHT:
      if(gb.buttons.pressed(BUTTON_MENU)){
        game.pause=COUNTER3;
        game.gameStatus=MENU;
      }else{
        player1.action = 0;
        player2.action = 0;
        switch(game.nbPlayer){
          case 1:
            if(gb.buttons.repeat(BUTTON_A,0) || gb.buttons.repeat(BUTTON_LEFT, 0)){
              player1.anim = 0;
              player1.action = 2; 
            }else{
              if(gb.buttons.repeat(BUTTON_B,0) || gb.buttons.repeat(BUTTON_RIGHT, 0)){
                player1.anim = 0;
                player1.action = 1;             
              }
            }
            if(padPlayer2.btnA_repeat>0 || padPlayer2.btnLEFT_repeat>0){
              player2.anim = 0;
              player2.action = 2; 
            }
      
            if(padPlayer2.btnB_repeat>0 || padPlayer2.btnRIGHT_repeat>0){
              player2.anim = 0;
              player2.action = 1;
            }
          break;
  
          case 2:
            if(gb.buttons.repeat(BUTTON_LEFT, 0)){
              player1.anim = 0;
              player1.action = 2; 
            }else{
              if(gb.buttons.repeat(BUTTON_RIGHT, 0)){
                player1.anim = 0;
                player1.action = 1;             
              }
            }
  
            if(gb.buttons.repeat(BUTTON_A,0)){ 
              player2.anim = 0;
              player2.action = 2; 
            }else{
              if(gb.buttons.repeat(BUTTON_B,0)){
                player2.anim = 0;
                player2.action = 1;             
              }
            }
          break;
        }
      }
      break;

     //##################################################
     //############# Buttons Player #####################
     //##################################################
      case RESULT:
      if(gb.buttons.pressed(BUTTON_MENU)){
        game.pause=RESULT;
        game.gameStatus=MENU;
      }
      break;

     //##################################################
     //############# Buttons Player #####################
     //##################################################
      case RUN:
      if(gb.buttons.pressed(BUTTON_MENU)){
        game.pause=RUN;
        game.gameStatus=MENU;
      }
      break;


     //##################################################
     //############# Buttons Player #####################
     //##################################################
      case WINNER:
      if(gb.buttons.pressed(BUTTON_MENU)){
        game.pause=WINNER;
        game.gameStatus=MENU;
      }
      if(gb.buttons.pressed(BUTTON_A) || gb.buttons.pressed(BUTTON_B) || gb.buttons.pressed(BUTTON_UP) || gb.buttons.pressed(BUTTON_LEFT) || gb.buttons.pressed(BUTTON_DOWN) || gb.buttons.pressed(BUTTON_RIGHT) ){ 
        game.globalTimer=0;
        game_init();
        game_initBackground();
        game_initPlayers();
        ennemy_initIA();
        gb.pickRandomSeed();
        game.gameStatus = TITLESCREEN;
      }
      break;  

     //##################################
     case MENU:
      if(gb.buttons.pressed(BUTTON_A)){
        if(game.menuOption==0){
          game.gameStatus = game.pause;
        }else{
          game.globalTimer=0;
          game_init();
          game_initBackground();
          game_initPlayers();
          ennemy_initIA();
          gb.pickRandomSeed();
          game.gameStatus = TITLESCREEN;
        }
      }else{
        if(gb.buttons.pressed(BUTTON_UP)){    
          game.menuOption = game.menuOption - 1;
          if(game.menuOption<0){game.menuOption=1;}
        }
  
        if(gb.buttons.pressed(BUTTON_DOWN)){    
          game.menuOption = game.menuOption + 1;
          if(game.menuOption>1){game.menuOption=0;}
        } 
      }

      
     break; 
  }
}
