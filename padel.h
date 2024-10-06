#ifndef PADEL_H
#define PADEL_H

#include"power.h"
#include"util.h"


class Padel {
    const int y = 50;
    int x;
    int length = 100;
     int width = 10;
     int defaultlength = 100;
    int col;
    int lengthincrease = 0;
    
    
    

public:

    Padel();
    int get_padcol();
    void set_padcol(int col);
    void set_x(int x);
    void set_length(int length);
    int get_x();
    int get_y();
    int get_width();
    int get_defaultlength();
    bool double_length();
    
   // void collisionbricks(bricks &bricks,greenPowerUp &GP , ball & b , pinkPowerup &PP,bluePowerup&BP,redPowerup&RP,yellowPowerup&YP)  ;
    int get_length ();
    void drawpadel();


    
    
};

#endif // PADEL_H