#pragma once

#include "ofMain.h"
#include "ofxVolumetrics.h"
class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		int volWidth, volHeight, volDepth;
		ofxImageSequencePlayer imageSequence;
		ofVideoPlayer video;
		ofImage img;
		ofShader shader;
		//ofTexture texture[3];
		//ofxVolumetrics myVolume;
		unsigned char* volumeData;
		ofxTexture3d tex3d;
		ofPixels* allPixels;

};
