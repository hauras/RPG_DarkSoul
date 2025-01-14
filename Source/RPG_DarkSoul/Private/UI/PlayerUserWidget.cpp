// Free to use, credit will be highly appreciated. 


#include "UI/PlayerUserWidget.h"

void UPlayerUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}