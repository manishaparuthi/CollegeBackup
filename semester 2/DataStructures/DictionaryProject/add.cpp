#include "add.h"
#include<windows.h>
using namespace std;
#include<iostream>
#include<fstream>
#include "dictionary.cpp"
#define ADD_WORD 10
extern Trie dictionary;
HWND hWordAdd,hMessg;
HWND hMeaningAdd;
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
            case ADD_WORD:
               char word[20];
               char meaning[20];
               GetWindowText(hWordAdd,word,20);
               GetWindowText(hMeaningAdd,meaning,20);
               cout<<"word: "<<word;
               cout<<"meaninng : "<<meaning;
                dictionary.insert("is","am");
                fstream f;
                f.open("wordmng.txt", ios::out | ios::app);
                char var[40] = {};
                if(!f)
                {
                    cerr<<"Unable to open file .\n";
                    exit(0);
                }
                int j=0;
                int k = 0;
                for(int i=0;word[i]!='\0';i++)
                {
                    var[j]=word[i];
                    j++;
                }
                var[j]='-';
                j++;
                for( k=0;meaning[k]!='\0';k++)
                {
                    var[j]=meaning[k];
                    j++;
                }
                var[j]=',';
                j++;
                var[j]='\0';
                f << var << endl;
                cout << var;
                f.close();
                dictionary.insert(word,meaning);
                SetWindowText(hMessg,"Word Added to the dictionary");
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
    char* str="AddWord";
    HWND hAdd= CreateWindow("static",str,WS_VISIBLE | WS_CHILD ,20,20,100,100,hwnd,NULL,NULL,NULL);
    CreateWindow("static","Enter Word: ",WS_VISIBLE | WS_CHILD ,40,60,80,30,hwnd,NULL,NULL,NULL);
    hWordAdd=CreateWindow("edit",NULL,WS_VISIBLE | WS_CHILD | WS_BORDER | WM_HSCROLL,120,60,120,45,hwnd,NULL,NULL,NULL);
    CreateWindow("static","Enter Meaning: ",WS_VISIBLE | WS_CHILD ,40,140,80,40,hwnd,NULL,NULL,NULL);
    hMeaningAdd=CreateWindow("edit",NULL,WS_VISIBLE | WS_CHILD | WS_BORDER,120,140,120,45,hwnd,NULL,NULL,NULL);
    CreateWindow("button","Add Word ",WS_VISIBLE | WS_CHILD | MB_OK ,200,250,80,40,hwnd,(HMENU)ADD_WORD,NULL,NULL);
    //HWND hMessg= CreateWindow("static",NULL,WS_VISIBLE | WS_CHILD ,200,300,100,100,hwnd,NULL,NULL,NULL);

}

