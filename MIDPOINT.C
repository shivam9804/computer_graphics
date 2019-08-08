#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void main(){

 int x1, x2, y1, y2, p, dy, dx, xnext, ynext, q, gd = DETECT, gm;

 clrscr();

 initgraph(&gd, &gm,"C:\Turboc3\BIN");

 printf("Enter the start point");
 scanf("%d %d", &x1,&y1);

 printf("Enter the end point");
 scanf("%d %d", &x2,&y2);

 dy = y2-y1;
 dx = x2-x1;
 ynext = y1;
 p = dy-(dx/2);
 q = dy-dx;
// printf("/n%d dy:", dy);
// printf("/n%d dx:", dx);
// printf("/n%d ynext:", ynext);
// printf("/n%d p:", p);
// printf("/n%d q:", q);

 for(xnext = x1; xnext<=x2; xnext++){
	printf("\nxnext %d", xnext);
	printf("\tynext %d", ynext);
	printf("\tp %d", p);
       //	putpixel(xnext,ynext,xnext);
       //	delay(50);
	if(p>0){
		ynext++;
		p+=q;
	}
	else{
		p+=dy;
	}

 }
   getch();
}