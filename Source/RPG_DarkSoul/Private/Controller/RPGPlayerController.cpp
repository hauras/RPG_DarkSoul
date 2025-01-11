// Free to use, credit will be highly appreciated. 

#include "GameFramework/Character.h"
#include "Controller/RPGPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Character/PlayerCharacter.h"
#include "InputActionValue.h"

ARPGPlayerController::ARPGPlayerController()
{
    bReplicates = true;
}

void ARPGPlayerController::BeginPlay()
{
    Super::BeginPlay();
    check(RPGContext);

    UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
    check(Subsystem);
    Subsystem->AddMappingContext(RPGContext, 0);

    bShowMouseCursor = false;
    FInputModeGameOnly InputMode;
    SetInputMode(InputMode);

    bEnableMouseOverEvents = true;
    bEnableClickEvents = true;
}

void ARPGPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

    EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ARPGPlayerController::Move);
    EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ARPGPlayerController::Look);
    EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ARPGPlayerController::Jump);

    //EnhancedInputComponent->BindAction(AttackAction, ETriggerEvent::Triggered, this, &ARPGPlayerController::Attack);

}

void ARPGPlayerController::Move(const FInputActionValue& InputActionValue)
{
    const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
    const FRotator Rotation = GetControlRotation();
    const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);
    const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
    const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

    if (APawn* ControlledPawn = GetPawn<APawn>())
    {
        ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
        ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
    }
}

void ARPGPlayerController::Look(const FInputActionValue& InputActionValue)
{
    APlayerCharacter* PlayerChar = Cast<APlayerCharacter>(GetPawn());
    if (PlayerChar)
    {
        PlayerChar->Look(InputActionValue);
    }
}

void ARPGPlayerController::Jump()
{
    if (APawn* ControlledPawn = GetPawn<APawn>())
    {
        ACharacter* MyCharacter = Cast<ACharacter>(ControlledPawn);
        if (MyCharacter)
        {
            MyCharacter->Jump();
        }
    }
}

