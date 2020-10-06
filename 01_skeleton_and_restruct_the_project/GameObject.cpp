#include "GameObject.h"

void CGameObject::SetPosition(float x, float y)
{
	this->x = x;
	this->y = y;
}

float CGameObject::GetX()
{
	return this->x;
}

float CGameObject::GetY()
{
	return this->y;
}

CGameObject::CGameObject(float x, float y, LPDIRECT3DTEXTURE9 texture)
{
	this->x = x;
	this->y = y;
	this->texture = texture;
}

void CGameObject::Render()
{
	CGame::GetInstance()->Draw(x, y, texture);
}

CGameObject::~CGameObject()
{
	if (texture != NULL) texture->Release();
}
