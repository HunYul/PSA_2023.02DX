#include "framwork.h"
#include "Player.h"

Player::Player(int hp, int atk, string name)
	:Creature(hp, atk, name) {}

void Player::Attack(shared_ptr<Creature> other)
{
	if (other == nullptr || other->IsAlive() == false || this->IsAlive() == false)
		return;
	cout << _name << "��" << other->GetName() << "�� �����Ͽ����ϴ�!!!";
	SoundManager::GetInstance()->PlayerSound();
	other->Damaged(this->_atk);
	AddAggro(this-> _atk);
	
	if(other->IsAlive()) // ü��Ȯ��
		cout << other->GetName() << "�� ���� ü�� :" << other->GetHP() << endl;
}