 /*************************
  *  main_client.cpp
  *  
  *
  *  editor: amo
  *************************/
#include <stdlib.h>
#include <utils/RefBase.h>
#include <utils/Log.h>
#include <android/log.h>

#include <IAmoService.h>

#include <binder/IInterface.h>
#include <binder/IBinder.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>
using namespace android;

/* -------------------------------------------------------------------- */
/* my define macro                                                     */
/* -------------------------------------------------------------------- */

/* -------------------------------------------------------------------- */
/* global variables                                                     */
/* -------------------------------------------------------------------- */
sp<IServiceManager> sm;
sp<IBinder> bpbinder;
sp<IAmoService> isvc;

/* -------------------------------------------------------------------- */
/* implements                                                           */
/* -------------------------------------------------------------------- */
int main(__unused int argc, __unused char **argv)
{
	ALOGD("[main_client]: >>>");
	sm = defaultServiceManager();
	if(sm == NULL){
		ALOGD("[main_client]: !!! sm is null");
		goto exit;
	}
	bpbinder = sm->getService(IAmoService::descriptor);
	if(bpbinder == NULL){
		ALOGD("[main_client]: !!! bpbinder is null");
		goto exit;
	}
	isvc = interface_cast<IAmoService>(bpbinder);
	if(isvc == NULL){
		ALOGD("[main_client]: !!! isvc is null");
		goto exit;
	}
	ALOGD("[main_client]: ... going to isvc->amoLog()");
	isvc->amoLog();
	
exit:	
	ALOGD("[main_client]: ... finished");
	return 0;
}
