#pragma once
#include "Player.h"
#include "MonsterManager.h"
#include "BlockManager.h"

//	IScene 이라는 녀석을 상속해주면
//	이 녀석은 씬 이야! 라고 알려주게된다 (Start, Update, Render)
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
	// IScene을(를) 통해 상속됨
	virtual HRESULT Start() override;
	virtual void Update() override;
	virtual void Render() override;
};

