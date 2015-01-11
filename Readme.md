ofxClipboard
============

A simple addon for access to the system clipboard.

Currently supports :

* Windows
* OSX (untested)

Usage
-----

### Copy :

```c++
ofxClipboard::copy(myTextString);
```

### Paste :

```c++
myTextString = ofxClipboard::paste();
```

Credits
-------

Based on information in the forum post [http://forum.openframeworks.cc/t/drag-amp-drop-copy-amp-paste/2296]. Thanks to:

* ascorbin
* gameover (hack?)