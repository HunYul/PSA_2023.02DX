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
	cout << "�̸� : " << _name << endl;
	cout << "ü�� : " << _name << endl;
	cout << "���ݷ� : " << _name << endl;
}


void Creature::Attack(shared_ptr<Creature> other)
{
	if (other == nullptr)
		return;
	if (_isAlive == false || other->_isAlive == false)
		return;
	other->Damaged(this->_atk);

	cout << this->_name << "��" << other->_name << "�����Ͽ����ϴ�."<< endl;
	cout << "����" << other->_name << "�� ü�� : " << other->_hp << endl;
}

void Creature::Damaged(int amount)
{
	if (amount <= 0.0f || _isAlive == false)
		return;

	_hp -= amount;

	if (_hp < 0.0f)
	{
		cout << "���!" << endl;
		_hp = 0;
		_isAlive = false;
	}
}