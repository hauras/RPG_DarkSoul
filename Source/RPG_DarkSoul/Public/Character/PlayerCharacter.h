// Free to use, credit will be highly appreciated. 

#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterBase.h"
#include "InputActionValue.h"
#include "PlayerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;

/**
 * 
 */
UCLASS()
class RPG_DARKSOUL_API APlayerCharacter : public ACharacterBase
{
	GENERATED_BODY()
	
public:

	void Look(const FInputActionValue& Value);

};
