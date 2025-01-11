#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterBase.h"
#include "InputActionValue.h"
#include "PlayerCharacter.generated.h"

class UAnimMontage;

/**
 * 플레이어 캐릭터 클래스
 */
UCLASS()
class RPG_DARKSOUL_API APlayerCharacter : public ACharacterBase
{
    GENERATED_BODY()

public:
    APlayerCharacter();

    // 카메라 회전 처리
    void Look(const FInputActionValue& Value);

    // 공격 실행
    void PerformAttack();

protected:
    virtual void BeginPlay() override;

    // 공격 애니메이션 몽타주
    UPROPERTY(EditDefaultsOnly, Category = "Combat")
    UAnimMontage* AttackMontage;

private:
    bool bIsAttacking;  // 공격 상태
    int32 ComboIndex;   // 현재 콤보 단계

    // 공격 상태 초기화
    void ResetAttackState();

    // 몽타주 종료 시 호출될 함수
    UFUNCTION()
    void OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted);

    // 콤보 가능 여부를 설정
    void EnableNextCombo();
};