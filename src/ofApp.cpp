#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(30);
    ofSetVerticalSync(true);
    
    shadertoy.load("shaders/cloud.frag");
    
    //    width = 1920;
    //    height = 1080;
    
    width = 1280 * 2;
    height = 720;
    //    width = 1920;
    //    height = 1080;
    
    syphonFbo.allocate(width,height);
    
    syphonServer.setName("pCloud");
    

    
    // init parameters for cloud
    

    
    
    gui.setup();
    gui.add(tickDelta.set("tickDelta",0.001,0.001,1.0));
    gui.add(cloudtransform.set("cloudtransform",0.1,0.01,1.0));
    gui.add(cloudscale.set("cloudscale",0.1,0.01,1.0));
    gui.add(speed.set("speed",0.001,0.001,0.5));
    gui.add(clouddark.set("clouddark",0.01,0.01,1.0));
    gui.add(cloudlight.set("cloudlight",0.01,0.01,1.0));
    gui.add(cloudcover.set("cloudcover",0.01,0.01,1.0));
    gui.add(cloudalpha.set("cloudalpha",1.0,0.1,20.0));
    gui.add(skytint.set("skytint",0.01,0.01,1.0));
    
    
    tickDelta.set(0.1);
    cloudtransform.set(0.5); // speed of cloud transforming 0.1 ~ 0.9 ,bigger more cloud
    cloudscale.set(0.3);
    speed.set(0.02);
    clouddark.set(0.6);  // 0.3 ~ 0.6  bigger lighter
    cloudlight.set(0.2);
    cloudcover.set(0.2);
    cloudalpha.set(8.0);
    skytint.set(0.5);

}

//--------------------------------------------------------------
void ofApp::update(){
    tick += tickDelta.get();

}

//--------------------------------------------------------------
void ofApp::draw(){
    syphonFbo.begin();
    ofClear(255, 255, 255);
    shadertoy.begin();
    shadertoy.setUniform1f("time",tick);
    shadertoy.setUniform1f("width", width);
    shadertoy.setUniform1f("height", height);
    shadertoy.setUniform1f("cloudtransform",cloudtransform.get());
    shadertoy.setUniform1f("cloudscale",cloudscale.get());
    shadertoy.setUniform1f("speed",speed.get());
    shadertoy.setUniform1f("clouddark",clouddark.get());
    shadertoy.setUniform1f("cloudlight",cloudlight.get());
    shadertoy.setUniform1f("cloudcover",cloudcover.get());
    shadertoy.setUniform1f("cloudalpha",cloudalpha.get());
    shadertoy.setUniform1f("skytint",skytint.get());

    shadertoy.end();
    shadertoy.draw(0, 0, width, height);
    syphonFbo.end();
    
    syphonServer.publishTexture(&syphonFbo.getTexture());
    
    gui.draw();
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}
