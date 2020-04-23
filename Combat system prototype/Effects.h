#pragma once
#include "Player.h"
#include "Constants.h"
#include <math.h>
#include <vector>

class Effect
{
protected:
	Player *target;
	Player *perpetrator;
	double effectivness = 1.0;
	int duration;
	std::vector<Effect*>linked_effects;
	Effects::Effect effect_id;

	virtual std::string WhenVanish() { return ""; };
	void LinkOtherEffect(Effect *other)
	{
		other->linked_effects.emplace_back(this);
		this->linked_effects.emplace_back(other);
	}

public:
	
	Effect(Player *target, Player *perpetrator, double effectivness_modifier)
	{
		this->target = target;
		this->perpetrator = perpetrator;
		this->effectivness *= effectivness;
	}
	bool operator<(const Effect& other)
	{
		return this->effect_id < other.effect_id;
	}
	Effect& operator=(Effect& other)
	{
		if (this != &other)
		{
			if (this->effectivness < other.effectivness)
			{
				this->effectivness = other.effectivness;
			}
			if (this->duration < other.duration)
			{
				this->duration = other.duration;
			}
		}
		return *this;
	}
	~Effect()
	{
		WhenVanish();
		for (int i = 0; i < static_cast<int>(linked_effects.size()); ++i)//unlinking this effect from other effects
		{
			for (int j = 0; j < static_cast<int>(linked_effects[i]->linked_effects.size()); ++j)
			{
				if (linked_effects[i]->linked_effects[j] == this)
				{
					linked_effects[i]->linked_effects.erase(linked_effects[i]->linked_effects.begin() + j);
					break;
				}
			}
		}
	}
	virtual std::string Tick(bool &active)
	{
		--duration;
		active = duration <= 0;
		return "";
	}
	Effects::Effect GetID()
	{
		return effect_id;
	}
};

