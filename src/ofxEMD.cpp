#include "ofxEMD.h"

float dist(feature_t *F1, feature_t *F2) {
    int dX = F1->X - F2->X, dY = F1->Y - F2->Y, dZ = F1->Z - F2->Z;
    return sqrt(dX*dX + dY*dY + dZ*dZ);
}

double ofxEMD::getEmd(vector<ofVec3f> features1, vector<double> weights1, vector<ofVec3f> features2, vector<double> weights2) {
    int n1 = features1.size();
    int n2 = features2.size();
    feature_t f1[n1];
    feature_t f2[n2];
    float w1[n1];
    float w2[n2];
    
    for (int k=0; k<features1.size(); k++) {
        f1[k] = {static_cast<float>(features1[k][0]), static_cast<float>(features1[k][1]), static_cast<float>(features1[k][2])};
    }
    for (int k=0; k<features2.size(); k++) {
        f2[k] = {static_cast<float>(features2[k][0]), static_cast<float>(features2[k][1]), static_cast<float>(features2[k][2])};
    }
    
    int iw1 = 0, iw2 = 0;
    for (auto w : weights1) {
        w1[iw1++] = w;
    }
    for (auto w : weights2) {
        w2[iw2++] = w;
    }
    
    signature_t s1 = { n1, f1, w1};
    signature_t s2 = { n2, f2, w2};
    
    return emd(&s2, &s2, dist, 0, 0);
}