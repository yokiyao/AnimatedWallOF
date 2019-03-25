

#ifndef VIDEOCONTAINER_H_
#define VIDEOCONTAINER_H_

#include "ofParameterGroup.h"
#include "ofParameter.h"
#include "ofMain.h"
#include "ofxDSHapVideoPlayer.h"

class VideoContainer;

template<typename ParameterType>
class ofVideoContainerParam : public ofReadOnlyParameter<ParameterType, VideoContainer> {
	friend class VideoContainer;
};

class VideoContainer {
public:
	VideoContainer();

	void setup(string videoContainerID, string yourVideoName, string videoName);
	void draw();
	//void update();

	ofParameterGroup parameters;
	ofParameter<string> myVideoName;
	ofParameter<glm::vec2> center;
	ofParameter<float> width;
	ofParameter<float> height;
	ofVideoContainerParam<int> frameNum;

	//ofVideoPlayer myPlayer;
	ofxDSHapVideoPlayer myPlayer;

	bool isTriggered;
	bool isDone;
	bool isPlaying;
	bool isContained;
	bool isHidden;
};

#endif /* VIDEOCONTAINER_H_ */
