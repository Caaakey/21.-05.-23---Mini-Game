#include "stdafx.h"
#include "BaseScene.h"

BaseScene::BaseScene()
	: m_Player(nullptr), m_BlockManager(nullptr), m_MonsterManager(nullptr)
{
}

BaseScene::~BaseScene()
{
	SAFE_DELETE(m_Player);
	SAFE_DELETE(m_MonsterManager);
	SAFE_DELETE(m_BlockManager);
}

HRESULT BaseScene::Start()
{
	m_BlockManager = new BlockManager();
	m_BlockManager->Start();

	m_Player = new Player();
	m_Player->Start();
	m_Player->Blocks = m_BlockManager;

	m_MonsterManager = new MonsterManager();
	m_MonsterManager->Start(m_BlockManager);

	return S_OK;
}

void BaseScene::Update()
{
	m_Player->Update();
	m_MonsterManager->Update();

	if (m_MonsterManager->IntersectCollider(m_Player->GetHitRect())) {
		m_Player->Hit(0.0f);
	}
}

void BaseScene::Render()
{
	m_BlockManager->Render();
	m_MonsterManager->Render();
	m_Player->Render();
}
