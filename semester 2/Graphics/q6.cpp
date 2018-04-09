#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>
using namespace std;
#include<iostream>
/*union REGS i, o;
BOOL WINAPI GetCursorPos(_Out_ LPPOINT lpPoint);
BOOL WINAPI SetCursorPos(_In_ int X,_In_ int Y);
int WINAPI ShowCursor(_In_ BOOL bShow);


int initmouse()
{
   i.x.ax = 0;
   int86(0X33, &i, &o);
   return ( o.x.ax );
}

void showmouseptr()
{
   i.x.ax = 1;
   int86(0X33, &i, &o);
}

void hidemopuseptr()
{
   i.x.ax = 2;
   int86(0X33, &i, &o);
}

void getmousepos(int *x, int *y)
{
   //i.x.ax = 3;
   //int86(0X33, &i, &o);
   LPPOINT lpPoint;

   lpPoint.x=x;
   lpPoint.y=y;

   GetCursorPos(lpPoint);

}

void movemouseptr(int x, int y)
{
   //i.x.ax = 4;
   //i.x.cx = x;
   //i.x.dx = y;
   //int86(0X33, &i, &o);
   SetCursorPos( x, y);

}
*/

main()
{
   int gd = DETECT, gm, midx, midy, radius, x, y, tempx, tempy;

   radius = 100;
   POINT lpPoint ;




   initgraph(&gd, &gm, "C:\\TC\\BGI");
    //int WINAPI ShowCursor(_In_ BOOL bShow);

  /* if(!initmouse())
   {
      closegraph();
      exit(1);
   }
*/
cout<<"getmaxx(): "<<getmaxx();
cout<<"getmaxy(): "<<getmaxy();
   midx = getmaxx()/2;
   midy = getmaxy()/2;

    midx=midx+10;
    midy=midy+40;
  // showmouseptr();
  midx=midx-4.5;
 midy=midy-25.5;
   SetCursorPos(midx,midy);
   circle(midx, midy, radius);

   x = tempx = midx;
   y = tempy = midy;

   while(!kbhit())
   {
       GetCursorPos(&lpPoint);
        x=lpPoint.x;//=x;
        y=lpPoint.y;//=y;
      if((pow(x-midx-4.5,2)+pow(y-midy-25.5,2)-pow(radius,2))>0)
      {
         SetCursorPos(tempx, tempy);
         x = tempx;
         y = tempy;
      }

      tempx = x;
      tempy = y;
   }

    getch();
   closegraph();
   return 0;
}
