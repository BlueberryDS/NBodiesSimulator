#ifndef DUMMY_HANDLE
#define DUMMY_HANDLE

#include "ResManager\ImageManager.hpp"
#include "DrawHandle.hpp"

class DummyHandle : public DrawHandle {
	Image image;
public:
	DummyHandle(ImageManager & man){ image = man.getRes("Resources\testBerry.png"); }
	const float getX(){ return 100; }
	const float getY(){ return 100; }
	const float getRadius(){ return 2; }
	const float getRotation(){ return 0.5; }
	Image getImage(){ return image; }
};

#endif