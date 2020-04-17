#include "Player.h"

Player::Player(int hp, int initiative, std::vector<Skills::SkillName> move_set)
{
	this->current_hp = hp;
	this->total_hp = hp;
	this->initiative = initiative;
	this->move_set = move_set;
}
bool Player::CanUseAbility()
{
	const double base_cost = SkillRegister::GetSkills()->GetCost(static_cast<SkillName>(move_id));
	const double actual_cost = base_cost; // multiply that by other modifiers
	return actual_cost <= accumulated_initiative;
}
void Player::GainInitiative()
{
	accumulated_initiative += initiative;
}
std::string Player::UseAbility(Player * opponent)
{
	auto skill_register = SkillRegister::GetSkills();
	accumulated_initiative -= skill_register->GetCost(static_cast<SkillName>(move_id));
	const std::string ret = skill_register->TakeAction(move_set[move_id])(this, opponent);
	move_id = (move_id + 1) % static_cast<int>(move_set.size());
	return ret;
}
bool Player::IsAlive()
{
	return current_hp > 0;
}


