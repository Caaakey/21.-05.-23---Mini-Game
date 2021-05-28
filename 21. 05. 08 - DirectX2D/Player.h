#pragma once
#include "Renderer.h"
#include "BulletManager.h"

class BlockManager;
class Player
{
	enum Status {
		IDLE = 0,
		MOVE,
		JUMP,

		IDLE_ATTACK,
		MOVE_ATTACK,
		JUMP_ATTACK,
		
		HIT
	};

public:
	Player();
	~Player();

	HRESULT Start();
	void Update();
	void Render();
	void Hit(float damage);

public:
	D2D_RECT_F GetHitRect() {
		D2D_RECT_F rect = m_Renderer->GetRect();

		return D2D1::RectF(
			rect.left + 24.0f,
			rect.top + 24.0f,
			rect.right - 24.0f,
			rect.bottom - 16.0f
		);
	}

private:
	Renderer* m_Renderer;
	BulletManager* m_Bullet;
	int m_Status;

	float m_Speed;
	float m_JumpPower;
	float m_BulletSpeed;

	bool m_IsHit;
	bool m_IsOpacity;
	float m_MaxOpacityTime;

public:
	BlockManager* Blocks;

};

