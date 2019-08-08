#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void mycircle(int x, int y, int p);

int x1=0,y1=0,xk1, yk1, xk2, yk2, p1, p2, r1, r2, gd=DETECT, gm, screenx, screeny;

void main() {

   initgraph(&gd, &gm,"C\TURBOC3\BGI");
   screenx = getmaxx();            		//gets x resolution
   screeny = getmaxy();                         //gets y resolution
   line(screenx/2,0,screenx/2,screeny);         //shifted line in the x axis
   line(0, screeny/2, screenx, screeny/2);      //shifted line in the y axis
   printf("Enter the circle center co-ordinate");
   scanf("%d %d", &x1, &y1);
   putpixel(x1+screenx/2,y1+screeny/2,WHITE);
   printf("Enter the bigger circle radius: ");
   scanf("%d", &r1);
   printf("Enter the samll circle radius");
   scanf("%d", &r2);
   xk1=0;
   yk1=r1;
   xk2= 0;
   yk2=r2;
   p1=5/4-r1;                  //decision factor for outer circle
   p2=5/4-r2;                  //decision circle for inner circle
   mycircle(xk1,yk1,p1);      //function for outer circle
   mycircle(xk2,yk2,p2);      //function for ineer circle
   getch();
   }

   void mycircle(xk,yk,p){                //function to draw the circle
   for(xk = 0; xk <= yk; xk++){

	//start and end ppoint to print the octet
	putpixel(xk+x1+(screenx/2), yk+y1+(screeny/2), RED);
	putpixel(yk+x1+(screenx/2), xk+y1+(screeny/2), RED);
	putpixel(-xk+x1+(screenx/2), yk+y1+(screeny/2), RED);
	putpixel(yk+x1+(screenx/2), -xk+y1+(screeny/2), RED);
	putpixel(-xk+x1+(screenx/2), -yk+y1+(screeny/2), RED);
	putpixel(-yk+x1+(screenx/2), -xk+y1+(screeny/2), RED);
	putpixel(xk+x1+(screenx/2), -yk+y1+(screeny/2), RED);
	putpixel(-yk+x1+(screenx/2), xk+y1+(screeny/2), RED);
	delay(40);
	if(p>=0){                        //decision factor
		p+=2*xk-2*yk+5;
		yk--;
	}
	else{
		p+=2*xk+3;
	}
   }}
