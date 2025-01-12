// Free to use, credit will be highly appreciated. 

#include "Character/CharacterBase.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ACharacterBase::ACharacterBase()
{
    // 충돌 및 회전 설정
    GetCapsuleComponent()->SetCollisionProfileName(TEXT("RPGCapsule"));
    GetMesh()->SetCollisionProfileName(TEXT("NoCollision"));

	// 컨트롤러 회전 설정 비활성화
    bUseControllerRotationPitch = false;
    bUseControllerRotationYaw = false;
    bUseControllerRotationRoll = false;

	// 카메라 설정
    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
    SpringArm->SetupAttachment(GetRootComponent());
    SpringArm->TargetArmLength = 200.f;
    SpringArm->SocketOffset = FVector(0.f, 55.f, 65.f);
    SpringArm->bUsePawnControlRotation = true;

    FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
    FollowCamera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
    FollowCamera->bUsePawnControlRotation = false;

	// 캐릭터 이동 설정
    GetCharacterMovement()->bOrientRotationToMovement = true;
    GetCharacterMovement()->RotationRate = FRotator(0.f, 500.f, 0.f);
    GetCharacterMovement()->MaxWalkSpeed = 400.f;
    GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
}

void ACharacterBase::AttackCheck()
{
    UE_LOG(LogTemp, Warning, TEXT("AuroraCharacter AttackCheck called!"));

    // 충돌 검사 매개변수 설정
    FCollisionQueryParams Params(SCENE_QUERY_STAT(Attack), false, this); // 충돌 쿼리 파라미터 생성
    FHitResult OutHitResult; // 충돌 결과 저장 변수

    // 공격 범위 및 반경 설정
    const float AttackRange = 40.0f; // 공격 거리
    const float AttackRadius = 50.0f; // 공격 범위 반경
    const float AttackDamage = 30.0f; // 공격 데미지

    // 충돌 검사 시작 및 종료 지점 계산
    const FVector Start = GetActorLocation() + GetActorForwardVector() * GetCapsuleComponent()->GetScaledCapsuleRadius(); // 시작 지점
    const FVector End = Start + GetActorForwardVector() * AttackRange; // 종료 지점

    // 충돌 검사 실행
    bool HitDetected = GetWorld()->SweepSingleByChannel(
        OutHitResult, // 결과 저장
        Start,        // 시작 지점
        End,          // 종료 지점
        FQuat::Identity, // 회전
        ECollisionChannel::ECC_GameTraceChannel1, // 충돌 채널 설정
        FCollisionShape::MakeSphere(AttackRadius), // 구체 형태 설정
        Params); // 쿼리 파라미터 적용

    if (HitDetected) // 충돌 발생 시 처리 (현재 비어 있음)
    {
        // 충돌 처리 로직 추가 가능
    }

    // 디버그 캡슐 출력
#if ENABLE_DRAW_DEBUG
    FVector CapsuleOrigin = Start + (End - Start) * 0.5f; // 캡슐 중심 계산
    float CapsuleHalfHeight = AttackRange * 0.5f; // 캡슐 높이 설정
    FColor DrawColor = HitDetected ? FColor::Green : FColor::Red; // 충돌 여부에 따른 색상 설정

    // 캡슐 그리기
    DrawDebugCapsule(
        GetWorld(),
        CapsuleOrigin,
        CapsuleHalfHeight,
        AttackRadius,
        FRotationMatrix::MakeFromZ(GetActorForwardVector()).ToQuat(),
        DrawColor,
        false,
        5.0f // 5초 동안 표시
    );
#endif
}
