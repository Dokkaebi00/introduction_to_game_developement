#pragma once
#include<iostream>
#include<Windows.h>
#include<d3d9.h>
#include<d3dx9.h>

#define MAX_FRAME_RATE 60

class CGame
{
	static CGame* __hInstance;

	HWND hWnd;

	LPDIRECT3D9 d3d = NULL;
	LPDIRECT3DDEVICE9 d3ddv = NULL;
	LPDIRECT3DSURFACE9 backBuffer = NULL;
	LPD3DXSPRITE spriteHandler = NULL;

	int backBufferWidth = 0;
	int backBufferHeight = 0;
};

