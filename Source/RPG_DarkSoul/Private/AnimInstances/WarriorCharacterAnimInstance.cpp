#include "GameFramework/Actor.h"
#include "AnimInstances/WarriorCharacterAnimInstance.h"

void UWarriorCharacterAnimInstance::PlayAttackMontage()
{
    if (!AttackMontage) return;

    // 공격 몽타주 재생
    Montage_Play(AttackMontage);
}

void UWarriorCharacterAnimInstance::JumpToSectionAttackMontage(uint8 SectionIndex)
{
    if (!AttackMontage) return;

    // 섹션 이름 생성 (예: "Attack1", "Attack2", "Attack3")
    FName SectionName = FName(*FString::Printf(TEXT("Attack%d"), SectionIndex));
    Montage_JumpToSection(SectionName, AttackMontage);
}