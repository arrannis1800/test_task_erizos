// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "components/StaticMeshComponent.h"
#include "Text3D/Public/Text3DComponent.h"
#include "Text3D.generated.h"

UENUM(BlueprintType)
enum class EMargin : uint8
{
	Left   = 0,
	Top    = 1,
	Right  = 2,
	Bottom = 3,
};

USTRUCT(BlueprintType)
struct FMargin3DText
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Margins")
	float Left;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Margins")
	float Top;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Margins")
	float Right;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Margins")
	float Bottom;

	FMargin3DText()
		: Left(0.0f), Top(0.0f), Right(0.0f), Bottom(0.0f)
	{
	}
};

UCLASS()
class UETASK_API AText3D : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AText3D();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* DefaultSceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UText3DComponent* Text3D;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* Plane;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Margins")
	FMargin3DText Margin;

	UFUNCTION(BlueprintCallable, Category = "Text")
	void ChangeText(FText text);

	UFUNCTION(BlueprintCallable, Category = "Text")
	void ChangeTextAndResize(FText text);

	UFUNCTION(BlueprintCallable)
	void ResizePlane();

	UFUNCTION(BlueprintCallable)
	void SetPlaneLocation();

	UFUNCTION(BlueprintCallable, Category = "Margins")
	void ModifyMargin(float MarginValue, EMargin MarginType);

	UFUNCTION(BlueprintCallable, Category = "Margins")
	void ModifyMarginAndResize(float MarginValue, EMargin MarginType);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
