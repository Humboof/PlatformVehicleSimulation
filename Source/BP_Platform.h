#pragma once

#include "Blueprint/BlueprintSupport.h"
#include "Runtime/CoreUObject/Public/UObject/NoExportTypes.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"

class UPhysicsConstraintComponent;
class UPointLightComponent;
class UNiagaraComponent;
class UStaticMeshComponent;
class UArrowComponent;
class USceneComponent;

#include "BP_Platform.generated.h"

UCLASS(config=Engine, Blueprintable, BlueprintType, meta=(ReplaceConverted="/Game/ThirdPersonCPP/Blueprints/BP_Platform.BP_Platform_C", OverrideNativeName="BP_Platform_C"))
class ABP_Platform_C : public AActor
{	
	public:
		GENERATED_BODY()

		UPROPERTY(BlueprintReadWrite, NonTransactional, meta=(Category="Default", OverrideNativeName="PhysicsConstraint3"))
		UPhysicsConstraintComponent* PhysicsConstraint3;

		UPROPERTY(BlueprintReadWrite, NonTransactional, meta=(Category="Default", OverrideNativeName="PhysicsConstraint2"))
		UPhysicsConstraintComponent* PhysicsConstraint2;

		UPROPERTY(BlueprintReadWrite, NonTransactional, meta=(Category="Default", OverrideNativeName="PhysicsConstraint1"))
		UPhysicsConstraintComponent* PhysicsConstraint1;

		UPROPERTY(BlueprintReadWrite, NonTransactional, meta=(Category="Default", OverrideNativeName="PointLight3"))
		UPointLightComponent* PointLight3;

		UPROPERTY(BlueprintReadWrite, NonTransactional, meta=(Category="Default", OverrideNativeName="NS_Exhaust3"))
		UNiagaraComponent* NS_Exhaust3;

		UPROPERTY(BlueprintReadWrite, NonTransactional, meta=(Category="Default", OverrideNativeName="Sphere4"))
		UStaticMeshComponent* Sphere4;

		UPROPERTY(BlueprintReadWrite, NonTransactional, meta=(Category="Default", OverrideNativeName="Engine4Mesh"))
		UStaticMeshComponent* Engine4Mesh;

		UPROPERTY(BlueprintReadWrite, NonTransactional, meta=(Category="Default", OverrideNativeName="PointLight2"))
		UPointLightComponent* PointLight2;

		UPROPERTY(BlueprintReadWrite, NonTransactional, meta=(Category="Default", OverrideNativeName="NS_Exhaust2"))
		UNiagaraComponent* NS_Exhaust2;

		UPROPERTY(BlueprintReadWrite, NonTransactional, meta=(Category="Default", OverrideNativeName="Sphere3"))
		UStaticMeshComponent* Sphere3;

		UPROPERTY(BlueprintReadWrite, NonTransactional, meta=(Category="Default", OverrideNativeName="Engine3Mesh"))
		UStaticMeshComponent* Engine3Mesh;

		UPROPERTY(BlueprintReadWrite, NonTransactional, meta=(Category="Default", OverrideNativeName="PointLight1"))
		UPointLightComponent* PointLight1;

		UPROPERTY(BlueprintReadWrite, NonTransactional, meta=(Category="Default", OverrideNativeName="PointLight"))
		UPointLightComponent* PointLight;

		UPROPERTY(BlueprintReadWrite, NonTransactional, meta=(Category="Default", OverrideNativeName="NS_Exhaust"))
		UNiagaraComponent* NS_Exhaust;

		UPROPERTY(BlueprintReadWrite, NonTransactional, meta=(Category="Default", OverrideNativeName="NS_Exhaust1"))
		UNiagaraComponent* NS_Exhaust1;

		UPROPERTY(BlueprintReadWrite, NonTransactional, meta=(Category="Default", OverrideNativeName="Sphere2"))
		UStaticMeshComponent* Sphere2;

		UPROPERTY(BlueprintReadWrite, NonTransactional, meta=(Category="Default", OverrideNativeName="Engine2Mesh"))
		UStaticMeshComponent* Engine2Mesh;

		UPROPERTY(BlueprintReadWrite, NonTransactional, meta=(Category="Default", OverrideNativeName="Sphere"))
		UStaticMeshComponent* Sphere;

		UPROPERTY(BlueprintReadWrite, NonTransactional, meta=(Category="Default", OverrideNativeName="Cube"))
		UStaticMeshComponent* Cube;

		UPROPERTY(BlueprintReadWrite, NonTransactional, meta=(Category="Default", OverrideNativeName="Engine1Mesh"))
		UStaticMeshComponent* Engine1Mesh;

		UPROPERTY(BlueprintReadWrite, NonTransactional, meta=(Category="Default", OverrideNativeName="PhysicsConstraint"))
		UPhysicsConstraintComponent* PhysicsConstraint;

		UPROPERTY(BlueprintReadWrite, NonTransactional, meta=(Category="Default", OverrideNativeName="Arrow"))
		UArrowComponent* Arrow;

		UPROPERTY(BlueprintReadWrite, NonTransactional, meta=(Category="Default", OverrideNativeName="StaticMesh"))
		UStaticMeshComponent* StaticMesh;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="Pitch", Category="Default", MultiLine="true", OverrideNativeName="Pitch"))
		float Pitch;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="Roll", Category="Default", MultiLine="true", OverrideNativeName="Roll"))
		float Roll;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="Thrust", Category="Default", MultiLine="true", OverrideNativeName="Thrust"))
		float Thrust;

		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(DisplayName="Corrective Thrust", Category="Default", MultiLine="true", OverrideNativeName="CorrectiveThrust"))
		float CorrectiveThrust;

		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(DisplayName="Damping Factor", Category="Default", MultiLine="true", OverrideNativeName="DampingFactor"))
		float DampingFactor;

		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(DisplayName="Previous Rotation", Category="Default", MultiLine="true", OverrideNativeName="PreviousRotation"))
		FVector PreviousRotation;

		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(DisplayName="Change in Rotation", Category="Default", MultiLine="true", OverrideNativeName="ChangeInRotation"))
		FVector ChangeInRotation;

		UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="CallFunc_BreakRotator_Roll"))
		float CallFunc_BreakRotator_Roll;

		UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="CallFunc_BreakRotator_Pitch"))
		float CallFunc_BreakRotator_Pitch;

		UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="CallFunc_BreakRotator_Yaw"))
		float CallFunc_BreakRotator_Yaw;

		UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="K2Node_Event_DeltaSeconds"))
		float K2Node_Event_DeltaSeconds;

		UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="CallFunc_BreakRotator_Roll_1"))
		float CallFunc_BreakRotator_Roll_1;

		UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="CallFunc_BreakRotator_Pitch_1"))
		float CallFunc_BreakRotator_Pitch_1;

		UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="CallFunc_BreakRotator_Yaw_1"))
		float CallFunc_BreakRotator_Yaw_1;
};
