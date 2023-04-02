#include "framwork.h"
#include "Mage.h"

Mage::Mage(int hp, int atk, string name)
	: Player(hp, atk, name)
{
	SoundManager::GetInstance()->MonsterSound();
}

void Mage::Attack(shared_ptr<Creature> other)
{
	if (other == nullptr || other->IsAlive() == false || this->IsAlive() == false)
		return;
	cout << _name << "�� " << other->GetName() << "�� ����! ";
	SoundManager::GetInstance()->MageSound();
	other->Damaged(this->_atk);
	AddAggro(this->_atk);

	if (other->IsAlive())
		cout << other->GetName() << "�� ���� ü�� : " << other->GetHP() << endl ;
}
