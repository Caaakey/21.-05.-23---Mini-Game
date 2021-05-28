#include "stdafx.h"
#include "Transform.h"

Transform::Transform()
	: Position({ 0, 0 }), Rotation(0), Scale({ 1.0f, 1.0f }),
	isJumping(false), m_Gravity(0), m_GravityDirection(0), m_PrevPositionY(0),
	m_ImageSize({ 0, 0 }), m_CurrentFloorRect({0, }), isDown(false), GravityAcceleration(1.0f),
	LocationOffsetY(0.0f)
{
}

Transform::~Transform()
{
}

void Transform::Jump(float jumpPower, float radian)
{
	if (isJumping) return;

	isJumping = true;
	m_Gravity = jumpPower;
	m_GravityDirection = radian;

	m_CurrentFloorRect = { 0, };
	m_PrevPositionY = 0;
}

bool Transform::CheckLocation(D2D_RECT_F rect)
{
	if (m_GravityDirection < PI) return false;

	D2D_RECT_F rc = GetRect();
	D2D_VECTOR_2F point = GetBottomPoint();
	if (Collision::IsInRectPoint(rect, point))
	{
		if (m_PrevPositionY <= rect.top)
		{
			Position.y = rect.top - m_ImageSize.height * Scale.y + LocationOffsetY;

			isJumping = false;
			isDown = false;
			m_GravityDirection = 0.0f;

			m_CurrentFloorRect = rect;
			m_PrevPositionY = 0;
			return true;
		}
	}

	return false;
}

void Transform::UpdateJump()
{
	if (isJumping)
	{
		float gravity = sinf(m_GravityDirection) * m_Gravity;
		if (m_GravityDirection <= PI * 2.0f)
			m_GravityDirection += (PI / 128.0f) * GravityAcceleration;

		if (m_GravityDirection >= PI)
			m_PrevPositionY = GetBottomPoint().y;

		Position.y -= gravity;
	}
	else if (m_CurrentFloorRect.bottom != 0)
	{
		float x = GetBottomPoint().x;
		if (x < m_CurrentFloorRect.left ||
			x > m_CurrentFloorRect.right)
		{
			Jump(24.0f, PI);
			isDown = true;
		}
	}
}
