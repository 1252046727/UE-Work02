// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Course2PlayerController.generated.h"

class UInputMappingContext;
class USettlementWidget;
/**
 *
 */
UCLASS()
class COURSE2_API ACourse2PlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere)
	TSubclassOf<USettlementWidget> SettlementWidgetClass;

	void ShowSettlementWidget(int32 FinalScore);
	void HideSettlementWidget();

protected:

	/** Input Mapping Context to be used for player input */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputMappingContext* InputMappingContext;

	// Begin Actor interface
protected:

	virtual void BeginPlay() override;

	// End Actor interface
private:
	UPROPERTY()
	TObjectPtr<USettlementWidget> SettlementWidget;
};
