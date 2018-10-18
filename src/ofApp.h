#pragma once

#include "ofMain.h"
#include "ofxSyphon.h"
#include "ofxGui.h"
#include "ofxShadertoy.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    
    ofShader            shader;
    ofxShadertoy        shadertoy;
    ofxSyphonServer     syphonServer;
    ofFbo               syphonFbo;
    
    
    int                 width;
    int                 height;
    
    float               tick = 0.0f;
    
    ofxPanel            gui;

    ofParameter<float>               tickDelta; // speed of cloud transforming 0.1 ~ 0.9 ,bigger more cloud

    ofParameter<float>               cloudtransform; // speed of cloud transforming 0.1 ~ 0.9 ,bigger more cloud
    ofParameter<float>               cloudscale;
    ofParameter<float>               speed;
    ofParameter<float>               clouddark;  // 0.3 ~ 0.6  bigger lighter
    ofParameter<float>               cloudlight;
    ofParameter<float>               cloudcover;
    ofParameter<float>               cloudalpha;
    ofParameter<float>               skytint;
    
    
};
