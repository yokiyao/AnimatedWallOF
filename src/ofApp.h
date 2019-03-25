#pragma once

#include "ofMain.h"
#include "ofxNetwork.h"  
#include "ofxGui.h"
#include "VideoContainer.h"



class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	//includes
	
	ofxUDPManager udpConnection;


	//udp stuffs
	string receivedMSG;
	vector<ofPoint> stroke;

	void vSyncChanged(bool & vSync);
	//gui
	ofxPanel gui;
	ofParameter<bool> vSync;
	ofParameterGroup parameters;
	ofXml settings;

	//video container
	VideoContainer videoContainer0, videoContainer1, videoContainer2;

	ofTrueTypeFont font;


	//ofVideoPlayer myvideo;

	bool bHide;
	int videoContainerNum;
	bool isTriggeredArray[0];

	
	
};
