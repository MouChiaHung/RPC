 /*************************
  *  main_server.cpp
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

/* -------------------------------------------------------------------- */
/* implements                                                           */
/* -------------------------------------------------------------------- */
int main(__unused int argc, __unused char **argv)
{
	ALOGD("[main_server]: >>>");
	sm = defaultServiceManager();
	if(sm == NULL){
		ALOGD("[main_server]: !!! sm is null");
		goto exit;
	}
	sm->addService(IAmoService::descriptor, new BnAmoService());
	ALOGD("[main_server]: going to ProcessState::self()->startThreadPool()");
	ProcessState::self()->startThreadPool();
	ALOGD("[main_server]: after ProcessState::self()->startThreadPool()");

	ALOGD("[main_server]: going to IPCThreadState::self()->joinThreadPool()");
	IPCThreadState::self()->joinThreadPool();
	ALOGD("[main_server]: after IPCThreadState::self()->joinThreadPool()");
exit:	
	ALOGD("[main_server]: ... finished");
	return 0;
}
