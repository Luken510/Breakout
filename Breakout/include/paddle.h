/** \file paddle.h
 * Header file for the paddle class.
 * States the parameters needed to create the Paddle object
 */

#ifndef PADDLE_H
#define PADDLE_H

#include <SFML/Graphics.hpp>

//! The Paddle Class
/*!
This class describes how to create a Paddle object
All the Paddle variables need to be set when the class is instantiated.
it is possible to get the left,right,top,bottom values of the Paddle
*/



class Paddle
{
	
private:

	float fPaddleVelocity; //!< The paddle's velocity
	float fPaddleWidth;//!< the paddles width
	float fPaddleHeight;//!< the paddles height

public:
	/**
	creating a RectangleShape object to draw the paddle and maintain the paddle
	*/
	sf::RectangleShape rPaddle;
	/** 
	The only constructor availible, takes all variables.
	\param X is the position of the Paddle X co-ordinate
	\param Y is the position of the Paddle Y co-ordinate 
	*/
	Paddle(float X, float Y);
	/**
	creating a 2D vector to contain the paddle's velocity
	*/
	sf::Vector2f vPaddleVelocity;
	void update();//!< updating the paddles position and velocity
	float fGetLeft();//!< get the left side of the paddle
	float fGetRight();//!< get the right side of the paddle
	float fGetTop();//!< get the top side of the paddle
	float fGetBottom();//!< get the bottom side of the paddle
	void SetPosition(int X, int Y);

};


#endif