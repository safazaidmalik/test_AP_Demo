//============================================================================
// Name        : game.cpp
// Author      : Hassan Mustafa
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Dodge 'Em...
//============================================================================

#ifndef DODGE_CPP_
#define DODGE_CPP_
#include "util.h"
#include <iostream>
#include<string>
#include<time.h>
#include<stdlib.h>
#include<cmath> // for basic math functions such as cos, sin, sqrt
#include<fstream>
using namespace std;


bool levelUp = 0;	// for checking when to increment level
int level;
float* sBoxcolor = colors[GOLD];
int l_box=20;
int h_box=10;
int high_Score[10];
int score=0;
int lives=3;
float ox=435;	//opponent's x coordinate
float oy=640;	//opponent's y coordinate
float px= 180;	//player's x coordinate
float py = 180;	//player's y coordinate
float o2x= 1000;	//second opponent's x coordinate
float o2y = 1000;//second opponent's y coordinate
int o2direction; //second opponent direction
int p_speedFactor=1;
int o_speedFactor=1;
float vPlayer=3;	//velocity of player
float vOpp=1;	//velocity of opponent
float v2Opp=1;	//velocity of opponent 2
float oPrevDirection;	//stores previous direction of opponent
float o2PrevDirection;	//stores previous direction of opponent 2
bool oCounting=0;	//flag for opponent turning
int oCounter=0;		//road switching timer for opponent 2
bool o2Counting=0;	//flag for opponent 2 turning
int o2Counter=0;		//road switching timer for opponent
float pPrevDirection;	//stores previous direction of player
bool pCounting=0;	//flag for arrow key detection
int pCounter=0;		//road switching timer for player
float playerDirection=1;	//gives angle of the player
float oppDirection=3;	//gives angle of the opponent
float opp2Direction=3;	//gives angle of the opponent
float width = 10;
float height = 9;
float radius = 3.5f;
int x_pos=0;	//variable for gift box's x position
int y_pos=0; 	//variable for gift box's y position
float* removeColor= colors[BLACK];
bool flag[64] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};	//flag for gift boxes

int boxCoord[64][2]={{790,670},{720,670},{650,670},{580,670},{790,600},{720,600},{650,600},{580,600},{790,530},{720,530},{650,530},{580,530},{790,460},{720,460},{650,460},{580,460},{790,245},{720,245},{650,245},{580,245},{790,175},{720,175},{650,175},{580,175},{790,105},{720,105},{650,105},{580,105},{790,35},{720,35},{650,35},{580,35},{30,670},{100,670},{170,670},{240,670},{30,600},{100,600},{170,600},{240,600},{30,530},{100,530},{170,530},{240,530},{30,460},{100,460},{170,460},{240,460},{30,245},{100,245},{170,245},{240,245},{30,175},{100,175},{170,175},{240,175},{30,105},{100,105},{170,105},{240,105},{30,35},{100,35},{170,35},{240,35}};

char printableKey='m';
char speedenUp = 'x';	//variable to recognize space bar to speeden up 
bool livesCheck= 1;
bool partialReset=0;
int resetCounter=0; 	//holds maximum value, after which it is made 0 again.
bool speedingFlag=0;
bool randomFlag=1;	//initialized true to allow random setting of opponent only once
string scoreString;
string livesString;
int roadway=0;		//Roadway number increases from inside to outside   (e.g. center most roadway is numbered 1)
int oPathway=0;		//Opponent's roadway returned by function RoadwayCount is stored here.
int o2Pathway=0;	//2nd Opponent's roadway returned by function RoadwayCount is stored here.
int pPathway=0;		//Player's roadway returned by function RoadwayCount is stored here.


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
//Board *b;






//function for initialising opponent to a random position
//...............................................................................
//float OpponentInitialiser(float intial_ox, float initial_oy){




//Function for determining level


//This function is called for determining which roadways player and opponent are respectively

int RoadwayCount(float pos_x, float pos_y){
	if((abs(pos_x-415)<= 180 ) && (abs(pos_y-355)<= 120 )){
		roadway=1;
	}
	else if((abs(pos_x-415)<= 250 ) && (abs(pos_y-355)<= 190 )){
		roadway=2;
	}
	else if((abs(pos_x-415)<= 320 ) && (abs(pos_y-355)<= 260 )){
		roadway=3;
	}
	else if((abs(pos_x-415)<= 390 ) && (abs(pos_y-355)<= 330 )){
		roadway=4;
	}
	return roadway;
}
//.....................................


void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors

	// calling some functions from util.cpp file to help students

	//Square at 400,20 position
	//DrawSquare( 400 , 20 ,40,colors[RED]); 
	//Square at 250,250 position
	//DrawSquare( 250 , 250 ,80,colors[GREEN]); 
	//Display Score
	//DrawString( 50, 800, "Score=0", colors[MISTY_ROSE]);
	//Triangle at 300, 450 position
	//DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[MISTY_ROSE] ); 
	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
	//Circle at 50, 670 position
	//DrawCircle(50,670,10,colors[RED]);
	//Line from 550,50 to 550,480 with width 10
	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	//DrawLine( 550 , 50 ,  550 , 480 , 10 , colors[MISTY_ROSE] );	


//showing screen when player looses
   if(livesCheck==0 && printableKey=='x'){
	 	DrawString( 300 , 550 , "GAME OVER!!",colors[SKY_BLUE]);
	 	DrawString( 300 , 400 , "Your Score: "+scoreString ,colors[SKY_BLUE]);
		DrawString(640, 150, " m = Main Menu", colors[GREEN]);
		DrawString(640, 110, " esc = Exit game", colors[GREEN]);
   }
  
   if(levelUp==1){
	level = level + 1;    //incrementing level
//	cout<< "1.  Level = "<<level<<endl;
	if(level==5)
		printableKey='w'; //setting canvas to show victory

   }

  if (printableKey =='w'){
	DrawString( 300 , 550 , "YOU WON!!",colors[SKY_BLUE]);
 	DrawString( 300 , 400 , "Your Score: "+scoreString ,colors[SKY_BLUE]);
	DrawString(640, 150, " m = Main Menu", colors[GREEN]);
	DrawString(640, 110, " esc = Exit game", colors[GREEN]);
   }

	
//original menu
  if(printableKey=='m'){
	DrawString( 60 , 720 , "1. Start a new game	  (press  n)",colors[SKY_BLUE]);
	DrawString( 60 , 660 , "2. See high-scores	  (press  s)",colors[SKY_BLUE]);
	DrawString( 60 , 600 , "3. Help	  (press  h)",colors[SKY_BLUE]);
	DrawString( 60 , 540 , "4. Exit	  (press  esc)",colors[SKY_BLUE]);
   }


//showing screen for HELP option

   else if(printableKey=='h'){

		DrawString( 360 , 780 , "GAME INSTRUCTIONS:",colors[GREEN]);
		DrawString( 60 , 640 , "Your goal is to collect maximum yellow gift-boxes whilst avoiding crashing into the opponent brown car. At each crash,",colors[GOLD]);
		DrawString( 60 , 600 , "one out of total 3 lives is lost. Use arrow keys to switch roadways at gaps in the roadways. Press space bar to speeden",colors[GOLD]);
		DrawString( 60 , 560 , "up your pace.", colors[GOLD]);
		DrawString( 60 , 400 , "GOOD LUCK!       [Press 'c' to start your game]",colors[GOLD]);
   }

//option for showing score
   else if (printableKey=='s'){
		//reading from a file
		string score1;
		ifstream fin ("high score.txt"); //name of the file it is supposed to read
		if (fin.is_open())
		{
			int lineCount=0;
			DrawString( 360, 600 , "HIGH SCORES ", colors[GREEN]);
			while ( getline (fin, score1) ) //this loop will run depending on the number of lines in the file
			{
				if(lineCount==9){
					DrawString( 360, 500 - 30*lineCount, to_string(lineCount+1)+ "  " + score1, colors[GOLD]);
			  	}
				else{
				DrawString( 360, 500 - 30*lineCount, to_string(lineCount+1)+ "    " + score1, colors[GOLD]);
				lineCount++;
				}
			}
			fin.close();
		}
		
		else 
			cout << "Unable to open file"; 
   }


//showing screen when new game starts
   else if(printableKey=='n'){		//reset all values to how they were initialized globally


	//random initialisation of opponent and direction setting
	InitRandomizer();
	int oppSection = GetRandInRange(1,3);
	if(oppSection==1){
		ox=40;
		oy = GetRandInRange(40,600);
		oppDirection = 3;
	}
	if(oppSection==2){
		ox = GetRandInRange(40,790);
		oy= 40;
		oppDirection = 0;
	}
	
	if(oppSection==3){
		ox=790;
		oy = GetRandInRange(40,600);
		oppDirection = 1;
	}


	levelUp = 0;	// for checking when to increment level
	level=1;
	sBoxcolor = colors[GOLD];
	l_box=20;
	h_box=10;
	high_Score[10];
	score=0;
	px=435;	//opponent's x coordinate
	py=665;	//opponent's y coordinate
	p_speedFactor=1;
	o_speedFactor=1;
	vPlayer=2;	//velocity of player
	vOpp=2;	//velocity of opponent
	oPrevDirection;	//stores previous direction of opponent
	oCounting=0;	//flag for opponent turning
	oCounter=0;		//road switching timer for opponent
	pPrevDirection;	//stores previous direction of player
	pCounting=0;	//flag for arrow key detection
	pCounter=0;		//road switching timer for player
	playerDirection=0;	//gives angle of the player
	width = 10;
	height = 9;
	radius = 3.5f;
	x_pos=0;	//variable for gift box's x position
	y_pos=0; 	//variable for gift box's y position
	removeColor= colors[BLACK];

//reprinting gift-boxes
	for(int i=0; i<64; i++){	
		flag[i] = 1;
	}

	printableKey='c';
	lives=3;
	speedenUp = 'x';	//variable to recognize space bar to speeden up 
	livesCheck= 1;
	partialReset=0;
	resetCounter=0; 	//holds maximum value of 6, after which it is made 0 again.
	speedingFlag=0;
	randomFlag=1;	//initialized true to allow random setting of opponent only once
	scoreString;
	livesString;
	roadway=0;		//Roadway number increases from inside to outside   (e.g. center most roadway is numbered 1)
	oPathway=0;		//Opponent's roadway returned by function RoadwayCount is stored here.
	pPathway=0;		//Player's roadway returned by function RoadwayCount is stored here.



   }


///////////////////////////////////////////////////


   else if(printableKey=='p'){
	DrawString( 360 , 780 , "GAME PAUSED",colors[GREEN]);
	DrawString( 60 , 720 , "1) Start a new game	(Press 'n')",colors[GREEN]);
	DrawString( 60 , 660 , "2) See high-scores	(Press 's')",colors[GREEN]);
	DrawString( 60 , 600 , "3) Help		(Press 'h')",colors[GREEN]);
	DrawString( 60 , 540 , "4) Exit		(Press 'esc')",colors[GREEN]);
	DrawString( 60 , 480 , "5) Continue	(Press 'c')",colors[GREEN]);
   }


   else if(printableKey=='c'){

//        InitRandomizer();
//        ox= GetRandInRange(long &ox_min,long &ox_max)
//        oy= GetRandInRange(long &oy_min,long &oy_max)


	scoreString = to_string(score);		//showing updated score
	DrawString( 60, 780, "Score : "+scoreString, colors[GREEN]);

	livesString = to_string(lives);		//showing updated lives
	DrawString( 240, 780, "Lives : "+livesString, colors[GREEN]);
	DrawString( 390, 780, "Level : "+to_string(level), colors[GREEN]);

	DrawSquare( 640 , 820 ,7,colors[GREEN]);
	DrawString( 650, 820, "p = Pause", colors[GREEN]);
	DrawSquare( 640 , 760 ,7,colors[GREEN]);
	DrawString( 650, 760, "esc = Exit", colors[GREEN]);
	

// Drawing opponent car
	//moving car counter-clockwise

		if(oCounting==0 && oy-1<ox && oppDirection==3){		//for bottom left corner
			oppDirection=0;			//to turn right when edge is reached
		}

		if(oCounting==0 && ox+1>840-oy && oppDirection==0){	//for bottom right corner
			oppDirection=1;			//to turn up when edge is reached
		}

		if(oCounting==0 && oy+1>ox-130 && oppDirection==1){	//for top right corner
			oppDirection=2;			//to turn down when edge is reached
		}

		if(oCounting==0 && ox-1<710-oy && oppDirection==2){	//for top left corner
			oppDirection=3;			//to turn down when edge is reached
		}

		if(oCounting==1){
			oCounter+=vOpp*o_speedFactor;
		}
		if(oCounter>=72){		// 70 is spacing between each roadway
			oCounting=0;		//oCounting flag is set false to enable oppenet's AI again
			oCounter=0;		
			oppDirection=oPrevDirection;		//sets direction back to anti-clockwise
		}


	ox+=vOpp*o_speedFactor*cos(oppDirection*1.5708);	// multiply with pi/2
	oy+=vOpp*o_speedFactor*sin(oppDirection*1.5708);	// multiply with pi/2
//	cout<<"oCounting = "<<oCounting<<endl;
//	cout<<"Opponent direction= "<<oppDirection<<endl;


//drawing opponent car

	float* color1 = colors[BLUE]; 
	radius = 3.5;
	float oxLocation=ox-20; //new variables formed by using its center coordinates
	float oyLocation=oy-20;
	
	DrawRoundRect(oxLocation, oyLocation, width, height, color1,radius); // bottom left tyre
	DrawRoundRect(oxLocation+width*3, oyLocation, width, height, color1,radius); // bottom right tyre
	DrawRoundRect(oxLocation+width*3, oyLocation+height*4, width, height, color1,radius); // top right tyre
	DrawRoundRect(oxLocation, oyLocation+height*4, width, height, color1,radius); // top left tyre
	DrawRoundRect(oxLocation, oyLocation+height*2, width,  height, color1, radius/2); // body left rect
	DrawRoundRect(oxLocation+width, oyLocation+height, width*2, height*3, color1, radius/2); // body center rect
	DrawRoundRect(oxLocation+width*3, oyLocation+height*2, width, height, color1, radius/2); // body right rect*/

// Drawing player's car
	//moving player clockwise	

		if(py<300 && px-1<py && playerDirection==2){	//for bottom left corner
			playerDirection=1;
		}
	
		if(py<300 && py-1<830-px && playerDirection==3  && px>520){	//for bottom right corner
			playerDirection=2;
		}

		if(py>400 && px+1>py +120 && playerDirection==0){	//for top right corner
			playerDirection=3;
		}

		if(py>400 && py+1> 710-px && playerDirection==1 && px<300){	//for top left corner
			
			playerDirection=0;
		}
		




	
		// after all collisions inequalities for player
		if(pCounting==1){
			pCounter+=vPlayer;
		}
		if(pCounter>=72){		// 70 is spacing between each roadway
			pCounting=0;		//pCounting flag is false to enable arrow keys again
			pCounter=0;		
			playerDirection=pPrevDirection;		//sets direction back to clockwise
		}
//Updating positions of player

		px+=vPlayer*p_speedFactor*cos(playerDirection*1.5708);	// multiply with pi/2	
		py+=vPlayer*p_speedFactor*sin(playerDirection*1.5708);	// multiply with pi/2

		if(level == 3)
			o_speedFactor =2;
		if(level ==4){
			o_speedFactor =1;


// creating a second opponent car
		   if(levelUp ==1){
				InitRandomizer();
				int opp2Section = (GetRandInRange(0,2) +2) %3;	//producing a different pseudo-random from original opponent 
				if(opp2Section==1){
					o2x=40;
					o2y = GetRandInRange(40,600);
					opp2Direction = 3;
				}
				if(opp2Section==2){
					o2x =  GetRandInRange(40,790);
					o2y= 40;
					opp2Direction = 0;
				}
				
				if(opp2Section==0){
					o2x=790;
					o2y = GetRandInRange(40,600) ;
					opp2Direction = 1;
				}
		  }

						
	// Drawing opponent 2 car
		//moving car counter-clockwise

			if(o2Counting==0 && o2y-1<o2x && opp2Direction==3){		//for bottom left corner
				opp2Direction=0;			//to turn right when edge is reached
			}

			if(o2Counting==0 && o2x+1>840-o2y && opp2Direction==0){	//for bottom right corner
				opp2Direction=1;			//to turn up when edge is reached
			}

			if(o2Counting==0 && o2y+1>o2x-130 && opp2Direction==1){	//for top right corner
				opp2Direction=2;			//to turn down when edge is reached
			}

			if(o2Counting==0 && o2x-1<710-o2y && opp2Direction==2){	//for top left corner
				opp2Direction=3;			//to turn down when edge is reached
			}

			if(o2Counting==1){
				o2Counter+=v2Opp;
			}
			if(o2Counter>=72){		// 70 is spacing between each roadway
				o2Counting=0;		//oCounting flag is set false to enable oppenet's AI again
				o2Counter=0;		
				opp2Direction=o2PrevDirection;		//sets direction back to anti-clockwise
			}


		o2x+=v2Opp*cos(opp2Direction*1.5708);	// multiply with pi/2
		o2y+=v2Opp*sin(opp2Direction*1.5708);	// multiply with pi/2
	//	cout<<"o2Counting = "<<oCounting<<endl;
	//	cout<<"Opponent 2 direction= "<<oppDirection<<endl;


//drawing 2nd opponent car using its center coordinates

	float* color2 = colors[BLUE]; 
	radius = 3.5;
	float o2xLocation=o2x-20;	//
	float o2yLocation=o2y-20;
	
	DrawRoundRect(o2xLocation, o2yLocation, width, height, color1,radius); // bottom left tyre
	DrawRoundRect(o2xLocation+width*3, o2yLocation, width, height, color1,radius); // bottom right tyre
	DrawRoundRect(o2xLocation+width*3, o2yLocation+height*4, width, height, color1,radius); // top right tyre
	DrawRoundRect(o2xLocation, o2yLocation+height*4, width, height, color1,radius); // top left tyre
	DrawRoundRect(o2xLocation, o2yLocation+height*2, width,  height, color1, radius/2); // body left rect
	DrawRoundRect(o2xLocation+width, o2yLocation+height, width*2, height*3, color1, radius/2); // body center rect
	DrawRoundRect(o2xLocation+width*3, o2yLocation+height*2, width, height, color1, radius/2); // body right rect*/



//calling function to check roadway numbers of opponent and player

		o2Pathway= RoadwayCount(o2x,o2y);
		pPathway = RoadwayCount(px,py);


//*****************************
//following are conditions for AI of opponent 2

		 if (pPathway-o2Pathway>0) {
//			cout<<"pPathway - oPathway"<<pPathway-oPathway<<endl;

			if((o2x>400 && o2x<470) && (o2Counting==0) && (opp2Direction==2)){
				cout<<"success"<<endl;
				o2PrevDirection=opp2Direction;	
				opp2Direction=1;
				cout<<"Opponent moving in upward direction = "<<opp2Direction<<endl;
				o2Counting=1;		//check flag true while moving upward from inner to outer roadway
			}

			else if((o2x>400 && o2x<470) && (o2Counting==0) && (opp2Direction==0)){
				cout<<"success"<<endl;
				o2PrevDirection=opp2Direction;	
				opp2Direction=3;
				cout<<"Opponent moving in downward direction = "<<opp2Direction<<endl;
				o2Counting=1;		//check flag true while moving downward from inner to outer roadway
			}
			
			else if((o2y>320 && o2y<390) && (o2Counting==0) && (opp2Direction==3) && level!=1){
				cout<<"success"<<endl;
				o2PrevDirection=opp2Direction;	
				opp2Direction=2;
				cout<<"Opponent 2 moving in left direction = "<<opp2Direction<<endl;
				o2Counting=1;		//check flag true while moving leftward from inner to outer roadway
			}

			else if((o2y>320 && o2y<390) && (o2Counting==0) && (opp2Direction==1) && level!=1){
				cout<<"success"<<endl;
				o2PrevDirection=opp2Direction;	
				opp2Direction=0;
				cout<<"Opponent 2 moving in left direction = "<<opp2Direction<<endl;
				o2Counting=1;		//check flag true while moving rightward from inner to outer roadway
			}


		}

		 else if (pPathway-o2Pathway<0) {
			cout<<"pPathway - o2Pathway = "<<pPathway-o2Pathway<<endl;

			if((o2x>400 && o2x<470) && (o2Counting==0) && (opp2Direction==2)){
				cout<<"success"<<endl;
				o2PrevDirection=opp2Direction;	
				opp2Direction=3;
				cout<<"Opponent moving in upward direction = "<<opp2Direction<<endl;
				o2Counting=1;		//check flag true while moving downward from outer to inner roadway
			}

			else if((o2x>400 && o2x<470) && (o2Counting==0) && (opp2Direction==0)){
				cout<<"success"<<endl;
				o2PrevDirection=opp2Direction;	
				opp2Direction=1;
				cout<<"Opponent 2 moving in downward direction = "<<opp2Direction<<endl;
				o2Counting=1;		//check flag true while moving upward from outer to inner roadway
			}

			else if((o2y>320 && o2y<390) && (o2Counting==0) && (opp2Direction==3) && level!=1){
				cout<<"success"<<endl;
				o2PrevDirection=opp2Direction;	
				opp2Direction=0;
				cout<<"Opponent moving in left direction = "<<opp2Direction<<endl;
				o2Counting=1;		//check flag true while moving leftward from inner to outer roadway
			}

			else if((o2y>320 && o2y<390) && (o2Counting==0) && (opp2Direction==1) && level!=1){
				cout<<"success"<<endl;
				o2PrevDirection=opp2Direction;	
				opp2Direction=2;
				cout<<"Opponent moving in left direction = "<<opp2Direction<<endl;
				o2Counting=1;		//check flag true while moving rightward from inner to outer roadway
			}

		}
		
		/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
		 * this function*/
		glutPostRedisplay();			



//end of AI part of opponent 2




}
//......................................................................................................






//calling function to check roadway numbers of opponent and player
		oPathway= RoadwayCount(ox,oy);
		pPathway = RoadwayCount(px,py);


//*****************************
//following are conditions for AI of opponent

		 if (pPathway-oPathway>0) {
//			cout<<"pPathway - oPathway"<<pPathway-oPathway<<endl;

			if((ox>400 && ox<470) && (oCounting==0) && (oppDirection==2)){
				cout<<"success"<<endl;
				oPrevDirection=oppDirection;	
				oppDirection=1;
				cout<<"Opponent moving in upward direction = "<<oppDirection<<endl;
				oCounting=1;		//check flag true while moving upward from inner to outer roadway
			}

			else if((ox>400 && ox<470) && (oCounting==0) && (oppDirection==0)){
				cout<<"success"<<endl;
				oPrevDirection=oppDirection;	
				oppDirection=3;
				cout<<"Opponent moving in downward direction = "<<oppDirection<<endl;
				oCounting=1;		//check flag true while moving downward from inner to outer roadway
			}
			
			else if((oy>320 && oy<390) && (oCounting==0) && (oppDirection==3) && level!=1){
				cout<<"success"<<endl;
				oPrevDirection=oppDirection;	
				oppDirection=2;
				cout<<"Opponent moving in left direction = "<<oppDirection<<endl;
				oCounting=1;		//check flag true while moving leftward from inner to outer roadway
			}

			else if((oy>320 && oy<390) && (oCounting==0) && (oppDirection==1) && level!=1){
				cout<<"success"<<endl;
				oPrevDirection=oppDirection;	
				oppDirection=0;
				cout<<"Opponent moving in left direction = "<<oppDirection<<endl;
				oCounting=1;		//check flag true while moving rightward from inner to outer roadway
			}


		}

		 else if (pPathway-oPathway<0) {
			cout<<"pPathway - oPathway = "<<pPathway-oPathway<<endl;

			if((ox>400 && ox<470) && (oCounting==0) && (oppDirection==2)){
				cout<<"success"<<endl;
				oPrevDirection=oppDirection;	
				oppDirection=3;
				cout<<"Opponent moving in upward direction = "<<oppDirection<<endl;
				oCounting=1;		//check flag true while moving downward from outer to inner roadway
			}

			else if((ox>400 && ox<470) && (oCounting==0) && (oppDirection==0)){
				cout<<"success"<<endl;
				oPrevDirection=oppDirection;	
				oppDirection=1;
				cout<<"Opponent moving in downward direction = "<<oppDirection<<endl;
				oCounting=1;		//check flag true while moving upward from outer to inner roadway
			}

			else if((oy>320 && oy<390) && (oCounting==0) && (oppDirection==3) && level!=1){
				cout<<"success"<<endl;
				oPrevDirection=oppDirection;	
				oppDirection=0;
				cout<<"Opponent moving in left direction = "<<oppDirection<<endl;
				oCounting=1;		//check flag true while moving leftward from inner to outer roadway
			}

			else if((oy>320 && oy<390) && (oCounting==0) && (oppDirection==1) && level!=1){
				cout<<"success"<<endl;
				oPrevDirection=oppDirection;	
				oppDirection=2;
				cout<<"Opponent moving in left direction = "<<oppDirection<<endl;
				oCounting=1;		//check flag true while moving rightward from inner to outer roadway
			}

		}
		
		/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
		 * this function*/
		glutPostRedisplay();			



//end of AI part of opponent 

//*****************************



//testing for arrow keys limit (shouldn't leave the canvas)
		if(px<20){
			px=20;
		}
		if(px>820){
			px=820;
		}

		if(py<20){
			py=20;
		}
		if(py>820){
			py=820;
		}


		if(speedingFlag==1){	//to speeden up player
			p_speedFactor=2;	//double speed
			speedingFlag=0;		//reset to zero to enable speeding again
		}
		else
			p_speedFactor=1;
		
//		cout<<endl<<"px = "<<px<<endl<<"py = "<<py<<endl<<"playerDirection = "<<playerDirection<<endl;
	

//drawing player's car using its usng it center coordinates
	float* color2 = colors[DARK_KHAKI]; 
	radius = 3.5;
	float pxLocation=px-20;
	float pyLocation=py-20;

	DrawRoundRect(pxLocation, pyLocation, width, height, color2,radius); // bottom left tyre
	DrawRoundRect(pxLocation+width*3, pyLocation, width, height, color2,radius); // bottom right tyre
	DrawRoundRect(pxLocation+width*3, pyLocation+height*4, width, height, color2,radius); // top right tyre
	DrawRoundRect(pxLocation, pyLocation+height*4, width, height, color2,radius); // top left tyre
	DrawRoundRect(pxLocation, pyLocation+height*2, width,  height, color2, radius/2); // body left rect
	DrawRoundRect(pxLocation+width, pyLocation+height, width*2, height*3, color2, radius/2); // body center rect
	DrawRoundRect(pxLocation+width*3, pyLocation+height*2, width, height, color2, radius/2); // body right rect*/


//decrementing lives if player and opponent collide
	if((partialReset==1 && resetCounter==21) || levelUp ==1){	//if levelUp is true, reprint all gift boxes
		levelUp = 0;		//allowing level to increment again
		for(int i=0; i<64; i++){	
			flag[i] = 1;		//set each element of gift box array true to reprint each one of them
		}
		partialReset=0;		//reset flag to zero
		resetCounter=0;		//maximum value was obtained hence it is brought back to zero
	}
	if(partialReset == 1){
		resetCounter++;			//to pause continuous lives' decrement till player moves totally over opponent
	}



//decrementing lives upon collision of player and opponent
	if((abs(px-ox)<19) && (abs(py-oy)<19) && (partialReset ==0) || ((abs(px-o2x)<19) && (abs(py-o2y)<19))  && (partialReset ==0)){
		lives--;
		partialReset = 1;		//flag set true for redrawing gift boxes when life is decreased
		

		cout<<"LIVES= "<<lives<<endl;
		if(lives<=0){
			livesCheck=0;		//setting flag false which will redirect player to a new screen
			printableKey='x';


//starting file writing when lives become zero to save score
			int high_Scores[11]= {0,0,0,0,0,0,0,0,0,0,0}; //scores array for 11 elements

//reading from a file
			string score1;
			ifstream fin ("high score.txt"); //name of the file to be read
			if (fin.is_open())
			{
				int num = 0;
				while (getline (fin, score1)) //this loop will run depending on the number of lines in the file
				{
					high_Scores[num] = stoi(score1);

					num++;
				  //HINT: use stoi() to convert string into Integer
				  
				}
				fin.close();
			}
			
			else 
				cout << "Unable to open file"; 
//end file reading
			
			high_Scores[10] = score;

			int temp;
			ofstream fout;
			fout.open ("high score.txt"); //this function takes the name of the file that you are writing to
			for(int i=0; i<11; i++){
//				cout<<high_Scores[i]<<endl;
			}			


			for(int i=0; i<11; i++){
				for(int iter=i+1; iter<11; iter++){
					if(high_Scores[i]<high_Scores[iter] && high_Scores[i]!=high_Scores[iter]){
						temp=high_Scores[i];
						high_Scores[i] = high_Scores[iter];
						high_Scores[iter]=temp;
					}
				}
			}

			for(int i=0; i<11; i++){
//				cout<<high_Scores[i]<<endl;
//				DrawString( 360, 600, "HIGH SCORES " + to_string(score), colors[GREEN]);
			}			



			for (int i = 0; i < 10; i++){
				fout << high_Scores[i] << endl;
			}
				
			fout.close();
			
		}
	//end file writing
			
	}	
	
//keeping record of high scores


//check finishes


// Drawing Arena's outer walls
	int gap_turn = 120;	//stays constant
	int sx = 20;
	int sy = 10;
	int swindow = 800;	//window size changes for each roadway
	int swidth = (swindow/2 - gap_turn/2);  // half width
	int s_tHeight = swidth-60;	//translating vertical rectangles down to leave space at top
	int sheight = 10;	//stays constant
	float *scolor = colors[BROWN];
		

	DrawRectangle(sx, sy, swidth, sheight, scolor); // bottom left
	DrawRectangle(sx + swidth + gap_turn, sy, swidth, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight*2, s_tHeight, scolor); // right down
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+s_tHeight+gap_turn, sheight*2, s_tHeight, scolor); // right up
	DrawRectangle(sx + swidth + gap_turn, sy+swindow+10-120, swidth, 10, scolor); // top left
	DrawRectangle(sx, sy+swindow+10-120, swidth, sheight, scolor); // top right
	DrawRectangle(sx-sheight*2, sy+sheight+s_tHeight+gap_turn, sheight*2, s_tHeight, scolor); // left up
	DrawRectangle(sx-sheight*2, sy+sheight, sheight*2, s_tHeight, scolor); // left down	


	//center rectangles
	DrawRectangle( 360 , 410, 140, 10, scolor);	//top horizontal rectangle
	DrawRectangle( 360 , 320, 140, 10, scolor);	//bottom horizontal rectangle
	DrawRectangle( 360 , 380, 20, 40, scolor);	//top left vertical rectangle
	DrawRectangle( 360 , 320, 20, 40, scolor);	//bottom left vertical rectangle
	DrawRectangle( 490 , 380, 20, 40, scolor);	//top right vertical rectangle
	DrawRectangle( 490 , 320, 20, 40, scolor);	//bottom left vertical rectangle



//Drawing layers of roadways

	for(int i=1; i<4; i++){

	sx+=70;
	sy+=70;
	swindow-=140;
	swidth = (swindow/2 - gap_turn/2); // half width
	s_tHeight = swidth-60;	//translating vertical rectangles down to leave space at top


	DrawRectangle(sx, sy, swidth, sheight, scolor); // bottom left
	DrawRectangle(sx + swidth + gap_turn, sy, swidth, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight*2, s_tHeight, scolor); // right down
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+ s_tHeight +gap_turn, sheight*2, s_tHeight, scolor); // right up
	DrawRectangle(sx + swidth + gap_turn, sy+swindow+10-120, swidth, sheight, scolor); // top left
	DrawRectangle(sx, sy+swindow+10-120, swidth, sheight, scolor); // top right
	DrawRectangle(sx-sheight*2, sy+sheight+ s_tHeight+gap_turn, sheight*2, s_tHeight, scolor); // left up
	DrawRectangle(sx-sheight*2, sy+sheight, sheight*2, s_tHeight, scolor); // left down
	}



//drawing gift boxes

   for(int i=0;i<64; i++){
	if(flag[i]==1){
		DrawRectangle(boxCoord[i][0], boxCoord[i][1], l_box, h_box, sBoxcolor);		//original position of gift boxes
		if((abs(px-boxCoord[i][0])<25) && (abs(py-boxCoord[i][1])<25)){
			flag[i]=0;		//removing gift boxes from screen
			score+=1;		//incrementing score

		}
	}

   }
   levelUp = 0;	// for checking when to increment level
   for(int i=0; i<64; i++){
	levelUp = levelUp || flag[i];	//level is not incremented if levelUp or even a single flag is true
   }

   levelUp = !(levelUp);

}



	glutPostRedisplay();
	glutSwapBuffers();                         // do not modify this line.. or draw anything below this line
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

		
	if (key	== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		if((playerDirection==1 || playerDirection==3) && (py>320 && py<390) && (px>20) && !(px>260 && px<600) && pCounting==0){
			pPrevDirection=playerDirection;			
			playerDirection=2;
			pCounting=1;		//check flag true only while switching roadway
		}
	}		

	else if (key == GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
		if((playerDirection==1 || playerDirection==3)  && (py>320 && py<390) && (px<780) && !(px>230 && px<530) && pCounting==0){
			pPrevDirection=playerDirection;		
			playerDirection=0;
			pCounting=1;		//check flag true only while switching roadway
		}
	}
	 else if (key == GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
		if((playerDirection==0 || playerDirection==2) && (px>380 && px<450) && (py<730) && !(py>230 && py<430) && pCounting==0){
			cout<<"success"<<endl;
			pPrevDirection=playerDirection;	
			playerDirection=1;
			cout<<"Player with up arrow direction = "<<playerDirection<<endl;
			pCounting=1;		//check flag true only while switching roadway
		}
	}

	else if (key == GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
		if((playerDirection==0 || playerDirection==2) && (px>380 && px<450) && (py>30)  && !(py>270 && py<480) && pCounting==0){
			pPrevDirection=playerDirection;	
			playerDirection=3;
			pCounting=1;		//check flag true only while switching roadway
		}
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
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	
	if (key == ' '){		//to double player's speed
		speedenUp=' ';
		speedingFlag=1;
	}

	if (key == 'n' || key == 'N'){
		printableKey='n';
		livesCheck=1; 		//to allow screen to be redirected away from GAME OVER screen
		cout << "n pressed" << endl;  //assigning variable for starting NEW game

	}

	if (key == 's' || key == 'S'){
		printableKey='s';	
		//cout << "s pressed" << endl;  //assigning variable for viewing high SCORES

	}


	if (key == 'h' || key == 'H'){
		printableKey='h';	
		//cout << "h pressed" << endl;  //assigning variable for HELP

	}
	if (key == 'p' || key == 'P'){
		printableKey='p';	
		//cout << "p pressed" << endl;  //assigning variable to PAUSE game

	}

	if (key == 'c' || key == 'C'){
		if(printableKey== 'p'){
			printableKey='c';	
		}
		cout << "c pressed" << endl;  //assigning variable to CONTINUE game

	}

	if (key == 'm' || key == 'M'){
		printableKey='m';	
		cout << "m pressed" << endl;  //assigning variable for main MENU

	}

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


	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(50.0, Timer, 0);

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
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {

	glutPostRedisplay();
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

	if (button == GLUT_LEFT_BUTTON){   // dealing only with left button

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{

	}
	glutPostRedisplay();
}


//void drawBox(bool flag1[], int boxCoord[][], px1, score1){
//   for(int i=0;i<64; i++){
//	if(flag[i]==1){
//		DrawRectangle(boxCoord[i][0], boxCoord[i][1], l_box, h_box, sBoxcolor);		//original position of gift boxes
//		if((abs(px-boxCoord[i][0])<25) && (abs(py-boxCoord[i][1])<25)){
//			flag[i]=0;		//removing gift boxes from screen
//			score+=1;		//incrementing score
//			cout<<"Score= "<<score<<endl;
//		}
//	}
//   }	
//
//}


/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	//b = new Board(60, 60); // create a new board object to use in the Display Function ...

	int width = 840, height = 840; // i have set my window size to be 800 x 600
	//b->InitalizeBoard(width, height);
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("OOP Centipede"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.


//	drawBox(flag, boxCoord, px, score);



	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.

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
#endif /* AsteroidS_CPP_ */
