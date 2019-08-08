#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void ff8(int x, int y, int oc, int nc);  //function declared to fill color using flood fill 8
void ff4(int x,int y,int oc1,int nc1);   //function declared to fill color using flood fill 8

void main(){
     int oc=0,ch, nc=0, oc1, nc1, gd=DETECT, gm;      //variable dclarde
     clrscr();
     initgraph(&gd,&gm,"C:\TURBOC3\BGI");
     printf("\n\t\t\tWhich algorithm do you want to use to fill the shape");
     printf("\n\t\t\t1.Flood fill 8");
     printf("\n\t\t\t2.Flood fill 4");
     scanf("\n%d",&ch);

     rectangle(100,60,60,100);	        //function to draw rectangle
     oc = getpixel(80,70);                //stores to color value inside the shape
     nc = 2;                              //defining color to fill the rectangle
     if(ch == 1){
     //printf("\n\t\t\tFlood fill 8");
     ff8(80,70,oc,nc);
     //printf("\n\t\t\tFlood fill 8");
     }else{
     //printf("\n\t\t\tFlood fill 4");
     ff4(80,70,oc,nc);	        	//function calld with pass by value
     //printf("\n\t\t\tFlood fill 4");
     }
     getch();
     closegraph();                        //to release the memory acquired by the program
}
void ff8(x,y,oc,nc){                      //function defined
     if(getpixel(x,y) == oc){             //condition to fill the rectangle
     putpixel(x,y,nc);                    //to print the pixel

     //print neighbouring pixel using recursion
     ff8(x,y+1,oc,nc);
     ff8(x-1,y,oc,nc);
     ff8(x,y-1,oc,nc);
     ff8(x+1,y,oc,nc);
     ff8(x-1,y+1,oc,nc);
     ff8(x-1,y-1,oc,nc);
     ff8(x+1,y-1,oc,nc);
     ff8(x+1,y+1,oc,nc);
     }
}
void ff4(x,y,oc1,nc1){                      //function defined
     if(getpixel(x,y) == oc1){             //condition to fill the rectangle
     putpixel(x,y,nc1);                    //to print the pixel

     //neighbouring pixel to printed using the recursion
     ff4(x,y+1,oc1,nc1);
     ff4(x-1,y,oc1,nc1);
     ff4(x,y-1,oc1,nc1);
     ff4(x+1,y,oc1,nc1);
     }
}
