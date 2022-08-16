// Copyright (c) 2018 Isara Technologies. All Rights Reserved.
#include "AndroidAPITemplateFunctions.h"
#include "AndroidAPITemplatePrivatePCH.h"

#if PLATFORM_ANDROID

#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

#define INIT_JAVA_METHOD(name, signature) \
if (JNIEnv* Env = FAndroidApplication::GetJavaEnv(true)) { \
	name = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, #name, signature, false); \
	check(name != NULL); \
} else { \
	check(0); \
}

#define DECLARE_JAVA_METHOD(name) \
static jmethodID name = NULL;

DECLARE_JAVA_METHOD(AndroidThunkJava_AndroidAPI_LaunchRelieve);
DECLARE_JAVA_METHOD(AndroidThunkJava_AndroidAPI_LaunchRestore);
DECLARE_JAVA_METHOD(AndroidThunkJava_AndroidAPI_LaunchFirefox);

void UAndroidAPITemplateFunctions::InitJavaFunctions()
{
	// Same here, but we add the Java signature (the type of the parameters is between the parameters, and the return type is added at the end,
	// here the return type is V for "void")
	// More details here about Java signatures: http://www.rgagnon.com/javadetails/java-0286.html
	INIT_JAVA_METHOD(AndroidThunkJava_AndroidAPI_LaunchRelieve, "()V");
	INIT_JAVA_METHOD(AndroidThunkJava_AndroidAPI_LaunchRestore, "()V");
	INIT_JAVA_METHOD(AndroidThunkJava_AndroidAPI_LaunchFirefox, "()V");

}
#undef DECLARE_JAVA_METHOD
#undef INIT_JAVA_METHOD

#endif

void UAndroidAPITemplateFunctions::AndroidAPITemplate_LaunchRelieve()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv(true))
	{
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, AndroidThunkJava_AndroidAPI_LaunchRelieve);
	}
	else
	{
		UE_LOG(LogAndroid, Warning, TEXT("ERROR: Could not get Java ENV\n"));
	}
#endif
}

void UAndroidAPITemplateFunctions::AndroidAPITemplate_LaunchRestore()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv(true))
	{
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, AndroidThunkJava_AndroidAPI_LaunchRestore);
	}
	else
	{
		UE_LOG(LogAndroid, Warning, TEXT("ERROR: Could not get Java ENV\n"));
	}
#endif
}

void UAndroidAPITemplateFunctions::AndroidAPITemplate_LaunchFirefox()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv(true))
	{
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, AndroidThunkJava_AndroidAPI_LaunchFirefox);
	}
	else
	{
		UE_LOG(LogAndroid, Warning, TEXT("ERROR: Could not get Java ENV\n"));
	}
#endif
}