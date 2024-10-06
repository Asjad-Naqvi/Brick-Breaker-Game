#include "util.h"
#include "padel.h"

#include "ball.h"

    

    

ball:: ball  (){
    x = 500;
    y = 400;
    speed = 10;
    x_speed = 0.0;
   Colors = 5; 
     bar_len = 30;
     default_speed = 10;
     score = 0;
     lives = 5;
}







void ball::set_lives(int lives){
    this ->lives = lives;
} 


int ball::get_lives(){
    return lives;
}





void ball::setspeed(int speed){
    this-> speed = speed;
}
int ball::get_speed(){
    return speed;
}
    void ball:: display_ball(){
        DrawCircle(x,y,10,colors[Colors]);
    }


    void ball:: set_x (int x){
    this -> x = x; 
}
int ball:: get_score(){
return score;
}

void ball::setbar_len(int bar_len){
    this -> bar_len=bar_len;

}

int ball:: getbar_len(){
    return bar_len;
}

int ball:: get_x(){
    return x;
}

void ball:: set_y (int y){
    this -> y = y; 
}

int ball:: get_y(){
    return y;
}

int ball::get_defspeed(){
    return default_speed;
}

void ball::set_score(int score){
 this->score = score;
}
void ball:: set_color(int Colors){
     this->Colors = Colors;
}

int get_color(){
    int Colors = Colors;
    return  Colors;
}





void ball::ball_move(int x1, int y1, Padel &p) {
    x += x_speed;
    y += speed;

    if (x <= 0 || x >= 1020) {
        x_speed = -x_speed;
    }

    if (y <= 0) {
        lives--;
        x = 500;
        y= 400; 
    }
    // if(lives == 0){
        
    // }

    if (y + 10 >= 900) { // Assuming the screen height is 900
        speed = -speed; // Handle game over scenario or reset ball position, etc.
    }

    // Collision with paddle
    if (x + 20 >= p.get_x() && x <= p.get_x() + p.get_length() && y + 20 >= p.get_y() && y <= p.get_y() + p.get_width()) {
        speed = -speed;
        p.set_padcol(Colors);
        // Calculate the relative position of the collision point on the paddle
        float relativeCollisionPoint = ((x + 10) - p.get_x()) / static_cast<float>(p.get_length());
        // Adjust the horizontal speed based on the relative collision point
        x_speed = (relativeCollisionPoint - 0.5f) * 10.0f;
    }
}











// void ball::collisionbricks(bricks &bricks,greenPowerUp &GP , Padel & p , pinkPowerup &PP,bluePowerup&BP,redPowerup&RP,yellowPowerup&YP) {
//     static int counter;
//     static bool newballAdded = false;
//     static ball* newBalls[2]; 

//     for (int i = 0; i < 12; i++) {
//         if (bricks.greenActive[i] &&
//             x >= bricks.greenX[i] && x <= bricks.greenX[i] + bricks.get_length() &&
//             y >= bricks.greenY[i] && y <= bricks.greenY[i] + bricks.get_width()) {
//             score++;
//             bar_len += 10;
//             bricks.greenActive[i] = false;

//             GP.set_xg(bricks.greenX[i]);
//             GP.set_yg(bricks.greenY[i]);

//             if (GP.get_xg() == bricks.greenX[5] && GP.get_yg() == bricks.greenY[5] && bricks.greenActive[5] == false) {
//                 GP.setGreenstatus(true);
//                 GP.display();

               
//             }
     

//             Colors = 31;
//             // Set color
//             speed = -speed;
//             break;
//         }

//         // Decrement green triangle's yg
       
    

//     // Check if the green triangle has reached the bottom of the screen
   
        
//         // Collision with red bricks
//         if (bricks.redActive[i] &&
//             x >= bricks.redX[i] && x <= bricks.redX[i] + bricks.get_length() &&
//             y >= bricks.redY[i] && y <= bricks.redY[i] + bricks.get_width()) {
                
//             bricks.redcollisions[i] -= 1;
//             Colors = 5;
//             bar_len += 10;

//             if (bricks.redcollisions[i] == 0)
//                 bricks.redActive[i] = false;
//             if (bricks.redActive[i] == false)
//                 score++;
                
                
//                 RP.set_xr(bricks.redX[i]);
//             RP.set_yr(bricks.redY[i]);

//             if (RP.get_xr() == bricks.redX[5] && RP.get_yr() == bricks.redY[5] && bricks.redActive[5] == false) {
//                 RP.setredstatus(true);
//                 RP.displayred();

               
//             } // Brick vanishes if no collisions left
            
//             speed = -speed;
//             break;
//         }
        
//         // Collision with pink bricks
//         if (bricks.pinkActive[i] &&
//             x >= bricks.pinkX[i] && x <= bricks.pinkX[i] + bricks.get_length() &&
//             y >= bricks.pinkY[i] && y <= bricks.pinkY[i] + bricks.get_width()) {
//             score++;
//             bar_len += 10;
//             bricks.pinkcollisions[i] -= 1;
//             Colors = 91;

//             if (bricks.pinkcollisions[i] == 0)
//                 bricks.pinkActive[i] = false; // Brick vanishes if no collisions left



//  PP.set_xp(bricks.pinkX[i]);//pink powerup
//             PP.set_yp(bricks.pinkY[i]);

//             if (PP.get_xp() == bricks.pinkX[5] && PP.get_yp() == bricks.pinkY[5] && bricks.pinkActive[5] == false) {
//                 PP.setpinkstatus(true);
//                 PP.displaypink();




//             }

            
//             speed = -speed;
//             break;
//         }



        
//         // Collision with yellow bricks
//         if (bricks.yellowActive[i] &&
//             x >= bricks.yellowX[i] && x <= bricks.yellowX[i] + bricks.get_length() &&
//             y >= bricks.yellowY[i] && y <= bricks.yellowY[i] + bricks.get_width()) {
//             score++;
//             bar_len += 10;
//             bricks.yellowcollisions[i] -= 1;
//             Colors = 23;

//             if (bricks.yellowcollisions[i] == 0)
//                 bricks.yellowActive[i] = false; // Brick vanishes if no collisions left
            



// YP.set_xy(bricks.yellowX[i]);//pink powerup
//             YP.set_yy(bricks.yellowY[i]);

//             if (YP.get_xy() == bricks.yellowX[5] && YP.get_yy() == bricks.yellowY[5] && bricks.yellowActive[5] == false) {
//                 YP.setyellowstatus(true);
//                 YP.displayyellow();

//             }






//             speed = -speed;
//             break;
//         }
        
//         // Collision with blue bricks
//         if (bricks.blueActive[i] &&
//             x >= bricks.blueX[i] && x <= bricks.blueX[i] + bricks.get_length() &&
//             y >= bricks.blueY[i] && y <= bricks.blueY[i] + bricks.get_width()) {
//             score++;
//             bar_len += 10;
//             bricks.bluecollisions[i] -= 1;
//             Colors = 68;

//             if (bricks.bluecollisions[i] == 0)
//                 bricks.blueActive[i] = false; 
            


// BP.set_xb(bricks.blueX[i]);//pink powerup
//             BP.set_yb(bricks.blueY[i]);

//             if (BP.get_xb() == bricks.blueX[5] && BP.get_yb() == bricks.blueY[5] && bricks.blueActive[5] == false) {
//                 BP.setbluestatus(true);
//                 BP.displayblue();




//             }
















//             speed = -speed;
//             break;
//         }
        
//         // Decrement green triangle's yg
        
//     }
//            if (GP.Greenstatus()) {
//             GP.set_yg(GP.get_yg() - 10);
//         }

//         // Collision detection with paddle and power-up
//         if (GP.get_yg() == p.get_y() + p.get_width() && GP.get_xg() > p.get_x() && GP.get_xg() < p.get_x() + p.get_length()) {
//             p.set_length(p.get_length() * 2);
//             counter = 0; // Reset counter when paddle length is extended
//         }

//         // Increment counter if paddle length is doubled
//         if (p.get_length() == p.get_defaultlength() * 2) {
//             counter++;
//         }

//         // Reset paddle length after 5 seconds
//         if (counter == 300) { // Assuming each iteration of your collision function represents 1/60th of a second
//             p.set_length(p.get_defaultlength());
//             counter = 0; // Reset counter
//         }




//           if (PP.getpinkstatus()) {
//             PP.set_yp(PP.get_yp() - 10);
//         }

//         // Collision detection with paddle and power-up
//         if (PP.get_yp() == p.get_y() + p.get_width() && PP.get_xp() > p.get_x() && PP.get_xp() < p.get_x() + p.get_length()) {
//             p.set_length(p.get_length() / 2);
//             counter = 0; // Reset counter when paddle length is extended
//         }

//         // Increment counter if paddle length is doubled
//         if (p.get_length() == p.get_defaultlength() / 2) {
//             counter++;
//         }

//         // Reset paddle length after 5 seconds
//         if (counter == 300) { // Assuming each iteration of your collision function represents 1/60th of a second
//             p.set_length(p.get_defaultlength());
//             counter = 0; // Reset counter
//         }





//   if (BP.getbluestatus()) {
//             BP.set_yb(BP.get_yb() - 10);
//         }

//         // Collision detection with paddle and power-up
//         if (BP.get_yb() == p.get_y() + p.get_width() && BP.get_xb() > p.get_x() && BP.get_xb() < p.get_x() + p.get_length()) {
//             speed /=2;
//             counter = 0; // Reset counter when paddle length is extended
//         }

//         // Increment counter if paddle length is doubled
//         if (default_speed > speed) {
//             counter++;
//         }

//         // Reset paddle length after 5 seconds
//         if (counter == 300) { // Assuming each iteration of your collision function represents 1/60th of a second
//             speed = 10;
//             counter = 0; // Reset counter
//         }










//  if (RP.getredstatus()) {
//             RP.set_yr(RP.get_yr() - 10);
//         }

//         // Collision detection with paddle and power-up
//         if (RP.get_yr() == p.get_y() + p.get_width() && RP.get_xr() > p.get_x() && RP.get_xr() < p.get_x() + p.get_length()) {
//             speed *=2;
//             counter = 0; // Reset counter when paddle length is extended
//         }

//         // Increment counter if paddle length is doubled
//         if (default_speed > speed) {
//             counter++;
//         }

//         // Reset paddle length after 5 seconds
//         if (counter == 300) { // Assuming each iteration of your collision function represents 1/60th of a second
//             speed = 10;
//             counter = 0; // Reset counter
//         }









//  if (YP.getyellowstatus()) {
//             YP.set_yy(YP.get_yy() - 10);
//         }

//         // Collision detection with paddle and power-up
//         if (YP.get_yy() == p.get_y() + p.get_width() && YP.get_xy() > p.get_x() && YP.get_xy() < p.get_x() + p.get_length()) {
//         if (!newballAdded) {
//         for (int i = 0; i < 2; ++i) {
//             if (newBalls[i] == nullptr) {
//                 newBalls[i] = new ball(); // Create a new ball instance
//                 newballAdded = true;
//                 counter = 0; // Reset counter
//                 break;
//             }
//         }
//     }

//     // Increment counter if a new ball is added
//     if (newballAdded) {
//         counter++;
//         if (counter >= 300) { // If 5 seconds have passed
//             for (int i = 0; i < 2; ++i) {
//                 if (newBalls[i] != nullptr) {
//                     delete newBalls[i]; // Delete the new ball instance
//                     newBalls[i] = nullptr;
//                 }
//             }
//             newballAdded = false;
//         }
//     }




    
// }
// }
