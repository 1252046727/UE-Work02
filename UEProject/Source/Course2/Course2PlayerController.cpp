// Copyright Epic Games, Inc. All Rights Reserved.


#include "Course2PlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "HUD/SettlementWidget.h"

void ACourse2PlayerController::BeginPlay()
{
	Super::BeginPlay();

	// get the enhanced input subsystem
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		// add the mapping context so we get controls
		Subsystem->AddMappingContext(InputMappingContext, 0);
	}
}

void ACourse2PlayerController::ShowSettlementWidget(int32 FinalScore)
{
	if (SettlementWidgetClass != nullptr)
	{
		//暂停
		SetPause(true);
		//只能操控ui界面
		SetInputMode(FInputModeUIOnly());
		//显示鼠标光标
		bShowMouseCursor = true;
		SettlementWidget = CreateWidget<USettlementWidget>(this, SettlementWidgetClass);
		if (SettlementWidget != nullptr)
		{
			// 更新分数
			SettlementWidget->UpdateScoreText(FinalScore);
			SettlementWidget->AddToViewport();
		}
	}
}

void ACourse2PlayerController::HideSettlementWidget()
{
	SettlementWidget->RemoveFromParent();
	SettlementWidget->Destruct();
	SetPause(false);
	SetInputMode(FInputModeGameOnly());
	bShowMouseCursor = false;
}