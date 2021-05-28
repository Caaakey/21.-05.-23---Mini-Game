#include "stdafx.h"
#include "Bullet.h"

Bullet::Bullet(std::string name, float x, float y, float angle, float speed, bool isReverse)
	: m_Texture(nullptr),
	m_Position({ x, y }), m_Speed(speed), m_FrameX(0), m_FrameY(0), m_CurrentFrame(0),
	m_Angle(angle), m_IsReverse(isReverse), m_FrameSpeed(0),
	m_CurrentFrameX(0), m_CurrentFrameY(0)
{
	m_Texture = _Texture->Find(name);
}

Bullet::Bullet(std::string name, float x, float y, UINT fx, UINT fy, int frameSpeed, float angle, float speed, bool isReverse)
	: m_Texture(nullptr),
	m_Position({ x, y }), m_Speed(speed), m_FrameX(fx), m_FrameY(fy), m_CurrentFrame(0),
	m_Angle(angle), m_IsReverse(isReverse), m_FrameSpeed(frameSpeed),
	m_CurrentFrameX(0), m_CurrentFrameY(0)
{
	m_Texture = _Texture->Find(name);
}

Bullet::~Bullet()
{
}

bool Bullet::Update()
{
	float x = cosf(m_Angle) * m_Speed;
	float y = sinf(m_Angle) * m_Speed;

	m_Position.x += x;
	m_Position.y += y;

	if (m_Texture->IsFrameImage()) {

		m_CurrentFrame++;
		if (m_CurrentFrame % m_FrameSpeed == 0) {
			m_CurrentFrameX++;

			if (m_CurrentFrameX == m_FrameX + 1) {
				if (m_FrameY != 0) {
					m_CurrentFrameY++;

					if (m_CurrentFrameY == m_FrameY + 1)
						m_CurrentFrameY = 0;
				}

				m_CurrentFrameX = 0;
			}

			m_CurrentFrame = 0;
		}
	}

	if (m_Position.x <= -m_Texture->GetSize().width || m_Position.x > _Application->Width + m_Texture->GetSize().width)
		return false;

	return true;
}

void Bullet::Render()
{
	if (m_Texture->IsFrameImage())
		m_Texture->DrawFrame(m_Position.x, m_Position.y, m_CurrentFrameX, m_CurrentFrameY, 0, 0, m_IsReverse);
	else
		m_Texture->Draw(m_Position.x, m_Position.y, m_Texture->GetSize().width, m_Texture->GetSize().height, m_IsReverse);
}
