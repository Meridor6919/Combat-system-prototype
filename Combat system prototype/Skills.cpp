#include <iostream>
#include "Player.h"
#include "Skills.h"
#include "EffectHeaders.h"

std::string default_attack(Player *attacker, Player *target)
{
	const int dmg = static_cast<int>((static_cast<double>(rand() % 10) + 1.0) * attacker->attack_modifier);
	target->current_hp -= dmg;
	return attacker->GetName() + " dealt " + std::to_string(dmg) + " dmg with default attack to " + target->GetName();
}
std::string bleeding_strike(Player *attacker, Player *target)
{
	const int dmg = static_cast<int>(1.0 * attacker->attack_modifier);
	target->current_hp -= dmg;
	if (dmg)
	{
		target->ApplyEffect(new Bleeding(target, attacker, 1.0));
	}
	return attacker->GetName() + " dealt " + std::to_string(dmg) + " dmg with bleeding strike to " + target->GetName();
}
std::string weakening_strike(Player * attacker, Player * target)
{
	const int dmg = static_cast<int>(1.0 * attacker->attack_modifier);
	target->current_hp -= dmg;
	if (dmg)
	{
		target->ApplyEffect(new Weakness(target, attacker, 1.0));
	}
	return attacker->GetName() + " dealt " + std::to_string(dmg) + " dmg with weakening strike to " + target->GetName();
}
