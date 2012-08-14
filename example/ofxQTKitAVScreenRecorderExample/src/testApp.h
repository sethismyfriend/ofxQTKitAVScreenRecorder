#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "ofxQTKitAVScreenRecorder.h"  //includes ofxQTKitRecorder and ofxQTKitVideoGrabber make sure to add these to your project. 

#define CAM_WIDTH  640
#define CAM_HEIGHT 480

class testApp : public ofBaseApp{
  public:
	void setup();
	void update();
	void draw();
	void exit();
    void keyPressed(int key);
    
    ofxQTKitAVScreenRecorder recorder; 
    
    //example FBO for saving to a frame buffer
    ofFbo fboSaver;
    ofPixels fboPixels;
    
    //testing rgba png
    ofImage alphaPNG; 
    
    //Getting a video stream to test audio sync
    ofxQTKitVideoGrabber grabber;
    ofImage testDraw; 
    
 
};

#endif	
