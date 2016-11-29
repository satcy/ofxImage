#pragma once

#include "ofImage.h"

#ifdef DISABLE_OFX_IMAGE
typedef ofImage ofxImage;
#else
class ofxImage : public ofImage{
protected:
    std::time_t lastTimestamp;
    string fileName;
public:
    ofxImage();
    ~ofxImage();
    
    bool load(string fileName);
    
    void enable();
    void disable();
    
    void update();
protected:
    void update(ofEventArgs &e);
};

#endif