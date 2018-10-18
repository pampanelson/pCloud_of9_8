#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
    
    int width = 1920;
    int height = 1080;
    
//    ofSetupOpenGL(width,height,OF_WINDOW);            // <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
//    ofRunApp(new ofApp());
    
    
    ofGLWindowSettings settings;
    settings.setGLVersion(3, 2);    // <--- ofxShadertoy NEEDS the GL Programmable Renderer
    settings.width = width;
    settings.height = height;
    ofCreateWindow(settings);       // <-------- setup the GL context
    
    // this kicks off the running of my app
    ofRunApp(new ofApp());

}
