#include "s3e.h"
#include "IwDebug.h"
#include "ResManager\ImageManager.hpp"
#include "DrawHandle.hpp"
#include "DummyHandle.hpp"
#include <vector>

// Main entry point for the application
int main()
{
	//Initialise system(s)
	ImageManager imageManager;
   

	//Create a stack of DummyHandles
	std::vector<DummyHandle> dummyHandles;
	dummyHandles.push_back(DummyHandle(imageManager));


    // Loop forever, until the user or the OS performs some action to quit the app
    while (!s3eDeviceCheckQuitRequest())
    {
        //Update the input systems
        s3eKeyboardUpdate();
        s3ePointerUpdate();

		//Set Screen to Black
        Iw2DSurfaceClear(0xffffffff);
        
    }

    //Terminate modules being used
    
    
    // Return
    return 0;
}
