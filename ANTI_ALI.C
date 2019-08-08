#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>

void plot(int x, int y, int c);
void drawline(int x0, int y0, int x1, int y1);


int gd=DETECT,gm;
int x0,y0,x1,k,i,y1,dy,dx,steep,temp0,temp1,temp2,temp3,xend,yend,xgap,xpxl1,ypxl1,xpxl2,ypxl2;
float gradient, intery;


void plot(x, y, c){
	printf("\nc = %d", c);
	k = c*10;
	printf("\nx = %d, y = %d, c = %d",x,y,k);
	putpixel(x,y,k);
}

float ipart(x){
     return  floor(x);
}

float round(x){
     return ipart(x+0.5);
}

float fpart(x){
     return x - floor(x);
}

float rfpart(x){
     return  1 - fpart(x);
}

void drawline(x0,y0,x1,y1){
     steep = abs(y1-y0) > abs(x1-x0);
     if(abs(y1-y0) > abs(x1-x0)){
	temp0 = x0;
	x0=y0;
	x0=temp0;

	temp1 = x1;
	x1=y1;
	y1=temp1;

     }
     if(x0>x1){
	temp2=x0;
	x0=x1;
	x1=temp2;

	temp3=y0;
	y0=y1;
	y1=temp3;
     }

     dx = x1-x0;
     dy = y1-y0;
     gradient = dy/dx;

     if(gradient == 0.0){
	gradient = 1.0;
     }

     xend = round(x0);
     yend = y0 + gradient * (xend - x0);
     xgap = rfpart(x0 + 0.5);
     xpxl1 = xend;
     ypxl1 = ipart(yend);
     if(steep>0){
	plot(ypxl1, xpxl1, rfpart(yend) * xgap);
	plot(ypxl1+1, xpxl1, fpart(yend) * xgap);
     }
     else{
	plot(xpxl1, ypxl1, rfpart(yend) * xgap);
	plot(xpxl1, ypxl1+1, fpart(yend) * xgap);
     }
      intery = yend + gradient;

     xend = round(x1);
     yend = y1 + gradient * (xend - x1);
     xgap = fpart(x1 + 0.5);
     xpxl2 = xend;
     ypxl2 = ipart(yend);
     if(steep>0){
	plot(ypxl1, xpxl2, rfpart(yend) * xgap);
	plot(ypxl2+1, xpxl2, fpart(yend) * xgap);
     }
     else{
	plot(xpxl2, ypxl2, rfpart(yend) * xgap);
	plot(xpxl2, ypxl2+1, fpart(yend) * xgap);
     }

     if(steep>0){
	for(i = xpxl1+1; i<xpxl2-1; i++){
	   plot(ipart(intery), 1, rfpart(intery));
	   plot(ipart(intery)+1, 1, fpart(intery));
	   intery = intery + gradient;
	}

     }else{
	 for(i = xpxl1+1; i<xpxl2-1; i++){
	   plot(i, ipart(intery), rfpart(intery));
	   plot(i, ipart(intery)+1, fpart(intery));
	   intery = intery + gradient;
	}
     }
}
void main(){
	clrscr();
	initgraph(&gm,&gd,"C:\TURBOC3\BIN");
	printf("Enter the start point");
	scanf("%d %d", &x0, &y0);

	printf("Enter the end point");
	scanf("%d %d", &x1, &y1);

	drawline(x0,y0,x1,y1);
	getch();
}