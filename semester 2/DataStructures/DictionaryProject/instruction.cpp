#include "instruction.h"
#include <windows.h>
using namespace std;
#include<iostream>
#define INOK 8
void RegisterInstructionClass(HINSTANCE hInst)
{
    WNDCLASSEX Instruction ={0};
    Instruction.hInstance = hInst;
    Instruction.lpszClassName = "InstructionClass";
    Instruction.lpfnWndProc = InstructionProcedure;      /* This function is called by windows */
    Instruction.style = CS_DBLCLKS;                 /* Catch double-clicks */
    Instruction.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    Instruction.hIcon = LoadIcon (NULL, IDI_ASTERISK);
    Instruction.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    Instruction.hCursor = LoadCursor (NULL, IDC_ARROW);
    Instruction.lpszMenuName = NULL;                 /* No menu */
    Instruction.cbClsExtra = 0;                      /* No extra bytes after the window class */
    Instruction.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    Instruction.hbrBackground = GetSysColorBrush(COLOR_3DFACE);

    /* Register the instruction class*/
    RegisterClassEx (&Instruction);

}

LRESULT CALLBACK InstructionProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)                  /* handle the messages */
    {
    case WM_CREATE:
        AddInstructionInfo(hwnd);
        break;

    case WM_COMMAND:
        {
            switch(wParam)
            {
            case INOK:
              DestroyWindow(hwnd);
              MessageBeep(MB_OK);
              break;
            }
        }
        break;

    case WM_DESTROY:
            DestroyWindow(hwnd);
            //PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}

void displayInstruction(HWND hWnd)
{
    CreateWindow("InstructionClass","Instruction",WS_VISIBLE | WS_OVERLAPPEDWINDOW,100,100,400,400,hWnd,NULL,NULL,NULL);
}
void AddInstructionInfo(HWND hwnd)
{
    char* str="hello welcome to the Instruction window";
    //CreateWindow("static",str,WS_VISIBLE | WS_CHILD ,20,20,100,100,hwnd,NULL,NULL,NULL);
    CreateWindow("static",str,WS_VISIBLE | WS_CHILD ,20,20,300,300,hwnd,NULL,NULL,NULL);
    CreateWindow("button","OK,Got it! ",WS_VISIBLE | WS_CHILD ,180,180,80,40,hwnd,(HMENU)INOK,NULL,NULL);
}

