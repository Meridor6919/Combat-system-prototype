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

	virtual int GetDuration() = 0;

public:
	Effect(Effects::Effect effect_id, Player *target, Player *perpetrator, double effectivness_modifier, double duration_modifier)
	{
		this->effect_id = effect_id;
		this->target = target;
		this->perpetrator = perpetrator;
		this->effectivness *= effectivness;
		this->duration = round(GetDuration()*duration_modifier);
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
	void LinkOtherEffect(Effect *other)
	{
		other->linked_effects.emplace_back(this);
		this->linked_effects.emplace_back(other);
	}
	~Effect()
	{
		for (int i = 0; i < static_cast<int>(linked_effects.size()); ++i)
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
	virtual bool Tick() = 0;
	virtual void WhenVanish() = 0;
};

