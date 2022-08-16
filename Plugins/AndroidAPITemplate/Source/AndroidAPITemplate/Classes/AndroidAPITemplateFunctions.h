// Copyright (c) 2018 Isara Technologies. All Rights Reserved.

#pragma once

#include "AndroidAPITemplateFunctions.generated.h"

UCLASS(NotBlueprintable)
class UAndroidAPITemplateFunctions : public UObject {
	GENERATED_BODY()
	
public:

#if PLATFORM_ANDROID
	static void InitJavaFunctions();
#endif

	/**
	 * Displays a toast text on the screen
	 */
	UFUNCTION(BlueprintCallable, meta = (Keywords = "AndroidAPI ", DisplayName = "Launch ROVR Relieve"), Category = "ROVR Launcher")
		static void AndroidAPITemplate_LaunchRelieve();

	UFUNCTION(BlueprintCallable, meta = (Keywords = "AndroidAPI ", DisplayName = "Launch ROVR Restore"), Category = "ROVR Launcher")
		static void AndroidAPITemplate_LaunchRestore();

	UFUNCTION(BlueprintCallable, meta = (Keywords = "AndroidAPI ", DisplayName = "Launch Firefox"), Category = "ROVR Launcher")
		static void AndroidAPITemplate_LaunchFirefox();

	UFUNCTION(BlueprintCallable, meta = (Keywords = "AndroidAPI ", DisplayName = "Check Internet"), Category = "ROVR Launcher")
		static bool AndroidAPITemplate_CheckInternet();

	UFUNCTION(BlueprintCallable, meta = (Keywords = "AndroidAPI ", DisplayName = "Check Valid Connection"), Category = "ROVR Launcher")
		static bool AndroidAPITemplate_CheckValidConnection();
};
