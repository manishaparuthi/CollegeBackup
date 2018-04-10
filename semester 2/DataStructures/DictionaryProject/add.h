#ifndef ADD
#define ADD
#include<windows.h>
void AddAddInfo(HWND);
LRESULT CALLBACK AddProcedure (HWND, UINT, WPARAM, LPARAM);
void RegisterAddClass(HINSTANCE);
void displayAdd(HWND);
#endif

