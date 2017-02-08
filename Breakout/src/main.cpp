/*! \mainpage Breakout
 *
 * This is the documentation for the retro game Breakout
 * 
 * This program is a replica of the retro game Breakout
 * 
 */

/** \file main.cpp
 * Contains the entry point for the program.
 * Contains the entry point for the program which creates the main game loop
 * The collision tests, and the text/image objects
 * as well as updating the other objects constantly through the main loop
 */







#include <iostream>
#include "ball.h"
#include "block.h"
#include "paddle.h"
#include "wall.h"
#include "collisions.h"
#include "isIntersecting.h"
#include "outputText.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <memory>
#include <vector>


using namespace std;

int Score = 0;
int iLives = 3;

/**
the first test of collisions, between the paddle and the ball
/Param mPaddle is the class Paddle
/Param mBall is the class Ball
*/
void paddleAndBallCollision(Paddle& mPaddle, Ball& mBall)
{
	if(!isIntersecting(mPaddle, mBall)) return;

	
	if(mBall.cBall.getPosition().x < mPaddle.rPaddle.getPosition().x) mBall.vBallVelocity.x = -mBall.ballVelocity;
	else mBall.vBallVelocity.x = mBall.ballVelocity;

	mBall.vBallVelocity.y = -mBall.ballVelocity;
}
/**
the second of the test collisions, between the block and the ball
once collided it destroys the block and bounces off said block
/Param mBlock is the class block
/Param mBall is the class ball
*/
void blockAndBallcollision(Block& mBlock, Ball& mBall)
{

	

	if(!isIntersecting(mBlock, mBall)) return;//!< calls the template function to test collision if false, leave the function
	mBlock.bDestroyed = true;//!< the block has be destoryed
	int runTotalNumOfBlocks=0;//!< the total number of blocks destroyed
	runTotalNumOfBlocks++;//!<iterating the number destroyed
	Score++;
	if (runTotalNumOfBlocks == mBlock.TotalNumOfBlocks){ mBall.Victory = true;}//!<if the number destroyed is = to the total number, victory conditions are met

	float overlapLeft = mBall.fGetRight() - mBlock.fGetLeft();//!<if it is overlapped on the left
	float overlapRight = mBlock.fGetRight() - mBall.fGetLeft();//!< if it is overlapped on the right
	float overlapTop = mBall.fGetBottom() - mBlock.fGetTop();//!< if it is overlapped on the top
	float overlapBottom = mBlock.fGetBottom() - mBall.fGetTop();//!< if it is overlapped on the bottom

	bool ballFromLeft(abs(overlapLeft) < abs(overlapRight));//!<check to see what side left or right, it has collided
	bool ballFromTop(abs(overlapTop) < abs(overlapBottom));//!< check to see what side, top or bottom, it has collided

	float minOverlapX = ballFromLeft ? overlapLeft : overlapRight; //!< check to see what side left or right, it has collided
	float minOverlapY = ballFromTop ? overlapTop : overlapBottom;// !< check to see what side, top or bottom, it has collided

	if(abs(minOverlapX) < abs(minOverlapY)) // if the min overlap of x is < y, then it must of collided from the sides else the top/bot
		mBall.vBallVelocity.x = ballFromLeft ? -mBall.ballVelocity : mBall.ballVelocity;
	else
		mBall.vBallVelocity.y = ballFromTop ? -mBall.ballVelocity : mBall.ballVelocity;	
}
/**
the third collision test, between the walls and the Ball
/param mWall is the wall class
/param mBall is the ball class
*/
void wallandBallcollision(Wall& mWall, Ball& mBall)
{
	if(!isIntersecting(mWall, mBall)) return;
	float overlapLeft = mBall.fGetRight() - mWall.fGetLeft();
	float overlapRight = mWall.fGetRight() - mBall.fGetLeft();
	float overlapTop = mBall.fGetBottom() - mWall.fGetTop();
	float overlapBottom = mWall.fGetBottom() - mBall.fGetTop();

	bool ballFromLeft(abs(overlapLeft) < abs(overlapRight));
	bool ballFromTop(abs(overlapTop) < abs(overlapBottom));

	float minOverlapX = ballFromLeft ? overlapLeft : overlapRight;
	float minOverlapY = ballFromTop ? overlapTop : overlapBottom;

	if(abs(minOverlapX) < abs(minOverlapY))
		mBall.vBallVelocity.x = ballFromLeft ? -mBall.ballVelocity : mBall.ballVelocity;
	else
		mBall.vBallVelocity.y = ballFromTop ? -mBall.ballVelocity : mBall.ballVelocity;	

}



void reset(Ball &ball, Paddle &Paddle)
{
	
	ball.SetPosition(800/2, 600/2);
	ball.vBallVelocity.x = -0.1f;
	ball.vBallVelocity.y = -0.1f;

	Paddle.SetPosition(800/2, 600 - 25);
}

/**
The entry point for the application.
*/
int main()
{
	sf::Texture backgroundTexture;//!< create the backgroundtexture
	sf::Sprite backgroundSprite;//!< create the background sprite

	backgroundTexture.loadFromFile("../assets/bg.png");//!<load the background texture 281x71 image
	backgroundSprite.setTexture(backgroundTexture);//!<set the sprite to the texture
	backgroundSprite.setOrigin(141.f,35.5f);//!<set the sprites origin 
	backgroundSprite.setPosition(400,300);//!<set the position of the sprite

	sf::Text Text1; //!< create the first text
	sf::Text Text2;//!< create the second text
	sf::Text Score1;//!<create the score text
	sf::Text Score2;//!<create the score text
	sf::Text Lives1;//!<create the Lives text
	sf::Text Lives2;//!<create the Lives text
	sf::Font arial1; //!< create the font being used
	arial1.loadFromFile("..\\assets\\arial.TTF"); //!<load the font from file
	Text1.setString("GAME OVER!\n\Thanks for playing!"); //!< set the text to be drawn
	Text1.setFont(arial1);//!< set the font of text1
	Text1.setCharacterSize(36);//!< set the character size of text1
	Text1.setColor(sf::Color::White);//!<set the colour of text1
	Text1.setPosition(-400,-300);//!<set the starting position of text1
	//outputText tGameOver(36.f, -400,-300);
	Text2.setString("YOU WIN!\n\Thanks for playing!");//!<set the text of text2 
	Text2.setFont(arial1);//!<set the font of text2
	Text2.setCharacterSize(36);//!<set the sizeof text2
	Text2.setColor(sf::Color::White);//!<set the colour of text2
	Text2.setPosition(-400,-300);//!<set the starting position of text2

	Score1.setString("Score : ");//!<set the text of Score1 
	Score1.setFont(arial1);//!<set the font of Score1
	Score1.setCharacterSize(16);//!<set the sizeof Score1
	Score1.setColor(sf::Color::White);//!<set the colour of Score1
	Score1.setPosition(100,0);//!<set the starting position of Score1

	Score2.setFont(arial1);//!<set the font of Score2
	Score2.setCharacterSize(16);//!<set the sizeof Score2
	Score2.setColor(sf::Color::White);//!<set the colour of Score2
	Score2.setPosition(200,0);//!<set the starting position of Score2

	Lives1.setString("Lives : ");//!< set the text of Lives1
	Lives1.setFont(arial1);//!<set the font of Lives1
	Lives1.setCharacterSize(16);//!<set the sizeof Lives1
	Lives1.setColor(sf::Color::White);//!<set the colour of Lives1
	Lives1.setPosition(400,0);//!<set the starting position of Lives1

	Lives2.setFont(arial1);//!<set the font of Lives2
	Lives2.setCharacterSize(16);//!<set the sizeof Lives2
	Lives2.setColor(sf::Color::White);//!<set the colour of Lives2
	Lives2.setPosition(500,0);//!<set the starting position of Lives2

	
	
	int iWindowWidth = 800;//!<set the window width
	int iWindowHeight = 600;//!<set the window height

	Ball MainBall(iWindowWidth/2, iWindowHeight/2);//!< create an instance of the Ball
	Paddle Player1(iWindowWidth/2, iWindowHeight - 25);//!<create the paddle
	Wall Wall3(800, 20, 400,0);//!<create the third wall
	Wall Wall1(25, 600, 0,0);//!<create the first wall
	Wall Wall2(25, 600, 800,0);//!<create the second wall
	
	
	Block Blockspt2(0,0);//!<to get the height/width cause of the array not allowing it
	int iNumOfBlocksX = Blockspt2.getNumOfX();//!<to get the number of columns
	int iNumOfBlocksY = Blockspt2.getNumOfY();//!<to get the number of rows
	vector<Block> blocks;//!<creating a 2D vector of blocks colums x rows
	// iterate through the block vector
	for(int iX = 0; iX < iNumOfBlocksX; ++iX)
		for(int iY = 0; iY < iNumOfBlocksY; ++iY)		
			blocks.emplace_back((iX + 1) * (Blockspt2.getWidth() + 3) - 20, 
								(iY + 2) * (Blockspt2.getHeight() + 3));	

	sf::RenderWindow window(sf::VideoMode(iWindowWidth,iWindowHeight), "Breakout"); //!< open the main window
		

	// Run a game Loop
	while (window.isOpen())
	{
		window.clear(sf::Color::Black);
		

		sf::Event event;
		while (window.pollEvent(event))
		{
			//close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}
		//draw the background
		//window.draw(backgroundSprite);
		// update and draw the paddle
		Player1.update();
		window.draw(Player1.rPaddle);
		// update and draw the ball
		MainBall.update();
		window.draw(MainBall.cBall);


		//defeat conditions
		if (MainBall.fGetBottom() >= 600) 
		{
			iLives--;
			if ( iLives >= 0)
			{
				reset(MainBall, Player1);
				Score = 0;
			}
			if ( iLives == 0)
			{
				Text1.setPosition(200,200);
				MainBall.vBallVelocity.x = 0;
				MainBall.vBallVelocity.y = 0;
				Player1.vPaddleVelocity.x = 0;
				Player1.vPaddleVelocity.y = 0;
			}

		};
		//victory conditions
		if(MainBall.Victory == true)
		{
			Text2.setPosition(200,200);
			MainBall.vBallVelocity.x = 0;
			MainBall.vBallVelocity.y = 0;
			Player1.vPaddleVelocity.x = 0;
			Player1.vPaddleVelocity.y = 0;
		}


		// update and draw the walls
		window.draw(Wall1.rWall);
		window.draw(Wall2.rWall);
		window.draw(Wall3.rWall);
		//draw text
		window.draw(Text1);
		window.draw(Text2);
		window.draw(Score1);
		window.draw(Lives1);
		//draw the score
		string sScore = to_string(Score);
		Score2.setString(sScore);//!<set the text of Score2 
		window.draw(Score2);
		//draw the lives
		string sLives = to_string(iLives);
		Lives2.setString(sLives);
		window.draw(Lives2);
		

		// updating and drawing the array of blocks
		for(auto& block : blocks) window.draw(block.rBlock);

		
		paddleAndBallCollision(Player1,MainBall);//!<constantly checking for Paddle/Ball colllision
		wallandBallcollision(Wall1,MainBall);//!< constantly checking for Wall1/ball collision
		wallandBallcollision(Wall2,MainBall);//!<constantly checking for Wall2/ball collision
		wallandBallcollision(Wall3,MainBall);//!<constantly checking for Wall3/Ball collosion
		
		for(auto& block : blocks ) blockAndBallcollision(block,MainBall);//!< constantly checking through all blocks if they have collided with the ball
		blocks.erase(remove_if(begin(blocks),end(blocks), [](const Block& mBlock){return mBlock.bDestroyed; }),end(blocks));//!<checks if the blocks have been destroyed, places them to the front of the array, and erases

		

		window.display();
	}

	return 0;
};
