
/** \file isIntersecting.h
 * Header file for the template class.
 * used by the collisions to test if they have intersected
 */


#ifndef ISINTERSECTING_H
#define ISINTERSECTING_H



//! The Template Class T1, T2
/*!
This class is a template describing a function that checks whether two objects have intersected
The Templates Class doesn't need to be instantiated untill used by another class
This allows other classes to call on this function and test whether two objects have intersected
*/

template<class T1, class T2> 

/**
 This function is taking the templated class parameters and comparing them 
 This function need to be instantiated by another object
 That object will then pass the parameters mA and mB ( which are classes ) into this function
 This function will then compare whether or not they have intersected, returning a bool
 /Param mA is a template class
 /Param mB is a template Class
 */

bool isIntersecting(T1& mA, T2& mB)
{
	return mA.fGetRight() > mB.fGetLeft() && mA.fGetLeft() < mB.fGetRight() 
			&& mA.fGetBottom() > mB.fGetTop() && mA.fGetTop() < mB.fGetBottom();
};

#endif