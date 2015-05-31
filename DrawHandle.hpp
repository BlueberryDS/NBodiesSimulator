#include <string>
#include "ResManager\Image.hpp"

#ifndef DRAW_HANDLE
#define DRAW_HANDLE

class DrawHandle
{

public:
	virtual ~DrawHandle(){}
	DrawHandle(){}

	virtual const float getX() = 0;
	/*
	Returns a float containing the X position of the drawing in arbitrary coordinates
	*/

	virtual const float getY() = 0;
	/*
	Returns a float containing the Y position of the drawing in arbitrary coordinates
	*/

	virtual const float getRadius() = 0;
	/*
	Returns a float representing the size in arbirtrary units.
	*/

	virtual const float getRotation() = 0;
	/*
	Returns a float with the rotation in fractions of pi
	*/

	virtual const Image getImage() = 0;
	/*
	Returns the Image object to be drawn.
	*/
};

#endif