#include<stdio.h>
#include<conio.h>
#include<graphics.h>
int main()
 {
  int i,gd=DETECT,gm;
  initgraph(&gd,&gm,"");
  int midx = getmaxx()/2;
   int midy = getmaxy()/2;

     settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
    outtextxy(25,240,"Press any key to view the moving car");
    getch();
    cleardevice();

    char a='g';
    i=0;
    while(i<300&& a=='g')
    {

    cleardevice();
    setcolor(7);
     rectangle(midx+200,midy-80,midx+260,midy+80);
    rectangle(midx+230,midy+80,midx+235,midy+250);
    //setfillstyle(SOLID_FILL,YELLOW);
    //floodfill(midx+231, midy+81,WHITE);
   // setcolor(RED);
   circle(midx+230, midy-50, 22);
   circle(midx+230, midy, 20);
   circle(midx+230, midy+50, 22);
   //setfillstyle(SOLID_FILL,GREEN);
   //floodfill(midx+230, midy+50,WHITE);
   //cleardevice();
    setcolor(8);
    bar(0,455,640,475); //** road
    setfillstyle(SOLID_FILL,8);
    setcolor(255);
    circle(40+i,440,10);  //** 1st tyre
    circle(160+i,440,10);   //** 2nd tyre

    //setcolor(RED);
    arc(40+i,440,0,180,14);   //** first arc on tyre
    arc(160+i,440,0,180,14);      //** second arc on tyre
    line(55+i,440,145+i,440);       //** line between tyre arc

    arc(51+i,440,75,180,25);    //** dicky side arc
    arc(78+i,415,75,180,22);   //** arc on dicky arc

    line(78+i,393,130+i,393);    //** roof of the car
    arc(127+i,415,-5,90,22);   //** front glass

    line(148+i,415,185+i,415);   //** bonnott of the car
    line(185+i,415,190+i,440);   //** head lights of car

    line(175+i,440,190+i,440);   //** line infront of the bottom of front tyre
    arc(125+i,415,-2,80,20);    //** arc for making front glass of the car

    line(107+i,415,146+i,415);    //** down front screen window
    arc(80+i,415,100,180,20);   //** back side

    line(59+i,415,100+i,415); //** back window lower line
    line(100+i,397,100+i,415);   //** back window center line
    line(73+i,396,100+i,396);  //** back window upper line

    line(106+i,396,106+i,415);   //** first window center line
    line(128+i,396,106+i,396);   //** first window upper side.
    setfillstyle(SOLID_FILL,GREEN);
   floodfill(midx+230, midy+50,7);
    delay(35);
    //cleardevice();
    i++;
    int temp=i;
    a=getch();
    }
cleardevice();
if(a=='r'||a=='R')
   {

    setcolor(7);
     rectangle(midx+200,midy-80,midx+260,midy+80);
    rectangle(midx+230,midy+80,midx+235,midy+250);
    //setfillstyle(SOLID_FILL,YELLOW);
    //floodfill(midx+231, midy+81,WHITE);
   // setcolor(RED);
   circle(midx+230, midy-50, 22);
   circle(midx+230, midy, 20);
   circle(midx+230, midy+50, 22);
   //setfillstyle(SOLID_FILL,GREEN);
   //floodfill(midx+230, midy+50,WHITE);
   //cleardevice();
    setcolor(8);
    bar(0,455,640,475); //** road
    setfillstyle(SOLID_FILL,8);
    setcolor(255);
    circle(40+i,440,10);  //** 1st tyre
    circle(160+i,440,10);   //** 2nd tyre

    //setcolor(RED);
    arc(40+i,440,0,180,14);   //** first arc on tyre
    arc(160+i,440,0,180,14);      //** second arc on tyre
    line(55+i,440,145+i,440);       //** line between tyre arc

    arc(51+i,440,75,180,25);    //** dicky side arc
    arc(78+i,415,75,180,22);   //** arc on dicky arc

    line(78+i,393,130+i,393);    //** roof of the car
    arc(127+i,415,-5,90,22);   //** front glass

    line(148+i,415,185+i,415);   //** bonnott of the car
    line(185+i,415,190+i,440);   //** head lights of car

    line(175+i,440,190+i,440);   //** line infront of the bottom of front tyre
    arc(125+i,415,-2,80,20);    //** arc for making front glass of the car

    line(107+i,415,146+i,415);    //** down front screen window
    arc(80+i,415,100,180,20);   //** back side

    line(59+i,415,100+i,415); //** back window lower line
    line(100+i,397,100+i,415);   //** back window center line
    line(73+i,396,100+i,396);  //** back window upper line

    line(106+i,396,106+i,415);   //** first window center line
    line(128+i,396,106+i,396);   //** first window upper side.
    setfillstyle(SOLID_FILL,RED);
   floodfill(midx+230, midy-50,7);
   //delay(10000);
     a=getch();
   }
   cleardevice();
   if(a=='y'||a=='Y')
   {

    setcolor(7);
     rectangle(midx+200,midy-80,midx+260,midy+80);
    rectangle(midx+230,midy+80,midx+235,midy+250);
    //setfillstyle(SOLID_FILL,YELLOW);
    //floodfill(midx+231, midy+81,WHITE);
   // setcolor(RED);
   circle(midx+230, midy-50, 22);
   circle(midx+230, midy, 20);
   circle(midx+230, midy+50, 22);
   //setfillstyle(SOLID_FILL,GREEN);
   //floodfill(midx+230, midy+50,WHITE);
   //cleardevice();
    setcolor(8);
    bar(0,455,640,475); //** road
    setfillstyle(SOLID_FILL,8);
    setcolor(255);
    circle(40+i,440,10);  //** 1st tyre
    circle(160+i,440,10);   //** 2nd tyre

    //setcolor(RED);
    arc(40+i,440,0,180,14);   //** first arc on tyre
    arc(160+i,440,0,180,14);      //** second arc on tyre
    line(55+i,440,145+i,440);       //** line between tyre arc

    arc(51+i,440,75,180,25);    //** dicky side arc
    arc(78+i,415,75,180,22);   //** arc on dicky arc

    line(78+i,393,130+i,393);    //** roof of the car
    arc(127+i,415,-5,90,22);   //** front glass

    line(148+i,415,185+i,415);   //** bonnott of the car
    line(185+i,415,190+i,440);   //** head lights of car

    line(175+i,440,190+i,440);   //** line infront of the bottom of front tyre
    arc(125+i,415,-2,80,20);    //** arc for making front glass of the car

    line(107+i,415,146+i,415);    //** down front screen window
    arc(80+i,415,100,180,20);   //** back side

    line(59+i,415,100+i,415); //** back window lower line
    line(100+i,397,100+i,415);   //** back window center line
    line(73+i,396,100+i,396);  //** back window upper line

    line(106+i,396,106+i,415);   //** first window center line
    line(128+i,396,106+i,396);   //** first window upper side.
    setfillstyle(SOLID_FILL,YELLOW);
   floodfill(midx+230, midy,7);
   //delay(10000);
     a=getch();
   }
   a='g';
    while(i<300&& a=='g')
    {

    cleardevice();
    setcolor(7);
     rectangle(midx+200,midy-80,midx+260,midy+80);
    rectangle(midx+230,midy+80,midx+235,midy+250);
    //setfillstyle(SOLID_FILL,YELLOW);
    //floodfill(midx+231, midy+81,WHITE);
   // setcolor(RED);
   circle(midx+230, midy-50, 22);
   circle(midx+230, midy, 20);
   circle(midx+230, midy+50, 22);
   //setfillstyle(SOLID_FILL,GREEN);
   //floodfill(midx+230, midy+50,WHITE);
   //cleardevice();
    setcolor(8);
    bar(0,455,640,475); //** road
    setfillstyle(SOLID_FILL,8);
    setcolor(255);
    circle(40+i,440,10);  //** 1st tyre
    circle(160+i,440,10);   //** 2nd tyre

    //setcolor(RED);
    arc(40+i,440,0,180,14);   //** first arc on tyre
    arc(160+i,440,0,180,14);      //** second arc on tyre
    line(55+i,440,145+i,440);       //** line between tyre arc

    arc(51+i,440,75,180,25);    //** dicky side arc
    arc(78+i,415,75,180,22);   //** arc on dicky arc

    line(78+i,393,130+i,393);    //** roof of the car
    arc(127+i,415,-5,90,22);   //** front glass

    line(148+i,415,185+i,415);   //** bonnott of the car
    line(185+i,415,190+i,440);   //** head lights of car

    line(175+i,440,190+i,440);   //** line infront of the bottom of front tyre
    arc(125+i,415,-2,80,20);    //** arc for making front glass of the car

    line(107+i,415,146+i,415);    //** down front screen window
    arc(80+i,415,100,180,20);   //** back side

    line(59+i,415,100+i,415); //** back window lower line
    line(100+i,397,100+i,415);   //** back window center line
    line(73+i,396,100+i,396);  //** back window upper line

    line(106+i,396,106+i,415);   //** first window center line
    line(128+i,396,106+i,396);   //** first window upper side.
    setfillstyle(SOLID_FILL,GREEN);
   floodfill(midx+230, midy+50,7);
    delay(35);
    //cleardevice();
    i++;
    int temp=i;

    }
    getch();
     return 0;
  }
