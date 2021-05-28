#include "stdafx.h"
#include "MainEntryClass.h"

//	���� �߰��� �� ���
#include "BaseScene.h"

//	�� ������ ���⿡�ٰ� �������ּ���!
MainEntryClass::MainEntryClass()
{
	m_Scenes.push_back(new BaseScene());
}

MainEntryClass::~MainEntryClass()
{
	for (auto i : m_Scenes)
		SAFE_DELETE(i);

	m_Scenes.clear();
	//	���� ���Ϳ� clear ȣ�� �� ���� ���Ҵ� ���� ������
	//	capacity (����) �� ���� �ʴ´�
	//	���� ó���� ���� 10���� �ְ�, clear ȣ�� �� �� ���� 10ĭ�� ��������
	//	�׷��� �� �� �������� �����ϱ� ���� ���� ������ �̿��Ͽ� �����Ѵ�
	std::vector<IScene*>().swap(m_Scenes);

	InputManager::Get()->Release();
}

HRESULT MainEntryClass::Start()
{
	try
	{
		for (auto i : m_Scenes)
			i->Start();
	}
	catch (HRESULT h) // std::exception
	{
		HResult(h);
		return h;
	}

	return S_OK;
}

void MainEntryClass::Update()
{
	for (auto i : m_Scenes)
		i->Update();

	if (_KeyCode->GetKeyDown(VK_ESCAPE))
		PostQuitMessage(0);
}

void MainEntryClass::Render()
{
	for (auto i : m_Scenes)
		i->Render();
}