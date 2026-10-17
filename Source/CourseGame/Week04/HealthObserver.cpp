#include "Week04/HealthObserver.h"
#include "Week04/HealthComponent.h"
AHealthObserver::AHealthObserver() { PrimaryActorTick.bCanEverTick=false; }
void AHealthObserver::AttachToHealth(UHealthComponent* NewSource)
{
    // LAB 4: detach old source; validate and store the new weak source;
    // bind once to change/death, then take an initial snapshot (not a change event).
}
void AHealthObserver::Detach()
{
    // LAB 4: remove only this observer's bindings from a still-valid source.
    // Clear the weak reference. EndPlay below already calls this function.
}
void AHealthObserver::EndPlay(const EEndPlayReason::Type Reason) { Detach(); Super::EndPlay(Reason); }
void AHealthObserver::Changed(float Health,float Maximum)
{
    LastHealth=Health; ++ChangeEvents;
    UE_LOG(LogTemp,Display,TEXT("W4_OBSERVER %s health=%.1f/%.1f changes=%d"),*GetName(),Health,Maximum,ChangeEvents);
    if (bReenterOnChange && Source.IsValid()) Source->ApplyDamage(1.f);
}
void AHealthObserver::Died() { ++DeathEvents; }
