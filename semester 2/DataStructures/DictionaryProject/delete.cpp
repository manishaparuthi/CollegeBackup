#include "delete.h"
#include<windows.h>
using namespace std;
#include<iostream>
#define DELETE_WORD 9
LRESULT CALLBACK DeleteProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)                  /* handle the messages */
    {
    case WM_CREATE:
        AddDeleteInfo(hwnd);
        //AddInstructionInfo(hwnd);
        break;
    case WM_COMMAND:
        {
            switch(wParam)
            {
            case DELETE_WORD:
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
void RegisterDeleteClass(HINSTANCE hInst)
{
    WNDCLASSEX Delete ={0};
    Delete.hInstance = hInst;
    Delete.lpszClassName = "DeleteClass";
    Delete.lpfnWndProc = DeleteProcedure;      /* This function is called by windows */
    Delete.style = CS_DBLCLKS;                 /* Catch double-clicks */
    Delete.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    Delete.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    Delete.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    Delete.hCursor = LoadCursor (NULL, IDC_ARROW);
    Delete.lpszMenuName = NULL;                 /* No menu */
    Delete.cbClsExtra = 0;                      /* No extra bytes after the window class */
    Delete.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    Delete.hbrBackground = GetSysColorBrush(COLOR_3DFACE);

    /* Register the Delete class*/
    RegisterClassEx (&Delete);

}
void displayDelete(HWND hWnd)
{
    CreateWindow("DeleteClass","Delete",WS_VISIBLE | WS_OVERLAPPEDWINDOW,200,200,400,400,hWnd,NULL,NULL,NULL);
}


void AddDeleteInfo(HWND hwnd)
{
    char* str="DeleteWord";
    HWND hDelete= CreateWindow("static",str,WS_VISIBLE | WS_CHILD ,20,20,300,300,hwnd,NULL,NULL,NULL);
    CreateWindow("static","Enter Word: ",WS_VISIBLE | WS_CHILD ,40,60,300,300,hwnd,NULL,NULL,NULL);
    CreateWindow("edit",NULL,WS_VISIBLE | WS_CHILD | WS_BORDER,120,60,80,30,hwnd,NULL,NULL,NULL);
    CreateWindow("button","OK ",WS_VISIBLE | WS_CHILD | MB_OK | WS_BORDER ,180,180,80,40,hwnd,(HMENU)DELETE_WORD,NULL,NULL);
}


