#include "framwork.h"
#include "SoundManager.h"

SoundManager* SoundManager::_instance = nullptr;
SoundManager::SoundManager()
{
	_PlayerSound = "(�÷��̾ �����ϴ� �Ҹ�)";
	_MonsterSound = "(���Ͱ� �����ϴ� �Ҹ�)";
	_KnightSound = "(�÷��̾ �����ϴ� �Ҹ�)";
	_MageSound = "(�÷��̾ �����ϴ� �Ҹ�)";
	_ArcherSound = "(�÷��̾ �����ϴ� �Ҹ�)";
}
