// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseGoreCharacter.generated.h"

class UPrimitiveComponent;

UCLASS()
class GOREMOD_API ABaseGoreCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseGoreCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
		void OnCharacterHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExploteBone")//, meta = (AllowPrivateAccess = "true"))
		FName BoneName = TEXT("spine_01");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExploteBone")
		TArray<FName> BoneNames; 

	UFUNCTION(BlueprintCallable)
		void BreakBone(FVector Direction,FName inBoneName);
};
