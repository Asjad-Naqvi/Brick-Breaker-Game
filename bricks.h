
#ifndef BRICKS_H
#define BRICKS_H

#include "util.h"

#include"ball.h"
#include"padel.h"
class ball;
class Pedal;

class bricks : public ball {
    
    int length = 75;
    int width = 25;
    static float Colors;
    int greenCollisions;
    int redCollisions;
    int pinkCollisions;
    int yellowCollisions;
    int blueCollisions;
    int lives;
public:
ball b;
Padel p;
int blueX[12];
int blueY[12];
    int greenX[12];
    int greenY[12];
    int redX[12];
    int redY[12];
    int pinkX[12];
    int pinkY[12];
    int yellowX[12];
    int yellowY[12];
     bool greenActive[12]; // Boolean array to track visibility of green bricks
    bool redActive[12];   // Boolean array to track visibility of red bricks
    bool pinkActive[12];  // Boolean array to track visibility of pink bricks
    bool yellowActive[12]; 
    bool blueActive[12];
    int bluecollisions[12] ;
    int redcollisions[12] ;
    int pinkcollisions[12] ;
    int yellowcollisions[12] ;

  

   void set_lives(int lives);
   int get_lives();
void set_length(int length);
int get_length();
void set_width(int width);
int get_width();
    bricks();
    void display();
    void activateAllBricks();
    void collisionbricks(Padel & p ,greenPowerUp &GP , ball & b , pinkPowerup &PP,bluePowerup&BP,redPowerup&RP,yellowPowerup&YP)  ;
};
#endif
