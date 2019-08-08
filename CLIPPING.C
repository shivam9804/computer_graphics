#include<stdio.h>
#include<conio.h>
#include<graphics.h>

int checkpoint(int x1, int y1, int xmin, int ymin, int xmax, int ymax){
	if(x1 < xmin){
		return 1;
	}
	else if(x1 > xmax){
		return 2;
	}
	else if(y1 < ymin){
		return 3;
	}
	else if(y1 > ymax){
		return 4;
	}
 return 0;
}

void dline(int x1, int y1, int x2, int y2, int xmin, int ymin, int xmax, int ymax){
	int dy, dx, xn, yn, xinc, yinc, p, i, x3, y3, x, y;

  dy = y2-y1;                                 //calculating dy
  dx = x2-x1;                                 //calculating dx

  if(abs(dy) > abs(dx))                       //comparing the value for the value of pixel
  {
	p = abs(dy);                          //takin absolute value
  }
  else
  {
	p = abs(dx);
  }

  xn = dx/p;                                    //calculating the value for increment
  yn = dy/p;                                    //calculating the value for increment

  for(i = 0; i <= p; i++){                     //forloop to calculate the next value

	xinc = x1 + xn;
	x1 = xinc;

	yinc = y1 + yn;
	y1 = yinc;

	x = x1*10;                        //converting the value to nearest integer
	x3 = (x/10)+0.5;
	x = x3;

	y = y1*10;                         //converting the value to nearest integer
	y3 = (y/10)+0.5;
	y=y3;
	//printf("%d", checkpoint(x,y,xmin,ymin,xmax,ymax));
	if(checkpoint(x,y,xmin,ymin,xmax,ymax)==0){
	//printf("I am in");
	putpixel(x,y,GREEN);                   //to plot the varibales
	}
       }
}

void main(){
	int x1, y1, x2, y2, gd=DETECT, gm, xmin, ymin, xmax, ymax;
	clrscr();

	initgraph(&gd,&gm,"C:\TURBOC3\BGI");
	setcolor(YELLOW);
	line(50,50,100,50);
	line(100,50,100,100);
	line(100,100,150,100);
	line(150,100,150,150);
	line(150,150,50,150);
	line(50,150,50,50);
	getch();
	setcolor(RED);			//set clippind wndow color
	//co-odinate given
	rectangle(60,30,200,200);
	getch();
	dline(50,50,100,50,60,30,200,200);
	dline(100,50,100,100,60,30,200,200);
	dline(100,100,150,100,60,30,200,200);
	dline(150,100,150,150,60,30,200,200);
	dline(150,150,50,150,60,30,200,200);
	dline(50,150,50,50,60,30,200,200);
	getch();
	closegraph();
}
