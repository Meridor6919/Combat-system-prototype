#pragma once
#include <string>
#include <vector>
#include "Constants.h"
#include "Skills.h"

class Effect;

using namespace Skills;
class Player
{
	std::vector<Effect*> active_effects;
	std::vector<Skills::SkillName> move_set;
	std::string name;
	int total_hp;
	int initiative;
	int current_hp;
	int accumulated_initiative = 0;
	int move_id = 0;
	
public:
	Player() = delete;
	Player(std::string name, int hp, int initiative, std::vector<Skills::SkillName> move_set);
	bool IsAlive();
	bool CanUseAbility();
	void GainInitiative();
	void ApplyEffect(Effect* effect);
	void EndOfTurn();
	std::string GetName();
	std::string UseAbility(Player *opponent);
	~Player();
};

