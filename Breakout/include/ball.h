/** \file ball.h
 * Header file for the ball class.
 * * States the parameters needed to create the ball object
 */

#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>



//! The Ball Class
/*!
This class describes how to create a ball object
All the Balls variables need to be set when the class is instantiated.
it is possible to get the left,right,top,bottom values of the Ball
*/

class Ball 
{
	
private:
	
	

public:
	/**
	creating a CircleShape object to draw the circle
	*/
	sf::CircleShape cBall;
	/** 
	The only constructor availible, takes all variables.
	\param X is the position of the Balls X co-ordinate
	\param Y is the position of the Balls Y co-ordinate 
	*/
	Ball(float X, float Y);

	/**
	Creating a 2d vector to contain the Balls Velocity
	*/
	sf::Vector2f vBallVelocity; 


	void update(); //!< Update the position/velocity
	float fGetLeft(); //!< Get the Left side of the Ball
	float fGetRight(); //!< Get the right side of the ball
	float fGetTop(); //!< Get the top side of the ball
	float fGetBottom(); //!< Get the Bottom side of the ball
	float ballRadius; //!< The Balls Radius
	float ballVelocity;//!< The Balls Velocity
	bool Victory; //!< Bool for Victory conditions
	void SetPosition(int X, int Y);
};


#endif
