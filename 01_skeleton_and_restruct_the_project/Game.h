#pragma once
#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>

#include <windows.h>
#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <stdlib.h>

#define _W(x)  __W(x)
#define __W(x)  L##x

#define VA_PRINTS(s) {				\
		va_list argp;				\
		va_start(argp, fmt);		\
		vswprintf_s(s, fmt, argp);	\
		va_end(argp);				\
}


#define MAX_FRAME_RATE 60


class CGame
{
	static CGame* __instance;
	HWND hWnd;				// Window handle

	LPDIRECT3D9 d3d = NULL;						// Direct3D handle
	LPDIRECT3DDEVICE9 d3ddv = NULL;				// Direct3D device object

	LPDIRECT3DSURFACE9 backBuffer = NULL;
	LPD3DXSPRITE spriteHandler = NULL;			// Sprite helper library to help us draw 2D image on the screen 

	int backBufferWidth = 0;
	int backBufferHeight = 0;

public:
	void Init(HWND hWnd);
	void Draw(float x, float y, LPDIRECT3DTEXTURE9 texture);
	void Draw(float x, float y, LPDIRECT3DTEXTURE9 texture, int left, int top, int right, int bottom);
	LPDIRECT3DTEXTURE9 LoadTexture(LPCWSTR texturePath);



	LPDIRECT3DDEVICE9 GetDirect3DDevice() { return this->d3ddv; }
	LPDIRECT3DSURFACE9 GetBackBuffer() { return backBuffer; }
	LPD3DXSPRITE GetSpriteHandler() { return this->spriteHandler; }
	int GetBackBufferWidth() { return this->backBufferWidth; }
	int GetBackBufferHeight() { return this->backBufferHeight; }

	void DebugOut(const wchar_t* fmt, ...);
	void DebugOutTitle(const wchar_t* fmt, ...);

	static CGame* GetInstance();

	~CGame();
};