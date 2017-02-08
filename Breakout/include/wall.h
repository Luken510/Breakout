/** \file wall.h
 * Header file for the wall class.
 * States the parameters needed to create the Wall object
 */

#ifndef WALL_H
#define WALL_H

#include <SFML/Graphics.hpp>



//! The Wall Class
/*!
This class describes how to create a Wall object
All the Wall variables need to be set when the class is instantiated.
it is possible to get the left,right,top,bottom values of the Wall
*/


class Wall 
{
	
private:

	
	float fWallWidth;//!<the width of the wall
	float fWallHeight;//!<the height of the wall

public:
	/**
	creating a rectangle object to draw the wall
	*/
	sf::RectangleShape rWall;
	/** 
	The only constructor availible, takes all variables.
	\param X is the position of the Walls X co-ordinate
	\param Y is the position of the Walls Y co-ordinate 
	*/
	Wall(float Width, float Height, float X, float Y);
	float fGetLeft();//!< get the left side of the wall
	float fGetRight();//!< get the right side of the wall
	float fGetTop();//!< get the top side of the wall
	float fGetBottom();//!< get the bottom side of the wall


};


#endif