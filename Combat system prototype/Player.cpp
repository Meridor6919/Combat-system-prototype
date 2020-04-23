#include "Player.h"
#include "Effects.h"

Player::Player(std::string name, int hp, int initiative, std::vector<Skills::SkillName> move_set)
{
	this->name = name;
	this->current_hp = hp;
	this->total_hp = hp;
	this->initiative = initiative;
	this->move_set = move_set;
}
bool Player::CanUseAbility()
{
	const double base_cost = SkillRegister::GetSkills()->GetCost(static_cast<SkillName>(move_set[move_id]));
	const double actual_cost = base_cost; // multiply that by other modifiers
	return actual_cost <= accumulated_initiative;
}
void Player::GainInitiative()
{
	accumulated_initiative += initiative;
}
void Player::ApplyEffect(Effect* effect)
{
	if (!active_effects.size())
	{
		active_effects.emplace_back(effect);
		return;
	}
	std::vector<Effect*>::iterator it = std::lower_bound(active_effects.begin(), active_effects.end(), effect->GetID(), [](Effect* first, Effects::Effect id) { return first->GetID() < id; });
	if ((*it)->GetID() == effect->GetID())
	{
		(*it) = effect;
	}
	else
	{
		active_effects.insert(it, effect);
	}
}
std::string Player::EndOfTurn()
{
	std::string return_value = "";
	for (int i = 0; i < static_cast<int>(active_effects.size()); ++i)
	{
		bool active = true;
		return_value += active_effects[i]->Tick(active);
		if (active)
		{
			delete active_effects[i];
			active_effects.erase(active_effects.begin() + i);
		}
	}
	return return_value;
}
std::string Player::GetName()
{
	return name;
}
std::string Player::UseAbility(Player * opponent)
{
	auto skill_register = SkillRegister::GetSkills();
	accumulated_initiative -= skill_register->GetCost(static_cast<SkillName>(move_set[move_id]));
	const std::string ret = skill_register->TakeAction(move_set[move_id])(this, opponent);
	move_id = (move_id + 1) % static_cast<int>(move_set.size());
	return ret;
}
Player::~Player()
{
	for (int i = 0; i < static_cast<int>(active_effects.size()); ++i)
	{
		delete active_effects[i];
	}
}
bool Player::IsAlive()
{
	return current_hp > 0;
}


