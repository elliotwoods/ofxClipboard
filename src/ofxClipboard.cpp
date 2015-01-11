#include "ofxClipboard.h"
#include "ofAppRunner.h"
#include "ofAppGLFWWindow.h"

namespace ofxClipboard {
	string staticClipboard;

	//-----------
	void copy(const string & content) {
		ofAppGLFWWindow * window = (ofAppGLFWWindow *)ofGetWindowPtr();
		if (window) {
			glfwSetClipboardString(window->getGLFWWindow(), content.c_str());
		}
		else {
			ofxClipboard::staticClipboard = content;
		}
	}

	//-----------
	string paste() {
		ofAppGLFWWindow * window = (ofAppGLFWWindow *)ofGetWindowPtr();
		if (window) {
			return string(glfwGetClipboardString(window->getGLFWWindow()));
		}
		else {
			return ofxClipboard::staticClipboard;
		}
	}
}