// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"
//Components
#include "Components/SkeletalMeshComponent.h"
#include "Components/PrimitiveComponent.h"
//Utils
#include "Engine/EngineTypes.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();


	UE_LOG(LogTemp, Warning, TEXT(" Hey your are a Base Character"))

		USkeletalMeshComponent* MyMeshComp = GetMesh();
	    MyMeshComp->OnComponentHit.AddDynamic(this, &ABaseCharacter::OnCharacterHit);


	     /*MyMeshComp->SetSimulatePhysics(true);
	     MyMeshComp->SetNotifyRigidBodyCollision(true);
		 GetMesh()->BodyInstance.SetCollisionProfileName("BlockAllDynamic");
		
		
		 GetMesh()->BreakConstraint(FVector(100,0,100),GetActorLocation(), TEXT("spine_01"));*/

}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}




// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABaseCharacter::OnCharacterHit(UPrimitiveComponent * HitComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, FVector NormalImpulse, const FHitResult & Hit)
{
	//BoneName aleatorio
	
	if ( (OtherActor) && (OtherActor != this) && (OtherComp)  )
	{
		if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("I Hit: %s"), *OtherActor->GetName()));
		
		USkeletalMeshComponent* MyMeshComp = GetMesh();
		MyMeshComp->SetSimulatePhysics(true);
		MyMeshComp->SetNotifyRigidBodyCollision(true);
		MyMeshComp->BodyInstance.SetCollisionProfileName("BlockAllDynamic");
		MyMeshComp->BreakConstraint(NormalImpulse, GetActorLocation(), BoneName);
	}
}



