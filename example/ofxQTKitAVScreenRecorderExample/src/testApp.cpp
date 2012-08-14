#include "testApp.h"

void testApp::setup() {	
	
    ofBackground(0,0,0);
    ofSetFrameRate(24);
    
    recorder.setup(); 
    
    grabber.initGrabber(CAM_WIDTH,CAM_HEIGHT);
    fboSaver.allocate(CAM_WIDTH, CAM_HEIGHT, GL_RGB);
    fboPixels.allocate(CAM_WIDTH, CAM_HEIGHT, OF_IMAGE_COLOR);
    ofEnableAlphaBlending();
    alphaPNG.loadImage("1.png"); //test image
    fboSaver.begin();
    ofClear(255,255,255,0);
    fboSaver.end();
    
}



void testApp::update() {
    grabber.grabFrame();
    
    //the timing seems pretty good at 24fps
    if (grabber.isFrameNew()){
        if(recorder.getIsRecording()) {
            //Capture a texture to a Frame Buffer Object and write the pixels to our Recorder. 
            fboSaver.begin();
            ofClear(255, 255, 255);
            ofBackground(0, 0, 0);
            ofSetColor(255,255,255,ofMap(mouseX, 0,ofGetWidth(),0,255)); //vary alpha by mouseX
            grabber.draw(30,30,320,240); //overlap a bunch of video frames
            grabber.draw(280,30,320,240);
            grabber.draw(30,280,320,240);
            grabber.draw(280,220,320,240);
            alphaPNG.draw(200, 200); //shows that you can draw an alpha png file into the fbo. 
            fboSaver.end();
            
            fboSaver.readToPixels(fboPixels);
            recorder.addFrame(fboPixels);
            
            // OR capture the texture directly from the screen. 
            // testDraw.grabScreen(640, 0, CAM_WIDTH, CAM_HEIGHT);
            // if((stopAddingFrames == false) && isRecording) recorder.addFrame(testDraw.getPixelsRef());
        }
	}
    
    recorder.update(); 
}

void testApp::draw() {
    
    //map dark to light to mouse
    ofSetColor(255,255,255,ofMap(mouseX, 0,ofGetWidth(),0,255));    
    grabber.draw(0,0);
    
    ofSetColor(255, 255, 255); 
    ofDrawBitmapString("\nMove mouse left to right to vary opacity\nPress 'r' to begin recording.\nPress 's' to save recording to file.\nWait 3 seconds and press 'r' again to record more files.", 20, ofGetWindowHeight()-60);
    
}


void testApp::keyPressed(int key) {
    switch (key) {
        case 's':
            recorder.finishMovie(); 
            break;
        
        case 'r':
            recorder.startNewRecording(); 
            break; 

        default:
            break;
    }
}


void testApp::exit(){ 
    recorder.exit(); 
}

