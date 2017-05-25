#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255);
	ofEnableDepthTest();
	ofSetFrameRate(24);
	ofSetWindowTitle("NoiseBox");

	this->x_noise = ofRandom(10.0);
	this->y_noise = ofRandom(10.0);
	this->z_noise = ofRandom(10.0);

	this->box_size = 4;

	this->light.setPosition(ofVec3f(0, 256, 512));
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	cam.begin();

	ofEnableLighting();
	this->light.enable();

	float tmp_x_noise = x_noise;
	float tmp_y_noise = y_noise;
	float tmp_z_noise = z_noise;
	float noise_span = 0.025;

	float box_span = box_size;

	for (int x = 0; x <= this->x_len; x++) {

		tmp_x_noise += noise_span;
		tmp_y_noise = y_noise;
		for (int y = 0; y <= this->y_len; y++) {

			tmp_y_noise += noise_span;
			tmp_z_noise = z_noise;
			for (int z = 0; z <= this->z_len; z++) {
				ofVec3f location = ofVec3f(x * box_span - (this->x_len * box_span) / 2, y * box_span - (this->y_len * box_span) / 2, z * box_span - (this->z_len * box_span) / 2);
				float dist = location.distance(ofVec3f(0, 0, 0));
				float noise_value = ofNoise(tmp_x_noise, tmp_y_noise, tmp_z_noise, ofGetFrameNum() * noise_span);
				if (dist > 126 && dist < 130) {
					ofColor c;

					ofPushMatrix();
					if (noise_value < 0.33) {
						ofTranslate(location * (1 + noise_value));
						c = ofColor(0, 0, 255);
					} else if(noise_value > 0.66) {
						c = ofColor(0, 255, 0);
						ofTranslate(location * (1.25 + noise_value));
					} else {
						c = ofColor(255, 0, 0);
						ofTranslate(location * (1.5 + noise_value));
					}
					ofSetColor(c);
					//ofBox(this->box_size * (noise_value > 0.5 ? noise_value : 1 - noise_value));
					ofBox(this->box_size);
					ofPopMatrix();
				}

				tmp_z_noise += noise_span;
			}
		}
	}

	//this->x_noise += noise_span;
	//this->y_noise -= noise_span;
	this->z_noise += noise_span;

	cam.end();
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
