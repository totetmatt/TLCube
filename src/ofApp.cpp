#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetLogLevel(OF_LOG_VERBOSE);



	shader.load("shader.vert", "shader.frag");
	imageSequence.init("./imgs/fromvideo/", 3, ".jpg", 1);
	volWidth = imageSequence.getWidth();
	volHeight = imageSequence.getHeight();
	volDepth = imageSequence.getSequenceLength();
	tex3d.allocate(volWidth,volHeight,volDepth,GL_RGB);


	// std::cout << volWidth << ": " << volHeight << ": "<< volDepth<< std::endl;


	for (int z = 0; z < volDepth; z++) {
		imageSequence.loadFrame(z);
		tex3d.loadData(imageSequence.getPixels(),1,0,0,z);
	
	}

}

//--------------------------------------------------------------
void ofApp::update(){
	
	
	float iTime = ofGetElapsedTimef();
	shader.begin();

		tex3d.bind();
			if(flagFilterModeLinear) {
				glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
				glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			} else {
				glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
				glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
			}
			shader.setUniform1i("tex3d", 0); // volume texture reference
		tex3d.unbind();
		shader.setUniform1f("iTime", iTime);
		shader.setUniform2f("iResolution", glm::vec2(ofGetWidth(), ofGetHeight()));
		shader.setUniform2f("iFrameSize", glm::vec2(volWidth, volHeight));
	shader.end();
}

//--------------------------------------------------------------
void ofApp::draw(){
	shader.begin();
	 ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
	shader.end();


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	shader.load("shader.vert", "shader.frag");

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (key == 'f') {
		flagFilterModeLinear = !flagFilterModeLinear;
	}
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
