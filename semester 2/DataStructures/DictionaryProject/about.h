#ifndef ABT
#define ABT
#include<windows.h>
void AddAboutInfo(HWND);
LRESULT CALLBACK AboutProcedure (HWND, UINT, WPARAM, LPARAM);
void RegisterAboutClass(HINSTANCE);
void displayAbout(HWND);
#endif
