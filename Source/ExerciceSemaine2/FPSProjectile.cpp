// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSProjectile.h"

// Sets default values
AFPSProjectile::AFPSProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if (!RootComponent)
	{
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("ProjectileSceneComponent"));
	}
	if (!CollisionComponent)
	{
		CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
		CollisionComponent->InitSphereRadius(15.0f);
		RootComponent = CollisionComponent;
	}
	if (!ProjectileMovementComponent)
	{
		ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
		ProjectileMovementComponent->SetUpdatedComponent(CollisionComponent);
		ProjectileMovementComponent->InitialSpeed = 1000.0f;
		ProjectileMovementComponent->MaxSpeed = 1000.0f;
		ProjectileMovementComponent->bRotationFollowsVelocity = true;
		ProjectileMovementComponent->bShouldBounce = true;
		ProjectileMovementComponent->Bounciness = 0.3f;
		ProjectileMovementComponent->ProjectileGravityScale =1.0f;
	}

	if (!ProjectileMeshComponent)
	{
		ProjectileMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMeshComponent"));
		static ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh(TEXT("StaticMesh'/Game/Sphere.Sphere'"));
		if (Mesh.Succeeded())
		{
			ProjectileMeshComponent->SetStaticMesh(Mesh.Object);
			ProjectileMeshComponent->OnComponentHit.AddDynamic(this, &AFPSProjectile::OnHit);
		}
	}


	/*static ConstructorHelpers::FObjectFinder<UMaterial>Material(TEXT("Material'/Game/BulletMat.BulletMat'"));
	if (Material.Succeeded())
	{
		ProjectileMaterialInstance = UMaterialInstanceDynamic::Create(Material.Object, ProjectileMeshComponent);
	}
	ProjectileMeshComponent->SetMaterial(0, ProjectileMaterialInstance);
	ProjectileMeshComponent->SetRelativeScale3D(FVector(0.09f, 0.09f, 0.09f));
	ProjectileMeshComponent->SetupAttachment(RootComponent);*/

	/*static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMesh(TEXT("StaticMesh'/Game/Geometry/Meshes/1M_Cube.1M_Cube'"));

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("NomMesh"));
	if (CubeMesh.Succeeded()) {
		StaticMesh->SetStaticMesh(CubeMesh.Object);
	}*/

	//StaticMesh->SetSimulatePhysics(true);
	//StaticMesh->OnComponentHit.AddDynamic(this, &ATestJumpPad::OnHit);

	//RootComponent = StaticMesh;

}

// Called when the game starts or when spawned
void AFPSProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFPSProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Function that initializes the projectile's velocity in the shoot direction.
void AFPSProjectile::FireInDirection(const FVector& ShootDirection)
{
	ProjectileMovementComponent->Velocity = ShootDirection * ProjectileMovementComponent->InitialSpeed;
}

void AFPSProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) {
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Projectile just hit something"));
}
