#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetLogLevel(OF_LOG_VERBOSE);
	/*ofLoadImage(texture[0], "01.JPG");
	ofLoadImage(texture[1], "02.JPG");
	ofLoadImage(texture[2], "03.JPG");*/



	shader.load("shader.vert", "shader.frag");
	imageSequence.init("./", 2, ".JPG", 1);
	volWidth = imageSequence.getWidth();
	volHeight = imageSequence.getHeight();
	volDepth = imageSequence.getSequenceLength();
	tex3d.allocate(volWidth,volHeight,volDepth,GL_RGBA);


	std::cout << volWidth << ": " << volHeight << ": "<< volDepth<< std::endl;
	volumeData = new unsigned char[volWidth * volHeight * volDepth * 4];
	for (int z = 0; z < volDepth; z++) {
		imageSequence.loadFrame(z);
		//texture[z].loadData(imageSequence.getPixels());
		for (int x = 0; x < volWidth; x++) {
			for (int y = 0; y < volHeight; y++) {
				
				int i4 = ((x + volWidth * y) + z * volWidth * volHeight) * 4;
				ofColor c = imageSequence.getPixels().getColor(x + y * volWidth);

				volumeData[i4]     = c.r;
				volumeData[i4 + 1] = c.g;
				volumeData[i4 + 2] = c.b;
				volumeData[i4 + 3] = 0.0f;

				
			}
		}
	}

	//myVolume.setup(volWidth, volHeight, volDepth, ofVec3f(1, 1, 2), true);
	//myVolume.updateVolumeData(volumeData, volWidth, volHeight, volDepth, 0, 0, 0);
	tex3d.loadData(volumeData, volWidth, volHeight, volDepth, 0, 0, 0, GL_RGB);
	//myVolume.setRenderSettings(1.0, 1.0, 0.75, 0.5);

	
	

}

//--------------------------------------------------------------
void ofApp::update(){

	float iTime = ofGetElapsedTimef();
	shader.begin();


		tex3d.bind();
			shader.setUniform1i("tex3d", 0); // volume texture reference
		tex3d.unbind();



	shader.setUniform1f("iTime", iTime);
	shader.setUniform2f("iResolution", glm::vec2(ofGetWidth(), ofGetHeight()));
	shader.setUniform2f("iFrameSize", glm::vec2(volWidth, volHeight));
	//shader.setUniformTexture("tex", texture[0], 0);
	
	shader.end();
}

//--------------------------------------------------------------
void ofApp::draw(){
	shader.begin();
	 ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
	shader.end();
	/*
	ofSetColor(255, 255, 255, 255);

	  
	cam.begin();
	myVolume.drawVolume(0, 0, 0, ofGetHeight(), 0);
	cam.end();

	ofSetColor(0, 0, 0, 64);
	ofDrawRectangle(0, 0, 270, 90);
	ofSetColor(255, 255, 255, 255);

	ofDrawBitmapString("volume dimensions: " + ofToString(myVolume.getVolumeWidth()) + "x" + ofToString(myVolume.getVolumeHeight()) + "x" + ofToString(myVolume.getVolumeDepth()) + "\n" +
		"FBO quality (q/Q): " + ofToString(myVolume.getRenderWidth()) + "x" + ofToString(myVolume.getRenderHeight()) + "\n" +
		"Z quality (z/Z):   " + ofToString(myVolume.getZQuality()) + "\n" +
		"Threshold (t/T):   " + ofToString(myVolume.getThreshold()) + "\n" +
		"Density (d/D):     " + ofToString(myVolume.getDensity()) + "\n" , 20, 20);*/

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
