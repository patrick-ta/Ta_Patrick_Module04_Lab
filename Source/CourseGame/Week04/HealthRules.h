#pragma once
#include <cmath>
#include <algorithm>
namespace Week04Rules
{
struct Change { float Value; bool Changed; bool Died; };
inline float ValidMaximum(float Value) { return std::isfinite(Value) && Value>0.f ? Value : 100.f; }
inline Change Damage(float Health,float Maximum,float Amount)
{
    // LAB 1: reject non-positive/non-finite damage and damage to a dead target.
    // Calculate clamped health. Return the value, whether it changed, and
    // whether it crossed from alive to dead. Do not publish events in this pure rule.
    if (!std::isfinite(Amount) || Amount <= 0.f || Health <= 0.f) return { Health,false,false };
    const float Next = std::max(0.f, std::min(Maximum, Health - Amount));
    return { Next,Next != Health,Next == 0.f };
}
inline Change Heal(float Health,float Maximum,float Amount)
{
    if (!std::isfinite(Amount) || Amount<=0.f || Health<=0.f) return {Health,false,false};
    const float Next=Health+std::min(Amount,Maximum-Health);
    return {Next,Next!=Health,false};
}
}
