#include "framwork.h"
#include "Knight.h"

Knight::Knight(int hp, int atk, string name)
	: Player(hp, atk, name)
{
	SoundManager::GetInstance()->MonsterSound();
}

void Knight::Attack(shared_ptr<Creature> other)
{
	if (other == nullptr || other->IsAlive() == false || this->IsAlive() == false)
		return;
	cout << _name << "이 " << other->GetName() << "을 공격하였습니다 ";
	SoundManager::GetInstance()->KnightSound();
	other->Damaged(this->_atk);
	AddAggro(this->_atk);

	if (other->IsAlive())
		cout << other->GetName() << "의 남은 체력 : " << other->GetHP() << endl;
}
