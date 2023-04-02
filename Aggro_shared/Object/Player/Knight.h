#pragma once
class Knight : public Player
{
public:
	Knight() {};
	Knight(int hp, int atk, string name);
	virtual ~Knight() {};

	virtual void Attack(shared_ptr<Creature> ohter) override;

};


