#pragma once
#include <string>
#include <vector>
#include "Constants.h"
#include "Skills.h"
#include <algorithm>

class Effect;

using namespace Skills;
class Player
{
	std::vector<Effect*> active_effects;
	std::vector<Skills::SkillName> move_set;
	int move_id = 0;
	std::string name;
	
public:

	int initiative;
	int total_hp;
	int accumulated_initiative = 0;
	double attack_modifier = 1.0;
	int current_hp;

	Player() = delete;
	Player(std::string name, int hp, int initiative, std::vector<Skills::SkillName> move_set);
	bool IsAlive();
	bool CanUseAbility();
	void GainInitiative();
	void ApplyEffect(Effect* effect);
	std::string EndOfTurn();
	std::string GetName();
	std::string UseAbility(Player *opponent);
	~Player();
};

