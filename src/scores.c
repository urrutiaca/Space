#include "invaders.h" //stdlib and stdio already loaded here
#include <string.h>

bool loaded = false;
char cscores[100];
char s[10];
int len = 0;

enum pantallas eventos_resultados(sfRenderWindow* w, sfEvent *e){
  // We always asume there is only the top 10 high scores in the file
  // the rest will be ignored
  if(!loaded){

    char ch;
    int scores[10];
    int line = 0;
    FILE *fp;
  
    fp = fopen("/media/erick/HDD/Coral/Space/resources/scores.txt", "r"); // read mode
  
    if (fp == NULL)
    {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }
    scores[line] = 0;

    while((ch = fgetc(fp)) != EOF){
      cscores[len] = ch;
      if(ch == '\n'){
        ++line;
        scores[line] = 0;
      }
      else{
        scores[line] = scores[line]*10 + (ch - '0');
      }
      //printf("%i\n",scores[line]);
      
      ++len;
    }
    cscores[len] = '+'; //Lets add a stop char
  
  
    fclose(fp);
    loaded = !loaded;
  }

  return RESULTADOS;
}



/*
// we know the scores len is 100 and they are separated by a \n
// the retunr lengght is always 10
char* rscore(char* scores, int scoreLoc){

  char ch;
  char scAux[10];
  int actualScore = 0;
  int scoreLen = 0;
  FILE *fp;

  fp = fopen("/media/erick/HDD/Coral/Space/resources/scores.txt", "r"); // read mode

  if (fp == NULL)
  {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
  }


  while((ch = fgetc(fp)) != EOF && (ch = fgetc(fp)) != '+' ){

    if(actualScore == scoreLoc){
      ++scoreLen;
      scAux[scoreLen - 1] = ch;
    }
    else if(ch == '\n'){
      ++actualScore;
    }
    
  }
  fclose(fp);  

  int start = 9 - scoreLen;
  for(size_t i = 0; i < 10; i++)
  {
    if(i >= start){
      s[i] = scAux[i - start];
    }
    else{
      s[i] = '0';
    }
  }
  
  return s;

}*/

int dibujar_scores(sfRenderWindow* w3){
  sfVideoMode pj = {800, 600 , 32};
  w3 = sfRenderWindow_create(pj, "SPACE INVADERS", sfClose, NULL);

  sfEvent e3;

  //texto ENDGAME
  sfText* endgame;
  endgame = sfText_create();
  sfText_setString(endgame, "END GAME");
  sfText_setCharacterSize(endgame, 70);
  sfText_setPosition(endgame, (sfVector2f){240,50});
  sfText_setFont(endgame, sfFont_createFromFile("resources/Athletic.TTF"));
  sfText_setColor(endgame, sfColor_fromRGB(144,12,63) );


  //texto SCORES
  char* name_with_extension;
  sfText* scores;
  scores = sfText_create();
  sfText_setString(scores, "SCORES");
  sfText_setCharacterSize(scores, 40);
  sfText_setPosition(scores, (sfVector2f){330,140});
  sfText_setFont(scores, sfFont_createFromFile("resources/Athletic.TTF"));
  sfText_setColor(scores, sfColor_fromRGB(144,12,63));

  /*//texto s1
  rscore(cscores, 0);
 

  sfText* s1;
  scores = sfText_create();
  sfText_setString(s1, s);
  sfText_setCharacterSize(s1, 40);
  sfText_setPosition(s1, (sfVector2f){330,140});
  sfText_setFont(s1, sfFont_createFromFile("resources/Athletic.TTF"));
  sfText_setColor(s1, sfColor_fromRGB(144,12,63));

    //texto s2
  rscore(cscores, 1);
  sfText* s2;
  scores = sfText_create();
  sfText_setString(s2,  s);
  sfText_setCharacterSize(s2, 40);
  sfText_setPosition(s2, (sfVector2f){330,140});
  sfText_setFont(s2, sfFont_createFromFile("resources/Athletic.TTF"));
  sfText_setColor(s2, sfColor_fromRGB(144,12,63));

    //texto s3
  rscore(cscores, 3);
  sfText* s3;
  scores = sfText_create();
  sfText_setString(s3,  s);
  sfText_setCharacterSize(s3, 40);
  sfText_setPosition(s3, (sfVector2f){330,140});
  sfText_setFont(s3, sfFont_createFromFile("resources/Athletic.TTF"));
  sfText_setColor(s3, sfColor_fromRGB(144,12,63));

    //texto s4
  rscore(cscores, 4);

  sfText* s4;
  scores = sfText_create();
  sfText_setString(s4,  s);
  sfText_setCharacterSize(s4, 40);
  sfText_setPosition(s4, (sfVector2f){330,140});
  sfText_setFont(s4, sfFont_createFromFile("resources/Athletic.TTF"));
  sfText_setColor(s4, sfColor_fromRGB(144,12,63));

    //texto s5
  rscore(cscores, 5);
  sfText* s5;
  scores = sfText_create();
  sfText_setString(s5,  s);
  sfText_setCharacterSize(s5, 40);
  sfText_setPosition(s5, (sfVector2f){330,140});
  sfText_setFont(s5, sfFont_createFromFile("resources/Athletic.TTF"));
  sfText_setColor(s5, sfColor_fromRGB(144,12,63));*/


  sfTexture* texture1;
  texture1 = sfTexture_createFromFile("resources/enemy2.png", NULL);
  sfSprite* enemy1;
  enemy1 = sfSprite_create();
  sfSprite_setTexture(enemy1, texture1, sfTrue);
  sfSprite_setPosition(enemy1, (sfVector2f){110, 526});
  sfSprite_setScale(enemy1, (sfVector2f){0.14,0.14});

  sfTexture* texture2;
  texture2 = sfTexture_createFromFile("resources/enemy1.png", NULL);
  sfSprite* enemy2;
  enemy2 = sfSprite_create();
  sfSprite_setTexture(enemy2, texture2, sfTrue);
  sfSprite_setPosition(enemy2, (sfVector2f){357, 522});
  sfSprite_setScale(enemy2, (sfVector2f){0.15,0.15});

  sfTexture* texture3;
  texture3 = sfTexture_createFromFile("resources/enemy3.png", NULL);
  sfSprite* enemy3;
  enemy3 = sfSprite_create();
  sfSprite_setTexture(enemy3, texture3, sfTrue);
  sfSprite_setPosition(enemy3, (sfVector2f){580, 520});
  sfSprite_setScale(enemy3, (sfVector2f){0.16,0.16});

  sfRenderWindow_drawText(w3,endgame, NULL);
  sfRenderWindow_drawText(w3, scores, NULL);
  sfRenderWindow_drawSprite(w3, enemy1, NULL);
  sfRenderWindow_drawSprite(w3, enemy2, NULL);
  sfRenderWindow_drawSprite(w3, enemy3, NULL);
  sfRenderWindow_display(w3);

    return 0;
}


















/*
int f_pantallaendgame(){


  sfVideoMode pj = {800, 600 , 32};
  sfRenderWindow* w3;
  w3 = sfRenderWindow_create(pj, "SPACE INVADERS", sfClose, NULL);

  sfEvent e3;

  //texto ENDGAME
  sfText* endgame;
  endgame = sfText_create();
  sfText_setString(endgame, "END GAME");
  sfText_setCharacterSize(endgame, 70);
  sfText_setPosition(endgame, (sfVector2f){240,50});
  sfText_setFont(endgame, sfFont_createFromFile("resources/Athletic.TTF"));
  sfText_setColor(endgame, sfColor_fromRGB(144,12,63) );


  //texto SCORES
  sfText* scores;
  scores = sfText_create();
  sfText_setString(scores, "SCORES");
  sfText_setCharacterSize(scores, 40);
  sfText_setPosition(scores, (sfVector2f){330,140});
  sfText_setFont(scores, sfFont_createFromFile("resources/Athletic.TTF"));
  sfText_setColor(scores, sfBlack);

  sfTexture* texture1;
  texture1 = sfTexture_createFromFile("resources/enemy2.png", NULL);
  sfSprite* enemy1;
  enemy1 = sfSprite_create();
  sfSprite_setTexture(enemy1, texture1, sfTrue);
  sfSprite_setPosition(enemy1, (sfVector2f){110, 526});
  sfSprite_setScale(enemy1, (sfVector2f){0.14,0.14});

  sfTexture* texture2;
  texture2 = sfTexture_createFromFile("resources/enemy1.png", NULL);
  sfSprite* enemy2;
  enemy2 = sfSprite_create();
  sfSprite_setTexture(enemy2, texture2, sfTrue);
  sfSprite_setPosition(enemy2, (sfVector2f){357, 522});
  sfSprite_setScale(enemy2, (sfVector2f){0.15,0.15});

  sfTexture* texture3;
  texture3 = sfTexture_createFromFile("resources/enemy3.png", NULL);
  sfSprite* enemy3;
  enemy3 = sfSprite_create();
  sfSprite_setTexture(enemy3, texture3, sfTrue);
  sfSprite_setPosition(enemy3, (sfVector2f){580, 520});
  sfSprite_setScale(enemy3, (sfVector2f){0.16,0.16});




  while(sfRenderWindow_isOpen(w3)){
    while(sfRenderWindow_pollEvent(w3, &e3)){

      if(e3.type == sfEvtClosed){
        printf("Cerrando\n");
        sfRenderWindow_close(w3);
      }//else if{

        //obtener datos del file donde se guardan los puntajes
        //hacer la comparacion de datos
        //agregar nuevo puntaje en caso de
        //imprimirlos en pantalla

      }

      sfRenderWindow_clear(w3, sfWhite);
      sfRenderWindow_drawText(w3,endgame, NULL);
      sfRenderWindow_drawText(w3, scores, NULL);
      sfRenderWindow_drawSprite(w3, enemy1, NULL);
      sfRenderWindow_drawSprite(w3, enemy2, NULL);
      sfRenderWindow_drawSprite(w3, enemy3, NULL);
      sfRenderWindow_display(w3);

    }


    sfText_destroy(endgame);
    sfText_destroy(scores);
    sfSprite_destroy(enemy1);
    sfSprite_destroy(enemy2);
    sfSprite_destroy(enemy3);
    sfRenderWindow_destroy(w3);




    return 0;
  }
*/