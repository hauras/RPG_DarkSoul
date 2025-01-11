#include "Character/PlayerCharacter.h"
#include "Animation/AnimInstance.h"

APlayerCharacter::APlayerCharacter()
{
    bIsAttacking = false;  // 초기 상태
    ComboIndex = 0;        // 초기 콤보 단계
}

void APlayerCharacter::BeginPlay()
{
    Super::BeginPlay();
}

void APlayerCharacter::Look(const FInputActionValue& Value)
{
    FVector2D LookAxisVector = Value.Get<FVector2D>();
    AddControllerYawInput(LookAxisVector.X);
    AddControllerPitchInput(LookAxisVector.Y);
}

void APlayerCharacter::PerformAttack()
{
    if (bIsAttacking) return; // 공격 중이면 실행하지 않음
    if (!AttackMontage) return; // 몽타주가 없으면 실행하지 않음

    UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
    if (!AnimInstance) return;

    // 공격 시작
    bIsAttacking = true;

    // 콤보 섹션 이름 생성
    FName SectionName = FName(*FString::Printf(TEXT("Attack%d"), ComboIndex + 1));

    // 디버깅 로그 추가
    UE_LOG(LogTemp, Log, TEXT("Attempting to jump to section: %s"), *SectionName.ToString());

    // 몽타주 재생 또는 섹션으로 이동
    if (!AnimInstance->Montage_IsPlaying(AttackMontage))
    {
        AnimInstance->Montage_Play(AttackMontage);
        UE_LOG(LogTemp, Log, TEXT("Montage_Play called."));
    }

    AnimInstance->Montage_JumpToSection(SectionName, AttackMontage);
    UE_LOG(LogTemp, Log, TEXT("Montage_JumpToSection called for section: %s"), *SectionName.ToString());

    // OnMontageEnded 델리게이트 연결
    AnimInstance->OnMontageEnded.AddDynamic(this, &APlayerCharacter::OnAttackMontageEnded);

    // 다음 콤보 준비
    GetWorld()->GetTimerManager().SetTimerForNextTick(this, &APlayerCharacter::EnableNextCombo);
}

void APlayerCharacter::EnableNextCombo()
{
    if (ComboIndex < 2) // 최대 콤보 단계 (3단계까지)
    {
        ComboIndex++;
    }
    else
    {
        ComboIndex = 0; // 마지막 단계 이후 초기화
    }
}

void APlayerCharacter::OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted)
{
    if (Montage == AttackMontage)
    {
        ResetAttackState();

        // 델리게이트 해제
        UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
        if (AnimInstance)
        {
            AnimInstance->OnMontageEnded.RemoveDynamic(this, &APlayerCharacter::OnAttackMontageEnded);
        }
    }
}

void APlayerCharacter::ResetAttackState()
{
    bIsAttacking = false; // 공격 상태 초기화
}