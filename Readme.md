ofxClipboard
============

A simple addon for access to the system clipboard.

Currently supports :

* Windows
* OSX (untested)

Usage
-----

```c++
// Copy
ofxClipboard::copy(myTextString);

// Paste
myTextString = ofxClipboard::paste();
```

Credits
-------

Developed based on information in [this forum post](http://forum.openframeworks.cc/t/drag-amp-drop-copy-amp-paste/2296) thanks to:

* ascorbin
* gameover (hack?)

ofxClipboard is distrubuted under the [MIT License](http://en.wikipedia.org/wiki/MIT_License).