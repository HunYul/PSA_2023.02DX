#pragma once
class Mage : public Player
{
public:
	Mage() {};
	Mage(int hp, int atk, string name);
	virtual ~Mage() {};

	virtual void Attack(shared_ptr<Creature> ohter) override;

};
