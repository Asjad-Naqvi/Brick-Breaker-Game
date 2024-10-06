
// GREENPOWERUP_H
#ifndef GREENPOWERUP_H
#define GREENPOWERUP_H

#include "ball.h"
#include "padel.h"



#include "util.h"

class greenPowerUp {
public:
    greenPowerUp();

    void set_xg(int xg);
    int get_xg();

    void set_yg(int yg);
    int get_yg();
     
    void display();
    bool Greenstatus();
    void setGreenstatus(bool greenstatus);
    
private:
    int xg;
    int yg;
    bool greenstatus; // Adding greenstatus as a private member variable
};





 class pinkPowerup {
private :
int xp;
int yp;

public:
bool pinkstatus;
pinkPowerup();
void set_xp(int xp);
    int get_xp();

    void set_yp(int yp);
    int get_yp();
     
    void displaypink();
    bool getpinkstatus();
    void setpinkstatus(bool greenstatus);



};






class bluePowerup{


private :
int xb;
int yb;

public:
bool bluestatus;
bluePowerup();
void set_xb(int xb);
    int get_xb();

    void set_yb(int yb);
    int get_yb();
     
    void displayblue();
    bool getbluestatus();
    void setbluestatus(bool bluestatus);








};



class redPowerup{


private :
int xr;
int yr;

public:
bool redstatus;
redPowerup();
void set_xr(int xr);
    int get_xr();

    void set_yr(int yr);
    int get_yr();
     
    void displayred();
    bool getredstatus();
    void setredstatus(bool redstatus);








};




class yellowPowerup{


private :
int xy;
int yy;

public:
bool newballstatus;
bool yellowstatus;
yellowPowerup();
void set_xy(int xy);
    int get_xy();

    void set_yy(int yy);
    int get_yy();
     
    void displayyellow();
    bool getyellowstatus();
    void setyellowstatus(bool yellowstatus);
    void setnewBallstatus(bool newballstatus);
bool getnewBallstatus();







};










#endif // GREENPOWERUP_H
