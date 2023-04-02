#include "framwork.h"
#include "Player.h"

Player::Player(int hp, int atk, string name)
	:Creature(hp, atk, name) {}

void Player::Attack(shared_ptr<Creature> other)
{
	if (other == nullptr || other->IsAlive() == false || this->IsAlive() == false)
		return;
	cout << _name << "이" << other->GetName() << "을 공격하였습니다!!!";
	SoundManager::GetInstance()->PlayerSound();
	other->Damaged(this->_atk);
	AddAggro(this-> _atk);
	
	if(other->IsAlive()) // 체력확인
		cout << other->GetName() << "의 현재 체력 :" << other->GetHP() << endl;
}