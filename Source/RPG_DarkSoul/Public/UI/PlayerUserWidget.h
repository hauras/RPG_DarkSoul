// Free to use, credit will be highly appreciated. 

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class RPG_DARKSOUL_API UPlayerUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);
	
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;

protected:

	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();

};
