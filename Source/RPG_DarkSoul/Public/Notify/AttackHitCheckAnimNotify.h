// Free to use, credit will be highly appreciated. 

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "AttackHitCheckAnimNotify.generated.h"

/**
 * 
 */
UCLASS()
class RPG_DARKSOUL_API UAttackHitCheckAnimNotify : public UAnimNotify
{
	GENERATED_BODY()

protected:
    virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;	
};
