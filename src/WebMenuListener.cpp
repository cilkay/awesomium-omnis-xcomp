///
/// WebMenuListener Impl
/// 
/// 14.08.15/jm
///
///

/// Include required Header Files 
#include <iostream>
#include <string>
#include <omnis/extcomp.he>
#include <omnis/extfval.he>
#include <omnis/hwnd.he>
#include <omnis/gdi.he>
#include "WebMenuListener.h"
#include "WebBrowser.h"

using namespace WebLib;

/*
	Constructor
*/
WebMenuListener::WebMenuListener(HWND pHWnd)
{
	mHWnd = pHWnd;	// Ref auf das Fenster via hwnd
}

/*
	Destructor
*/
WebMenuListener::~WebMenuListener()
{	
}

void WebMenuListener::OnShowPopupMenu(Awesomium::WebView* caller, const Awesomium::WebPopupMenuInfo& menu_info) {
	// Generate the popup menu
	HMENU hPopupMenu = CreatePopupMenu();
	for (size_t i = 0; i < menu_info.items.size(); i++) {
		const Awesomium::WebMenuItem& item = menu_info.items.At(i);
		if (item.type == Awesomium::kWebMenuItemType_Option)
			InsertMenu(hPopupMenu, i, MF_STRING | (i == menu_info.selected_item ? MF_CHECKED : MF_UNCHECKED), 
				1000 + i, Awesomium::ToString(item.label).c_str());
		else if (item.type == Awesomium::kWebMenuItemType_Group)
			InsertMenu(hPopupMenu, i, MF_DISABLED | MF_STRING, 1000 + i, 
				Awesomium::ToString(item.label).c_str());
	}

	// Display the menu and get the selected ID
	SetForegroundWindow(mHWnd);

	// Set the menu position.
	RECT rect;
	GetWindowRect(mHWnd, &rect);
	int selected_id = TrackPopupMenu(hPopupMenu, TPM_TOPALIGN | 
		TPM_LEFTALIGN | TPM_RETURNCMD,
		rect.left + menu_info.bounds.x, 
		rect.top + menu_info.bounds.y + 20, 0, mHWnd, NULL);

	// Handle the selected id
	if (selected_id >= 1000)
		caller->DidSelectPopupMenuItem(selected_id - 1000);
	else
		caller->DidCancelPopupMenu();
}
