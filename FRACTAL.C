#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void frac(int x1, int y1, int x2, int y2, int x3, int y3,int l);
void drawt(int x1, int y1, int x2, int y2, int x3, int y3);
void main(){
	int gd=DETECT, gm, x1, y1, x2, y2, x3, y3, l;
	float p;
	clrscr();

	initgraph(&gd,&gm,"C:\TURBOC3\BGI");
	//printf("Enter the starting co-ordinate");
	//scanf("%d %d", &x1,&y1);
	x1 =0; y1=0;
	printf("Enter the length of triangle");
	scanf("%d", &l);
	p = (1.732*l)/2;
	x2 = x1-l/2;
	y2 = y1+p;
	x3 = x1+l/2;
	y3 = y1+p;
	frac(x1,y1,x2,y2,x3,y3,l);
	//line(x1, y1, x1-l/2, y1+p);
	//line(x1,y1,x1+l/2,y1+p);
	//line(x1+l/2,y1+p,x1-l/2,y1+p);
	//line(x1-l/4,y1+p/2,x1+l/4,y1+p/2);
	getch();
}

void frac(int x1, int y1, int x2, int y2, int x3, int y3, int l){
	if(l>1){
	   drawt(x1,y1,x2,y2,x3,y3);
	   setcolor(RED);
	   frac((x3+x2)/2,(y3+y2)/2,(x1+x3)/2,(y1+y3)/2,(x2+x1)/2,(y2+y1)/2,l/2);
	   setcolor(YELLOW);
	   frac((x1+x2)/2,(y1+y2)/2,x2,y2,(x2+x3)/2,(y2+y3)/2,l/2);
	   setcolor(BLUE);
	   frac((x1+x3)/2,(y1+y3)/2,(x2+x3)/2,(y2+y3)/2,x3,y3,l/2);
	   setcolor(CYAN);
	   frac(x1,y1,(x1+x2)/2,(y1+y2)/2,(x1+x3)/2,(y1+y3)/2,l/2);
	}
}

void drawt(int x1, int y1, int x2, int y2, int x3, int y3){
	line(x1+getmaxx()/2,y1+getmaxy()/2,x2+getmaxx()/2,y2+getmaxy()/2);
	line(x2+getmaxx()/2,y2+getmaxy()/2,x3+getmaxx()/2,y3+getmaxy()/2);
	line(x3+getmaxx()/2,y3+getmaxy()/2,x1+getmaxx()/2,y1+getmaxy()/2);
}