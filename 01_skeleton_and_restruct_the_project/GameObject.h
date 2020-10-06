#pragma once

#include<Windows.h>
#include<d3d9.h>
#include<d3dx9.h>
#include"Game.h"

class CGameObject
{
protected:
	float x;
	float y;
	LPDIRECT3DTEXTURE9 texture;

public:
	void SetPosition(float x, float y);
	float GetX();
	float GetY();

	CGameObject(float x = 0.0f, float y = 0.0f, LPDIRECT3DTEXTURE9 texture = NULL);

	virtual void Update(DWORD dt);
	virtual void Render();

	~CGameObject();
};

typedef CGameObject* LPGAMEOBJECT;

