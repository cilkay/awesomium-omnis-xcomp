///
/// WebMenuListener Header
/// 
/// 14.08.15/jm 
///
///

#ifndef _WEBMENULISTNER_HE_
#define _WEBMENULISTNER_HE_


/// Include required Header Files 
#include <Awesomium/WebCore.h>
#include <Awesomium/WebConfig.h>
#include <Awesomium/BitmapSurface.h>
#include <Awesomium/STLHelpers.h>
#include <Awesomium/Platform.h>
#include <Awesomium/WebString.h>
#include <Awesomium/WebStringArray.h>
#include <Awesomium/WebViewListener.h>
#include <Awesomium/DataPak.h>
#include "webLib.h"

// define NamesSpace 
namespace WebLib {

	class WebMenuListener : public Awesomium::WebViewListener::Menu {
		private:
			// Awsomium Vars
			HWND					mHWnd;
			
		public:
		
			WebMenuListener			(HWND pHWnd);
			~WebMenuListener			();
			
			/// This event occurs when the page requests to display a dropdown
			/// (popup) menu. This is usually the result of a user clicking on
			/// a "select" HTML input element. It is your responsibility to
			/// display this menu in your application. This event is not modal.
			///
			/// @see WebView::DidSelectPopupMenuItem
			/// @see WebView::DidCancelPopupMenu
			virtual void OnShowPopupMenu(Awesomium::WebView* caller,
										 const Awesomium::WebPopupMenuInfo& menu_info);

			/// This event occurs when the page requests to display a context menu.
			/// This is usually the result of a user right-clicking somewhere on the
			/// page. It is your responsibility to display this menu in your
			/// application and perform the selected actions. This event is not modal.
			virtual void OnShowContextMenu(Awesomium::WebView* caller,
										   const Awesomium::WebContextMenuInfo& menu_info) {};
	};
}  // namespace WebLib
#endif