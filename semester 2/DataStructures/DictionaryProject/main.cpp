#include <windows.h>
#include<stdlib.h>
#include<fstream>
#include "dicti.h"
#include "about.h"
#include "instruction.h"
#include "add.h"
#include "search.h"
#include "delete.h"
#include<cstring>
#include<iostream>
using namespace std;
#define MENU_ABOUT 1
#define MENU_INSTRUCTIONS 2
#define MENU_EXIT 3
#define MENU_ADD 4
#define MENU_SEARCH 5
#define MENU_DELETE 6
#define OK 7
#define MENU_CREATE 13
/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);
void AddMenus(HWND);
void AddControls(HWND);
void loadImages();
HMENU hMenu;
HWND hWord,hMeaning,hLogo,hOut;
HBITMAP hSearch,hDict;
extern Trie dictionary;
HINSTANCE hinst;
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


    //dictionary.insert("the","meaningThe");

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
    RegisterAboutClass(hThisInstance);
    RegisterInstructionClass(hThisInstance);
    RegisterAddClass(hThisInstance);
    RegisterSearchClass(hThisInstance);
    RegisterDeleteClass(hThisInstance);
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
        //hDict=(HBITMAP)LoadImage(NULL,"dict",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
        //hLogo=CreateWindow("static",NULL,WS_VISIBLE | WS_CHILD | SS_BITMAP ,225,50,100,100,hwnd,NULL,NULL,NULL);
        //SendMessage(hLogo,STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hDict);
        loadImages();
        AddMenus(hwnd);
        AddControls(hwnd);
        break;
    case WM_COMMAND:
        switch(wParam)
        {
            case MENU_EXIT:
                DestroyWindow(hwnd);
                break;
            case MENU_ABOUT:
                displayAbout(hwnd);
                break;
            case MENU_INSTRUCTIONS:
                displayInstruction(hwnd);
                break;
            case MENU_ADD:
                displayAdd(hwnd);
                MessageBeep(MB_OK);
                break;
            case MENU_SEARCH:
                displaySearch(hwnd);
                MessageBeep(MB_OK);
                break;
            case MENU_DELETE:
                displayDelete(hwnd);
                MessageBeep(MB_OK);
                break;
            case MENU_CREATE:
                ifstream f1;
                f1.open("wordmng.txt",ios::in);
                if(!f1)
                {
                    cerr<<"Unable to open file .\n";
                    exit(0);
                }
                string x;
                //cout<<"\n The content of the file is : \n";
                int i;
                while(!f1.eof())
                {
                    getline(f1,x);
                    i=0;
                    char word[20]={};
                    char meaning[20]={};
                    while(x[i]!='-')
                    {
                        //cout<<"x[i]: "<<x[i];
                        word[i]=x[i];
                        i++;
                    }
                    i++;
                    int j=0;
                    while(x[i]!=',')
                    {
                        //cout<<"x[i]: "<<x[i];
                        meaning[j]=x[i];
                        j++;
                        i++;
                    }
                    dictionary.insert(word,meaning);
                    }
                f1.close();
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
    AppendMenu(hMenu,MF_STRING,MENU_ABOUT,"About");
    AppendMenu(hMenu,MF_STRING,MENU_INSTRUCTIONS,"Instructions");
    AppendMenu(hMenu,MF_STRING,MENU_EXIT,"Exit");
    SetMenu(hwnd,hMenu);
}
void AddControls(HWND hwnd)
{
    CreateWindow("button","Add Word ",WS_VISIBLE | WS_CHILD ,150,180,98,38,hwnd,(HMENU)MENU_ADD,NULL,NULL);
    CreateWindow("button","Search Word ",WS_VISIBLE | WS_CHILD ,300,180,98,38,hwnd,(HMENU)MENU_SEARCH,NULL,NULL);
    //CreateWindow("button","Delete Word ",WS_VISIBLE | WS_CHILD ,225,250,98,38,hwnd,(HMENU)MENU_DELETE,NULL,NULL);
    CreateWindow("button","CreateDictionary ",WS_VISIBLE | WS_CHILD ,225,300,108,38,hwnd,(HMENU)MENU_CREATE,NULL,NULL);
    hLogo=CreateWindow("static",NULL,WS_VISIBLE | WS_CHILD | SS_BITMAP ,225,50,100,100,hwnd,NULL,NULL,NULL);
    SendMessage(hLogo,STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hDict);
}
void loadImages()
{
    hDict=(HBITMAP)LoadImage(NULL,"C:/Users/Tarun/Desktop/codeblocks/test/dict.png",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
    if(hDict==NULL) {
        cout<<"\nImage is not loading...";
    }
}


