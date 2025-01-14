// Free to use, credit will be highly appreciated. 

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PlayerHUD.generated.h"

class UPlayerUserWidget;
/**
 * 
 */
UCLASS()
class RPG_DARKSOUL_API APlayerHUD : public AHUD
{
	GENERATED_BODY()

UPROPERTY()
	TObjectPtr<UPlayerUserWidget>  OverlayWidget;
protected:
	virtual void BeginPlay() override;
private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UPlayerUserWidget> OverlayWidgetClass;	
};
