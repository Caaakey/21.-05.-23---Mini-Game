#pragma once

class Bullet
{
public:
	Bullet(std::string name, float x, float y, float angle, float speed, bool isReverse);
	Bullet(std::string name, float x, float y, UINT fx, UINT fy, int frameSpeed, float angle, float speed, bool isReverse);
	~Bullet();

private:
	BaseTexture* m_Texture;

	D2D_VECTOR_2F m_Position;
	float m_Angle;
	float m_Speed;
	bool m_IsReverse;

	UINT m_FrameX;
	UINT m_FrameY;
	int m_FrameSpeed;

	UINT m_CurrentFrameX;
	UINT m_CurrentFrameY;
	int m_CurrentFrame;

public:
	bool Update();
	void Render();

	D2D_RECT_F GetRect() {
		return D2D1::RectF(m_Position.x, m_Position.y,
			m_Position.x + m_Texture->GetSize().width,
			m_Position.y + m_Texture->GetSize().height);
	}

	D2D1_ELLIPSE GetEllipse() {
		return D2D1::Ellipse({ m_Position.x, m_Position.y },
			m_Texture->GetSize().width / 2.0f,
			m_Texture->GetSize().height / 2.0f);
	}

};

