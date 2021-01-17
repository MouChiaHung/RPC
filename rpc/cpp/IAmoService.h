#ifndef _I_AMO_SERVICE_H_
#define _I_AMO_SERVICE_H_

#include <stdio.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IBinder.h>
#include <binder/Binder.h>
#include <binder/ProcessState.h>
#include <binder/IPCThreadState.h>
#include <binder/IServiceManager.h>

using namespace android;

class IAmoService : public IInterface
{
#if 0
#define DECLARE_META_INTERFACE(INTERFACE) \
	static const android::String16 descriptor;
	static android::sp<I##INTERFACE> asInterface(const android::sp<android::IBinder>& obj);
	virtual const android::String16& getInterfaceDescriptor() const;
	I##INTERFACE();
	virtual ~I##INTERFACE();
#endif
public:
	enum{
		AMO = 1
	};
	DECLARE_META_INTERFACE(AmoService);
	virtual void amoLog() = 0; 
};

class BpAmoService : public BpInterface<IAmoService>
{
	public:
		BpAmoService(const sp<IBinder>& impl): BpInterface<IAmoService>(impl){
			ALOGD("[BpAmoService::BpAmService(sp<IBinder>&)]: ###\n");
		}
		virtual void amoLog();
};

class BnAmoService : public BnInterface<IAmoService>
{
	public:
		virtual status_t onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flag=0);
		virtual void amoLog();
};


#endif
