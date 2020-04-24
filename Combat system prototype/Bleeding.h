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
	Bleeding& operator=(Effect& other) override
	{
		if (this != &other)
		{
			if (this->effectivness < other.effectivness)
			{
				this->effectivness = other.effectivness + this->effectivness*0.1;
			}
			else
			{
				this->effectivness = other.effectivness*0.1 + this->effectivness;
			}
		}
		if (this->duration < other.duration)
		{
			this->duration = other.duration;
		}
		return *this;
	}
};