#pragma once
#include "stdafx.h"

//	안에 변수 구현 불가능
//	내부 함수 직접 구현 불가능
//	정말 껍데기만 제공 (폼(form)만 제공)
__interface IScene
{
	//	씬이 실행될 때 단 한 번만 호출됨! (초기화)
	HRESULT Start();

	//	프로그램이 돌아갈 때 프레임마다 호출 됨 (지속적)
	void Update();

	//	그릴 녀석을 업데이트랑 동일하게 호출 됨 (지속적)
	void Render();
};
