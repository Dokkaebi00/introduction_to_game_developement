#include "Game.h"
#include "debug.h"

LPDIRECT3D9 CGame::GetDirect3D()
{
    return this->d3d;
}

LPDIRECT3DDEVICE9 CGame::GetDirect3DDevice()
{
    return this->d3ddv;
}

LPDIRECT3DSURFACE9 CGame::GetBackBuffer()
{
    return this->backBuffer;
}

LPD3DXSPRITE CGame::GetSpriteHandler()
{
    return this->spriteHandler;
}

int CGame::GetBackBufferWidth()
{
    return this->backBufferWidth;
}

int CGame::GetBackBufferHeight()
{
    return this->backBufferHeight;
}

void CGame::InitDirectX(HWND hWnd)
{
    LPDIRECT3D9 d3d = Direct3DCreate9(D3D_SDK_VERSION);

    this->hWnd = hWnd;

    D3DPRESENT_PARAMETERS d3dpp;

    d3dpp.Windowed = TRUE;
    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
    d3dpp.BackBufferCount = 1;

    RECT r;
    GetClientRect(hWnd, &r);

    backBufferHeight = r.bottom + 1;
    backBufferWidth = r.right + 1;

    d3dpp.BackBufferHeight = backBufferHeight;
    d3dpp.BackBufferWidth = backBufferWidth;

    d3d->CreateDevice(
        D3DADAPTER_DEFAULT,
        D3DDEVTYPE_HAL,
        hWnd,
        D3DCREATE_SOFTWARE_VERTEXPROCESSING,
        &d3dpp,
        &d3ddv
    );

    if (!hWnd)
    {
        DebugOut(L"[ERROR] CreateDevice failed\n");
        return;
    }

    d3ddv->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &backBuffer);

    D3DXCreateSprite(d3ddv, &spriteHandler);

    DebugOut(L"[INFO] InitGame done;\n");
}
