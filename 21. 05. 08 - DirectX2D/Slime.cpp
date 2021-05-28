#include "stdafx.h"
#include "Slime.h"

Slime::Slime(std::string name, D2D_VECTOR_2F position) : BasePawn(name)
	, m_Status(0), m_CurrentJumpCount(0), m_JumpPower(32.0f)
{
	m_Speed = RandomHelper::RandomRange(2.5f, 5.5f);
	m_Renderer->Position = position;
	m_Renderer->Scale = { 2.0f, 2.0f };

	m_MaxJumpCount = rand() % 70 + 30;
}

Slime::~Slime()
{
}

HRESULT Slime::Start()
{
	D2D_POINT_2U move[] = { {0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0} };
	m_Renderer->AddAnimation(move, 6, 8, true);
	m_Renderer->Jump(m_JumpPower, PI);

	return S_OK;
}

void Slime::Update()
{
	float speed = m_Renderer->isReverse ? -m_Speed : m_Speed;
	m_Renderer->Position.x += speed;

	D2D_RECT_F rect = m_Renderer->GetRect();

	if (!m_Renderer->isReverse && (float)_Application->Width <= rect.right) {
		m_Renderer->isReverse = !m_Renderer->isReverse;
		m_Renderer->Position.x -= speed;
	}
	else if (m_Renderer->isReverse && 0.0f >= rect.left) {
		m_Renderer->isReverse = !m_Renderer->isReverse;
		m_Renderer->Position.x += speed;
	}

	if (!m_Renderer->isJumping)
	{
		m_CurrentJumpCount++;
		if (m_CurrentJumpCount == m_MaxJumpCount) {
			m_Renderer->Jump(m_JumpPower);

			m_CurrentJumpCount = 0;
			m_MaxJumpCount = rand() % 70 + 30;
		}
	}

	m_Renderer->Update(m_Status);
	UpdateCheckLocation();
}

void Slime::Render()
{
	m_Renderer->Render();

	//_RenderTarget->DrawRectangle(GetHitRect(), _Renderer->GetBrush());
}

D2D1_RECT_F Slime::GetHitRect()
{
	D2D_RECT_F rect =  m_Renderer->GetRect();
	return D2D1::RectF(
		rect.left + 20.0f,
		rect.top + 20.0f,
		rect.right - 30.0f,
		rect.bottom
	);
}

void Slime::Hit(float damage)
{
}

void Slime::LandingLocation()
{
}
