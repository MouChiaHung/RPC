 /*************************
  *  IAmoService.cpp
  *  
  *
  *  editor: amo
  *************************/
#include <stdlib.h>
#include <utils/RefBase.h>
#include <utils/Log.h>
#include <android/log.h>
#include <binder/TextOutput.h>

#include <IAmoService.h>

#include <binder/IInterface.h>
#include <binder/IBinder.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>
using namespace android;

/* -------------------------------------------------------------------- */
/* my define macro                                                      */
/* -------------------------------------------------------------------- */
#if 0
#define IMPLEMENT_META_INTERFACE(INTERFACE, NAME) \
	const android::String16 I##INTERFACE::descriptor(NAME);
	const android::getInterfaceDescriptor() const {return I##INTERFACE::descriptor;}
	android::sp<I##INTERFACE> I##INTERFACE::asInterface(const android::sp<android::IBinder>& obj)
	{
		android::sp<I##INTERFACE> intr;
		if(obj != NULL){
			/* calls to sp<T>& sp<T>::operator=(T*), retrieves IAmoService object corresponding to IBinder bbinder pointed by sp<T> */ 
			intr = static_cast<I##INTERFACE*>(obj->queryLocalInterface(I##INTERFACE::descriptor).get());
			if(intr == NULL){
				/* calls to BpAmoService(const sp<IBinder>& impl) */
				intr = new Bp##INTERFACE(obj);
			}
		}
		return intr;	
	}
	I##INTERFACE::I##INTERFACE() {}
	I##INTERFACE::I##~INTERFACE() {}
#endif
//IMPLEMENT_META_INTERFACE(AmoService, "android.amo.service");

const android::String16 IAmoService::descriptor("android.amo.service");
const android::String16& IAmoService::getInterfaceDescriptor() const {return IAmoService::descriptor;} 
android::sp<IAmoService> IAmoService::asInterface(const sp<IBinder>& obj)
{
	android::sp<IAmoService> isvc;
	if(obj != NULL){
		isvc = static_cast<IAmoService*>(obj->queryLocalInterface(IAmoService::descriptor).get());
		if(isvc == NULL) isvc = new BpAmoService(obj);
	}
	return isvc;
}
IAmoService::IAmoService(){ALOGD("[IAmoService::IAmoService()]: ***:%p", this);}
IAmoService::~IAmoService(){ALOGD("[IAmoService::~IAmoService()]: ***:%p", this);}

/* -------------------------------------------------------------------- */
/* global variables                                                     */
/* -------------------------------------------------------------------- */

/* -------------------------------------------------------------------- */
/* implements                                                           */
/* -------------------------------------------------------------------- */
/*
BpAmoService::BpAmoService(const sp<IBinder>& impl) :
	BpInterface<IAmoService>(impl);
{
	ALOGD("[BpAmoService::BpAmService(sp<IBinder>&)]: ###\n");
}
*/

void BpAmoService::amoLog()
{
	ALOGD("[BpAmoService::amoLog()]: >>>\n");
	Parcel data, reply;
	data.writeInterfaceToken(IAmoService::descriptor);
	remote()->transact(AMO, data, &reply);
	ALOGD("[BpAmoService::amoLog()]: ... got reply:%d\n", reply.readInt32());	
}

status_t BnAmoService::onTransact(uint_t code, const Parcel& data, Parcel* reply, uint32_t flags)
{
	ALOGD("[BnAmoService::onTransact()]: >>>(%x,%x)\n", code, flags);
	switch(code){
		case AMO:
			ALOGD("[BnAmoService::onTransact()]: ... code is AMO\n");
			CHECK_INTERFACE(IAmoService, data, reply);
			ALOGD("[BnAmoService::onTransact()]: ... going to amoLog()\n");
			amoLog();
			ALOGD("[BnAmoService::onTransact()]: ... going to reply->writeInt32()\n");
			reply->writeInt32(7589);
			break;
		default:
			ALOGD("[BnAmoService::onTransact()]: ... code is unknown\n");
			BBinder::onTransact(code, data, reply, flags);
			break;
	}
	ALOGD("[BnAmoService::onTransact()]: ... finished:%d\n", NO_ERROR);
	return NO_ERROR;
}

void BnAmoService::amoLog()
{
	ALOGD("[BnAmoService::amoLog()]: ### amo service here\n");
}
