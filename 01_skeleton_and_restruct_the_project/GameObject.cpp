#include "GameObject.h"

void CGameObject::SetPosition(float x, float y)
{
	this->x = x;
	this->y = y;
}

int CGameObject::GetX()
{
	return this->x;
}

int CGameObject::GetY()
{
	return this->y;
}

void CGameObject::Update(DWORD dt)
{
}

void CGameObject::Render()
{
	CGame::GetInstance()->Draw(x, y, texture);
}

CGameObject::CGameObject(float x, float y, LPDIRECT3DTEXTURE9 texture)
{
	this->x = x;
	this->y = y;
	this->texture = texture;
}

CGameObject::~CGameObject()
{
	if (texture != NULL) texture->Release();
}
