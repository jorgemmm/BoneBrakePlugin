// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGoreCharacter.h"
//Components
#include "Components/SkeletalMeshComponent.h"
#include "Components/PrimitiveComponent.h"
//Utils
#include "Engine/EngineTypes.h"

#define OUT

// Sets default values
ABaseGoreCharacter::ABaseGoreCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	UE_LOG(LogTemp, Warning, TEXT(" Hey your are a Base Character"))
	
		
	BoneName = TEXT("spine_01");
	BoneNames = { TEXT("spine_01") ,TEXT("lowerarm_r"),TEXT("lowerarm_l"), TEXT("calf_r"),TEXT("calf_l"),TEXT("hand_r"),TEXT("foot_l") };

	USkeletalMeshComponent* MyMeshComp = GetMesh();	
	MyMeshComp->OnComponentHit.AddDynamic(this, &ABaseGoreCharacter::OnCharacterHit);

	/**

	MyMeshComp->SetSimulatePhysics(true);
	MyMeshComp->SetNotifyRigidBodyCollision(true);
	MyMeshComp->BodyInstance.SetCollisionProfileName("BlockAllDynamic");
	MyMeshComp->BreakConstraint(FVector(100,300,100), GetActorLocation(), TEXT("spine_01"));

	*/
	

}

// Called when the game starts or when spawned
void ABaseGoreCharacter::BeginPlay()
{
	Super::BeginPlay();
	


}

// Called every frame
void ABaseGoreCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseGoreCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


void ABaseGoreCharacter::BreakBone(FVector Direction, FName inBoneName)
{
	USkeletalMeshComponent* MyMeshComp = GetMesh();


	/*MyMeshComp->BodyInstance.SetCollisionProfileName(TEXT("BlockAllDynamic"));
	MyMeshComp->SetSimulatePhysics(true);
	MyMeshComp->SetNotifyRigidBodyCollision(true);*/

	MyMeshComp->BreakConstraint(Direction, GetActorLocation(), inBoneName);
}
//Hazlo con un linetrace que lea el hueso y pase el FNANE que lea y 
//la direcci�n del hit (Normal Hit) A la funcion

//Busca la Logica similar en el proyecto simpleshooter Gun.h/cpp  
//return GetWorld()->LineTraceSingleByChannel(OUT Hit, EyeLocation, TraceEnd, COLLISION_WEAPON, QueryParams);


void ABaseGoreCharacter::OnCharacterHit(UPrimitiveComponent * HitComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, FVector NormalImpulse, const FHitResult & Hit)
{
	
	//BoneName aleatorio
	
	
	
	FName BoneNameToBrake;
	

	if ((OtherActor) && (OtherActor != this) && (OtherComp))
	{
		if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("I Hit: %s"), *OtherActor->GetName()));

		USkeletalMeshComponent* MyMeshComp = GetMesh();

		/*MyMeshComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		MyMeshComp->SetCollisionProfileName(TEXT("BlockAllDynamic"));*/
		MyMeshComp->BodyInstance.SetCollisionProfileName(TEXT("BlockAllDynamic"));
		MyMeshComp->SetSimulatePhysics(true);
		MyMeshComp->SetNotifyRigidBodyCollision(true);
		
		BoneNameToBrake = BoneName;

		MyMeshComp->BreakConstraint(NormalImpulse * 10, GetActorLocation(), BoneNameToBrake);
		
		if (BoneNames.Num() > 0)
		{ 
			BoneNameToBrake = BoneNames[FMath::RandRange(0, BoneNames.Num()-1)];

		   MyMeshComp->BreakConstraint(NormalImpulse, GetActorLocation(), BoneNameToBrake);
		}
		
		
		
		
		//MyMeshComp->BreakConstraint(NormalImpulse*10, GetActorLocation(), BoneName);


	}
}

