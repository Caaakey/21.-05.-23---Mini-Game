#include "stdafx.h"
#include "MonsterManager.h"
#include "BlockManager.h"

#include "Slime.h"

MonsterManager::MonsterManager()
	: m_Blocks(nullptr)
{
}

MonsterManager::~MonsterManager()
{
	for (auto i : m_Monsters)
		SAFE_DELETE(i);
}

HRESULT MonsterManager::Start(BlockManager* pBlock)
{
	m_Blocks = pBlock;

	_Texture->LoadTexture("Slime", L"../_Resources/Slime.png", 6, 1);

	AddMonster(new Slime("Slime", {200.0f, 10.0f}));

	return S_OK;
}

void MonsterManager::Update()
{
	for (auto i : m_Monsters)
		i->Update();
}

void MonsterManager::Render()
{
	for (auto i : m_Monsters)
		i->Render();
}

void MonsterManager::AddMonster(BasePawn* pawn)
{
	pawn->Blocks = m_Blocks;
	pawn->Start();

	m_Monsters.push_back(pawn);
}

bool MonsterManager::IntersectCollider(D2D_RECT_F rect)
{
	for (auto i : m_Monsters) {
		if (Collision::IsInRect(rect, i->GetHitRect())) return true;
	}

	return false;
}
