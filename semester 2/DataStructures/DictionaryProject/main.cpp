#include <windows.h>
#include<stdlib.h>
#include "dictionary.h"
#include<cstring>
#include<iostream>
using namespace std;
#define FILE_MENU_NEW 1
#define FILE_MENU_OPEN 2
#define FILE_MENU_EXIT 3
#define SUB_MENU_TITLE 4
/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);
void AddMenus(HWND);
void AddControls(HWND);
HMENU hMenu;
HWND hWord,hMeaning,hOut;
Trie dictionary;
/*  Make the class name into a global variable  */
char szClassName[ ] = "Trie: Dictionary";

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */


    dictionary.insert("the","meaningThe");

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = GetSysColorBrush(COLOR_3DFACE);

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
   hwnd= CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           "Data Structure Project: Dictionary",       /* Title Text */
           WS_SYSMENU | WS_MAXIMIZEBOX |WS_MINIMIZEBOX, /* default window */
           100,
           100,       /* where the window ends up on the screen */
           600,                 /* The programs width */
           600,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nCmdShow);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}


/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)                  /* handle the messages */
    {
    case WM_CREATE:
        AddMenus(hwnd);
        AddControls(hwnd);
        break;
    case WM_COMMAND:
        switch(wParam)
        {
            case FILE_MENU_EXIT:
                //MessageBeep(MB_OK);
                DestroyWindow(hwnd);
                break;
            case FILE_MENU_NEW:
                MessageBeep(MB_ICONINFORMATION);
                //DestroyWindow(hwnd);
                break;
            case FILE_MENU_OPEN:
                MessageBeep(MB_OK);
                //DestroyWindow(hwnd);
                break;
            case SUB_MENU_TITLE:
                char name[30];
                GetWindowText(hWord,name,30);
                //char age[10];
                char* out=dictionary.search(name);
                SetWindowText(hMeaning,out);
                //GetWindowText(hMeaning,age,10);
                //char out[80];
                //strcpy(out,name);
                //strcat(out," is ");
                //strcat(out,age);
                //strcat(out," years old.");
                SetWindowText(hOut,out);
                break;
        }

        break;

    case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}
void AddMenus(HWND hwnd)
{
    hMenu=CreateMenu();
    HMENU hFileMenu=CreateMenu();
    HMENU hSubMenu=CreateMenu();

    AppendMenu(hSubMenu,MF_STRING,SUB_MENU_TITLE,"ChangeTitle");
    AppendMenu(hSubMenu,MF_STRING,NULL,"File");

    AppendMenu(hFileMenu,MF_POPUP,(UINT_PTR)hSubMenu,"New");
    AppendMenu(hFileMenu,MF_STRING,FILE_MENU_OPEN,"Open");
    AppendMenu(hFileMenu,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hFileMenu,MF_STRING,FILE_MENU_EXIT,"Exit");


    AppendMenu(hMenu,MF_POPUP,(UINT_PTR)hFileMenu,"File");
    AppendMenu(hMenu,MF_STRING,NULL,"Copy");

    SetMenu(hwnd,hMenu);
}
void AddControls(HWND hwnd)
{
    CreateWindow("static","Enter Word: ",WS_VISIBLE | WS_CHILD ,100,50,98,38,hwnd,NULL,NULL,NULL);
    hWord=CreateWindow("edit","",WS_VISIBLE | WS_CHILD | WS_BORDER,200,50,98,38,hwnd,NULL,NULL,NULL);
    CreateWindow("static","Meaning: ",WS_VISIBLE | WS_CHILD ,100,90,98,38,hwnd,NULL,NULL,NULL);
    hMeaning=CreateWindow("edit","",WS_VISIBLE | WS_CHILD | WS_BORDER,200,90,98,38,hwnd,NULL,NULL,NULL);
    CreateWindow("button","Generate ",WS_VISIBLE | WS_CHILD ,150,140,98,38,hwnd,(HMENU)SUB_MENU_TITLE,NULL,NULL);
    hOut=CreateWindow("edit","",WS_VISIBLE | WS_CHILD | WS_BORDER,170,190,300,200,hwnd,NULL,NULL,NULL);
}

