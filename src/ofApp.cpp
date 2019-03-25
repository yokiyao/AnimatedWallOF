#include "ofApp.h"

#define PORT 9000
//--------------------------------------------------------------
void ofApp::setup() {
	ofBackground(0,0,0);
	ofDisableAntiAliasing();

	//myvideo.load("video1.mp4");
	//myvideo.play();

	//udp setting
	ofxUDPSettings settings;
	settings.receiveOn(PORT);
	settings.blocking = false;
	udpConnection.Setup(settings);
	
	//trigger area number
	videoContainerNum = 3;
	//std::array<bool, 3> isTriggeredArray;
	//std::array<VideoContainer, 3> videoContainers;
	

	bHide = true;

	for (int i = 0; i < videoContainerNum; i++) {
		isTriggeredArray[i] = false;
	}


	//video containers
	//
	videoContainer0.setup("videoContainer0", "wall", "alpha-test-video-2");
	videoContainer1.setup("videoContainer1", "bunny", "alpha-test-video-2");
	videoContainer2.setup("videoContainer2", "countdown", "alpha-test-video-2");

	parameters.setName("settings");
	parameters.add(vSync.set("vSync", true));
	vSync.addListener(this, &ofApp::vSyncChanged);
	parameters.add(videoContainer0.parameters);
	parameters.add(videoContainer1.parameters);
	parameters.add(videoContainer2.parameters);

	gui.setup(parameters);

	gui.loadFromFile("settings.xml");

	font.load(OF_TTF_SANS, 9, true, true);
	ofEnableAlphaBlending();
}

//--------------------------------------------------------------
void ofApp::update() {
	//myvideo.update();

	char udpMessage[100000];
	udpConnection.Receive(udpMessage, 100000);
	string message = udpMessage;
	if (message != "") {
		stroke.clear();
		int x, y;
		vector<string> strData = ofSplitString(message, "/e/");
		for (unsigned int i = 0; i < strData.size(); i++) {
			vector<string> data = ofSplitString(strData[i], ",");
			if (data.size() == 2) {
				x = atof(data[0].c_str());
				y = atof(data[1].c_str());
				stroke.push_back(ofPoint(x, y));
			}
		}
		
		if (y == 1) {
			isTriggeredArray[x] = true;
			
		}
		else {
			isTriggeredArray[x] = false;

		}

		
		//printf(message.c_str() );
		


	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	
	videoContainer0.draw();
	videoContainer1.draw();
	videoContainer2.draw();
	

	
	//cout << ofGetWidth() << endl;
	//cout << ofGetHeight() << endl;
	
	if (!bHide) {
		font.drawString("frame:" + ofToString(videoContainer1.frameNum), ofGetWidth() - 150, 20);
		font.drawString("fps:" + ofToString((int)ofGetFrameRate()), ofGetWidth() - 150, 40);
		font.drawString("'h' -- hide ui", ofGetWidth() - 150, 60);
		font.drawString("'f' -- fullscreen", ofGetWidth() - 150, 80);
		font.drawString("'l' -- load xml", ofGetWidth() - 150, 100);
		font.drawString("'s' -- save xml", ofGetWidth() - 150, 120);

	}
	
	//for (int num = 0; num < videoContainerNum; num++) {
	//	if (isTriggeredArray[num]) {
	//		
	//	}
	//}

	if (isTriggeredArray[0]) {
		//ofSetHexColor(0xff0000);
		if (!bHide) ofDrawEllipse(10, 10, 50, 50);
		videoContainer0.isTriggered = true;
		videoContainer0.isContained = true;
	}
	else {
		if (!bHide) ofDrawEllipse(10, 10, 30, 30);
		videoContainer0.isContained = false;

		//videoContainer0.isTriggered = false;
		//ofSetHexColor(0x00ff00);
	}
	

	///////////////////////////////
	if (isTriggeredArray[1]) {
		//ofSetHexColor(0xff0000);
		if (!bHide) ofDrawEllipse(100, 10, 50, 50);
		videoContainer1.isTriggered = true;
		videoContainer1.isContained = true;

	}
	else {
		//ofSetHexColor(0x00ff00);
		if (!bHide) ofDrawEllipse(100, 10, 30, 30);
		videoContainer1.isContained = false;
		//videoContainer1.isTriggered = false;

	}
	
	///////////////////////////////

	if (isTriggeredArray[2]) {
		//ofSetHexColor(0xff0000);
		if (!bHide) ofDrawEllipse(200, 10, 50, 50);
		videoContainer2.isTriggered = true;
		videoContainer2.isContained = true;

	}
	else {
		//ofSetHexColor(0x00ff00);
		if (!bHide) ofDrawEllipse(200, 10, 30, 30);
		videoContainer2.isContained = false;

		//videoContainer2.isTriggered = false;
	}
	
	if (!bHide) {
		gui.draw();
		ofSetColor(255);
		ofDrawCircle(ofGetWidth() / 2, ofGetHeight() / 2, 5, 5);
	}
	

}

void ofApp::vSyncChanged(bool & vSync) {
	ofSetVerticalSync(vSync);
	ofLogNotice() << "vSync changed: " << vSync;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == 's') {
		ofSerialize(settings, parameters);
		settings.save("settings.xml");
	}
	if (key == 'l') {
		settings.load("settings.xml");
		ofDeserialize(settings, parameters);
	}
	if (key == 'o') {
		cout << videoContainer0.parameters;
		cout << videoContainer1.parameters;
		cout << videoContainer2.parameters;
	}

	if (key == 'f') {
		//ofSetFullscreen(false);
		ofToggleFullscreen();
	}

	if (key == 'h') {
		bHide = !bHide;
		videoContainer0.isHidden = !videoContainer0.isHidden;
		videoContainer1.isHidden = !videoContainer1.isHidden;
		videoContainer2.isHidden = !videoContainer2.isHidden;
	}

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
