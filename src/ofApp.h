#pragma once

#include "ofMain.h"
#include "ofxiOS.h"
#include "ofxiOSExtras.h"
#include "ofxOsc.h"
#import "ofxUI.h"
#import "ofxJSONElement.h"

// listen on port 12345
#define PORT 12345
#define NUM_MSG_STRINGS 20

class ofApp : public ofxiOSApp {
public:
    void setup();
    void update();
    void draw();
    void exit();
    
    void touchDown(ofTouchEventArgs & touch);
    void touchMoved(ofTouchEventArgs & touch);
    void touchUp(ofTouchEventArgs & touch);
    void touchDoubleTap(ofTouchEventArgs & touch);
    void touchCancelled(ofTouchEventArgs & touch);
    
    void lostFocus();
    void gotFocus();
    void gotMemoryWarning();
    void deviceOrientationChanged(int newOrientation);
    
    //video and osc
    int count;
    void setupVideo();
    //void downloadVideos();
    //void changeVideo(string video);
    
    ofxOscReceiver receiver;
    
    int current_msg_string;
    string msg_strings[NUM_MSG_STRINGS];
    float timers[NUM_MSG_STRINGS];
    
    int mouseX;
    int mouseY;
    string mouseButtonState;
    float position;
    float currentMovie;
    ofVideoPlayer player;
    
    bool switchVideo;
    
    
    
    //ui
    ofxUICanvas *gui;
    ofxUIDropDownList *ddl;
    void setupUI();
    void guiEvent(ofxUIEventArgs &e);
    void updateDDL();
    bool debug;
    void drawDebug();
    
    
    //json
    ofxJSONElement response;
    std::stringstream ss;
    bool gotJSON;
    void getJSON();
    void updateJSONDebug();
    void loadJSON();
    
    void downloadVideos();
    
    ofURLFileLoader fileloader;
    void urlResponse(ofHttpResponse & response);
    
    void changeVideo(string video);
    
    
};

