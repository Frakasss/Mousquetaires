//strat copy:         IA repeat all player action
//strat copy delay:   IA repeat all player action made 3 tour before
//strat random:       IA select randomly
//strat I know you:   IA ???
//strat not dummy1:   if player play the same thing more than 3 time, change strat
//strat not dummy2:   if player win more than 3 time in a row, change strat
//strat double:       if IA win, play the same next time

void ennemy_initIA(){
  iaData.selectedAction=0;
  iaData.currentStrategy=0;
}


void ennemy_init(){
  padPlayer2.btnUP_pressed = false;
  padPlayer2.btnDOWN_pressed = false;
  padPlayer2.btnLEFT_pressed = false;
  padPlayer2.btnRIGHT_pressed = false;
  padPlayer2.btnA_pressed = false;
  padPlayer2.btnB_pressed = false;
  padPlayer2.btnUP_repeat = 0;
  padPlayer2.btnDOWN_repeat = 0;
  padPlayer2.btnLEFT_repeat = 0;
  padPlayer2.btnRIGHT_repeat = 0;
  padPlayer2.btnA_repeat = 0;
  padPlayer2.btnB_repeat = 0;
}


void ennemy_initGame(){
  padPlayer2.btnUP_pressed = false;
  padPlayer2.btnDOWN_pressed = false;
  padPlayer2.btnLEFT_pressed = false;
  padPlayer2.btnRIGHT_pressed = false;
  padPlayer2.btnA_pressed = false;
  padPlayer2.btnB_pressed = false;
  padPlayer2.btnUP_repeat = 0;
  padPlayer2.btnDOWN_repeat = 0;
  padPlayer2.btnLEFT_repeat = 0;
  padPlayer2.btnRIGHT_repeat = 0;
  padPlayer2.btnA_repeat = 0;
  padPlayer2.btnB_repeat = 0;
}


void ennemy_manageStrategy(){
}


void ennemy_ia(){
  if(game.globalTimer==0){
    iaData.selectedAction = random(0, 3);

    switch ( game.gameStatus )
    {
      case COUNTER3:
      ennemy_init();
        /*
        ennemy_init();
        */
        break;

      case COUNTER2:
        /*
        ennemy_init();
        if(player1.type==0){padPlayer2.btnB_repeat = 5;}
        if(player1.type==1){padPlayer2.btnA_repeat = 5;}
        if(player1.type==2){}
        */
        break;
  
      case COUNTER1:
        ennemy_init();
        if(game.difficulty<3){
          if(iaData.selectedAction==1){padPlayer2.btnA_repeat = 5;}
          if(iaData.selectedAction==2){padPlayer2.btnB_repeat = 5;}
        }
        break;

      case FIGHT:
        if(game.difficulty>0){
          ennemy_init();
          if(iaData.selectedAction==1){padPlayer2.btnA_repeat = 5;}
          if(iaData.selectedAction==2){padPlayer2.btnB_repeat = 5;}
        }
        break;

      case RESULT:
        break;  
    }
  }
}


void ennemy_strategiesInit(){
}


