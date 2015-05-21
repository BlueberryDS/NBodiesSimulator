#include <string>

class DrawHandle
{
	/*
	This class contains the DrawHandle.
	*/
	Image image;

public:
	DrawHandle(String);
	virtual ~DrawHandle();

	virtual const float getX();
	virtual const float getY();
	virtual const float getRadius();
	const Image getImage();
	virtual void DrawHandle();
};