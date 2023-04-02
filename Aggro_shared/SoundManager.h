#pragma once
class SoundManager
{
private:
	SoundManager();
	~SoundManager();
public:
	static void Create()
	{
		if (_instance == nullptr)
			_instance = new SoundManager();
	}

	static void Delete()
	{
		if (_instance != nullptr)
		{
			delete _instance;
				_instance = nullptr;
		}
	}

	static SoundManager* GetInstance()
	{
		if (_instance != nullptr)
			return _instance;
		return nullptr;
	}

	void PlayerSound() { cout << _PlayerSound << endl; }
	void MonsterSound() { cout << _MonsterSound << endl; }
	void KnightSound() { cout << _KnightSound << endl; }
	void MageSound() { cout << _MageSound << endl; }
	void ArcherSound() { cout << _ArcherSound << endl; }

private:
	static SoundManager* _instance;

	string _PlayerSound;
	string _MonsterSound;
	string _KnightSound;
	string _MageSound;
	string _ArcherSound;

};