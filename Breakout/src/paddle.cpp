/** \file paddle.cpp
 * cpp file for the paddle class.
 * contains all the parameters to create the paddle and maintain it
 */

#include "paddle.h"


#include <SFML/Graphics.hpp>



//instantiate the class Block

Paddle::Paddle(float X, float Y)
{
		fPaddleHeight = 10;
		fPaddleWidth = 120;
	
		
		fPaddleVelocity = 0.12f;
		rPaddle.setPosition(X,Y);
		rPaddle.setSize(sf::Vector2f(fPaddleWidth, fPaddleHeight));
		rPaddle.setFillColor(sf::Color::Red);
		rPaddle.setOutlineColor(sf::Color::Yellow);
		rPaddle.setOutlineThickness(2);
		rPaddle.setOrigin(fPaddleWidth/2, fPaddleHeight/2);
		vPaddleVelocity.x = -fPaddleVelocity;
		vPaddleVelocity.y = 0;

	
}

// update the paddles position, whether or not the player is moving it
void Paddle::update()
{
	rPaddle.move(vPaddleVelocity);
	// this is waiting for the input of the left or right key to be pressed, once pressed the paddle will be moved either left or right by its velo
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && fGetLeft()>12.5) { vPaddleVelocity.x = -fPaddleVelocity;}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && fGetRight()<=788.5f) { vPaddleVelocity.x = +fPaddleVelocity;}

	else vPaddleVelocity.x = 0;


}
// get the left of the paddle
float Paddle::fGetLeft()
{
	float fLeft = rPaddle.getPosition().x - (rPaddle.getSize().x)/2;
	return fLeft;
}
//get the right of the paddle
float Paddle::fGetRight()
{
	float fRight = rPaddle.getPosition().x + (rPaddle.getSize().x)/2;
	return fRight;
}
// get the top of the paddle
float Paddle::fGetTop()
{
	float fTop = rPaddle.getPosition().y - (rPaddle.getSize().y)/2;
	return fTop;
}
// get the bottom of the paddle
float Paddle::fGetBottom()
{
	float fBottom = rPaddle.getPosition().y + (rPaddle.getSize().y)/2;
	return fBottom;
}

void Paddle::SetPosition(int X,int Y)
{
	rPaddle.setPosition(X,Y);
}
