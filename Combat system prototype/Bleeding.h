#pragma once
#include "Effects.h"

class Bleeding : public Effect
{
	
public:
	Bleeding(Player *target, Player *perpetrator, double effectivness_modifier) : Effect(target, perpetrator, effectivness_modifier)
	{
		effect_id = Effects::Bleeding;
		duration = 3;
	}
	std::string Tick(bool &active) override
	{
		double duration_now = static_cast<double>(duration);
		Effect::Tick(active);
		target->current_hp -= static_cast<int>(duration_now * effectivness);
		return '\t' + target->GetName() + " took " + std::to_string(static_cast<int>(duration_now * effectivness)) + " dmg from bleeding.\n";
	}
};