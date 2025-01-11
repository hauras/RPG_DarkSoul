// Free to use, credit will be highly appreciated. 


#include "AnimInstances/CharacterBaseAnimInstance.h"
#include "Character/PlayerCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void UCharacterBaseAnimInstance::NativeInitializeAnimation()
{
	OwningCharacter = Cast<ACharacterBase>(TryGetPawnOwner());
	if (OwningCharacter)
	{
		OwningMovementComponent = OwningCharacter->GetCharacterMovement();
	}
}
void UCharacterBaseAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	if (!OwningCharacter || !OwningMovementComponent)
	{
		return;
	}

	// 속도 및 가속 상태 업데이트
	GroundSpeed = OwningCharacter->GetVelocity().Size2D();
	bHasAcceleration = OwningMovementComponent->GetCurrentAcceleration().SizeSquared2D() > 0.f;

	// **점프 상태 업데이트 추가**
	bIsInAir = OwningMovementComponent->IsFalling(); // 공중 여부 확인
	VerticalSpeed = OwningCharacter->GetVelocity().Z; // 수직 속도

	// **InAir 상태 블렌드 값 계산**
	if (bIsInAir) // 공중에 있을 때
	{
		// 상승 중 (점프 시작)
		if (VerticalSpeed > 10.f) // 일정 속도 이상 상승 중
		{
			InAir = 1.0f; // BS_Jump의 시작 부분
		}
		// 최고점 (Apex)
		else if (VerticalSpeed > -10.f && VerticalSpeed < 10.f) // 거의 정지 상태
		{
			InAir = 0.5f; // BS_Jump의 중간 부분
		}
		// 하강 중 (착지 준비)
		else
		{
			InAir = 0.25f; // 하강 부분
		}
	}
	else
	{
		// 착지 후
		InAir = 0.0f; // BS_Jump의 끝 부분 (착지 상태)
	}

	// **착지 상태 업데이트**
	bJustLanded = bWasInAir && !bIsInAir; // 공중에서 착지했는지 확인
	bWasInAir = bIsInAir;
}
