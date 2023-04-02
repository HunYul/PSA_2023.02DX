#include "framwork.h"

int random(int min, int max) { return rand() % (max - min + 1) + min; };

bool AllDead(shared_ptr<Creature>monsterArr[], int size)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (monsterArr[i]->IsAlive() == false)
		{
			++count;
		}
	}
	if (count == size)
		return true;
	else
		return false;
}
int main()
{
	srand((unsigned int)time(nullptr));

	SoundManager::Create();
	vector <shared_ptr<Creature>> players;
	shared_ptr<Player> p = nullptr;
	shared_ptr<Monster> Boss = make_shared <Monster>(1500, 20, "타락한 천사");
	for (int i = 0; i < 10; i++)
	{
		string job;
		switch (rand() % 3)
		{
		case 0:
		{
			job = "나이트" + to_string(i + 1);
			p = make_shared<Knight>(random(120, 210), random(40, 20), job);
			break;
		}
		case 1:
		{
			job = "법사" + to_string(i + 1);
			p = make_shared<Mage>(random(70, 80), random(55, 30), job);
			break;
		}
		case 2:
		{
			job = "궁수" + to_string(i + 1);
			p = make_shared<Archer>(random(80, 70), random(20, 25), job);
			break;
		}
		}
		players.push_back(p);
	}


	while (true)
	{
		cout << endl;
		for (auto pl : players)
		{
			pl->Attack(Boss);
		}

		cout << endl;

		if (Boss->IsAlive() == false)
		{
			cout << "레이드 클리어 미션 성공!!" << endl;
			break;
		}

		dynamic_pointer_cast<Monster>(Boss)->AttackPlayers(players);

		Boss->AttackPlayers(players);

		bool AllDead = true;
		for (auto alive : players)
		{
			if (alive->IsAlive())
			{
				AllDead = false;
				break;
			}
		}
		if (AllDead)
		{
			cout << "파티원이 모두 전멸하였습니다. 미션 실패" << endl;
			break;
		}

		SoundManager::Delete();


		return 0;
	}
}

