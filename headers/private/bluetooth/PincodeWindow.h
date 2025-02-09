/*
* Copyright 2021, Haiku, Inc.
* Distributed under the terms of the MIT License.
*
* Authors:
*		Oliver Ruiz Dorantes <oliver.ruiz.dorantes@gmail.com>
* 		Tri-Edge AI <triedgeai@gmail.com>
*/

#ifndef	_PINCODE_REQUEST_WINDOW_H_
#define	_PINCODE_REQUEST_WINDOW_H_


#include <View.h>
#include <Window.h>

#include <bluetooth/bluetooth.h>
#include <bluetooth/HCI/btHCI.h>

#include <BluetoothIconView.h>

class BStringView;
class BButton;
class BTextControl;

namespace Bluetooth {

class RemoteDevice;

class PincodeWindow : public BWindow {
public:
							PincodeWindow(bdaddr_t address, hci_id hid);
							PincodeWindow(RemoteDevice* rDevice);
	virtual void			MessageReceived(BMessage* msg);
	virtual bool			QuitRequested();
			void			SetBDaddr(BString address);

private:
			void			InitUI();
			bdaddr_t		fBdaddr;
			hci_id			fHid;

			BStringView*	fMessage;
			BStringView*	fRemoteInfo;
			BButton*		fAcceptButton;
			BButton*		fCancelButton;
			BTextControl*	fPincodeText;

			BluetoothIconView* 	fIcon;
			BStringView*		fMessage2;
			BStringView*		fDeviceLabel;
			BStringView*		fDeviceText;
			BStringView*		fAddressLabel;
			BStringView*		fAddressText;
};

}

#ifndef	_BT_USE_EXPLICIT_NAMESPACE
using Bluetooth::PincodeWindow;
#endif

#endif /* _PINCODE_REQUEST_WINDOW_H_ */
