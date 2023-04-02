#include "framwork.h"
#include "Creature.h"

Creature::Creature(int hp, int atk, string name)
	: _hp(hp), _atk(atk), _name(name), _isAlive(true)
{
}

Creature::~Creature()
{
}

void Creature::SetInfo(int hp, int atk, string name)
{
	_hp = hp;
	_atk = atk;
	_name = name;
}

void Creature::PrintInfo()
{
	if (_isAlive == false) return;
	cout << "이름 : " << _name << endl;
	cout << "체력 : " << _name << endl;
	cout << "공격력 : " << _name << endl;
}


void Creature::Attack(shared_ptr<Creature> other)
{
	if (other == nullptr)
		return;
	if (_isAlive == false || other->_isAlive == false)
		return;
	other->Damaged(this->_atk);

	cout << this->_name << "을" << other->_name << "공격하였습니다."<< endl;
	cout << "현재" << other->_name << "의 체력 : " << other->_hp << endl;
}

void Creature::Damaged(int amount)
{
	if (amount <= 0.0f || _isAlive == false)
		return;

	_hp -= amount;

	if (_hp < 0.0f)
	{
		cout << "사망!" << endl;
		_hp = 0;
		_isAlive = false;
	}
}