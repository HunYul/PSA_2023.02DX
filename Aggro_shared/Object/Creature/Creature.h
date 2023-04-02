#pragma once

class Creature
{
public:
	Creature() : _hp(0), _atk(0), _name(" ") {};
	Creature(int hp, int atk, string name) : _hp(hp), _atk(atk), _name(name) {};
	virtual ~Creature();

	void SetInfo(int hp, int atk, string name);
	void PrintInfo();

	// 가상함수
	virtual void Attack(	shared_ptr<Creature> other);
	void Damaged(int amount);
	bool IsAlive() { return _isAlive; }
	const int GetHP() { return _hp; }
	const int GetAtk() { return _atk; }
	const string& GetName() { return _name; }

protected:
	int _hp;
	int _atk;
	string _name;

	int _aggro = 0;
	bool _isAlive =true;
};

