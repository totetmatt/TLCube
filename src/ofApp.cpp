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
	/*                              ImageW     ImageH       NbImage	 RGBA  
														
		*/
	for (int z = 0; z < volDepth; z++) {
		imageSequence.loadFrame(z);
		//texture[z].loadData(imageSequence.getPixels());
		for (int y = 0; y < volHeight; y++) {
			for (int x = 0; x < volWidth; x++) {
				int i4 = ((x + volWidth * y) + z * volWidth * volHeight) * 4;
				ofColor c = imageSequence.getPixels().getColor(x + y * volWidth);
				volumeData[i4]     = c.r;
				volumeData[i4 + 1] = c.g;
				volumeData[i4 + 2] = c.b;
				volumeData[i4 + 3] = (char)1.0;
			}
		}
	}
	tex3d.loadData(volumeData, volWidth, volHeight, volDepth, 0, 0, 0, GL_RGBA);
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
