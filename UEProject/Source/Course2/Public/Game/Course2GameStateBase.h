// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "Course2GameStateBase.generated.h"

class ABlockActor;
/**
 * 
 */
UCLASS()
class COURSE2_API ACourse2GameStateBase : public AGameStateBase
{
	GENERATED_BODY()

public:
	//����
	UPROPERTY(EditAnywhere)
	int32 X;
	//���ű���
	UPROPERTY(EditAnywhere)
	float Y;
	//��ҪĿ������
	UPROPERTY(EditAnywhere, meta = (ClampMin = "0", ClampMax = "10"))
	int32 N;
	//�÷�
	UPROPERTY()
	int32 Score;
	//��Ϸʱ��(��)
	UPROPERTY(EditAnywhere)
	float T;

	// ��Ҫ����Ĳ���
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Materials")
	TObjectPtr<UMaterialInterface> ImportantMaterial;

	UPROPERTY()
	TObjectPtr<ABlockActor> NewBlock;
	//Block
	UPROPERTY(EditAnywhere)
	TSubclassOf<ABlockActor> BlockActorClass;

protected:
	virtual void BeginPlay() override;

private:
	// ��ʱ�����
	FTimerHandle GameEndTimerHandle;

	void EndGame();
};