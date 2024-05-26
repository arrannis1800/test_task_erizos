// Fill out your copyright notice in the Description page of Project Settings.


#include "Text3D.h"

// Sets default values
AText3D::AText3D()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	RootComponent = DefaultSceneRoot;

	Text3D = CreateDefaultSubobject<UText3DComponent>(TEXT("Text3DComponent"));
	Text3D->SetupAttachment(DefaultSceneRoot);

	Plane = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlaneComponent"));
	Plane->SetupAttachment(DefaultSceneRoot);
	Plane->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	Plane->SetRelativeLocation(FVector(10, 0, 0));
	Plane->SetWorldRotation(FRotator(90, 0, 0));
	

	static ConstructorHelpers::FObjectFinder<UStaticMesh> PlaneMesh(TEXT("/Engine/BasicShapes/Plane"));
	if (PlaneMesh.Succeeded())
	{
		Plane->SetStaticMesh(PlaneMesh.Object);
	}
}

void AText3D::ChangeText(FText text)
{
	Text3D->SetText(text);
}

void AText3D::ChangeTextAndResize(FText text)
{
	ChangeText(text);
	SetPlaneLocation();
	ResizePlane();
}

void AText3D::ResizePlane()
{
	FRotator ActorRotation = this->GetActorRotation();
	this->SetActorRotation(FRotator::ZeroRotator);

	FVector ActorOrig, ActorExt;
	this->GetActorBounds(true, ActorOrig, ActorExt);
	ActorExt.Y += Margin.Left + Margin.Right;
	ActorExt.Z += Margin.Top + Margin.Bottom;

	FBoxSphereBounds bounds = Plane->GetStaticMesh()->GetBounds();
	FVector PlaneExt = bounds.BoxExtent;

	Plane->SetRelativeScale3D(FVector(ActorExt.Z / PlaneExt.X, ActorExt.Y / PlaneExt.Y, 1));
	this->SetActorRotation(ActorRotation);
}

void AText3D::SetPlaneLocation()
{
	FVector ActorOrig, ActorExt;
	this->GetActorBounds(true, ActorOrig, ActorExt);
	FVector MoveVector = FVector(-Text3D->Extrude / 2.0f, Margin.Left - Margin.Right, Margin.Bottom - Margin.Top);
	MoveVector = GetActorRotation().RotateVector(MoveVector);

	Plane->SetWorldLocation(ActorOrig - MoveVector);
}

void AText3D::ModifyMargin(float MarginValue, EMargin MarginType)
{
	switch (MarginType)
	{
	case EMargin::Left:
		Margin.Left = MarginValue;
		break;
	case EMargin::Top:
		Margin.Top = MarginValue;
		break;
	case EMargin::Right:
		Margin.Right = MarginValue;
		break;
	case EMargin::Bottom:
		Margin.Bottom = MarginValue;
		break;
	default:
		break;
	}
	
}

void AText3D::ModifyMarginAndResize(float MarginValue, EMargin MarginType)
{
	ModifyMargin(MarginValue, MarginType);
	SetPlaneLocation();
	ResizePlane();
}

// Called when the game starts or when spawned
void AText3D::BeginPlay()
{
	Super::BeginPlay();

	SetPlaneLocation();
	ResizePlane();
}

// Called every frame
void AText3D::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

