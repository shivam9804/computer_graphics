#include<stdio.h>
#include<conio.h>

void concir(int xnext, int ynext, int  p, int x1, int y1);

void main(){
 int r=13, x1, y1, ynext, p, p1, temp,x2,y2;
 clrscr();
 printf("Enter the co-ordinate to check where it lies");
 scanf("%d %d", &x1, &y1);
 //printf("%d", --x1);
 p = x1*x1 + y1*y1 - r*r;
 //printf("%d", p);
 if(p > 0){
    printf("Your co-ordinate lies outside the circle");
 }
 else if(p < 0){
    printf("Your co-ordinate lies inside the circle");
 }
 else{
    printf("Your co-ordinate lies on the circle");
    ynext = r;
    p1 = 3-2*y1;                                                //calculating decision factor foe outer circle
    concir(0,ynext,p1,x1,y1);
   }                                         //sending the value for outer circle
    getch();
}

void concir(int xnext,int ynext,int p1,int x1,int y1){
   int xprev, yprev, flag;
   flag=0;
   if(x1 == 0 && y1 > 0){
	printf("\nthe previous value is: (%d,%d)", --x1,y1);
	printf("\nthe current value is: (%d,%d)", x1,y1);
	printf("\nthe next value is: (%d,%d)", x1+1,y1);
   }
   else{
   for(xnext = 0; xnext <= ynext; xnext++){
	//printf("\n%d %d %d %d %d", xnext,ynext,p,x1,y1);
	if(xnext==x1 && ynext==y1 && y1>=x1){
	      flag=1;
	      printf("\nPrevious co-ordinate is: (%d,%d)", xprev,yprev);
	      printf("\nCurrent co-ordinate is: (%d,%d)", xnext,ynext);
	 }
	 else if(x1==ynext && y1==xnext && x1>y1){
	      flag=3;
	      printf("\nPrevious co-ordinate is: (%d,%d)", yprev,xprev);
	      printf("\nCurrent co-ordinate is: (%d,%d)", ynext,xnext);
	 }
	 xprev=xnext; yprev=ynext;
	if( p1 < 0){                                                //decision factor to determine p value and co-ordinate
	    p1 = p1+4*xnext+6;
	}
	else{                                                      //decision factor to determine p value and co-ordinate
	   ynext-=1;
	   p1 = p1+4*xnext-4*ynext+10;
	}
	if(flag == 1){
	   printf("\nNext co-ordinate is: (%d,%d)", xnext,ynext);
	   flag=2;
	}
	else if(flag == 3){
	   printf("\nNext co-ordinate is: (%d,%d)", ynext,xnext);
	   flag=2;
	}
   }
}
}