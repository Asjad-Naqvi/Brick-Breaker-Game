#ifndef BALL_H
#define BALL_H

#include "padel.h"

#include "power.h"
class Padel;
class ball   : public Padel {
    int x;
    int y;
    int score;
    int Colors;
    float x_speed;
    int lives;
    int bar_len;

public:

int speed;
    int default_speed;
    ball();
    void set_lives(int lives);
   int get_lives();
    int get_defspeed();
    void setspeed(int speed);//speed
    int get_speed();
    void setbar_len(int bar_len);
    int getbar_len();
    int get_score();
    void display_ball();
    void set_x(int x);
    int get_x();
    void set_y(int y);
    int get_y();
    void ball_move(int x1, int y1, Padel &p);
    void set_score(int score);
    void set_color(int Colors);
    int get_color();
    // void collisionbricks(bricks &bricks , greenPowerUp & GP,Padel & p , pinkPowerup&PP,bluePowerup & BP,redPowerup&RP,yellowPowerup&YP);
};

#endif // BALL_H