#include "util.h"
#include"bricks.h"
#include "padel.h"
#include"power.h"
#include"ball.h"


bricks::bricks() {
    
    
    for (int i = 0; i < 12; i++) {
        lives = 3;
        greenX[i] = 50 + i * 80;
        greenY[i] = 750;
        redX[i] = 50 + i * 80;
        redY[i] = 700;
        pinkX[i] = 50 + i * 80;
        pinkY[i] = 650;
        yellowX[i] = 50 + i * 80;
        yellowY[i] = 600;
        blueX[i] = 50 + i * 80;
        blueY[i] = 550;
        
        // Initialize all bricks as active
        blueActive[i] = true;
        greenActive[i] = true;
        redActive[i] = true;
        pinkActive[i] = true;
        yellowActive[i] = true;
        bluecollisions[i] = 3;
        redcollisions[i] = 3;
        yellowcollisions[i] = 3;
    pinkcollisions[i] = 3;

    }
   

}







    void bricks:: set_length(int length){
        this ->length = length;

    }
int bricks:: get_length(){
    return length;
}

    void bricks:: set_width(int width){
        this ->width = width;

    }
int bricks:: get_width(){
    return width;
}
void bricks::activateAllBricks() {
    for (int i = 0; i < 12; i++) {
        greenActive[i] = true;
        redActive[i] = true;
        pinkActive[i] = true;
        yellowActive[i] = true;
        blueActive[i] = true;
    }
}

















void bricks::display() {
    int colorindex;
    srand(time(0));
    int arr[5] = {5,31,68,23,91}; 

    for (int i = 0; i < 12; i++) {
        if (greenX[i] != -1 && greenActive[i]) {
            
            DrawRectangle(greenX[i], greenY[i], length, width, colors[arr[rand()%5]]);
        }
    }
    for (int i = 0; i < 12; i++){
        if (redX[i] != -1 && redActive[i]) {
            DrawRectangle(redX[i], redY[i], length, width, colors[arr[rand()%5]]);
        }}

        for (int i = 0; i < 12; i++){
            if (pinkX[i] != -1 && pinkActive[i]) {
            DrawRectangle(pinkX[i], pinkY[i], length, width, colors[arr[rand()%5]]);
        }}
       
        
        for(int i=0;i<12;i++){
             if (yellowX[i] != -1 && yellowActive[i]) {
            DrawRectangle(yellowX[i], yellowY[i], length, width, colors[arr[rand()%5]]);
        }
        }
       for(int i= 0;i< 12;i++){
        if (blueX[i] != -1 && blueActive[i]) {
            DrawRectangle(blueX[i], blueY[i], length, width, colors[arr[rand()%5]]);
        }
       }
        
    
}







// void bricks::display() {
//     int colorindex;
//     srand(time(0));
//     int arr[5] = {5,31,68,23,91}; 

//     for (int i = 0; i < 12; i++) {
//         if (greenX[i] != -1 && greenActive[i]) {
            
//             DrawRectangle(greenX[i], greenY[i], length, width, colors[GREEN]);
//         }
//     }
//     for (int i = 0; i < 12; i++){
//         if (redX[i] != -1 && redActive[i]) {
//             DrawRectangle(redX[i], redY[i], length, width, colors[RED]);
//         }}

//         for (int i = 0; i < 12; i++){
//             if (pinkX[i] != -1 && pinkActive[i]) {
//             DrawRectangle(pinkX[i], pinkY[i], length, width, colors[PINK]);
//         }}
       
        
//         for(int i=0;i<12;i++){
//              if (yellowX[i] != -1 && yellowActive[i]) {
//             DrawRectangle(yellowX[i], yellowY[i], length, width, colors[YELLOW]);
//         }
//         }
//        for(int i= 0;i< 12;i++){
//         if (blueX[i] != -1 && blueActive[i]) {
//             DrawRectangle(blueX[i], blueY[i], length, width, colors[BLUE]);
//         }
//        }
        
    
// }









//WHERE ALL THE MAGIC IS HAPPENING
void bricks :: collisionbricks(Padel &p,greenPowerUp &GP , ball & b , pinkPowerup &PP,bluePowerup&BP,redPowerup&RP,yellowPowerup&YP)  {



static int counter;
   

    for (int i = 0; i < 12; i++) {
        if (greenActive[i] &&
           b.get_x()  >= greenX[i] && b.get_x() <= greenX[i] + get_length() &&
            b.get_y() >= greenY[i] && b.get_y() <= greenY[i] + get_width()) {
           
           greenActive[i] = false;
           if(greenActive[i]==false){
            b.set_score(b.get_score()+1);
           }
            
             
            

            GP.set_xg(greenX[i]);
            GP.set_yg(greenY[i]);

            if (GP.get_xg() == greenX[5] && GP.get_yg() == greenY[5] && greenActive[5] == false) {
                GP.setGreenstatus(true);
                GP.display();

               
            }
     

            b.set_color(31) ;
            // Set color
            b.setspeed(-(b.get_speed())) ;
            break;
        }

        // Decrement green triangle's yg
       
    

    // Check if the green triangle has reached the bottom of the screen
   
        
        // Collision with red bricks
        if (redActive[i] &&
            b.get_x() >= redX[i] && b.get_x() <= redX[i] + length &&
            b.get_y() >= redY[i] && b.get_y() <= redY[i] + width) {
                
            redcollisions[i] -= 1;
            b.set_color(5) ;
            

            if (redcollisions[i] == 0)
                redActive[i] = false;
            if (redActive[i] == false)
                b.set_score(b.get_score()+1);
                b.setbar_len(b.getbar_len()+10);
                
                
                RP.set_xr(redX[i]);
            RP.set_yr(redY[i]);

            if (RP.get_xr() == redX[5] && RP.get_yr() == redY[5] && redActive[5] == false) {
                RP.setredstatus(true);
                RP.displayred();

               
            } // Brick vanishes if no collisions left
            
            b.setspeed(-b.get_speed()) ;
            break;
        }
        
        // Collision with pink bricks
        if (pinkActive[i] &&
            b.get_x() >= pinkX[i] && b.get_x() <= pinkX[i] +length &&
            b.get_y() >= pinkY[i] && b.get_y() <= pinkY[i] + width) {
            
            //bar_len += 10;
            pinkcollisions[i] -= 1;
            b.set_color(91);

            if (pinkcollisions[i] == 0)
                pinkActive[i] = false; 
                if(pinkActive[i]==false)
                {b.set_score(b.get_score()+1);}// Brick vanishes if no collisions left
                b.setbar_len(b.getbar_len()+10);



 PP.set_xp(pinkX[i]);//pink powerup
            PP.set_yp(pinkY[i]);

            if (PP.get_xp() == pinkX[5] && PP.get_yp() == pinkY[5] && pinkActive[5] == false) {
                PP.setpinkstatus(true);
                PP.displaypink();




            }

            
            b.setspeed(b.get_speed());//speed
            break;
        }



        
        // Collision with yellow bricks
        if (yellowActive[i] &&
            b.get_x() >= yellowX[i] && b.get_x() <= yellowX[i] + length &&
            b.get_y() >= yellowY[i] && b.get_y() <= yellowY[i] + width) {
            
            b.setbar_len(b.getbar_len()+10);//bar on top
            yellowcollisions[i] -= 1;
            b.set_color(23);

            if (yellowcollisions[i] == 0)
                yellowActive[i] = false;
                if(yellowActive[i]==0)
                 {b.set_score(b.get_score()+1);}// Brick vanishes if no collisions left
            



YP.set_xy(yellowX[i]);//pink powerup
            YP.set_yy(yellowY[i]);

            if (YP.get_xy() == yellowX[5] && YP.get_yy() == yellowY[5] && yellowActive[5] == false) {
                YP.setyellowstatus(true);
                YP.displayyellow();

            }






            b.setspeed(-b.get_speed()) ;
            break;
        }
        
        // Collision with blue bricks
        if (blueActive[i] &&
            b.get_x() >= blueX[i] && b.get_x() <= blueX[i] + length &&
            b.get_y() >= blueY[i] && b.get_y() <= blueY[i] +width) {
            
            b.setbar_len(b.getbar_len()+10);
        bluecollisions[i] -= 1;
            b.set_color(68);

            if (bluecollisions[i] == 0)
                blueActive[i] = false; 
            if(blueActive[i]==false){
                b.set_score(b.get_score()+1);
            }


BP.set_xb(blueX[i]);// powerup
            BP.set_yb(blueY[i]);

            if (BP.get_xb() == blueX[5] && BP.get_yb() == blueY[5] && blueActive[5] == false) {
                BP.setbluestatus(true);
                BP.displayblue();




            }
















            b.setspeed(-b.get_speed()) ;
            break;
        }
        
        // Decrement green triangle's yg
        
    }
           if (GP.Greenstatus()) {
            GP.set_yg(GP.get_yg() - 10);
        }

        // Collision detection with paddle and power-up
        if (GP.get_yg() == p.get_y() + p.get_width() && GP.get_xg() > p.get_x() && GP.get_xg() < p.get_x() + p.get_length()) {
           p. set_length(p.get_length()*2);
            counter = 0; // Reset counter when paddle length is extended
        }
        

        // Increment counter if paddle length is doubled
        if (p.get_length() == p.get_defaultlength() * 2) {
            counter++;
        }
        

        // Reset paddle length after 5 seconds
        if (counter == 300) { // Assuming each iteration of your collision function represents 1/60th of a second
            p.set_length(p.get_defaultlength());
            counter = 0; // Reset counter
        }
        

        




          if (PP.getpinkstatus()) {
            PP.set_yp(PP.get_yp() - 10);
        }

        // Collision detection with paddle and power-up
        if (PP.get_yp() == p.get_y() + p.get_width() && PP.get_xp() > p.get_x() && PP.get_xp() < p.get_x() + p.get_length()) {
            p.set_length(p.get_length() / 2);
            counter = 0; // Reset counter when paddle length is extended
        }

        // Increment counter if paddle length is doubled
        if (p.get_length() == p.get_defaultlength() / 2) {
            counter++;
        }

        // Reset paddle length after 5 seconds
        if (counter == 300) { // Assuming each iteration of your collision function represents 1/60th of a second
            p.set_length(p.get_defaultlength());
            counter = 0; // Reset counter
        }















  if (BP.getbluestatus()) {
            BP.set_yb(BP.get_yb() - 10);
        }

        // Collision detection with paddle and power-up
        if (BP.get_yb() == p.get_y() + p.get_width() && BP.get_xb() > p.get_x() && BP.get_xb() < p.get_x() + p.get_length()) {
            b.setspeed(b.get_speed()/2);
            counter = 0; // Reset counter when paddle length is extended
        }

        // Increment counter if paddle length is doubled
        if (b.get_defspeed() > b.get_speed()) {
            counter++;
        }

        // Reset paddle length after 5 seconds
        if (counter == 300) { // Assuming each iteration of your collision function represents 1/60th of a second
            b.setspeed(10);
            counter = 0; // Reset counter
        }










 if (RP.getredstatus()) {
            RP.set_yr(RP.get_yr() - 10);
        }

        // Collision detection with paddle and power-up
        if (RP.get_yr() == p.get_y() + p.get_width() && RP.get_xr() > p.get_x() && RP.get_xr() < p.get_x() + p.get_length()) {
            b.setspeed(b.get_speed()*2);
            counter = 0; // Reset counter when paddle length is extended
        }

        // Increment counter if paddle length is doubled
        if (b.get_defspeed() > b.get_speed()) {
            counter++;
        }

        // Reset paddle length after 5 seconds
        if (counter == 300) {
             // Assuming each iteration of your collision function represents 1/60th of a second
            b.setspeed(10);
            counter = 0; // Reset counter
        }









 if (YP.getyellowstatus()) {
            YP.set_yy(YP.get_yy() - 10);
        }

        // Collision detection with paddle and power-up
        if (YP.get_yy() == p.get_y() + p.get_width() && YP.get_xy() > p.get_x() && YP.get_xy() < p.get_x() + p.get_length()) {
        YP.setnewBallstatus(true);
        counter= 0; 
       
    

    // Increment counter if a new ball is added
    if (YP.getnewBallstatus()) 
    {
        counter++;
        if (counter >= 300) { // If 5 seconds have passed
          
            YP.setnewBallstatus(false);
        }
    }




    
}









}

