#pragma once
#include "Effects.h"

class Weakness : public Effect
{

public:
	Weakness(Player *target, Player *perpetrator, double effectivness_modifier) : Effect(target, perpetrator, effectivness_modifier)
	{
		effect_id = Effects::Weakness;
		duration = 3;
	}
	std::string Tick(bool &active) override
	{
		target->attack_modifier *= 0.8  / effectivness;
		Effect::Tick(active);
		return '\t' + target->GetName() + " has been weakend and his attacks would deal " + std::to_string(static_cast<int>(0.8 / effectivness * 100.0)) + "% dmg.\n";
	}
};