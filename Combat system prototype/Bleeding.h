#include "Effects.h"

class Bleeding : public Effect
{
	
public:
	Bleeding(Player *target, Player *perpetrator, double effectivness_modifier) : Effect(target, perpetrator, effectivness_modifier)
	{
		effect_id = Effects::Bleeding;
		duration = 3;
	}
	bool Tick() override
	{
		target->current_hp -= 3 * effectivness;
		return Effect::Tick();
	}
};