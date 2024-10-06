//============================================================================
// Name        : .cpp
// Author      : Sibt ul Hussain
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Centipede...
//============================================================================
#include"menu.h"

#include "main.cpp"


#include "ball.h"

#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;



top ma;





// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */

void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}


/*
 * Main Canvas drawing function.
 * */
int dx=200;
void GameDisplay()/**/{



string str = "Score : "+ to_string(ma.getscore());
int highscore= ma.readHighScore();
	string str3 = "HighScore : "+to_string(highscore);



	string str2 = "Your Lives :"+to_string(ma.get_lives());
	if(ma.getstatus()==false)
	{
		DrawRectangle(0,0,1020,900,colors[BLACK]);
		 DrawString(400,550,"Press Enter to start the game ",colors[WHITE]);
		 DrawString(400,475,"Press Q to quit the game",colors[WHITE]);
		
	}else if
//pause screen
(ma.checkresume() == false){
	DrawRectangle(0,0,1020,900,colors[WHITE]);
		 DrawString(400,550,"Press r to resume the game ",colors[RED]);
		 DrawString(400,475,"Press Q to quit the game",colors[RED]);
		 DrawString(400,650,str3,colors[RED]);
		 ma.setstatus(true);

}

	else{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	
	
	

	//Display Score
	
	 DrawString( 50, 875, str, colors[MISTY_ROSE]);
	 DrawString(800,850,"Ali Asjad-23i-2648 ",colors[WHITE] );
	 DrawString(50,850,str3,colors[WHITE]);
	 DrawRectangle(50,800,ma.getbarlength(),25,colors[ROYAL_BLUE]);
	 DrawString(50,50,str2,colors[WHITE]);

	//  if(ma.getbarlength() == 250)
	//  exit(1);

	if(ma.get_lives()>0){ma.display_padel();
	ma.dislay_ball();
	ma.display_bricks();
	ma.displaygreen();
	ma.displaypink();
	ma.displayblue();
	ma.displared();
	ma.displayyellow();
	ma.newball();}
	
	if (ma.getscore()==50){

		DrawRectangle(0,0,1020,900,colors[WHITE]);
		 DrawString(400,550,"Congradulations!! you Have won the Game (: ",colors[RED]);
		 DrawString(400,475,"Press Q to quit the game",colors[BLACK]);

	}

	if(ma.get_lives()==0){
		DrawRectangle(0,0,1020,900,colors[WHITE]);
		 DrawString(400,550,"uhoh All your Lives are lost ): ",colors[RED]);
		 DrawString(400,475,"Press Q to quit the game",colors[BLACK]);

	}




	
	}
	glutSwapBuffers(); // do not modify this line..

}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...
		

	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
	dx++;

	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {

	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {

	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
    if (key == 27 || key == 113) { // Escape key or Q
        exit(1); // Exit the program
    } else if (key == 13) { // Enter key
         {
            // Start the game only if it's not already started
            ma.setstatus(true);
            ma.setresume(true); // Resume the game
        }
    } else if (key == 112) { // P key
        // Show the resume screen regardless of the game status
        ma.setstatus(true);
        ma.setresume(false); // Show the resume screen
    } else if (key == 109) { // M key
        // Show the main menu regardless of the game status
        ma.setstatus(false);
        ma.setresume(true);
    } else if (key == 114) { // R key
         {
            // Pause the game only if it's currently running
            ma.setstatus(true);
            ma.setresume(true); // Show the pause screen
        }
    }
    glutPostRedisplay();
}





/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	// implement your functionality here
if (ma.getscore() == 50) {
        ma.updateHighScore(ma.getscore());}

	 if (ma.getstatus()==true && ma.checkresume() ==true ) { // Check if game is started and Enter key is pressed
        ma.newballmove();
        ma.newballcolission();
        ma.move();
        ma.collision();
    }

	
	GameDisplay();
	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(1000.0/60, Timer, 0);
	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	//cout << x << " " << y << endl;
	glutPostRedisplay();
}
// to move the padel
void MouseMoved(int x, int y) {



	ma.setPadel(x) ;
	int a = ma.getpadelx();
	
	if(x+=3)
	a+=5;

	if(x-=3)
	a-=5;

	//glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{
			cout<<"Right Button Pressed"<<endl;

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	int width = 1020, height = 900; // i have set my window size to be 800 x 600

	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("My Game "); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
