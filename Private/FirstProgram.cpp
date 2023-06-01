// Copyright Epic Games, Inc. All Rights Reserved.


#include "FirstProgram.h"
#include "RequiredProgramMainCPPInclude.h"
#include "Framework/Application/SlateApplication.h"
#include "StandaloneRenderer.h"
#include "Widgets/SWindow.h"
#include "Math/Vector2D.h"
#include "SMyButton.h"
#include "SMyCanvas.h"
#include "Widgets/Text/STextBlock.h"
DEFINE_LOG_CATEGORY_STATIC(LogFirstProgram, Log, All);
IMPLEMENT_APPLICATION(FirstProgram, "FirstProgram");
int WINAPI WinMain(_In_ HINSTANCE hInInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR, _In_ int nCmdShow)
{
	// do the slate viewer thing
	GEngineLoop.PreInit(GetCommandLineW());
	//创建一个Window
	FSlateApplication::InitializeAsStandaloneApplication(GetStandardStandaloneRenderer());
	TSharedPtr<SMyCanvas> MyCanvas = SNew(SMyCanvas);
	TSharedPtr<SWindow> MainWindow = SNew(SWindow)
		.Title(FText::FromString("Wan Cheng Unreal OSS Resources Library"))
		.SupportsMaximize(false)//将最大化按钮隐藏掉
		.SupportsMinimize(false)//将最小化按钮隐藏掉
		.ClientSize(FVector2D(800.600))
		[
			MyCanvas.ToSharedRef()
		];
	//对Slate程序进行初始化
	FSlateApplication::Get().AddWindow(MainWindow.ToSharedRef());
	while (!IsEngineExitRequested()) {
		//如果有退出请求，直接退出，执行GetStandardStandaloneRenderer(),杀死进程。
		FSlateApplication::Get().PumpMessages();
		FSlateApplication::Get().Tick();
	}
	FSlateApplication::Shutdown();
	return 0;
}

