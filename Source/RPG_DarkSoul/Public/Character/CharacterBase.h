// Free to use, credit will be highly appreciated. 

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterBase.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class RPG_DARKSOUL_API ACharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	ACharacterBase();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category ="Camera")
	UCameraComponent* FollowCamera;
};
