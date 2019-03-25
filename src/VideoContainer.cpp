

#include "VideoContainer.h"

VideoContainer::VideoContainer() {
	// TODO Auto-generated constructor stub
	isHidden = true;
}

//yourVideoName == the name you want to show in UI
//videoFileName == file name
void VideoContainer::setup(string videoContainerID, string yourVideoName, string videoFileName) {
	parameters.setName(videoContainerID);
	//parameters.setName(yourVideoName);
	parameters.add(myVideoName.set("yourVideoName", yourVideoName));
	parameters.add(center.set("center", glm::vec2(ofGetWidth()*.5, ofGetHeight()*.5), glm::vec2(0, 0), glm::vec2(ofGetWidth(), ofGetHeight())));
	parameters.add(width.set("width", 480, 0, 1920));
	parameters.add(height.set("height", 270, 0, 1080));
	//color.set("color", ofColor(127), ofColor(0, 0), ofColor(255));

	//parameters.add(color);
	parameters.add(frameNum.set("frameNum", 0));

	//video
	myPlayer.load(videoFileName + ".avi");
	myPlayer.setLoopState(OF_LOOP_NONE);
	
}


void VideoContainer::draw() {

	frameNum++;
	isDone = myPlayer.getIsMovieDone();
	isPlaying = myPlayer.isPlaying();


	if (isTriggered) {
		myPlayer.update();
		myPlayer.play();
		myPlayer.draw(center.get().x, center.get().y, width, height);
		//cout << myPlayer.getCurrentFrame() << endl;
		//cout << myPlayer.getLoopState() << endl;
	}

	if (myPlayer.getCurrentFrame() == myPlayer.getTotalNumFrames() && !isContained) {
		//myPlayer.setFrame(1);
		myPlayer.stop();
		//myPlayer.draw(center.get().x, center.get().y, width, height);
		isTriggered = false;
		//cout << myPlayer.getCurrentFrame() << endl;
	}
	if (!isHidden) {
		ofNoFill();
		ofSetColor(255, 0, 0);
		ofDrawRectangle(center.get().x, center.get().y, width, height);

		ofSetColor(255);
	}
	
	/*if (isDone) {
		isTriggered = false;
	}*/
	
	


	
	//ofSetColor(100);
	//ofDrawCircle(changedx, center.get().y, 10, 10);

}
