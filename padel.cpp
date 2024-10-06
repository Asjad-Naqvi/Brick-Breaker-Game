#include "padel.h"
#include"ball.h"

#include"power.h"
#include "util.h"

// default constructor for inital
Padel::Padel() : y(50),x(20),length(100),width(10),col(5){
    
}

ball b;

int Padel::get_padcol(){
    return col;
}
void Padel::set_padcol(int col){
    this ->col = col;
}

void Padel::set_x(int x) {
    this->x = x;
}

int Padel::get_x() {
    return x;
}

int Padel::get_y() {
    return y;
}
    void Padel::set_length(int length){
        this ->length = length;
    }
int Padel::get_width(){
    return width;
}
int Padel::get_length(){
    return length;
}
void Padel::drawpadel() {
    DrawRectangle(x, y, length, width, colors[col]);
}
int Padel ::get_defaultlength(){
    return defaultlength;
}

bool Padel::double_length(){
    set_length(get_length()*2);
    return true;
}

















// void Padel::collisionbricks(bricks &bricks,greenPowerUp &GP , ball&b , pinkPowerup &PP,bluePowerup&BP,redPowerup&RP,yellowPowerup&YP)  {
//     static int counter;
//     static bool newballAdded = false;
//     static ball* newBalls[2]; 

//     for (int i = 0; i < 12; i++) {
//         if (bricks.greenActive[i] &&
//            b.get_x()  >= bricks.greenX[i] && b.get_x() <= bricks.greenX[i] + bricks.get_length() &&
//             b.get_y() >= bricks.greenY[i] && b.get_y() <= bricks.greenY[i] + bricks.get_width()) {
           
//            bricks.greenActive[i] = false;
//            if(bricks.greenActive[i]==false){
//             b.set_score(b.get_score()+1);
//            }
            
             
            

//             GP.set_xg(bricks.greenX[i]);
//             GP.set_yg(bricks.greenY[i]);

//             if (GP.get_xg() == bricks.greenX[5] && GP.get_yg() == bricks.greenY[5] && bricks.greenActive[5] == false) {
//                 GP.setGreenstatus(true);
//                 GP.display();

               
//             }
     

//             b.set_color(31) ;
//             // Set color
//             b.setspeed(-b.get_speed()) ;
//             break;
//         }

//         // Decrement green triangle's yg
       
    

//     // Check if the green triangle has reached the bottom of the screen
   
        
//         // Collision with red bricks
//         if (bricks.redActive[i] &&
//             b.get_x() >= bricks.redX[i] && b.get_x() <= bricks.redX[i] + bricks.get_length() &&
//             b.get_y() >= bricks.redY[i] && b.get_y() <= bricks.redY[i] + bricks.get_width()) {
                
//             bricks.redcollisions[i] -= 1;
//             b.set_color(5) ;
            

//             if (bricks.redcollisions[i] == 0)
//                 bricks.redActive[i] = false;
//             if (bricks.redActive[i] == false)
//                 b.set_score(b.get_score()+1);
//                 b.setbar_len(b.getbar_len()+10);
                
                
//                 RP.set_xr(bricks.redX[i]);
//             RP.set_yr(bricks.redY[i]);

//             if (RP.get_xr() == bricks.redX[5] && RP.get_yr() == bricks.redY[5] && bricks.redActive[5] == false) {
//                 RP.setredstatus(true);
//                 RP.displayred();

               
//             } // Brick vanishes if no collisions left
            
//             b.setspeed(-b.get_speed()) ;
//             break;
//         }
        
//         // Collision with pink bricks
//         if (bricks.pinkActive[i] &&
//             b.get_x() >= bricks.pinkX[i] && b.get_x() <= bricks.pinkX[i] + bricks.get_length() &&
//             b.get_y() >= bricks.pinkY[i] && b.get_y() <= bricks.pinkY[i] + bricks.get_width()) {
            
//             //bar_len += 10;
//             bricks.pinkcollisions[i] -= 1;
//             b.set_color(91);

//             if (bricks.pinkcollisions[i] == 0)
//                 bricks.pinkActive[i] = false; 
//                 if(bricks.pinkActive[i]==false)
//                 {b.set_score(b.get_score()+1);}// Brick vanishes if no collisions left
//                 b.setbar_len(b.getbar_len()+10);



//  PP.set_xp(bricks.pinkX[i]);//pink powerup
//             PP.set_yp(bricks.pinkY[i]);

//             if (PP.get_xp() == bricks.pinkX[5] && PP.get_yp() == bricks.pinkY[5] && bricks.pinkActive[5] == false) {
//                 PP.setpinkstatus(true);
//                 PP.displaypink();




//             }

            
//             b.setspeed(-b.get_speed()) ;
//             break;
//         }



        
//         // Collision with yellow bricks
//         if (bricks.yellowActive[i] &&
//             b.get_x() >= bricks.yellowX[i] && b.get_x() <= bricks.yellowX[i] + bricks.get_length() &&
//             b.get_y() >= bricks.yellowY[i] && b.get_y() <= bricks.yellowY[i] + bricks.get_width()) {
            
//             b.setbar_len(b.getbar_len()+10);//bar on top
//             bricks.yellowcollisions[i] -= 1;
//             b.set_color(23);

//             if (bricks.yellowcollisions[i] == 0)
//                 bricks.yellowActive[i] = false;
//                 if(bricks.yellowActive[i]==0)
//                  {b.set_score(b.get_score()+1);}// Brick vanishes if no collisions left
            



// YP.set_xy(bricks.yellowX[i]);//pink powerup
//             YP.set_yy(bricks.yellowY[i]);

//             if (YP.get_xy() == bricks.yellowX[5] && YP.get_yy() == bricks.yellowY[5] && bricks.yellowActive[5] == false) {
//                 YP.setyellowstatus(true);
//                 YP.displayyellow();

//             }






//             b.setspeed(-b.get_speed()) ;
//             break;
//         }
        
//         // Collision with blue bricks
//         if (bricks.blueActive[i] &&
//             b.get_x() >= bricks.blueX[i] && b.get_x() <= bricks.blueX[i] + bricks.get_length() &&
//             b.get_y() >= bricks.blueY[i] && b.get_y() <= bricks.blueY[i] + bricks.get_width()) {
            
//             b.setbar_len(b.getbar_len()+10);
//             bricks.bluecollisions[i] -= 1;
//             b.set_color(28);

//             if (bricks.bluecollisions[i] == 0)
//                 bricks.blueActive[i] = false; 
//             if(bricks.blueActive[i]==false){
//                 b.set_score(b.get_score()+1);
//             }


// BP.set_xb(bricks.blueX[i]);// powerup
//             BP.set_yb(bricks.blueY[i]);

//             if (BP.get_xb() == bricks.blueX[5] && BP.get_yb() == bricks.blueY[5] && bricks.blueActive[5] == false) {
//                 BP.setbluestatus(true);
//                 BP.displayblue();




//             }
















//             b.setspeed(-b.get_speed()) ;
//             break;
//         }
        
//         // Decrement green triangle's yg
        
//     }
//            if (GP.Greenstatus()) {
//             GP.set_yg(GP.get_yg() - 10);
//         }

//         // Collision detection with paddle and power-up
//         if (GP.get_yg() == y + width && GP.get_xg() > x && GP.get_xg() < x + length) {
//             set_length(get_length() * 2);
//             counter = 0; // Reset counter when paddle length is extended
//         }

//         // Increment counter if paddle length is doubled
//         if (get_length() == get_defaultlength() * 2) {
//             counter++;
//         }

//         // Reset paddle length after 5 seconds
//         if (counter == 300) { // Assuming each iteration of your collision function represents 1/60th of a second
//             set_length(get_defaultlength());
//             counter = 0; // Reset counter
//         }




//           if (PP.getpinkstatus()) {
//             PP.set_yp(PP.get_yp() - 10);
//         }

//         // Collision detection with paddle and power-up
//         if (PP.get_yp() == y + width && PP.get_xp() > x && PP.get_xp() < x + length) {
//             set_length(get_length() / 2);
//             counter = 0; // Reset counter when paddle length is extended
//         }

//         // Increment counter if paddle length is doubled
//         if (get_length() == get_defaultlength() / 2) {
//             counter++;
//         }

//         // Reset paddle length after 5 seconds
//         if (counter == 300) { // Assuming each iteration of your collision function represents 1/60th of a second
//             set_length(get_defaultlength());
//             counter = 0; // Reset counter
//         }





//   if (BP.getbluestatus()) {
//             BP.set_yb(BP.get_yb() - 10);
//         }

//         // Collision detection with paddle and power-up
//         if (BP.get_yb() == y + width && BP.get_xb() > x && BP.get_xb() < x + length) {
//             b.setspeed(b.get_speed()/2);
//             counter = 0; // Reset counter when paddle length is extended
//         }

//         // Increment counter if paddle length is doubled
//         if (b.get_defspeed() > b.get_speed()) {
//             counter++;
//         }

//         // Reset paddle length after 5 seconds
//         if (counter == 300) { // Assuming each iteration of your collision function represents 1/60th of a second
//             b.setspeed(10);
//             counter = 0; // Reset counter
//         }










//  if (RP.getredstatus()) {
//             RP.set_yr(RP.get_yr() - 10);
//         }

//         // Collision detection with paddle and power-up
//         if (RP.get_yr() == y + width && RP.get_xr() > x && RP.get_xr() < x + length) {
//             b.setspeed(b.get_speed()/2);
//             counter = 0; // Reset counter when paddle length is extended
//         }

//         // Increment counter if paddle length is doubled
//         if (b.get_defspeed() > b.get_speed()) {
//             counter++;
//         }

//         // Reset paddle length after 5 seconds
//         if (counter == 300) {
//              // Assuming each iteration of your collision function represents 1/60th of a second
//             b.setspeed(10);
//             counter = 0; // Reset counter
//         }









//  if (YP.getyellowstatus()) {
//             YP.set_yy(YP.get_yy() - 10);
//         }

//         // Collision detection with paddle and power-up
//         if (YP.get_yy() == y + width && YP.get_xy() > x && YP.get_xy() < x + length) {
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
//}
