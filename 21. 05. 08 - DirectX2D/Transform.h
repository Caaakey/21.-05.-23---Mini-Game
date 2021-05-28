#pragma once

class Transform
{
public:
	Transform();
	virtual ~Transform();

	void Jump(float jumpPower, float radian = PI / 1.25f);
	bool CheckLocation(D2D_RECT_F rect);

private:
	float m_Gravity;
	float m_GravityDirection;
	float m_PrevPositionY;
	D2D_RECT_F m_CurrentFloorRect;
	D2D_SIZE_F m_ImageSize;

protected:
	void SetImageSize(D2D_SIZE_F size) { m_ImageSize = size; }
	void UpdateJump();

public:
	D2D_VECTOR_2F Position;
	float Rotation;
	D2D_VECTOR_2F Scale;
	float GravityAcceleration;
	float LocationOffsetY;

	bool isJumping;
	bool isDown;

public:
	D2D_RECT_F GetRect() {
		return D2D1::RectF(
			Position.x,
			Position.y,
			Position.x + m_ImageSize.width * Scale.x,
			Position.y + m_ImageSize.height * Scale.y);
	}
	D2D_VECTOR_2F GetBottomPoint() {
		return {
			Position.x + (m_ImageSize.width * Scale.x) / 2.0f,
			Position.y + m_ImageSize.height * Scale.y + LocationOffsetY };
	}
};

