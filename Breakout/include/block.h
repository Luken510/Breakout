#ifndef BLOCK_H
#define BLOCK_H

#include <SFML/Graphics.hpp>


/** \file block.h
 * Header file for the block class.
 * * States the parameters needed to create the block object
 */



//! The Block Class
/*!
This class describes how to create a block object
All the Block variables need to be set when the class is instantiated.
it is possible to get the left,right,top,bottom values of the Ball
it is possible to get the number of X, and Y ( column / Rows ) of the Ball
it is possible to get the Total number of blocks ( x * y )
*/
class Block
{
	
private:

	
	float fBlockWidth; //!< the width of the blocks
	float fBlockHeight; //!< the height of the blocks
	int NumOfX; //!< The number of Blocks in x (columns)
	int NumOfY; //!< The Numer of Blocks in Y (rows)

public:
	/**
	create a rectangle shape object to draw and maintain the blocks
	*/
	sf::RectangleShape rBlock;
	/** 
	The only constructor availible, takes all variables.
	\param X is the position of the Blocks X co-ordinate
	\param Y is the position of the Block Y co-ordinate 
	*/
	Block(float X, float Y);
	void update(); //!< Update function to maintain and update the blocks
	float fGetLeft(); //!< Function to get the co-ords of the left side of the block
	float fGetRight(); //!< Get the right side of the block
	float fGetTop(); //!< get the top side of the block
	float fGetBottom(); //!< get the bottom side of the block
	float getHeight();  //!< get the height of the block
	float getWidth(); //!< get the width of the block
	bool bDestroyed; //!< whether the block has been destoryed or not
	int getNumOfX(); //!< get the number of blocks in columns
	int getNumOfY(); //!< get the number of blocks in rows
	int TotalNumOfBlocks; //!< get the total number of blocks x*y


};






#endif