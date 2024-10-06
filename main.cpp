#include"ball.h"
#include"bricks.h"
#include"padel.h"
 #include"util.h"
 #include"menu.h"
 #include"power.h"

#include <fstream>
using namespace std;



class top{
    ball ba;
    ball bal;
    Padel p;
    bricks b;
    menu m;
    greenPowerUp GP;
    pinkPowerup PP;
    bluePowerup BP;
    redPowerup RP;
    yellowPowerup YP;
    
public:
top():ba () , p (), b(),m(){}

void dislay_ball(){
    ba.display_ball();
}


void display_bricks(){
    b.display();
}

void display_padel(){
    p.drawpadel();
}
void displaygreen(){// Green triangle display
   if (GP.Greenstatus()==true) GP.display();
}


void displaypink(){
    if(PP.getpinkstatus()==true)PP.displaypink();
}

void displayblue(){
    if(BP.getbluestatus()==true)BP.displayblue();
}

void displared(){
    if(RP.getredstatus()==true)RP.displayred();
}

void displayyellow(){
    if(YP.getyellowstatus()==true)YP.displayyellow();
}



void move (){

    ba.ball_move(ba.get_x(),ba.get_y(),p);
}

void collision(){
    // p.collisionbricks(b,GP,ba,PP,BP,RP,YP);
    b.collisionbricks(p,GP,ba,PP,BP,RP,YP);
}



void newball(){
    if(YP.getnewBallstatus()==true){
        bal.display_ball();
        
        
    }
}


void newballmove(){
    if(YP.getnewBallstatus()==true){
        bal.ball_move(bal.get_x(),bal.get_y(),p);
        
        
    }

}
void newballcolission(){
    if(YP.getnewBallstatus()==true){
        b.collisionbricks(p,GP,bal,PP,BP,RP,YP);
        
        
    }

}

  
void setPadel(int x){
    p.set_x(x);
}


int getpadelx(){
    return p.get_x();
}

int getscore(){
    return ba.get_score();
}
int getbarlength(){
    return ba.getbar_len();
}


bool getstatus(){//for main menu
  return  m.checkstatus();
}
void setstatus(bool status){
    m.setstatus(status);
}

int get_lives(){
   return ba.get_lives();
}

int readHighScore() {
    int highScore = 0;
    ifstream file("highscore.txt");
    if (file.is_open()) {
        file >> highScore;
        file.close();
    }
    return highScore;
}

void  updateHighScore(int currentScore) {
    int highScore = readHighScore();
    if (currentScore > highScore) {
        ofstream file("highscore.txt");
        if (file.is_open()) {
            file << currentScore;
            file.close();
        }
    }
}

bool res = false;

bool checkresume() {
    return res;
}

void setresume(bool res) {
    this->res = res;
}



  


};
