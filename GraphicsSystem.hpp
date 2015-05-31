#ifndef GRAPHICS_SYSTEM
#define GRAPHICS_SYSTEM

#include<vector>
#include"DrawHandle.hpp"
#include "Iw2D.h"
#include "IwImage.h"
#include "IwGeomFMat2D.h"

class GraphicsSystem{
	std::vector<DrawHandle * > handles;
public:
	GraphicsSystem();
	/*initialization functions for graphics*/

	~GraphicsSystem();
	/*termination functions for graphics*/

	void update();
	/*
	Draws everything to screen
	*/
};

#endif