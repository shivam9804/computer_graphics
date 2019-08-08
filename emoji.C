#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

//for rotating ellipse and line according to the user entered value
void drawEllipse(int xc, int yc, int sta,int enda,int a, int b, float alpha, int color);
void shiftEllipse(float x2,float y2,int sta,int enda,int a,int b,int angle);
int getrx(float a,int x,int y);
int getry(float a,int x,int y);
void fline(int x1, int y1, int x2, int y2, float angle);
//end of rotation
void demoji(); 							//default emoji face
void fill(int x, int y, int bc, int c);  //fill algorithm
void translation();                      //translate emoji
void rotate();                           //rotate emoji
void scale();                            //scale's emoji
void animation();                        // simple animation

void main(){
	int ch,screenx, screeny, gd = DETECT, gm;
	clrscr();
	initgraph(&gd,&gm,"C:\TURBOC3\BGI");
	printf("\n\t\t\tGive desired 2-D animation to the emoji");
	printf("\n\t\t\t1.Translation");
	printf("\n\t\t\t2.Rotate");
	printf("\n\t\t\t3.Scale");
	printf("\n\t\t\t4.A Lame Story");
	printf("\n\t\t\t5.Exit");
	printf("\n\t\t\tEnter your choice (1-5):");
	demoji();
	scanf("%d", &ch);
	if(ch == 1){
		translation();
	}
	else if(ch == 2){
		rotate();
	}
	else if(ch == 3){
		scale();
	}
	else if( ch == 4){
		animation();
	}
	else if(ch == 5){
		printf("\n\t\t\tPress any key to exit");
		getch();
	}
	closegraph();
}

 void fill(x,y,bc,YELLOW){
	if(getpixel(x,y) == bc){             //condition to fill the rectangle
	    putpixel(x,y,YELLOW);                    //to print the pixel
	    //neighbouring pixel to printed using the recursion
	    fill(x,y+1,bc,YELLOW);
	    fill(x-1,y,bc,YELLOW);
	    fill(x,y-1,bc,YELLOW);
	    fill(x+1,y,bc,YELLOW);
    }
 }
void demoji(){		      //default emoji
	int e1, e2, x1=0, y1=0, bc, r1=30, screenx, screeny;
	screenx = getmaxx();
	screeny = getmaxy();
	//draws face
	circle(x1+screenx/2,y1+screeny/2,r1);                      //circle drawn
	bc = getpixel(x1+screenx/2+3,y1+screeny/2+3);             //gets the color from the circle to fill
	fill(x1+10+screenx/2+3,y1+10+screeny/2+3,bc,YELLOW);      //fills color

	//function to draw ellipse
	ellipse((x1+10+screenx/2)-25,(y1+10+screeny/2)-15,0,360,3,6);
	ellipse((x1+10+screenx/2)+3,(y1+10+screeny/2)-15,0,360,3,6);

	//gets the color inside ellipse to change the old color
	e1 = getpixel((x1+10+screenx/2)-25,(y1+10+screeny/2)-15);
	e2 = getpixel((x1+10+screenx/2)+3,(y1+10+screeny/2)-15);

	//fills the eye with black color
	fill((x1+10+screenx/2)-25,(y1+10+screeny/2)-20,e1,BLACK);
	fill((x1+10+screenx/2)+3,(y1+10+screeny/2)-20,e2,BLACK);

	//draws the mouth
	setcolor(BLACK);
	line((x1+screenx/2)-15,(y1+screeny/2)+12,(x1+screenx/2)+15,(y1+screeny/2)+12);
}

void translation(){
	int e1, e2, x1=0, y1=0, bc, r1=30, screenx, screeny, xshift=100, yshift=0;
	clrscr();
	screenx = getmaxx();
	screeny = getmaxy();
	demoji();
	printf("\n\t\t\t\tTranslation");
	printf("\n\n\t\t\tEnter the (x,y) vlaue to shift");
	scanf("%d %d", &xshift,&yshift);

	circle(x1+screenx/2+xshift,y1+screeny/2+yshift,r1);                      //circle drawn
	bc = getpixel(x1+screenx/2+3+xshift,y1+screeny/2+3+yshift);             //gets the color from the circle to fill
	fill(x1+10+screenx/2+3+xshift,y1+10+screeny/2+3+yshift,bc,YELLOW);      //fills color

	//function to draw ellipse
	ellipse((x1+10+screenx/2)-25+xshift,(y1+10+screeny/2)-15+yshift,0,360,3,6);
	ellipse((x1+10+screenx/2)+3+xshift,(y1+10+screeny/2)-15+yshift,0,360,3,6);

	//gets the color inside ellipse to change the old color
	e1 = getpixel((x1+10+screenx/2)-25+xshift,(y1+10+screeny/2)-15+yshift);
	e2 = getpixel((x1+10+screenx/2)+3+xshift,(y1+10+screeny/2)-15+yshift);

	//fills the eye with black color
	fill((x1+10+screenx/2)-25+xshift,(y1+10+screeny/2)-20+yshift,e1,BLACK);
	fill((x1+10+screenx/2)+3+xshift,(y1+10+screeny/2)-20+yshift,e2,BLACK);

	//draws the mouth
	setcolor(BLACK);
	line((x1+screenx/2)-15+xshift,(y1+screeny/2)+12+yshift,(x1+screenx/2)+15+xshift,(y1+screeny/2)+12+yshift);
	printf("\n\n\t\t\tPress any key to continue");
	getch();
	main();
}

void rotate(){					//rotatio function to rotate line and ellipse
    int x1=0, y1=0;
    float alpha=0;
    clrscr();
    printf("\n\t\t\t\tEnter the angle");
    scanf("%f", &alpha);
    if(alpha < 0){
		alpha = 360+alpha;
    }
    shiftEllipse(x1-10,y1-10,0,360,3,6,alpha);
    shiftEllipse(x1+10,y1-10,0,360,3,6,alpha);
    fline(x1-15,y1+12,x1+15,y1+12,alpha);
    printf("\n\n\t\t\tPress any key to continue");
    getch();
    main();
}

void drawEllipse(int xc, int yc, int sta,int enda,int a, int b, float alpha, int color){
	int i, theta, x, y, x1=0, y1=0, screenx, screeny;
	float t=3.14/180;
	screenx = getmaxx()/2;
	screeny = getmaxy()/2;
	alpha=360-alpha;
	setcolor(YELLOW);
	circle(x1+screenx,y1+screeny,30);
	setfillstyle(SOLID_FILL,YELLOW);
	floodfill(x1+screenx+1,y1+screeny+1,YELLOW);
	if(alpha==0 || alpha==360){
		ellipse(xc,yc,sta,enda,a,b);
	}
	else if(alpha==90){
		ellipse(xc,yc,sta+90,enda+90,b,a);
	}
	else if(alpha==180){
		ellipse(xc,yc,360-enda,360-sta,a,b);
	}
	else if(alpha==270){
		ellipse(xc,yc,enda+90,sta+90,b,a);
	}
	else{
		for(i=sta;i<enda;i+=1){
			theta=i;
			x = a*cos(t*theta)*cos(t*alpha)+b*sin(t*theta)*sin(t*alpha);
			y=b*sin(t*theta)*cos(t*alpha)-a*cos(t*theta)*sin(t*alpha);
			putpixel(xc+x,yc-y,color);
		}
	}

}

//main formula to for rotating the line and the ellipse
int getrx(float a,int x,int y){
	x = x * cos(a) - y * sin(a);
	return x;
}
int getry(float a,int x,int y){
	y = y * cos(a) + x * sin(a);
	return y;
}

void shiftEllipse(float x2,float y2,int sta,int enda,int a,int b,int angle){  //shifts the ellipse according the degree given and colors it
	int an,mx, my;
	float xnr2, ynr2, val;
	mx = getmaxx()/2;
	my = getmaxy()/2;
    val = angle*(M_PI/180);
	xnr2=getrx(val,x2,y2);
	ynr2=getry(val,x2,y2);
	setcolor(0);
	drawEllipse(mx+xnr2,my+ynr2,sta,enda,a,b,-1*angle,WHITE);
	setfillstyle(SOLID_FILL,BLACK);
	floodfill(mx+xnr2,my+ynr2,WHITE);
}
void fline(int x1, int y1, int x2, int y2, float alpha){
	int mx, my;
	float xnr1=0, ynr1=0, xnr2=0, ynr2=0, val, an;
	mx = getmaxx()/2;
	my = getmaxy()/2;
	if(alpha < 0){
	an = 360+alpha;
	val = an*3.14/180;
	}
	else{
	val = alpha*3.14/180;
	}
	//calls function to get the value to rotate
	xnr1=getrx(val,x1,y1);
	ynr1=getry(val,x1,y1);
	xnr2=getrx(val,x2,y2);
	ynr2=getry(val,x2,y2);

	setcolor(BLACK);
    //draws the line 
	line(xnr1+mx,ynr1+my,xnr2+mx,ynr2+my);

}


void scale(){
	int e1, e2, x1=0, y1=0, r1=30, screenx, screeny;
	float factor;
	clrscr();
	screenx = getmaxx();
	screeny = getmaxy();
	printf("\n\t\t\tEnter the factor");
	scanf("%f", &factor);
	//draws face and color it
	clrscr();
	setcolor(BLACK);
	circle((x1+screenx/2),(y1+screeny/2),r1*factor);                      //circle drawn
	setfillstyle(SOLID_FILL,YELLOW);
	floodfill(x1+screenx/2+1,y1+screeny/2+1,BLACK);      //fills color

	//function to draw and fill ellipse
	setfillstyle(SOLID_FILL,BLACK);
	fillellipse((x1-10*(factor)+screenx/2),(y1-10*(factor)+screeny/2),3*factor,6*factor);
	fillellipse((x1+10*(factor)+screenx/2),(y1-10*(factor)+screeny/2),3*factor,6*factor);

	//draws the mouth
	setcolor(BLACK);
	line((x1-15*(factor)+screenx/2),(y1+12*(factor)+screeny/2),(x1+15*(factor)+screenx/2),(y1+12*(factor)+screeny/2));
	printf("\n\t\t\t\tPress any key to continue");
	getch();
	main();
}
void animation(){
	int x1=0, y1=0, r=30, x=0,y=0, screenx,screeny;
	cleardevice();
	screenx = getmaxx();
	screeny = getmaxy();
	setcolor(YELLOW);
	circle(x1+screenx/2,y1+screeny/2,r);
	setfillstyle(SOLID_FILL,YELLOW);
	floodfill(x1+screenx/2+1,y1+screeny/2+1,YELLOW);

	setcolor(BLACK);
	ellipse(x1-10+screenx/2,y1-9+screeny/2,0,180,6,3);
	ellipse(x1-10+screenx/2,y1-8+screeny/2,0,180,6,3);
	ellipse(x1+10+screenx/2,y1-9+screeny/2,0,180,6,3);
	ellipse(x1+10+screenx/2,y1-8+screeny/2,0,180,6,3);
	arc(x1+screenx/2,y1+10+screeny/2,180,360,7);
	arc(x1+screenx/2,y1+9+screeny/2,180,360,7);
	setcolor(WHITE);
	outtextxy(x1+280,y1+100,"THIS IS BHOLU");
	outtextxy(x1+50,y1+150,"ONE FINE DAY HE WAS HAPPY AND ENJOYING THE PIXEL GARDEN, WHEN THIS HAPPENDED");
	//getch();
	delay(5000);
	cleardevice();

	//end of 1st scene

	//start of second scene

	//second scene
	//face
	cleardevice();
	outtextxy(x1+280,y1+100,"THIS IS DHOLU");
	outtextxy(x1+200,y1+150,"HEY BHOLU, DO YOU WANNA HEAR A JOKE?");

	circle(x1+screenx/2,y1+screeny/2,r);
	setfillstyle(SOLID_FILL,YELLOW);
	floodfill(x1+screenx/2+1,y1+screeny/2+1,WHITE);

	setcolor(BLACK);
	line(-5+screenx/2,0+screeny/2,-17+screenx/2,-5+screeny/2);
	line(-5+screenx/2,0+screeny/2,-17+screenx/2,5+screeny/2);
	line(5+screenx/2,0+screeny/2,17+screenx/2,5+screeny/2);
	line(5+screenx/2,0+screeny/2,17+screenx/2,-5+screeny/2);

	arc(x1+screenx/2,y1+10+screeny/2/2,180,360,9);
	arc(x1+screenx/2,y1+9+screeny/2,180,360,9);
	setcolor(WHITE);
	
	delay(5000);
	//end of second scene

	//start of third scene
	cleardevice();
	setcolor(YELLOW);
	circle(x1+screenx/2,y1+screeny/2,r);
	setfillstyle(SOLID_FILL,YELLOW);
	floodfill(x1+screenx/2+1,y1+screeny/2+1,YELLOW);

	setcolor(BLACK);
	ellipse(x1-10+screenx/2,y1-9+screeny/2,0,180,6,3);
	ellipse(x1-10+screenx/2,y1-8+screeny/2,0,180,6,3);
	ellipse(x1+10+screenx/2,y1-9+screeny/2,0,180,6,3);
	ellipse(x1+10+screenx/2,y1-8+screeny/2,0,180,6,3);
	arc(x1+screenx/2,y1+10+screeny/2,180,360,7);
	arc(x1+screenx/2,y1+9+screeny/2,180,360,7);
	setcolor(WHITE);
	outtextxy(x1+280,y1+100,"YEAH! SURE");
	//getch();
	delay(5000);
	//end of third scene

	//start of fourth scene

	cleardevice();
	outtextxy(x1,y1+100,"TWO PEANUTS WERE WALKING DONW A SPOOKY ROAD AT NIGHT, AND TELL ME WHAT HAPPENS");
	outtextxy(x1+250,y1+120,"TO ONE OF THEM?");

	circle(x1+screenx/2,y1+screeny/2,r);
	setfillstyle(SOLID_FILL,YELLOW);
	floodfill(x1+screenx/2+1,y1+screeny/2+1,WHITE);

	setcolor(BLACK);
	line(-5+screenx/2,0+screeny/2,-17+screenx/2,-5+screeny/2);
	line(-5+screenx/2,0+screeny/2,-17+screenx/2,5+screeny/2);
	line(5+screenx/2,0+screeny/2,17+screenx/2,5+screeny/2);
	line(5+screenx/2,0+screeny/2,17+screenx/2,-5+screeny/2);

	arc(x1+screenx/2,y1+10+screeny/2,180,360,9);
	arc(x1+screenx/2,y1+9+screeny/2,180,360,9);
	setcolor(WHITE);
	//getch();
	delay(15000);
	outtextxy(x1+250,y1+350,"ONE WAS ASSALTED");
	//getch();
	delay(6000);


	//end of fourth scene

	//start of fifth scene
	//dholu laughing face
	cleardevice();
	outtextxy(x1+250,y1+150,"DHOLU: HEHEHEHEHEHEH");
	setfillstyle(SOLID_FILL,YELLOW);
	circle(x+screenx/2,y+screeny/2,r);
	floodfill(x+screenx/2,y+screeny/2,WHITE);

	setcolor(BLACK);
	line(-5+screenx/2,0+screeny/2,-17+screenx/2,-5+screeny/2);
	line(-5+screenx/2,0+screeny/2,-17+screenx/2,5+screeny/2);
	line(5+screenx/2,0+screeny/2,17+screenx/2,5+screeny/2);
	line(5+screenx/2,0+screeny/2,17+screenx/2,-5+screeny/2);

	 //mouth
	setcolor(BLACK);
	ellipse(0+screenx/2,15+screeny/2,180,360,12,10);
	//dholu eyes
	line(0-11+screenx/2,0+15+screeny/2,0+11+screenx/2,0+15+screeny/2);
	line(0-10+screenx/2,0+18+screeny/2,0+10+screenx/2,0+18+screeny/2);
	setfillstyle(SOLID_FILL,WHITE);
	floodfill(0-11+screenx/2,0+17+screeny/2,BLACK);

	ellipse(0+screenx/2,0+24+screeny/2,0,180,6,4);
	setfillstyle(SOLID_FILL,RED);
	floodfill(0+1+screenx/2,0+24+screeny/2,BLACK);
	delay(5000);
	//end of fifth scene
	cleardevice();

	setcolor(WHITE);
	outtextxy(x1+250,y1+150,"LAME");
	demoji();
	getch();
	main();
}
