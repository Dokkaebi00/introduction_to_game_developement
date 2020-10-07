#include "Mario.h"

CMario::CMario(float x, float y, float vx, LPDIRECT3DTEXTURE9 texture) : CGameObject(x, y, texture)
{
	this->vx = vx;
}

void CMario::Update(DWORD dt)
{
	x = x + vx * dt;

	int BackBufferWidth = CGame::GetInstance()->GetBackBufferWidth();

	if (x <= 0 || x >= BackBufferWidth - MARIO_WIDTH);
	{
		vx = -vx;
		if (x <= 0)
		{
			x = 0;
		}
		else if (x >= BackBufferWidth - MARIO_WIDTH)
		{
			x = (float)(BackBufferWidth - MARIO_WIDTH);
		}
	}
}
