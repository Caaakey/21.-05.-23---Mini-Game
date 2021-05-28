#include "stdafx.h"
#include "Player.h"

#include "BlockManager.h"

Player::Player()
	: m_Renderer(nullptr), m_Bullet(nullptr),
	m_Status(0), m_Speed(5.0f), m_JumpPower(32.0f), m_BulletSpeed(12.0f),
	Blocks(nullptr), m_IsHit(false), m_IsOpacity(false), m_MaxOpacityTime(3.0f)
{
}

Player::~Player()
{
	SAFE_DELETE(m_Bullet);
	SAFE_DELETE(m_Renderer);
}

HRESULT Player::Start()
{
	m_Renderer = new Renderer("Char", L"../_Resources/Character.png", 14, 2);
	m_Renderer->isReverse = true;
	m_Renderer->Position.x = _Application->Width / 2.0f;
	m_Renderer->Position.y = _Application->Height / 2.0f;
	m_Renderer->Scale = { 1.2f, 1.2f };
	m_Renderer->Jump(m_JumpPower, PI);
	m_Renderer->SetIndexPointer(&this->m_Status);
	m_Renderer->LocationOffsetY = 15.0f;

	D2D_POINT_2U idle[] = { {0, 0}, {1, 0}, {2, 0} };
	m_Renderer->AddAnimation(idle, 3, 18, true);

	D2D_POINT_2U move[] = { {3, 0}, {4, 0}, {5, 0} };
	m_Renderer->AddAnimation(move, 3, 7);

	D2D_POINT_2U jump[] = { {0, 1} };
	m_Renderer->AddAnimation(jump, 1, 0);
	m_Renderer->SetDownAnimation(JUMP);
	m_Renderer->isDown = true;

	D2D_POINT_2U idle_Attack[] = { {6, 0} };
	m_Renderer->AddAnimation(idle_Attack, 1, 16, false, IDLE);

	D2D_POINT_2U move_Attack[] = { {7, 0}, {8, 0}, {9, 0} };
	m_Renderer->AddAnimation(move_Attack, 3, 6, false, MOVE);

	D2D_POINT_2U jump_Attack[] = { {1, 1} };
	m_Renderer->AddAnimation(jump_Attack, 1, 24, false, JUMP);

	D2D_POINT_2U hit[] = { {2, 1} };
	m_Renderer->AddAnimation(hit, 1, 64, false, IDLE);

	m_Bullet = new BulletManager();
	_Texture->LoadTexture("Bullet", L"../_Resources/Bullet.png");

	return S_OK;
}

void Player::Update()
{
	if (!m_IsHit) {
		if (_KeyCode->GetKey(VK_LEFT)) {
			if (m_Status < JUMP) m_Status = MOVE;

			m_Renderer->Position.x -= m_Speed;
			m_Renderer->isReverse = true;
		}
		else if (_KeyCode->GetKey(VK_RIGHT)) {
			if (m_Status < JUMP) m_Status = MOVE;

			m_Renderer->Position.x += m_Speed;
			m_Renderer->isReverse = false;
		}
		else {
			if (m_Status < JUMP) m_Status = IDLE;
		}

		if (_KeyCode->GetKeyDown('Z')) {

			if (m_Status != HIT) {

				switch (m_Status)
				{
				case IDLE: { m_Status = IDLE_ATTACK; } break;
				case MOVE: { m_Status = MOVE_ATTACK; } break;
				case JUMP: { m_Status = JUMP_ATTACK; } break;
				default: break;
				}

				//	마우스 위치로 발사
				//float angle = Collision::GetAngle(m_Renderer->Position.x, m_Renderer->Position.y, MousePoint.x, MousePoint.y);
				//m_Bullet->Shoot("Bullet", m_Renderer->Position.x, m_Renderer->Position.y, angle, m_BulletSpeed, false);

				float speed = m_Renderer->isReverse ? -m_BulletSpeed : m_BulletSpeed;
				m_Bullet->Shoot("Bullet", m_Renderer->Position.x, m_Renderer->Position.y, 0.0f, speed, false);
			}
		}
		if (_KeyCode->GetKeyDown(VK_SPACE)) {
			m_Status = JUMP;
			m_Renderer->Jump(m_JumpPower);
		}

		if (_KeyCode->GetKeyDown('Q')) Hit(0);
	}
	else 
		m_Renderer->Position.x += m_Renderer->isReverse ? 3.0f : -3.0f;

	m_Renderer->Update(m_Status);

	if (_Timer->CheckTime("Player Hit")) {
		m_IsOpacity = false;
		m_Renderer->Opacity = 1.0f;
	}

	for (auto b : Blocks->GetBlocks()) {
		if (m_Renderer->CheckLocation(b->GetRect()))
		{
			m_Status = IDLE;

			if (m_IsHit)
			{
				m_IsHit = false;
				m_Renderer->GravityAcceleration = 1.0f;

				m_IsOpacity = true;
				_Timer->SetTimer("Player Hit", m_MaxOpacityTime);
			}
			break;
		}
	}

	m_Bullet->Update();
	//printf("%f\n", _Timer->GetCurrentSecondTime("Player Hit"));
}

void Player::Render()
{
	if (m_IsOpacity) {
		float opacity = float(rand() % 10);
		m_Renderer->Opacity = opacity * 0.1f;

		printf("%f\n", opacity);
	}


	m_Renderer->Render();
	m_Bullet->Render();

	_RenderTarget->DrawRectangle(GetHitRect(), _Renderer->GetBrush());
}

void Player::Hit(float damage)
{
	if (m_IsOpacity) return;

	m_Status = HIT;
	m_IsHit = true;

	m_Renderer->Jump(m_JumpPower / 1.75f);
	m_Renderer->GravityAcceleration = 1.25f;
}
