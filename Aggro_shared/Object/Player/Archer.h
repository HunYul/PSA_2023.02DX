#pragma once
class Archer : public Player
{
public:
	Archer() {};
	Archer(int hp, int atk, string name);
	virtual ~Archer() {};

	virtual void Attack(shared_ptr<Creature> ohter) override;

};

