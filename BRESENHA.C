#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void main(){

 int x1, x2, y1, y2,ynext, xnext, dx, dy, pk;
 //int gd = DETECT, gm;

 clrscr();

 //initgraph(&gd,&gm,"C:\Turboc3\BIN");

 printf("Enter the starting point");
 scanf("%d %d", &x1, &y1);

 printf("Enter the end point");
 scanf("%d %d", &x2, &y2);

 ynext = y1;
 dy = y2-y1;
 dx = x2-x1;
 pk = 2*dy-dx;
 printf("du %d: ", dy);
 printf("\ndx %d: ", dx);
 printf("\npk %d: ", pk);

 for(xnext = x1; xnext <= x2; xnext++){
	printf("\nxnext %d", xnext);
	printf("\tynext %d", ynext);
	printf("\tpk    %d", pk);
       //putpixel(xnext,ynext,xnext);
       //delay(50);
	if(pk>0){
		pk = pk+2*dy-2*dx;
		ynext++;
	}
	else{
		pk = pk+2*dy;
	}
       //putpixel(xnext,ynext,xnext);
       //delay(50);
 }
   getch();
}
