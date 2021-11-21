// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTriggerBox.h"

#include "DrawDebugHelpers.h"
#include "ExerciceSemaine2Character.h"

AMyTriggerBox::AMyTriggerBox()
{
    //Register Events
    OnActorBeginOverlap.AddDynamic(this, &AMyTriggerBox::OnOverlapBegin);
    OnActorEndOverlap.AddDynamic(this, &AMyTriggerBox::OnOverlapEnd);
}

// Called when the game starts or when spawned
void AMyTriggerBox::BeginPlay()
{
    Super::BeginPlay();

    if(healthValue<=0){
    DrawDebugBox(GetWorld(), GetActorLocation(), GetComponentsBoundingBox().GetExtent(), FColor::Purple, true, 999, 0, 5);
    }
    else if (healthValue > 0) {
        DrawDebugBox(GetWorld(), GetActorLocation(), GetComponentsBoundingBox().GetExtent(), FColor::Green, true, 999, 0, 5);
    }
}

void AMyTriggerBox::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{
    // check if Actors do not equal nullptr and that 
    if (OtherActor && OtherActor != this)
    {
        if (GEngine)
        {

            AExerciceSemaine2Character* Character = Cast<AExerciceSemaine2Character>(OtherActor);
            if (Character == nullptr)
                return;
            if (healthValue <= 0) {
                GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Red, TEXT("Health updated"));
            }
            else if (healthValue > 0) {
                GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Red, TEXT("Health updated"));
            }
            
            Character->TakeDamage(healthValue);
        }
    }
}

void AMyTriggerBox::OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor)
{
    if (OtherActor && OtherActor != this)
    {
        if (GEngine)
        {
           /* GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, TEXT("Overlap Ended"));
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString::Printf(TEXT("%s has left the Trigger Box"), *OtherActor->GetName()));*/
        }
    }
}