void Music_Control(uint8_t state)
{
  if(state == 0)
  {
    digitalWrite(MUSIC1,LOW);
    delay(1000);
    digitalWrite(MUSIC1,HIGH);
    digitalWrite(MUSIC2,HIGH);
    digitalWrite(MUSIC3,HIGH);
  }
  else if(state == 1)
  {
    digitalWrite(MUSIC2,LOW);
    delay(1000);
    digitalWrite(MUSIC1,HIGH);
    digitalWrite(MUSIC2,HIGH);
    digitalWrite(MUSIC3,HIGH);
  }
  else if(state == 2)
  {
    digitalWrite(MUSIC3,LOW);
    delay(1000);
    digitalWrite(MUSIC1,HIGH);
    digitalWrite(MUSIC2,HIGH);
    digitalWrite(MUSIC3,HIGH);
  }
}

void first_part(){   
      strip1.setPixelColor(0, COLOR);
//      strip1.show();
     for(int i=30;i<=34;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     }
     for(int i=60;i<=68;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     }
     for(int i=90;i<=102 ;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     }
      for(int i=120;i<=136;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     }
      for(int i=150;i<=170;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     }
      for(int i=180;i<=204;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     }
      for(int i=210;i<=238;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     } 
    for(int i=240;i<=255;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     } 
     strip1.show();               
  }
void second_part(){

      for(int i=256;i<=271;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     }
     for(int i=273;i<=301;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     }
     for(int i=307;i<=331;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     }
     for(int i=341;i<=361;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     }
     for(int i=375;i<=391;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     }
          for(int i=409;i<=421;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     }
          for(int i=443;i<=451;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     }
          for(int i=477;i<=481;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     }

      strip1.setPixelColor(511, COLOR);
//      strip1.show();
    strip1.show();
  }
void Third_part(){   
     for(int i=15;i<=17;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     }
     for(int i=45;i<=51;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     }
     for(int i=75;i<=85 ;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     }
      for(int i=105;i<=119;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     }
      for(int i=135;i<=153;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     }
      for(int i=165;i<=187;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     }
      for(int i=195;i<=221;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     } 
    for(int i=225;i<=255;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     }
     strip1.show();                
  }

 void Fourth_part(){   
     for(int i=256;i<=286;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     }
     for(int i=290;i<=316;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     }
     for(int i=324;i<=346 ;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     }
      for(int i=358;i<=376;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     }
      for(int i=392;i<=406;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     }
      for(int i=426;i<=436;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     } 
    for(int i=460;i<=466;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     } 
    for(int i=494;i<=496;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     }  
     strip1.show();              
  }

void forword()
{
  for(int i=128;i<=383;i++){
      strip1.setPixelColor(i, COLOR);     
     } 
  strip1.show();
  }
void First_down(){   
      for(int i=8;i<=23;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     }
     for(int i=40;i<=55;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     }
     for(int i=72;i<=87;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     }
      for(int i=104;i<=119;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     }
      for(int i=136;i<=151;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     }
      for(int i=168;i<=183;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     }
      for(int i=200;i<=215;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     } 
    for(int i=232;i<=247;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     }
     strip1.show();              
  }
void First_up(){   
      for(int i=0;i<=7;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     }
     for(int i=24;i<=39;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     }
     for(int i=56;i<=71;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     }
      for(int i=88;i<=103;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     }
      for(int i=120;i<=135;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     }
      for(int i=152;i<=167;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     }
      for(int i=184;i<=199;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     } 
    for(int i=216;i<=231;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     } 
    for(int i=248;i<=255;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     }
     strip1.show();              
  }
void Second_down(){   
      for(int i=264;i<=279;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     }
     for(int i=296;i<=311;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     }
     for(int i=328;i<=343;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     }
      for(int i=360;i<=375;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     }
      for(int i=392;i<=407;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     }
      for(int i=424;i<=439;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     }
      for(int i=456;i<=471;i++){
      strip1.setPixelColor(i, COLOR);
      strip1.show();
     } 
    for(int i=488;i<=503;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     }
     strip1.show();              
  }
void Second_up(){   
     for(int i=256;i<=263;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     }
     for(int i=280;i<=295;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     }
     for(int i=312;i<=327;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     }
      for(int i=344;i<=359;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     }
      for(int i=376;i<=391;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     }
      for(int i=408;i<=423;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     }
      for(int i=440;i<=455;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     } 
    for(int i=472;i<=487;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     }
    for(int i=504;i<=511;i++){
      strip1.setPixelColor(i, COLOR);
//      strip1.show();
     }
     strip1.show();
  }
