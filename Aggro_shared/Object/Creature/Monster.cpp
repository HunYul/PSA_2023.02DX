#include "framwork.h"
#include "Monster.h"
Monster::Monster(int hp, int atk, string name)
	:Creature(hp, atk, name)
{
	SoundManager::GetInstance()->MonsterSound();
}

void Monster::Attack(shared_ptr<Creature> other)
{
	if (other == nullptr || other->IsAlive() == false || 
		this->IsAlive() == false)
		return;
	cout << _name << "이 " << other->GetName() << "을 공격하였습니다 ! ";
	SoundManager::GetInstance()->MonsterSound();
	other->Damaged(this->_atk);

	if (other->IsAlive())
		cout << other->GetName() << "의 남은 체력 : " << other->GetHP() << endl;
}


void Monster::AttackPlayers(vector <shared_ptr<Creature>> other)
{
	vector<pair<shared_ptr<Creature>, int>> v_aggros;
	for (auto player : other)
	{
		if (player->IsAlive())
		{
			v_aggros.push_back({ player, dynamic_pointer_cast<Player>(player)->GetAggro() });
		}
	}

	sort(v_aggros.begin(), v_aggros.end(), [](const pair< shared_ptr<Creature>, int> a, const pair<shared_ptr<Creature>, int> b)->bool {return a.second > b.second; });
	if (v_aggros.size() > 4)
		v_aggros.resize(4);
	for (auto v_player : v_aggros)
	{
		this->Attack(v_player.first);
	}
}
