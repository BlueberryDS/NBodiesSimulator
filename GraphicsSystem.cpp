#include "GraphicsSystem.hpp"

GraphicsSystem::GraphicsSystem()
{
	Iw2DInit();
}

GraphicsSystem::~GraphicsSystem()
{
	Iw2DTerminate();
}

void GraphicsSystem::update()
{
	for (int i = 0; i < handles.size(); i++){
		const CIw2DImage * img = handles[i]->getImage().getCIw2DImage();
		int height = img->GetHeight();
		int width = img->GetWidth();
		float scale = (float)(defaultSize / height);
		CIwFMat2D rot;
		rot.ScaleRot
	}

	//Draws Surface to screen
	Iw2DSurfaceShow();

	// Sleep for 0ms to allow the OS to process events etc.
	s3eDeviceYield(0);
}

