#include <SFML/Audio.h>
#include <SFML/Graphics.h>


#include <stdlib.h>
#include <stdio.h>

int f_pantallaprincipal(){

    sfVideoMode pp = {800, 600 , 32};
    sfRenderWindow* w;
    w = sfRenderWindow_create(pp, "SPACE INVADERS", sfResize | sfClose, NULL);

    sfEvent e;

    //texto SPACE INVADERS  
    sfText* SPACE;
    SPACE = sfText_create();
    sfText_setString(SPACE, "SPACE INVADERS");
    sfText_setCharacterSize(SPACE, 80);
    sfText_setPosition(SPACE, (sfVector2f){100,50});
    sfText_setFont(SPACE, sfFont_createFromFile("./Athletic.TTF"));
    sfText_setColor(SPACE, sfColor_fromRGB(144,12,63) );

    //texto SCORE ADVANCE TABLE
    sfText* scoretable;
    scoretable = sfText_create();
    sfText_setString(scoretable, "SCORE ADVANCE TABLE");
    sfText_setCharacterSize(scoretable, 20);
    sfText_setPosition(scoretable, (sfVector2f){300,170});
    sfText_setFont(scoretable, sfFont_createFromFile("./Athletic.TTF"));
    sfText_setColor(scoretable, sfBlack);

    //Imagenes de los enemigos y texto de los puntos
    sfTexture* texture1;
    texture1 = sfTexture_createFromFile("enemy2.png", NULL);
    sfSprite* enemy1;
    enemy1 = sfSprite_create();
    sfSprite_setTexture(enemy1, texture1, sfTrue);
    sfSprite_setPosition(enemy1, (sfVector2f){300, 220});
    sfSprite_setScale(enemy1, (sfVector2f){0.1,0.1});

    sfText* score1;
    score1 = sfText_create();
    sfText_setString(score1, "= 10 points");
    sfText_setCharacterSize(score1, 20);
    sfText_setPosition(score1, (sfVector2f){380,230});
    sfText_setFont(score1, sfFont_createFromFile("./232MKRL_.TTF"));
    sfText_setColor(score1, sfBlack);

    sfTexture* texture2;
    texture2 = sfTexture_createFromFile("enemy1.png", NULL);
    sfSprite* enemy2;
    enemy2 = sfSprite_create();
    sfSprite_setTexture(enemy2, texture2, sfTrue);
    sfSprite_setPosition(enemy2, (sfVector2f){295, 270});
    sfSprite_setScale(enemy2, (sfVector2f){0.12,0.12});

    sfText* score2;
    score2 = sfText_create();
    sfText_setString(score2, "= 20 points");
    sfText_setCharacterSize(score2, 20);
    sfText_setPosition(score2, (sfVector2f){380,290});
    sfText_setFont(score2, sfFont_createFromFile("./232MKRL_.TTF"));
    sfText_setColor(score2, sfBlack);

    sfTexture* texture3;
    texture3 = sfTexture_createFromFile("enemy3.png", NULL);
    sfSprite* enemy3;
    enemy3 = sfSprite_create();
    sfSprite_setTexture(enemy3, texture3, sfTrue);
    sfSprite_setPosition(enemy3, (sfVector2f){293, 330});
    sfSprite_setScale(enemy3, (sfVector2f){0.13,0.13});

    sfText* score3;
    score3 = sfText_create();
    sfText_setString(score3, "= 30 points");
    sfText_setCharacterSize(score3, 20);
    sfText_setPosition(score3, (sfVector2f){380,350});
    sfText_setFont(score3, sfFont_createFromFile("./232MKRL_.TTF"));
    sfText_setColor(score3, sfBlack);

    sfTexture* texture4;
    texture4 = sfTexture_createFromFile("enemy4.png", NULL);
    sfSprite* enemy4;
    enemy4 = sfSprite_create();
    sfSprite_setTexture(enemy4, texture4, sfTrue);
    sfSprite_setPosition(enemy4, (sfVector2f){300, 395});
    sfSprite_setScale(enemy4, (sfVector2f){0.17,0.17});

    sfText* score4;
    score4 = sfText_create();
    sfText_setString(score4, "= ??? ");
    sfText_setCharacterSize(score4, 20);
    sfText_setPosition(score4, (sfVector2f){380,410});
    sfText_setFont(score4, sfFont_createFromFile("./232MKRL_.TTF"));
    sfText_setColor(score4, sfBlack);

    //boton PLAY
    sfSprite* bplay;
    sfTexture* texture5;
    texture5 = sfTexture_createFromFile("playbut.jpg", NULL);
    bplay = sfSprite_create();
    sfSprite_setTexture(bplay, texture5, sfTrue);
    sfSprite_setPosition(bplay, (sfVector2f){300, 460});
    sfSprite_setScale(bplay, (sfVector2f){0.3,0.3});

    //boton MUltijugador
    sfSprite* bmultip;
    sfTexture* texture6;
    texture6 = sfTexture_createFromFile("multiplayerbut.jpg", NULL);
    bmultip = sfSprite_create();
    sfSprite_setTexture(bmultip, texture6, sfTrue);
    sfSprite_setPosition(bmultip, (sfVector2f){325, 530});
    sfSprite_setScale(bmultip, (sfVector2f){0.4,0.4});

    
    //no existe vara como tal para hacer un boton entonces se pueden programar con si se presiona o no el mouse en n rango de coordenadas

    while(sfRenderWindow_isOpen(w)){
        while(sfRenderWindow_pollEvent(w, &e)){

            if(e.type == sfEvtClosed){
                printf("Cerrando\n");
                sfRenderWindow_close(w);
            }else if(e.type ==sfEvtKeyPressed){

                //if boton jugar
                // if boton multijugador
                // if 

            }
        }

        sfRenderWindow_clear(w, sfWhite);
        sfRenderWindow_drawText(w,SPACE, NULL);
        sfRenderWindow_drawText(w, scoretable, NULL);
        sfRenderWindow_drawSprite(w, enemy1, NULL);
        sfRenderWindow_drawText(w, score1, NULL);
        sfRenderWindow_drawSprite(w, enemy2, NULL);
        sfRenderWindow_drawText(w, score2, NULL);
        sfRenderWindow_drawSprite(w, enemy3, NULL);
        sfRenderWindow_drawText(w, score3, NULL);
        sfRenderWindow_drawSprite(w, enemy4, NULL);
        sfRenderWindow_drawText(w, score4, NULL);
        sfRenderWindow_drawSprite(w, bplay, NULL);
        sfRenderWindow_drawSprite(w, bmultip, NULL);
        sfRenderWindow_display(w);
        
    }

    
    sfText_destroy(SPACE);
    sfText_destroy(scoretable);
    sfSprite_destroy(enemy1);
    sfSprite_destroy(enemy2);
    sfSprite_destroy(enemy3);
    sfSprite_destroy(enemy4);
    sfSprite_destroy(bmultip);
    sfSprite_destroy(bplay);
    sfText_destroy(score4);
    sfText_destroy(score1);
    sfText_destroy(score2);
    sfText_destroy(score3);
    sfRenderWindow_destroy(w);

    return 0;
}


int f_pantallajuego(){

    sfVideoMode pj = {800, 600 , 32};
    sfRenderWindow* w2;
    w2 = sfRenderWindow_create(pj, "SPACE INVADERS", sfResize | sfClose, NULL);

    sfEvent e2;

    //texto SCORE <1>
    sfText* primerscore;
    primerscore = sfText_create();
    sfText_setString(primerscore, "SCORE <1>");
    sfText_setCharacterSize(primerscore, 40);
    sfText_setPosition(primerscore, (sfVector2f){40,50});
    sfText_setFont(primerscore, sfFont_createFromFile("./232MKRL_.TTF"));
    sfText_setColor(primerscore, sfBlack);

    //texto SCORE <2>
    sfText* segundoscore;
    segundoscore = sfText_create();
    sfText_setString(segundoscore, "SCORE <2>");
    sfText_setCharacterSize(segundoscore, 40);
    sfText_setPosition(segundoscore, (sfVector2f){550,50});
    sfText_setFont(segundoscore, sfFont_createFromFile("./232MKRL_.TTF"));
    sfText_setColor(segundoscore, sfBlack);

    //texto HI-SCORE
    sfText* hiscore;
    hiscore = sfText_create();
    sfText_setString(hiscore, "HI-SCORE");
    sfText_setCharacterSize(hiscore, 40);
    sfText_setPosition(hiscore, (sfVector2f){300,50});
    sfText_setFont(hiscore, sfFont_createFromFile("./232MKRL_.TTF"));
    sfText_setColor(hiscore, sfBlack);

    //texto credit 
    sfText* credit;
    credit = sfText_create();
    sfText_setString(credit, "Credit 00");
    sfText_setCharacterSize(credit, 20);
    sfText_setPosition(credit, (sfVector2f){650,550});
    sfText_setFont(credit, sfFont_createFromFile("./232MKRL_.TTF"));
    sfText_setColor(credit, sfBlack);

    //linea
    sfRectangleShape* c;
    c = sfRectangleShape_create();
    sfRectangleShape_setFillColor(c, sfBlack);
    sfRectangleShape_setPosition(c, (sfVector2f){ 50, 545 });
    sfRectangleShape_setSize(c, (sfVector2f){ 710, 3 });
    

    while(sfRenderWindow_isOpen(w2)){
        while(sfRenderWindow_pollEvent(w2, &e2)){

            if(e2.type == sfEvtClosed){
                printf("Cerrando\n");
                sfRenderWindow_close(w2);
            }//else if(e.type ==sfEvtKeyPressed){

                //if boton jugar
                // if boton multijugador
                // if 

            }

        sfRenderWindow_clear(w2, sfWhite);
        sfRenderWindow_drawText(w2,segundoscore, NULL);
        sfRenderWindow_drawText(w2, primerscore, NULL);
        sfRenderWindow_drawText(w2, hiscore, NULL);
        sfRenderWindow_drawText(w2, credit, NULL);
        sfRenderWindow_drawRectangleShape(w2, c, NULL);
        sfRenderWindow_display(w2);

    }


    sfText_destroy(primerscore);
    sfText_destroy(segundoscore);
    sfText_destroy(hiscore);
    sfText_destroy(credit);
    sfRectangleShape_destroy(c);
    sfRenderWindow_destroy(w2);



    return 0;
}

int f_pantallaendgame(){


    sfVideoMode pj = {800, 600 , 32};
    sfRenderWindow* w3;
    w3 = sfRenderWindow_create(pj, "SPACE INVADERS", sfResize | sfClose, NULL);

    sfEvent e3;

    //texto ENDGAME
    sfText* endgame;
    endgame = sfText_create();
    sfText_setString(endgame, "END GAME");
    sfText_setCharacterSize(endgame, 70);
    sfText_setPosition(endgame, (sfVector2f){240,50});
    sfText_setFont(endgame, sfFont_createFromFile("./Athletic.TTF"));
    sfText_setColor(endgame, sfColor_fromRGB(144,12,63) );


    //texto SCORES
    sfText* scores;
    scores = sfText_create();
    sfText_setString(scores, "SCORES");
    sfText_setCharacterSize(scores, 40);
    sfText_setPosition(scores, (sfVector2f){330,140});
    sfText_setFont(scores, sfFont_createFromFile("./Athletic.TTF"));
    sfText_setColor(scores, sfBlack);

    sfTexture* texture1;
    texture1 = sfTexture_createFromFile("enemy2.png", NULL);
    sfSprite* enemy1;
    enemy1 = sfSprite_create();
    sfSprite_setTexture(enemy1, texture1, sfTrue);
    sfSprite_setPosition(enemy1, (sfVector2f){110, 526});
    sfSprite_setScale(enemy1, (sfVector2f){0.14,0.14});

    sfTexture* texture2;
    texture2 = sfTexture_createFromFile("enemy1.png", NULL);
    sfSprite* enemy2;
    enemy2 = sfSprite_create();
    sfSprite_setTexture(enemy2, texture2, sfTrue);
    sfSprite_setPosition(enemy2, (sfVector2f){357, 522});
    sfSprite_setScale(enemy2, (sfVector2f){0.15,0.15});

    sfTexture* texture3;
    texture3 = sfTexture_createFromFile("enemy3.png", NULL);
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

int main(){

    //f_pantallaprincipal();
    //f_pantallajuego();
    f_pantallaendgame();

    return 0;
}