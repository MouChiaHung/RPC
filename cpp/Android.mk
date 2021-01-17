LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := amos
LOCAL_MODULE_TAGS := optional
LOCAL_C_INCLUDES := ./\

LOCAL_SRC_FILES += 	main_server.cpp \
					IAmoService.cpp
LOCAL_SHARED_LIBRARIES := libutils libcutils libbinder liblog
LOCAL_C_INCLUDES += frameworks/native/include system/core/include
include $(BUILD_EXECUTABLE)

include $(CLEAR_VARS)
LOCAL_MODULE := amoc
LOCAL_MODULE_TAGS := optional
LOCAL_C_INCLUDES := ./\
					
LOCAL_SRC_FILES += 	main_client.cpp \
					IAmoService.cpp
LOCAL_SHARED_LIBRARIES := libutils libcutils libbinder liblog
LOCAL_C_INCLUDES += frameworks/native/include system/core/include
include $(BUILD_EXECUTABLE)