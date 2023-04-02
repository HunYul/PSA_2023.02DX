#pragma once
class Player : public Creature
{
public:
	Player() {};
	Player(int hp, int atk, string name);
	virtual ~Player() {};

	virtual void Attack(shared_ptr<Creature> other) override;
	void AddAggro(int atk) { _aggro += atk; }
	const int& GetAggro() const { return _aggro; }
protected:
	int _agrro = 0;
};

