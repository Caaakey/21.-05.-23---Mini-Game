#pragma once
#include "BasePawn.h"

class Slime : public BasePawn
{
	enum Status {
		MOVE = 0,
		JUMP,

		HIT,
		DEATH
	};

public:
	Slime(std::string name, D2D_VECTOR_2F position);
	~Slime();

	void Hit(float damage);

	// BasePawn을(를) 통해 상속됨
	virtual HRESULT Start() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual D2D1_RECT_F GetHitRect() override;

protected:
	// BasePawn을(를) 통해 상속됨
	virtual void LandingLocation() override;

private:
	int m_Status;
	float m_Speed;

	int m_MaxJumpCount;
	int m_CurrentJumpCount;
	float m_JumpPower;

};

