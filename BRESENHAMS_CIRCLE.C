#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void concir();

int x1, y1, xnext, ynext, ynext1, r1, r2, p, p2, gd=DETECT, gm, screenx, screeny;

void main(){
   //int xnext, ynext, r, p, gd=DETECT, gm, screenx, screeny;
   initgraph(&gd,&gm,"C:\TURBOC3\BGI");
   clrscr();
   printf("Enter the co-ordinate of the circle centre");
   scanf("%d %d", &x1, &y1);
   printf("Enter the radius for bigger circle: "); 		//asking user radius for outer circle
   scanf("%d", &r1);
   printf("Enter the radius for small circle: ");              //asking user radius for inner circle
   scanf("%d", &r2);
   screenx = getmaxx();                                        //x resolution of the screen
   screeny = getmaxy();                                       //y resolution of the screen
   line(screenx/2, 0, screenx/2, screeny);                   //plotting the shifted x axis on the screen
   line(0, screeny/2, screenx, screeny/2);                   //plotting the shifted y axis on the screen
   ynext = r1;
   p = 3-2*r1;                                                //calculating decision factor foe outer circle
   ynext1 = r2;
   p2 = 3-2*r2;                                               //decision factor for inner circle
   concir(0,ynext,p);                                         //sending the value for outer circle
   concir(0,ynext1,p2);                                       //sending the value for inner circle
   getch();
}
							      //function to draw circle with the shifted co-orodinate
 void concir(xnext, ynext, p){
   for(xnext = 0; xnext <= ynext; xnext++){
	putpixel(xnext+x1+(screenx/2), ynext+y1+(screeny/2), RED);
	putpixel(ynext+x1+(screenx/2), xnext+y1+(screeny/2), RED);
	putpixel(-xnext+x1+(screenx/2), ynext+y1+(screeny/2), RED);
	putpixel(ynext+x1+(screenx/2), -xnext+y1+(screeny/2), RED);
	putpixel(-xnext+x1+(screenx/2), -ynext+y1+(screeny/2), RED);
	putpixel(-ynext+x1+(screenx/2), -xnext+y1+(screeny/2), RED);
	putpixel(xnext+x1+(screenx/2), -ynext+y1+(screeny/2), RED);
	putpixel(-ynext+x1+(screenx/2), xnext+y1+(screeny/2), RED);
	delay(60);
	if( p < 0){                                                //decision factor to determine p value and co-ordinate
	    p = p+4*xnext+6;
	}
	else{                                                      //decision factor to determine p value and co-ordinate
	   ynext-=1;
	   p = p+4*xnext-4*ynext+10;
	}
   }
}