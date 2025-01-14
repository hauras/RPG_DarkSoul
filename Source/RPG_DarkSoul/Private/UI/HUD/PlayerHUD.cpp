// Free to use, credit will be highly appreciated. 


#include "UI/HUD/PlayerHUD.h"
#include "UI/PlayerUserWidget.h"

void APlayerHUD::BeginPlay()
{
    Super::BeginPlay();
	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	Widget->AddToViewport();
}