#pragma once
#include "Player.h"
#include "MonsterManager.h"
#include "BlockManager.h"

//	IScene �̶�� �༮�� ������ָ�
//	�� �༮�� �� �̾�! ��� �˷��ְԵȴ� (Start, Update, Render)
class BaseScene : public IScene
{
public:
	BaseScene();
	~BaseScene();

private:
	Player* m_Player;
	MonsterManager* m_MonsterManager;
	BlockManager* m_BlockManager;


public:
	// IScene��(��) ���� ��ӵ�
	virtual HRESULT Start() override;
	virtual void Update() override;
	virtual void Render() override;
};

