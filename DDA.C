#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>

void main(){

  float dy, dx, X1, X2, Y1, Y2, p, i, x1, y1;
  float Xn, Yn, Xinc, Yinc;
  int x , y, gd = DETECT, gm, screenx, screeny;

  clrscr();   //to clear screen

  initgraph(&gd, &gm,"C:\Turbo3\BGI");
  screenx = getmaxx();  //for screen resolution
  screeny = getmaxy();  //for screen resolution
  printf("Screen x: %d", screenx);             //printing the resolution
  printf("\nScreen y: %d", screeny);

  printf("\nEnter the starting point: ");      //asking user the initial point
  scanf("%f %f", &X1, &Y1);                    //taking input from the user

  printf("Enter the ending point: ");         //asking the final points from the user
  scanf("%f %f", &X2, &Y2);                   //taking the final input

  dy = Y2-Y1;                                 //calculating dy
 // printf(" dy: %f\n", dy);
  dx = X2-X1;                                 //calculating dx
 // printf(" dx: %f\n", dx);

  if(abs(dy) > abs(dx))                       //comparing the value for the value of pixel
  {
	p = abs(dy);                          //takin absolute value
  }
  else
  {
	p = abs(dx);
  }

 // printf(" p: %f\n", p);


  Xn = dx/p;                                    //calculating the value for increment
 // printf("%f\n Xn", Xn);
  Yn = dy/p;                                    //calculating the value for increment
 // printf("%f\n Yn", Yn);

  for(i = 0; i <= p; i++){                     //forloop to calculate the next value

       //	printf("\n");
       //	printf("%f\t", X1);
	Xinc = X1 + Xn;
	X1 = Xinc;

       //	printf("%f\t", Y1);
	Yinc = Y1 + Yn;
	Y1 = Yinc;

	x = X1*10;                        //converting the value to nearest integer
	x1 = (x/10)+0.5;
	x = x1;
	//printf("%d\t", x);

	y = Y1*10;                         //converting the value to nearest integer
	y1 = (y/10)+0.5;
	y=y1;
	//printf("%d\t", y);
	putpixel(x,y,i);                   //to plot the varibales
	delay(100);                        //to delay the plotting

  }
  getch();
}
