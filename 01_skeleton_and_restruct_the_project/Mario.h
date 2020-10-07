#pragma once

#include<Windows.h>
#include"Game.h"
#include"GameObject.h"

#define MARIO_VX 0.1f
#define MARIO_WIDTH 14

class CMario : public CGameObject
{
	float vx;
public:
	CMario(float x, float y, float vx, LPDIRECT3DTEXTURE9 texture);
	void Update(DWORD dt);
};

