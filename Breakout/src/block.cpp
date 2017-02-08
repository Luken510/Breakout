/** \file block.cpp
 * cpp file for the block class.
 * contains all the parameters to create the block and maintain it
 */

#include "block.h"
#include <SFML/Graphics.hpp>



//instantiate the class Block

Block::Block(float X, float Y)
{
		fBlockHeight = 15;
		fBlockWidth = 100;
		NumOfX = 7;
		NumOfY = 5;

		TotalNumOfBlocks = NumOfX*NumOfY;
		
		rBlock.setPosition(X,Y);
		rBlock.setSize(sf::Vector2f(fBlockWidth, fBlockHeight));
		rBlock.setFillColor(sf::Color::Cyan);
		rBlock.setOutlineColor(sf::Color::Blue);
		rBlock.setOutlineThickness(1);
		rBlock.setOrigin(fBlockWidth/2, fBlockHeight/2);
		bDestroyed = false;

	
}
// get the left side of the block
float Block::fGetLeft()
{
	float fLeft = rBlock.getPosition().x - (rBlock.getSize().x)/2;
	return fLeft;
}
// get the right side of the block
float Block::fGetRight()
{
	float fRight = rBlock.getPosition().x + (rBlock.getSize().x/2);
	return fRight;
}
//get the top side of the block
float Block::fGetTop()
{
	float fTop = rBlock.getPosition().y - (rBlock.getSize().y)/2;
	return fTop;
}
//get the bottom side of the block
float Block::fGetBottom()
{
	float fBottom = rBlock.getPosition().y + (rBlock.getSize().y)/2;
	return fBottom;
}
//get the height of the block
float Block::getHeight()
{
	return fBlockHeight;
}
//get the width of the block
float Block::getWidth()
{
	return fBlockWidth;
}
// get the number of columns
int Block::getNumOfX()
{
	return NumOfX;
}
// get the number of rows
int Block::getNumOfY()
{
	return NumOfY;
}

	