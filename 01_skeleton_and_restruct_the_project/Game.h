#pragma once
#include<iostream>
#include<Windows.h>
#include<d3d9.h>
#include<d3dx9.h>

#define MAX_FRAME_RATE 60

class CGame
{
	static CGame* __instance;

	//handle window (this variable is reprensted for the game's window)
	HWND hWnd;

	//a variable for the directx's environement
	LPDIRECT3D9 d3d;

	//a varialble for the device
	LPDIRECT3DDEVICE9 d3ddv;

	//a variable for the buffer
	LPDIRECT3DSURFACE9 backBuffer;

	//a variable to call sprite's library
	LPD3DXSPRITE spriteHandler;

	//buffer's size
	int backBufferWidth = 0;
	int backBufferHeight = 0;

public:
	LPDIRECT3D9 GetDirect3D();

	LPDIRECT3DDEVICE9 GetDirect3DDevice();
	LPDIRECT3DSURFACE9 GetBackBuffer();
	LPD3DXSPRITE GetSpriteHandler();

	int GetBackBufferWidth();
	int GetBackBufferHeight();

	void InitDirectX(HWND hWnd);
	void Draw(float x, float y, LPDIRECT3DTEXTURE9 texture);
	void Draw(float x, float y, LPDIRECT3DTEXTURE9 texture, int left, int top, int right, int bottom);
	LPDIRECT3DTEXTURE9 LoadTexture(LPCWSTR texturePath);

	static CGame* GetInstance();

	~CGame();
};

