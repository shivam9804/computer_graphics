#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void fill(int x, int y, int bc, int nc);     //function to fill shape wiht color
void fill1(int x, int y, int bc, int nc);

void main(){
	int gd=DETECT, gm, ch;
	clrscr();
	initgraph(&gd, &gm,"C:\TURBOC3\BGI");
	printf("\n\t\t\tWhich algorithm do you want to use to fill the shape");
	printf("\n\t\t\t1.Boundary fill 8");
	printf("\n\t\t\t2.Boundary fill 4");
	scanf("/n%d",&ch);
	if(ch==1){
	printf("\n\t\t\tBoundary fill 8");
	rectangle(100,60,60,100);             //rectangle drawing function
	fill(80,70,15,3);                     //function to fill rectangle with color
	}else{
	printf("\n\t\t\tBoundary fill 4");
	rectangle(100,60,60,100);             //rectangle drawing function
	fill1(80,70,15,3);                     //function to fill rectangle with color
	}
	getch();
	closegraph();                         //to release the memory acquired by the program
}

void fill(x,y,bc,nc){                                  //fill function defined
	if(getpixel(x,y) != bc && getpixel(x,y) != nc){                //condition to pickup the color form the co-ordinate and check
	putpixel(x,y,nc);		      //to print the pixel

	//points to fill the neighbouring points with recursion using flood fill 8

	fill(x-1,y+1,bc,nc);
	fill(x-1,y,bc,nc);
	fill(x-1,y-1,bc,nc);
	fill(x,y+1,bc,nc);
	fill(x,y-1,bc,nc);
	fill(x+1,y,bc,nc);
	fill(x+1,y-1,bc,nc);
	fill(x+1,y+1,bc,nc);
	}

}
void fill1(x,y,bc,nc){                                  //fill function defined
	if(getpixel(x,y) != bc && getpixel(x,y) != nc){                //condition to pickup the color form the co-ordinate and check
	putpixel(x,y,nc);		      //to print the pixel

	//points to fill the neighbouring points with recursion using flood fill 8

	fill(x-1,y,bc,nc);
	fill(x,y-1,bc,nc);
	fill(x+1,y,bc,nc);
	fill(x,y+1,bc,nc);
	}

}