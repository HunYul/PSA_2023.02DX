#include "framwork.h"
#include "Archer.h"
Archer::Archer(int hp, int atk, string name)
	: Player(hp, atk, name)
{
	SoundManager::GetInstance()->MonsterSound();
}

void Archer::Attack(shared_ptr<Creature> other)
{
	if (other == nullptr || other->IsAlive() == false || this->IsAlive() == false)
		return;
	cout << _name << "이 " << other->GetName() << "을 공격하였습니다! ";
	SoundManager::GetInstance()->ArcherSound();
	other->Damaged(this->_atk);
	AddAggro(this->_atk);

	if (other->IsAlive())
		cout << other->GetName() << "의 남은 체력 : " << other->GetHP() << endl;
}
