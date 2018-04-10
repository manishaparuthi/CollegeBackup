#include "add.h"
#include<windows.h>
using namespace std;
#include<iostream>
LRESULT CALLBACK AddProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)                  /* handle the messages */
    {
    case WM_CREATE:
        AddAddInfo(hwnd);
        //AddInstructionInfo(hwnd);
        break;
    case WM_COMMAND:
        {
            switch(wParam)
            {
            case 1:
              DestroyWindow(hwnd);
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
void RegisterAddClass(HINSTANCE hInst)
{
    WNDCLASSEX Add ={0};
    Add.hInstance = hInst;
    Add.lpszClassName = "AddClass";
    Add.lpfnWndProc = AddProcedure;      /* This function is called by windows */
    Add.style = CS_DBLCLKS;                 /* Catch double-clicks */
    Add.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    Add.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    Add.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    Add.hCursor = LoadCursor (NULL, IDC_ARROW);
    Add.lpszMenuName = NULL;                 /* No menu */
    Add.cbClsExtra = 0;                      /* No extra bytes after the window class */
    Add.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    Add.hbrBackground = GetSysColorBrush(COLOR_3DFACE);

    /* Register the Add class*/
    RegisterClassEx (&Add);

}
void displayAdd(HWND hWnd)
{
    CreateWindow("AddClass","Add",WS_VISIBLE | WS_OVERLAPPEDWINDOW,150,150,500,500,hWnd,NULL,NULL,NULL);
}


void AddAddInfo(HWND hwnd)
{
    char* str="Add Word";
     HWND hAbout= CreateWindow("static",str,WS_VISIBLE | WS_CHILD ,20,20,100,100,hwnd,NULL,NULL,NULL);
    CreateWindow("static","Enter Word: ",WS_VISIBLE | WS_CHILD ,20,60,80,30,hwnd,NULL,NULL,NULL);
    CreateWindow("edit",NULL,WS_VISIBLE | WS_CHILD | WS_BORDER,100,60,80,30,hwnd,NULL,NULL,NULL);
      CreateWindow("static","Enter Meaning: ",WS_VISIBLE | WS_CHILD ,20,100,80,30,hwnd,NULL,NULL,NULL);
      CreateWindow("edit",NULL,WS_VISIBLE | WS_CHILD | WS_BORDER,100,140,80,30,hwnd,NULL,NULL,NULL);
    CreateWindow("button","Add Word ",WS_VISIBLE | WS_CHILD | MB_OK ,200,200,80,40,hAbout,(HMENU)1,NULL,NULL);

}

