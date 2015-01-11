#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowShape(600, 120);
	ofSetWindowTitle("ofxClipboard example");
	ofSetDrawBitmapMode(ofDrawBitmapMode::OF_BITMAPMODE_SIMPLE);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackgroundGradient(40, 10);
	
	stringstream status;
	status << "Keyboard actions:" << endl;
	status << "[c] = set clipboard text" << endl;
	status << "[v] = get clipboard text" << endl;

	ofPushMatrix();
	ofScale(2.0f, 2.0f);

	ofDrawBitmapString(status.str(), 10, 20);

	ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key) {
	case 'c':
		{
			// COPY
			string newClipboardContent = ofSystemTextBoxDialog("Set the clipboard text:");
			ofxClipboard::copy(newClipboardContent); //<<<<<<<<<<<<<<<<<

			break;
		}
	case 'v':
		{
			// PASTE 
			string clipboardContent = ofxClipboard::paste(); //<<<<<<<<<<<<<<<<<
			ofSystemAlertDialog(clipboardContent);

			break;
		}
	default:
		break;
	}
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
