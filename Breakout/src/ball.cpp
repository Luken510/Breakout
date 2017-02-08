/** \file ball.cpp
 * cpp file for the ball class.
 * contains all the parameters to create the ball and maintain it
 */

#include "ball.h"
#include "paddle.h"
#include "isIntersecting.h"
#include "block.h"
#include "wall.h"
#include "SFML/Graphics.hpp"

/*!
Set all the values of the MainBall
the Balls radius and velocity
Creating the Ball to be drawn
Set position, colour
Set origin and victory condition
*/

Ball::Ball(float X, float Y)
{
		// set the Ball radius
		ballRadius = 7.f; 
		// set the Ball velocity
		ballVelocity = 0.08f;
		// setting the Balls position
		cBall.setPosition(X,Y);
		// Setting the balls radius to be drawn
		cBall.setRadius(ballRadius);
		// setting the fill colour
		cBall.setFillColor(sf::Color::Green);
		// setting the outline of the balls colour
		cBall.setOutlineColor(sf::Color::Green);
		// setting the thickness of the outline
		cBall.setOutlineThickness(1);
		//setting the origin
		cBall.setOrigin(ballRadius,ballRadius);
		//setting the velocity of x and y
		vBallVelocity.x = -ballVelocity;
		vBallVelocity.y = -ballVelocity;
		// setting the victory conddition to false
		Victory = false;
	
		
}


// Constantly update the position of the ball
void Ball::update()
{
	cBall.move(vBallVelocity);
}
// get the left side of the Ball
float Ball::fGetLeft()
{
	float fLeft = cBall.getPosition().x - cBall.getRadius();
	return fLeft;
}

// get the right side of the Ball
float Ball::fGetRight()
{
	float fRight = cBall.getPosition().x + cBall.getRadius();
	return fRight;
}
// get the top side of the ball
float Ball::fGetTop()
{
	float fTop = cBall.getPosition().y - cBall.getRadius();
	return fTop;
}
// get the bottom side of the ball
float Ball::fGetBottom()
{
	float fBottom = cBall.getPosition().y + cBall.getRadius();
	return fBottom;
}

void Ball::SetPosition(int X,int Y)
{
	cBall.setPosition(X,Y);
}


