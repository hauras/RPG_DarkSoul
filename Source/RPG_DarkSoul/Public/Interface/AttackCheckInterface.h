// Free to use, credit will be highly appreciated. 

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "AttackCheckInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UAttackCheckInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class RPG_DARKSOUL_API IAttackCheckInterface
{
	GENERATED_BODY()

public:
	virtual void AttackCheck() = 0;
};
