#ifndef DEL
#define DEL
#include<windows.h>
void AddDeleteInfo(HWND);
LRESULT CALLBACK DeleteProcedure (HWND, UINT, WPARAM, LPARAM);
void RegisterDeleteClass(HINSTANCE);
void displayDelete(HWND);
#endif
