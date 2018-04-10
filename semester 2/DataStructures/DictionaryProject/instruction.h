#ifndef INST
#define INST
#include<windows.h>
void AddInstructionInfo(HWND);
LRESULT CALLBACK InstructionProcedure (HWND, UINT, WPARAM, LPARAM);
void RegisterInstructionClass(HINSTANCE);
void displayInstruction(HWND);
#endif
