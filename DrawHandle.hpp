#include <string>
#include "ResManager\Image.hpp"

#ifndef DRAW_HANDLE
#define DRAW_HANDLE

class DrawHandle
{

public:
	virtual ~DrawHandle();

	virtual const float getX();
	/*
	Returns a float containing the X position of the drawing in arbitrary coordinates
	*/

	virtual const float getY();
	/*
	Returns a float containing the Y position of the drawing in arbitrary coordinates
	*/

	virtual const float getRadius();
	/*
	Returns a float representing the size in arbirtrary units.
	*/

	virtual const float getRotation();
	/*
	Returns a float with the rotation in fractions of pi
	*/

	const Image getImage();
	/*
	Returns the Image object to be drawn.
	*/
};

#endif