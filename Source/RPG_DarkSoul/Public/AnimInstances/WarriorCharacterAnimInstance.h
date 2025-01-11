#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/CharacterBaseAnimInstance.h"
#include "WarriorCharacterAnimInstance.generated.h"

/**
 * 전사 캐릭터의 애니메이션 인스턴스 클래스
 */
UCLASS()
class RPG_DARKSOUL_API UWarriorCharacterAnimInstance : public UCharacterBaseAnimInstance
{
	GENERATED_BODY()

public:
    // 공격 몽타주 재생
    void PlayAttackMontage();

    // 몽타주의 특정 섹션으로 이동
    void JumpToSectionAttackMontage(uint8 SectionIndex);

protected:
    // 공격 몽타주
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Combat")
    UAnimMontage* AttackMontage;
};