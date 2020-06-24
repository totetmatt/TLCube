#pragma once

#include "ofMain.h"
#include "ofxVolumetrics.h"
#include "ofxGui.h"
class ofApp : public ofBaseApp{

	public:
		static const string VERSION;
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

		void refreshTexture();

		int volWidth, volHeight, volDepth;
		ofxImageSequencePlayer imageSequence;

		ofShader shader;

		ofxTexture3d tex3d;
		
		ofxPanel gui;
		ofxLabel label;
		ofxTextField path;// imageSequence.init("I:\\TestCube\\out", 2, ".png", 1);
		ofxIntField digit;
		ofxTextField ext;
		ofxIntField start;
		ofxButton reloadTexture;




		bool flagFilterModeLinear = true;

};
