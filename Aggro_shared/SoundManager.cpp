#include "framwork.h"
#include "SoundManager.h"

SoundManager* SoundManager::_instance = nullptr;
SoundManager::SoundManager()
{
	_PlayerSound = "(플레이어가 공격하는 소리)";
	_MonsterSound = "(몬스터가 공격하는 소리)";
	_KnightSound = "(플레이어가 공격하는 소리)";
	_MageSound = "(플레이어가 공격하는 소리)";
	_ArcherSound = "(플레이어가 공격하는 소리)";
}
