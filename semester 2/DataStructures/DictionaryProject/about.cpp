#include "about.h"
#include<windows.h>
using namespace std;

#define ABOK 7
#include<iostream>
LRESULT CALLBACK AboutProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)                  /* handle the messages */
    {
    case WM_CREATE:
        AddAboutInfo(hwnd);
        break;
    case WM_COMMAND:
        {
            switch(wParam)
            {
            case ABOK:
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
void RegisterAboutClass(HINSTANCE hInst)
{
    WNDCLASSEX About ={0};
    About.hInstance = hInst;
    About.lpszClassName = "AboutClass";
    About.lpfnWndProc = AboutProcedure;      /* This function is called by windows */
    About.style = CS_DBLCLKS;                 /* Catch double-clicks */
    About.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    About.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    About.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    About.hCursor = LoadCursor (NULL, IDC_ARROW);
    About.lpszMenuName = NULL;                 /* No menu */
    About.cbClsExtra = 0;                      /* No extra bytes after the window class */
    About.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    About.hbrBackground = GetSysColorBrush(COLOR_3DFACE);

    /* Register the About class*/
    RegisterClassEx (&About);

}
void displayAbout(HWND hWnd)
{
    CreateWindow("AboutClass","About",WS_VISIBLE | WS_OVERLAPPEDWINDOW,100,100,400,500,hWnd,NULL,NULL,NULL);
}


void AddAboutInfo(HWND hwnd)
{
    char* str="Hello welcome to the Dictionary.This is like modern dictionary where we can search add and delete words according to our needs. ";
    CreateWindow("static",str,WS_VISIBLE | WS_CHILD ,20,20,300,300,hwnd,NULL,NULL,NULL);
    CreateWindow("button","OK ",WS_VISIBLE | WS_CHILD ,180,180,80,40,hwnd,(HMENU)ABOK,NULL,NULL);

}
