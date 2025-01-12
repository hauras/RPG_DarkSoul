// Free to use, credit will be highly appreciated. 


#include "Notify/AttackHitCheckAnimNotify.h"
#include "Interface/AttackCheckInterface.h"

void UAttackHitCheckAnimNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
    Super::Notify(MeshComp, Animation, EventReference);

    if (MeshComp)
    {
        IAttackCheckInterface* AttackPawn = Cast<IAttackCheckInterface>(MeshComp->GetOwner());
        if (AttackPawn)
        {
            AttackPawn->AttackCheck();
        }
    }
}