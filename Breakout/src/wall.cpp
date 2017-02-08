/** \file wall.cpp
 * cpp file for the wall class.
 * contains all the needed parameters to create a wall
 */

#include "wall.h"
#include <SFML/Graphics.hpp>


//instantiate the class Block
Wall::Wall(float Width, float Height, float X, float Y)
{
		fWallHeight= Height;
		fWallWidth = Width;
		rWall.setPosition(X,Y);
		rWall.setSize(sf::Vector2f(fWallWidth, fWallHeight));
		rWall.setFillColor(sf::Color::Blue);
		rWall.setOutlineColor(sf::Color::Cyan);
		rWall.setOutlineThickness(1);
		rWall.setOrigin(fWallWidth/2,0);

	
}
//get the left of the wall
float Wall::fGetLeft()
{
	float fLeft = rWall.getPosition().x - (rWall.getSize().x)/2;
	return fLeft;
}
// get the right of the wall
float Wall::fGetRight()
{
	float fRight = rWall.getPosition().x + (rWall.getSize().x)/2;
	return fRight;
}
//get the top of the wall
float Wall::fGetTop()
{
	float fTop = rWall.getPosition().y - (rWall.getSize().y);
	return fTop;
}
//get the bottom of the wall
float Wall::fGetBottom()
{
	float fBottom = rWall.getPosition().y + (rWall.getSize().y);
	return fBottom;
}
