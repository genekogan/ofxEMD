#pragma once

#include "emd.h"
#include "ofMain.h"

class ofxEMD {
public:
    double getEmd(vector<ofVec3f> features1, vector<double> weights1, vector<ofVec3f> features2, vector<double> weights2);
};
