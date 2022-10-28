#include "BP_Platform.h"
#include "Classes/Components/StaticMeshComponent.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"
#include <EngineGlobals.h>
#include <Runtime/Engine/Classes/Engine/Engine.h>

// Sets default values
APlatform::APlatform()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Setup the platform deck
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	RootCube = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RootCube"));

	// Engine 1
	Engine1Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Engine1Mesh"));
	Sphere = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sphere"));
	NS_Exhaust = CreateDefaultSubobject<UNiagaraComponent>(TEXT("NS_Exhaust"));
	PointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLight"));

	// Engine 2
	Engine2Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Engine2Mesh"));
	Sphere2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sphere2"));
	NS_Exhaust1 = CreateDefaultSubobject<UNiagaraComponent>(TEXT("NS_Exhaust1"));
	PointLight1 = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLight1"));

	// Engine 3
	Engine3Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Engine3Mesh"));
	Sphere3 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sphere3"));
	NS_Exhaust2 = CreateDefaultSubobject<UNiagaraComponent>(TEXT("NS_Exhaust2"));
	PointLight2 = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLight2"));

	// Engine 4
	Engine4Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Engine4Mesh"));
	Sphere4 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sphere4"));
	NS_Exhaust3 = CreateDefaultSubobject<UNiagaraComponent>(TEXT("NS_Exhaust3"));
	PointLight3 = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLight3"));

	// Attach the engines to the platform
	PhysicsConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(TEXT("PhysicsConstraint"));
	PhysicsConstraint1 = CreateDefaultSubobject<UPhysicsConstraintComponent>(TEXT("PhysicsConstraint1"));
	PhysicsConstraint2 = CreateDefaultSubobject<UPhysicsConstraintComponent>(TEXT("PhysicsConstraint2"));
	PhysicsConstraint3 = CreateDefaultSubobject<UPhysicsConstraintComponent>(TEXT("PhysicsConstraint3"));
	RootComponent = StaticMesh;

	// Set the forward arrow
	Arrow->CreationMethod = EComponentCreationMethod::Native;
	Arrow->AttachToComponent(StaticMesh, FAttachmentTransformRules::KeepRelativeTransform );
	Arrow->bHiddenInGame = false;

	// Setup physics defaults
	StaticMesh->BodyInstance.AngularDamping = 0.100000f;
	StaticMesh->BodyInstance.bSimulatePhysics = true;
	StaticMesh->BodyInstance.bOverrideMass = true;
	StaticMesh->SetCollisionProfileName(FName(TEXT("PhysicsActor")));

	PhysicsConstraint->CreationMethod = EComponentCreationMethod::Native;
	PhysicsConstraint->AttachToComponent(StaticMesh, FAttachmentTransformRules::KeepRelativeTransform );

	Engine1Mesh->CreationMethod = EComponentCreationMethod::Native;
	Engine1Mesh->AttachToComponent(StaticMesh, FAttachmentTransformRules::KeepRelativeTransform );
	Engine1Mesh->BodyInstance.bSimulatePhysics = true;
	Engine1Mesh->BodyInstance.bOverrideMass = true;
	Engine1Mesh->SetCollisionProfileName(FName(TEXT("PhysicsActor")));

	Sphere->CreationMethod = EComponentCreationMethod::Native;
	Sphere->AttachToComponent(Engine1Mesh, FAttachmentTransformRules::KeepRelativeTransform );
	Sphere->OverrideMaterials = TArray<UMaterialInterface*> ();
	Sphere->OverrideMaterials.Reserve(1);
	Sphere->OverrideMaterials.Add(nullptr);
	Sphere->BodyInstance.bEnableGravity = false;

	NS_Exhaust->CreationMethod = EComponentCreationMethod::Native;
	NS_Exhaust->AttachToComponent(Sphere, FAttachmentTransformRules::KeepRelativeTransform );

	PointLight->CreationMethod = EComponentCreationMethod::Native;
	PointLight->AttachToComponent(NS_Exhaust, FAttachmentTransformRules::KeepRelativeTransform );
	PointLight->AttenuationRadius = 10000.0f;
	PointLight->Intensity = 100.0f;
	PointLight->LightColor = FColor(255, 0, 0, 255);

	RootCube->CreationMethod = EComponentCreationMethod::Native;
	RootCube->AttachToComponent(StaticMesh, FAttachmentTransformRules::KeepRelativeTransform );
	RootCube->BodyInstance.bEnableGravity = false;
	RootCube->SetCollisionProfileName(FName(TEXT("OverlapAll")));

	Engine2Mesh->CreationMethod = EComponentCreationMethod::Native;
	Engine2Mesh->AttachToComponent(StaticMesh, FAttachmentTransformRules::KeepRelativeTransform );
	Engine2Mesh->BodyInstance.bSimulatePhysics = true;
	Engine2Mesh->BodyInstance.bOverrideMass = true;
	Engine2Mesh->SetCollisionProfileName(FName(TEXT("PhysicsActor")));

	Sphere2->CreationMethod = EComponentCreationMethod::Native;
	Sphere2->AttachToComponent(Engine2Mesh, FAttachmentTransformRules::KeepRelativeTransform );
	Sphere2->OverrideMaterials = TArray<UMaterialInterface*> ();
	Sphere2->OverrideMaterials.Reserve(1);
	Sphere2->OverrideMaterials.Add(nullptr);
	Sphere2->BodyInstance.bEnableGravity = false;

	NS_Exhaust1->CreationMethod = EComponentCreationMethod::Native;
	NS_Exhaust1->AttachToComponent(Sphere2, FAttachmentTransformRules::KeepRelativeTransform );

	PointLight1->CreationMethod = EComponentCreationMethod::Native;
	PointLight1->AttachToComponent(NS_Exhaust1, FAttachmentTransformRules::KeepRelativeTransform );
	PointLight1->AttenuationRadius = 10000.0f;
	PointLight1->Intensity = 100.0f;
	PointLight1->LightColor = FColor(255, 0, 0, 255);

	Engine3Mesh->CreationMethod = EComponentCreationMethod::Native;
	Engine3Mesh->AttachToComponent(StaticMesh, FAttachmentTransformRules::KeepRelativeTransform );
	Engine3Mesh->BodyInstance.bSimulatePhysics = true;
	Engine3Mesh->BodyInstance.bOverrideMass = true;
	Engine3Mesh->SetCollisionProfileName(FName(TEXT("PhysicsActor")));

	Sphere3->CreationMethod = EComponentCreationMethod::Native;
	Sphere3->AttachToComponent(Engine3Mesh, FAttachmentTransformRules::KeepRelativeTransform );
	Sphere3->OverrideMaterials = TArray<UMaterialInterface*> ();
	Sphere3->OverrideMaterials.Reserve(1);
	Sphere3->OverrideMaterials.Add(nullptr);
	Sphere3->BodyInstance.bEnableGravity = false;

	NS_Exhaust2->CreationMethod = EComponentCreationMethod::Native;
	NS_Exhaust2->AttachToComponent(Sphere3, FAttachmentTransformRules::KeepRelativeTransform );

	PointLight2->CreationMethod = EComponentCreationMethod::Native;
	PointLight2->AttachToComponent(NS_Exhaust2, FAttachmentTransformRules::KeepRelativeTransform );
	PointLight2->AttenuationRadius = 10000.0f;
	PointLight2->Intensity = 100.0f;
	PointLight2->LightColor = FColor(255, 0, 0, 255);

	Engine4Mesh->CreationMethod = EComponentCreationMethod::Native;
	Engine4Mesh->AttachToComponent(StaticMesh, FAttachmentTransformRules::KeepRelativeTransform );
	Engine4Mesh->BodyInstance.bSimulatePhysics = true;
	Engine4Mesh->BodyInstance.bOverrideMass = true;
	Engine4Mesh->SetCollisionProfileName(FName(TEXT("PhysicsActor")));

	Sphere4->CreationMethod = EComponentCreationMethod::Native;
	Sphere4->AttachToComponent(Engine4Mesh, FAttachmentTransformRules::KeepRelativeTransform );
	Sphere4->OverrideMaterials = TArray<UMaterialInterface*> ();
	Sphere4->OverrideMaterials.Reserve(1);
	Sphere4->OverrideMaterials.Add(nullptr);
	Sphere4->BodyInstance.bEnableGravity = false;

	NS_Exhaust3->CreationMethod = EComponentCreationMethod::Native;
	NS_Exhaust3->AttachToComponent(Sphere4, FAttachmentTransformRules::KeepRelativeTransform );

	PointLight3->CreationMethod = EComponentCreationMethod::Native;
	PointLight3->AttachToComponent(NS_Exhaust3, FAttachmentTransformRules::KeepRelativeTransform );
	PointLight3->AttenuationRadius = 10000.0f;
	PointLight3->Intensity = 100.0f;
	PointLight3->LightColor = FColor(255, 0, 0, 255);

	PhysicsConstraint1->CreationMethod = EComponentCreationMethod::Native;
	PhysicsConstraint1->AttachToComponent(StaticMesh, FAttachmentTransformRules::KeepRelativeTransform );
	PhysicsConstraint2->CreationMethod = EComponentCreationMethod::Native;
	PhysicsConstraint2->AttachToComponent(StaticMesh, FAttachmentTransformRules::KeepRelativeTransform );
	PhysicsConstraint3->CreationMethod = EComponentCreationMethod::Native;
	PhysicsConstraint3->AttachToComponent(StaticMesh, FAttachmentTransformRules::KeepRelativeTransform );

	// Setup variable defaults
	Pitch = 0.0f;
	Roll = 0.0f;
	Thrust = 0.0f;
	CorrectiveThrust = 23000.0f;
	DampingFactor = 10000.0f;
	PreviousRotation = FVector(0.0, 0.0, 0.0);
	ChangeInRotation = FVector(0.0, 0.0, 0.0);

	// Initialization complete
	Initialized = true;
}

// Set the creation method for all physics objects
void APlatform::PostLoadSubobjects(FObjectInstancingGraph* OuterInstanceGraph)
{
	Super::PostLoadSubobjects(OuterInstanceGraph);

	if (StaticMesh) {
		StaticMesh->CreationMethod = EComponentCreationMethod::Native;
	}
	if (Arrow) {
		Arrow->CreationMethod = EComponentCreationMethod::Native;
	}
	if (PhysicsConstraint) {
		PhysicsConstraint->CreationMethod = EComponentCreationMethod::Native;
	}
	if (Engine1Mesh) {
		Engine1Mesh->CreationMethod = EComponentCreationMethod::Native;
	}
	if (Sphere) {
		Sphere->CreationMethod = EComponentCreationMethod::Native;
	}
	if (NS_Exhaust) {
		NS_Exhaust->CreationMethod = EComponentCreationMethod::Native;
	}
	if (PointLight) {
		PointLight->CreationMethod = EComponentCreationMethod::Native;
	}
	if (RootCube) {
		RootCube->CreationMethod = EComponentCreationMethod::Native;
	}
	if (Engine2Mesh) {
		Engine2Mesh->CreationMethod = EComponentCreationMethod::Native;
	}
	if (Sphere2) {
		Sphere2->CreationMethod = EComponentCreationMethod::Native;
	}
	if (NS_Exhaust1) {
		NS_Exhaust1->CreationMethod = EComponentCreationMethod::Native;
	}
	if (PointLight1) {
		PointLight1->CreationMethod = EComponentCreationMethod::Native;
	}
	if (Engine3Mesh) {
		Engine3Mesh->CreationMethod = EComponentCreationMethod::Native;
	}
	if (Sphere3) {
		Sphere3->CreationMethod = EComponentCreationMethod::Native;
	}
	if (NS_Exhaust2) {
		NS_Exhaust2->CreationMethod = EComponentCreationMethod::Native;
	}
	if (PointLight2) {
		PointLight2->CreationMethod = EComponentCreationMethod::Native;
	}
	if (Engine4Mesh) {
		Engine4Mesh->CreationMethod = EComponentCreationMethod::Native;
	}
	if (Sphere4) {
		Sphere4->CreationMethod = EComponentCreationMethod::Native;
	}
	if (NS_Exhaust3) {
		NS_Exhaust3->CreationMethod = EComponentCreationMethod::Native;
	}
	if (PointLight3) {
		PointLight3->CreationMethod = EComponentCreationMethod::Native;
	}
	if (PhysicsConstraint1) {
		PhysicsConstraint1->CreationMethod = EComponentCreationMethod::Native;
	}
	if (PhysicsConstraint2) {
		PhysicsConstraint2->CreationMethod = EComponentCreationMethod::Native;
	}
	if (PhysicsConstraint3) {
		PhysicsConstraint3->CreationMethod = EComponentCreationMethod::Native;
	}
}

// Run the engines simulation
void APlatform::RunEngines()
{
	// Get change in rotation
	float X;
	float Y;
	float Z;
	FRotator RootCubeRotation = RootCube->USceneComponent::K2_GetComponentRotation();
	UKismetMathLibrary::BreakRotator(RootCubeRotation, X, Y, Z);
	FVector CubeVector = UKismetMathLibrary::MakeVector(X, Y, Z);
	FVector ChangeInRotation = UKismetMathLibrary::Subtract_VectorVector(CubeVector, PreviousRotation);

	// Get previous rotation
	FVector PreviousRotation = CubeVector;

	// Set the light intensity based on thrust
	float LightIntensity = UKismetMathLibrary::Multiply_FloatFloat(Thrust, 400.0);
	PointLight->ULightComponent::SetIntensity(LightIntensity);
	PointLight1->ULightComponent::SetIntensity(LightIntensity);
	PointLight2->ULightComponent::SetIntensity(LightIntensity);
	PointLight3->ULightComponent::SetIntensity(LightIntensity);

	// Set the particle strength based on thrust
	float ThrustParticlesStrength = UKismetMathLibrary::Multiply_FloatFloat(Thrust, 1800.0);
	NS_Exhaust->UNiagaraComponent::SetVariableFloat(FName(TEXT("None")), ThrustParticlesStrength);
	NS_Exhaust1->UNiagaraComponent::SetVariableFloat(FName(TEXT("None")), ThrustParticlesStrength);
	NS_Exhaust2->UNiagaraComponent::SetVariableFloat(FName(TEXT("None")), ThrustParticlesStrength);
	NS_Exhaust3->UNiagaraComponent::SetVariableFloat(FName(TEXT("None")), ThrustParticlesStrength);

	// Calculate corrective forces that need to be applied to the engines
	float PitchTarget = Pitch * 10.0;
	float PitchDifference = PitchTarget - Y;
	float RollTarget = Roll * 10.0;
	float RollDifference = RollTarget - X;

	float CorrectiveForce1 = (PitchDifference - RollDifference) * CorrectiveThrust;
	float CorrectiveForce2 = (-PitchDifference - RollDifference) * CorrectiveThrust;
	float CorrectiveForce3 = (PitchDifference + RollDifference) * CorrectiveThrust;
	float CorrectiveForce4 = (-PitchDifference + RollDifference) * CorrectiveThrust;

	float TotalCorrectiveAdjust = (CorrectiveForce1 + CorrectiveForce2 + CorrectiveForce3 + CorrectiveForce4)/4.0;

	float LiftThrust = UKismetMathLibrary::SafeDivide((22350.0 * 980.0),(4.0*UKismetMathLibrary::DegCos(PitchTarget)*UKismetMathLibrary::DegCos(RollTarget)) - TotalCorrectiveAdjust;

	float Thrust1 = LiftThrust + CorrectiveForce1;
	float Thrust2 = LiftThrust + CorrectiveForce2;
	float Thrust3 = LiftThrust + CorrectiveForce3;
	float Thrust4 = LiftThrust + CorrectiveForce4;

	FVector Force1 = UKismetMathLibrary::MakeVector(0.0, 0.0, Thrust1);
	FVector Force2 = UKismetMathLibrary::MakeVector(0.0, 0.0, Thrust2);
	FVector Force3 = UKismetMathLibrary::MakeVector(0.0, 0.0, Thrust3);
	FVector Force4 = UKismetMathLibrary::MakeVector(0.0, 0.0, Thrust4);

	FVector SphereRelativeLocation1 = AccessPrivateProperty<FVector>((Sphere), USceneComponent::RelativeLocation());
	FVector SphereRelativeLocation2 = AccessPrivateProperty<FVector>((Sphere2), USceneComponent::RelativeLocation());
	FVector SphereRelativeLocation3 = AccessPrivateProperty<FVector>((Sphere3), USceneComponent::RelativeLocation());
	FVector SphereRelativeLocation4 = AccessPrivateProperty<FVector>((Sphere4), USceneComponent::RelativeLocation());

	// Apply the forces to the engines
	Sphere->AddForceAtLocationLocal(Force1, SphereRelativeLocation1);
	Sphere2->AddForceAtLocationLocal(Force2, SphereRelativeLocation2);
	Sphere3->AddForceAtLocationLocal(Force3, SphereRelativeLocation3);
	Sphere4->AddForceAtLocationLocal(Force4, SphereRelativeLocation4);

	return;
}

// Called every frame
void APlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Initialized == true) {
		RunEngines();
	}
}