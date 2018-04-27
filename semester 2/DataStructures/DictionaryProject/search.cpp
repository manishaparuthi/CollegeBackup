#include "search.h"
#include<windows.h>
using namespace std;
#include<iostream>
#include "dicti.h"
#define OK_SEARCH 11
extern Trie dictionary;
HWND hWordSearch,hMeaningSearch,hSuggestionSearch;
LRESULT CALLBACK SearchProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)                  /* handle the messages */
    {
    case WM_CREATE:
        AddSearchInfo(hwnd);
        //AddInstructionInfo(hwnd);
        break;
    case WM_COMMAND:
        {
            switch(wParam)
            {
            case OK_SEARCH:
              char word[20],meaning[20];
              GetWindowText(hWordSearch,word,20);
              meaning = {};
              if(dictionary.search(word,meaning))
              {
                  SetWindowText(hMeaningSearch,meaning);
              }
              else
              {
                  SetWindowText(hMeaningSearch,"Word not found");
              }

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
void RegisterSearchClass(HINSTANCE hInst)
{
    WNDCLASSEX Search ={0};
    Search.hInstance = hInst;
    Search.lpszClassName = "SearchClass";
    Search.lpfnWndProc = SearchProcedure;      /* This function is called by windows */
    Search.style = CS_DBLCLKS;                 /* Catch double-clicks */
    Search.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    Search.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    Search.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    Search.hCursor = LoadCursor (NULL, IDC_ARROW);
    Search.lpszMenuName = NULL;                 /* No menu */
    Search.cbClsExtra = 0;                      /* No extra bytes after the window class */
    Search.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    Search.hbrBackground = GetSysColorBrush(COLOR_3DFACE);

    /* Register the Search class*/
    RegisterClassEx (&Search);

}
void displaySearch(HWND hWnd)
{
    CreateWindow("SearchClass","Search",WS_VISIBLE | WS_OVERLAPPEDWINDOW,150,150,500,500,hWnd,NULL,NULL,NULL);
}


void AddSearchInfo(HWND hwnd)
{
    char* str="SearchWord";
    CreateWindow("static",str,WS_VISIBLE | WS_CHILD ,20,20,100,100,hwnd,NULL,NULL,NULL);
    CreateWindow("static","Enter Word: ",WS_VISIBLE | WS_CHILD ,40,60,80,30,hwnd,NULL,NULL,NULL);
    hWordSearch=CreateWindow("edit",NULL,WS_VISIBLE | WS_CHILD | WS_BORDER,120,60,120,45,hwnd,NULL,NULL,NULL);
    CreateWindow("button","Search",WS_VISIBLE | WS_CHILD | MB_OK ,200,140,80,40,hwnd,(HMENU)OK_SEARCH,NULL,NULL);
    CreateWindow("static","Meaning is: ",WS_VISIBLE | WS_CHILD ,40,230,80,30,hwnd,NULL,NULL,NULL);
    hMeaningSearch=CreateWindow("edit",NULL,WS_VISIBLE | WS_CHILD | WS_BORDER,120,230,120,45,hwnd,NULL,NULL,NULL);
    CreateWindow("static","Suggestion: ",WS_VISIBLE | WS_CHILD ,40,280,80,30,hwnd,NULL,NULL,NULL);
    hSuggestionSearch=CreateWindow("static",NULL,WS_VISIBLE | WS_CHILD | WS_BORDER,120,280,120,80,hwnd,NULL,NULL,NULL);



}

