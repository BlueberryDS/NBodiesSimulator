#include "s3e.h"
#include "IwDebug.h"
#include "Iw2D.h"
#include "ResManager\ImageManager.hpp"
#include "DrawHandle.hpp"
#include "DummyHandle.hpp"


// Main entry point for the application
int main()
{
    //Initialise graphics system(s)
    Iw2DInit();


    // Loop forever, until the user or the OS performs some action to quit the app
    while (!s3eDeviceCheckQuitRequest())
    {
        //Update the input systems
        s3eKeyboardUpdate();
        s3ePointerUpdate();

        Iw2DSurfaceClear(0xffffffff);
        
        // Your rendering/app code goes here.


        //Draws Surface to screen
        Iw2DSurfaceShow();

        // Sleep for 0ms to allow the OS to process events etc.
        s3eDeviceYield(0);
    }

    //Terminate modules being used
    Iw2DTerminate();
    
    // Return
    return 0;
}
