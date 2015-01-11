#include "ofxClipboard.h"
#include "ofConstants.h"

//notes from : http://forum.openframeworks.cc/t/drag-amp-drop-copy-amp-paste/2296

namespace ofxClipboard {
#ifdef TARGET_WIN32

	//-----------
	bool copy(const string & content) {
		bool ok = false;
		if (OpenClipboard(NULL)){
			EmptyClipboard();
			HGLOBAL hClipboardData;
			hClipboardData = GlobalAlloc(GMEM_DDESHARE, content.size() + 1);
			char * pchData = (char*)GlobalLock(hClipboardData);
			strcpy(pchData, content.c_str());
			GlobalUnlock(hClipboardData);
			SetClipboardData(CF_TEXT, hClipboardData);
			CloseClipboard();
			ok = true;
		}
		return ok;
	}

	//-----------
	string paste() {
		string content = "";
		if (OpenClipboard(NULL)){
			HANDLE hClipboardData = GetClipboardData(CF_TEXT);
			if(IsClipboardFormatAvailable(CF_TEXT)){  
				char *pchData = (char*)GlobalLock(hClipboardData);  
				content.assign(pchData);
				GlobalUnlock(hClipboardData);  
				CloseClipboard();  
			}  
		}  
		return content;
	}

#elif TARGET_OSX

	//-----------
	bool copy(const string & content) {
		OSStatus             err = noErr;
		ItemCount            itemCount;
		PasteboardSyncFlags  syncFlags;
		static PasteboardRef inPasteboard = NULL;
		PasteboardCreate(kPasteboardClipboard, &inPasteboard);
		char* data;
		data = "";

		syncFlags = PasteboardSynchronize(inPasteboard);
		err = badPasteboardSyncErr;

		err = PasteboardGetItemCount(inPasteboard, &itemCount);
		require_noerr(err, CantGetPasteboardItemCount);

		for (int itemIndex = 1; itemIndex <= itemCount; itemIndex++) {
			PasteboardItemID  itemID;
			CFDataRef  flavorData;

			err = PasteboardGetItemIdentifier(inPasteboard, itemIndex, &itemID);
			require_noerr(err, CantGetPasteboardItemIdentifier);

			err = PasteboardCopyItemFlavorData(inPasteboard, itemID, CFSTR("public.utf8-plain-text"), &flavorData);
			data = (char*)CFDataGetBytePtr(flavorData);

			CantGetPasteboardItemIdentifier:
			;
		}

		CantGetPasteboardItemCount:

		return data;
	}

	//-----------
	string paste() {
		OSStatus err = noErr;  
		static PasteboardRef pasteboard = NULL;  
		PasteboardCreate(kPasteboardClipboard, &pasteboard);

		err = PasteboardClear(pasteboard);  
		require_noerr(err, PasteboardClear_FAILED);  

		CFDataRef data;

		data = CFDataCreate(kCFAllocatorDefault, (uchar_p*) byteArrayIndex, strlen(byteArrayIndex)+1);  
		err = PasteboardPutItemFlavor( pasteboard, (PasteboardItemID)1, kUTTypeUTF8PlainText, data, 0);   
		require_noerr( err, PasteboardPutItemFlavor_FAILED );  

		PasteboardPutItemFlavor_FAILED:	  
		PasteboardClear_FAILED:  
		return err;
	}

#else
	#warning ofxClipboard does not support your platform

	//-----------
	bool copy(const string & content) {
	}

	//-----------
	string paste() {
		return "";
	}

#endif	
}