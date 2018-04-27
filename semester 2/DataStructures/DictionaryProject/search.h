#ifndef SEARCH
#define SEARCH
#include<windows.h>
void AddSearchInfo(HWND);
LRESULT CALLBACK SearchProcedure (HWND, UINT, WPARAM, LPARAM);
void RegisterSearchClass(HINSTANCE);
void displaySearch(HWND);
#endif


