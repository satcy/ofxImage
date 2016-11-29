//
//  ofxShaderOnTheFly.cpp
//  onmyaku
//
//  Created by satcy on 2016/01/05.
//
//
#ifdef DISABLE_OFX_SHADER_ON_THE_FLY
#else
#include "ofxImage.h"
ofxImage::ofxImage() {
    fileName = "";
}

ofxImage::~ofxImage(){
    disable();
}

bool ofxImage::load(string fileName){
    this->fileName = fileName;
    enable();
    return ofImage::load(fileName);
}

void ofxImage::enable(){
    ofAddListener(ofEvents().update, this, &ofxImage::update);
}

void ofxImage::disable(){
    ofRemoveListener(ofEvents().update, this, &ofxImage::update);
}
void ofxImage::update(){
    if ( ofGetFrameNum()%100 == 0 ) {
        ofFile file(fileName);
        
        std::time_t timestamp = std::filesystem::last_write_time(file);
        
        if(lastTimestamp != timestamp ) {
            load(fileName);
        }
        
        lastTimestamp = timestamp;
    }
}

void ofxImage::update(ofEventArgs &e){
    update();
}
#endif