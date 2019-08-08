#include<stdio.h>
#include<math.h>
#include<graphics.h>


void bld(float x1,float y1,float x2,float y2);
int round_n(float x);
void dda(float x1,float y1,float x2,float y2);

void main()
{

	float x1,x2,x3,x4,x5,x6,y1,y2,y3,y4,y5,y6,a,b,l;
	int gd = DETECT, gm;

	initgraph(&gd,&gm,"C:\Turbo3\BGI");
	printf("Enter starting coordinates: ");
	scanf("%f,%f",&x1,&y1);

	printf("Enter length of the side of hexagon");
	scanf("%f",&l);


	b = l/2;
	a = sqrt(3) * b;

	x2 = x1 + l;
	y2 = y1;
	printf("%.1f,%f\n",x2,y2 );

	x3 = x1 + 3*b;
	y3 = y1 + a;
	printf("%.1f,%f\n",x3,y3 );

	x4 = x1 + l;
	y4 = y1 + 2 * a;
	printf("%.1f,%f\n",x4,y4 );

	x5 = x1;
	y5 = y1 +2*a;
	printf("%.1f,%f\n",x5,y5 );

	x6 = x1 - b;
	y6 = y1 + a;
	printf("%.1f,%f\n",x6,y6);


	 dda(x1,y1,x2,y2);
	 dda(x2,y2,x3,y3);
	 dda(x3,y3,x4,y4);
	 dda(x4,y4,x5,y5);
	 dda(x5,y5,x6,y6);
	 dda(x6,y6,x1,y1);

	 getch();

}


void bld(float x1,float y1,float x2,float y2)
{
	int dy = round_n(y2 - y1);
	int dx = round_n(x2 - x1);
	int yn = round_n(y1);
	int xn = round_n(x1);
        int lo = round_n(x1);
        int hi = round_n(x2);
        

	float pk = 2 * dy - dx;
	for (xn = lo; xn <= hi; xn++)
	{
		putpixel(xn,yn,xn);
		if (pk > 0)
		{
			pk = pk + 2*dy - 2*dx;
			yn++;
		}else{
			pk = pk + 2*dy;
		}
	}


}

 void dda(float x1,float y1,float x2,float y2)
 {
         float dy,dx,i,p;
         float xn,yn,xinc,yinc;
 
         dy = y2 - y1;
         dx = x2 - x1;
         
	 if (fabs(dy)>fabs(dx))
	 {
		 p = fabs(dy);             //Get absolute value for difference in points on y axis
	 }else{
		 p = fabs(dx);             //Get absolute value for difference in points on x axis
	 }

	 xn = (float) dx/p;
	 yn = (float) dy/p;



	 for (i = 0; i<=p; i++)
	 {
		 int xr,yr;
                 xr = round_n(x1);
                 //                printf("%d, ",xr);            Rounded x coordinate of pixel
                 xinc  = x1 + xn;
                 x1 = xinc;
                 yr = round_n(y1);
                 //                printf("%d\n",yr);            Rounded y coordinate of pixel
                 yinc = y1 + yn;
                 y1 = yinc;
                 
                 putpixel(xr,yr,i);             // Illuminating pixels on the screen
                 
         }
 }

int round_n(float x)

{
        int i ;
        x *= 10;
        i = (int) x;
        x = ((float) i/10) + 0.5;
        i = (int) x;
        return i;
}

