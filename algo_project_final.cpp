#include <cstdio>
#include<dos.h>
# include <time.h> //to get system time through time_t
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <climits>
#define pi(x) printf("%d\n",x)
#define ps(x) printf("%s\n",x)
#define gc getchar_unlocked
#define rep(i,n) for(int i=0;i<n;i++)
#define repp(i,n) for(int i=1;i<n;i++)
#include <utility>
#define si(x) scanf("%d",&x)
#define ss(x) scanf("%s",x)
#define sl(x) scanf("%lld",&x)
#define pc putchar_unlocked
#define mod 1000000007
#include <vector>
#define ll long long
#define pl(x) printf("%lld\n",x
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#define pb push_back
#include<iostream>
#include<stdio.h>
#include<cmath>
#include<windows.h>
#include<stdlib.h>
#include<graphics.h>
#include <bits/stdc++.h>
#define mp make_pair
using namespace std;

int mat[20][20]={};   //actual game matrix

int arr[20][2];   //	points initially covered calculated randomly using srand() or rand() max of 20 points

int dp[20][20];
int visited[20][20];
void init()
{
    for(int i=0;i<20;i++)for(int j=0;j<20;j++)dp[i][j]=222;
    for(int i=0;i<20;i++)for(int j=0;j<20;j++)visited[i][j]=0; //not yet visited
    //border case-put in visited

    for(int i=0;i<20;i++)
        {visited[9][i]=1;visited[0][i]=1;}
    for(int i=0;i<20;i++)
    {visited[i][15]=1;visited[i][0]=1;}

    //for(int i=0;i<20;i++)for(int j=0;j<20;j++)visited[i][j]=1;
}
int c=0;
void func(int mat[][20],int x,int y)
{
init();//to initialize dp matrix
dp[x][y]=0;
visited[x][y]=1;
queue<pair<int,int> >q;
q.push(mp(x+1,y+1));dp[x+1][y+1]=1;
visited[x+1][y+1]=1;
q.push(mp(x,y+1));dp[x][y+1]=1;
visited[x][y+1]=1;
q.push(mp(x+1,y));dp[x+1][y]=1;
visited[x+1][y]=1;
q.push(mp(x,y-1));dp[x][y-1]=1;
visited[x][y-1]=1;
q.push(mp(x-1,y));dp[x-1][y]=1;
visited[x-1][y]=1;
q.push(mp(x-1,y+1));dp[x-1][y+1]=1;
visited[x-1][y+1]=1;
q.push(mp(x-1,y-1));dp[x-1][y-1]=1;
visited[x-1][y-1]=1;
q.push(mp(x+1,y-1));dp[x+1][y-1]=1;
visited[x+1][y-1]=1;
while(!q.empty())
{

    ::c=::c+1;
    //if(::c==20)
     //   break;
    int currx=q.front().first;
int curry=q.front().second;

    //visited[q.front().first][q.front().second]=1; //visited this vertex
cout<<"x"<<q.front().first<<" "<<"y"<<q.front().second<<endl;

//delay(200);
if(!visited[currx+1][curry+1])
{q.push(mp(currx+1,curry+1));visited[currx+1][curry+1]=1;}dp[currx+1][curry+1]=min(dp[currx+1][curry+1],dp[currx][curry]+1);
if(!visited[currx][curry+1])
{q.push(mp(currx,curry+1));visited[currx][curry+1]=1;}dp[currx][curry+1]=min(dp[currx][curry+1],dp[currx][curry]+1);
if(!visited[currx+1][curry])
{q.push(mp(currx+1,curry));visited[currx+1][curry]=1;}dp[currx+1][curry]=min(dp[currx+1][curry],dp[currx][curry]+1);
if(!visited[currx][curry-1])
{q.push(mp(currx,curry-1));visited[currx][curry-1]=1;}dp[currx][curry-1]=min(dp[currx][curry-1],dp[currx][curry]+1);
if(!visited[currx-1][curry])
{q.push(mp(currx-1,curry));visited[currx-1][curry]=1;}dp[currx-1][curry]=min(dp[currx-1][curry],dp[currx][curry]+1);
if(!visited[currx-1][curry+1])
{q.push(mp(currx-1,curry+1));visited[currx-1][curry+1]=1;}dp[currx-1][curry+1]=min(dp[currx-1][curry+1],dp[currx][curry]+1);
if(!visited[currx-1][curry-1])
{q.push(mp(currx-1,curry-1));visited[currx-1][curry-1]=1;}dp[currx-1][curry-1]=min(dp[currx-1][curry-1],dp[currx][curry]+1);
if(!visited[currx+1][curry-1])
{q.push(mp(currx+1,curry-1));visited[currx+1][curry-1]=1;}dp[currx+1][curry-1]=min(dp[currx+1][curry-1],dp[currx][curry]+1);

q.pop();

}
}


void won()
{
    int bigx = getmaxwidth(); /* get largest x-coordinate. */
  int bigy = getmaxheight(); /* get largest y-coordinate.*/
  cout<<"bigx="<<bigx<<"\n"<<"bigy="<<bigy;
  //for(int i=0;;i=i+10)
  //{
      initwindow(bigx,bigy);
  setfillstyle(SOLID_FILL,MAGENTA);
  rectangle(0,0,bigx,bigy);
  floodfill(2,2,WHITE);
	    setcolor(YELLOW);
	      settextstyle(GOTHIC_FONT, HORIZ_DIR, 6);
	      outtextxy(getmaxwidth()/4,getmaxheight()/2,"HURRAY!!!   YOU WON :\)");

}
void gameover()
{
    int bigx = getmaxwidth(); /* get largest x-coordinate. */
  int bigy = getmaxheight(); /* get largest y-coordinate.*/
  cout<<"bigx="<<bigx<<"\n"<<"bigy="<<bigy;
      initwindow(bigx,bigy);
  setfillstyle(SOLID_FILL,CYAN);
  rectangle(0,0,bigx,bigy);
  floodfill(2,2,WHITE);
	    setcolor(BLUE);
	      settextstyle(GOTHIC_FONT, HORIZ_DIR, 6);
	      outtextxy(getmaxwidth()/4,getmaxheight()/2,"SORRY   GAME OVER");
}

void click_handler(int x, int y)
{
    //if (getpixel(x,y) == BLACK)
//    red_clicked = true;
    setfillstyle(SOLID_FILL,YELLOW);

    floodfill(x,y,WHITE);
}
void fun(int v1,int v2)
{
    mat[v2][v1]=-1;
}
string calc(int curr_x,int curr_y)
{
    rep(i,8)
    {
    rep(j,14)
    cout<<mat[i][j]<<" ";
    cout<<endl;
    }
	int flag=0;
	int x=curr_x;int y=curr_y;
			string fch; //final choice
    //cout<<"curr_x="<<x<<"curr_y="<<y;
	if(x==0)
    {
        gameover();
        getch();
        exit(0);
    }
    //return "left";
//quit();
	if(y==7)
    {
        gameover();
        getch();
        exit(0);
    }
		//return "down";

	if(y==0)
    {
        gameover();
        getch();
        exit(0);
    }
	//	return "up";

	if(x==13)
    {
        gameover();
        getch();
        exit(0);
    }
	//	{return "right";}
	//code reaches here means all 8 possibilities are open
	int minmoves=INT_MAX;
	//left calc
    cout<<"abcd";
	int tempx,tempy,count;
	 tempx=x; tempy=y;
	count=0;
	//left
	while(tempx>=0)
		{tempx--;if(mat[tempy][tempx]==-1)
			goto fr15;
		}
		if(curr_x+1<minmoves){
			flag=1;minmoves=curr_x+1;fch="left";
		}
        cout<<"abcd";
		fr15:
		//right calc
		tempx=x;tempy=y;count=0;
		while(tempx<14)   //assuming 14 circles in a row
		{tempx++;if(mat[tempy][tempx]==-1)
			goto fr14;
		}
		if(14-curr_x-1<minmoves){
			flag=1;minmoves=14-curr_x-1;fch="right";
		}
        cout<<"abcd";
		fr14:
		//up
		tempx=x;tempy=y;count=0;
			while(tempy>=0)
		{tempy--;if(mat[tempy][tempx]==-1)
			goto fr13;
		}
		if(curr_y+1<minmoves){
			flag=1;minmoves=curr_y+1;fch="up";
		}
		fr13:
		//down
		cout<<"\nyesitenter\n";
		tempx=x;tempy=y;count=0;
			while(tempy<=6)
		{tempy++;if(mat[tempy][tempx]==-1)
			{cout<<"\nyehuinabaat\n";goto fr12;}
		}
		if(8-curr_y-1<minmoves){
			flag=1;minmoves=8-curr_y-1;fch="down";
		}
	/*
	if(curr_x+1<minmoves)
		{flag=1;minmoves=curr_x+1;fch="left";}
	if(9-curr_x-1<minmoves)
		{flag=1;minmoves=9-curr_x-1;fch="right";}
	if(curr_y+1<minmoves)
		{flag=1;minmoves=curr_y+1;fch="up";}
	if(9-curr_y-1<minmoves)
		{flag=1;minmoves=9-curr_y-1;fch="down";}
	*/
	fr12:
	//int tempx=x;int tempy=y;
	tempx=x;tempy=y;
	//to calc top left moves
	//int count=0;
	count=0;
	while(tempx>=0 && tempy>=0 && tempx<=13 && tempy<=7)
	{
	    tempx--;tempy--;count++;
		if(mat[tempy][tempx]==-1)
			goto fr1;
	}
	if(count<minmoves)
	{
		flag=1;
		minmoves=count;fch="upleft";
	}
		fr1:
 tempx=x; tempy=y;
	//to calc top right moves
	 count=0;
	while(tempx>=0 && tempy>=0 && tempx<=13 && tempy<=7)
	{
	    tempx++;tempy--;count++;
		if(mat[tempy][tempx]==-1)
			goto fr2;
	}
	if(count<minmoves)
	{
		flag=1;
		minmoves=count;fch="upright";
	}
	fr2:
	tempx=x;tempy=y;
	//to calc bottom left moves
	 count=0;
	while(tempx>=0 && tempy>=0 && tempx<=13 && tempy<=7)
	{
	    tempx--;tempy++;count++;
		if(mat[tempy][tempx]==-1)
			goto fr3;
	}
	if(count<minmoves)
	{
		flag=1;
		minmoves=count;fch="bottomleft";
	}
	fr3:
	tempx=x;tempy=y;
	//to calc top left moves
	 count=0;
	while(tempx>=0 && tempy>=0 && tempx<=12 && tempy<=6)
	{
	    cout<<"varun";
	    tempx++;tempy++;count++;
		if(mat[tempy][tempx]==-1)
			{cout<<"nirmit"<<endl;goto fr4;}
	}
	if(count<minmoves)
	{
		flag=1;
		minmoves=count;fch="bottomright";
	}
	fr4:
if(flag)
	return fch;
else if(!flag)
{
    return "NULL";
    /*
int nirmit=0;
if(mat[x-1][y+1]==0)
{fch="bottomleft";return fch;}
else if(mat[x+1][y-1]==0)
    {fch="upright";return fch;}
else if(mat[x-1][y-1]==0)
    {fch="upleft";return fch;}
else if(mat[x+1][y+1]==0)
    {fch="bottomright";return fch;}
else if(mat[x+1][y]==0)
    {fch="right";return fch;}
else if(mat[x][y+1]==0)
    {fch="down";return fch;}
else if(mat[x-1][y]==0)
    {fch="left";return fch;}
else if(mat[x][y-1]==0)
    {fch="up";return fch;}
else
    return "NULL";
*/
}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int front(void)
{
   /* request auto detection */
//   int gdriver = DETECT, gmode, errorcode;
 int bigx = getmaxwidth(); /* get largest x-coordinate. */
  int bigy = getmaxheight(); /* get largest y-coordinate.*/
  cout<<"bigx="<<bigx<<"\n"<<"bigy="<<bigy;
  //for(int i=0;;i=i+10)
  //{
      initwindow(bigx,bigy,"Hello!!!\nCIRCLE THE DOT");
      //delay(1500);
  //}
  setfillstyle(SOLID_FILL,MAGENTA);
  rectangle(0,0,bigx,bigy);
  floodfill(2,2,WHITE);
   int xmax, ymax,x1,x2,y1,y2,button;
   int i,c,style,q;
     int p,x;
int z=0;
    for(p=0;p<20;p++)
	   for(x=0;x<20;x++)
	   arr[p][x]=0;
	    setcolor(YELLOW);
	      settextstyle(TRIPLEX_SCR_FONT, HORIZ_DIR, 9);
//	     settextstyle(SMALL_FONT, HORIZ_DIR, 7);
	     setlinestyle(DOTTED_LINE, 5, 2);//void setlinestyle( int linestyle, unsigned upattern, int thickness );
    setfillstyle(SOLID_FILL,RED);
 //rectangle(85,175,350,220);
 //rectangle(85,235,350,280);
  //rectangle(85,295,350,340);
  //bar(360,150,365,360);
  //bar(10,350,375,350);
  //circle(260,100, 45);
  //circle(220,50, 15);
   //circle(300,50, 15);
  //circle(240,90, 5);
   //circle(280,90, 5);
  line(260, 90, 250, 110);
    line(260, 90, 270, 110);
   line(250,110, 270, 110);
 //ellipse(260, 130, 0, 360,11, 6);
   //bar(200,145,320,155);
 //bar(330,440,350,480);
	   //setcolor(4);
	   settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 6);

 //    floodfill(86, 180, GREEN);

  //while(!kbhit())
    // {	show_mouse();
		//get_mouse_pos(&x1,&y1,&button);
	//	 randomize();
		     //q=	(rand()%15)+1;
		     //cout<<"\nq="<<q;
		     //if(q!=6)
		//setcolor(q);
	       //settextstyle(SANS_SERIF_FONT,0,4);

  //outtextxy(90,180,"1 PLAYER" );
//outtextxy(90,240,"2 PLAYER");
 outtextxy(90,300,"!!!PLAY!!!");
 //settextstyle(1,0,3);
 outtextxy(400,450,"EFFORTS BY:");
 //outtextxy(400,275,"Lovish mittal");
 outtextxy(400,550,"Varun Gambhir");
 outtextxy(400,600,"Nirmit Goyal");
	       //if(x1>248&&y1>=250&&x2<=368&&y2<=265)
		       //goto end;-----------SEE IT AFRETWARDS!!!!!!!!!!!!!!!!
int radius;
setlinestyle(SOLID_LINE,2,8);
		       setcolor(YELLOW);//by default//to set boundary color
for ( int i=10,radius = 25; radius <= 250; radius = radius + 20,i++)
{
    //cout<<"\a";
    setcolor(i);
      circle(1000, 600, radius);
      delay(100);
      if(i==15)
      {
          i=10;
      }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   settextstyle(GOTHIC_FONT, HORIZ_DIR, 4);


   setlinestyle(SOLID_LINE, 5, 1);

   line(10,80,630,80);
   line(10,81,630,81);
   setcolor(12);
    setlinestyle(DASHED_LINE, 5, 1);
//fractrals*****************************

   //line(10,175,10,215);
   //line(10,215,80,190);
   //line(80,190,10,175);
   //re(10,175,10,215,80,190,5);

//second

   //line(10,235,10,275);
   //line(10,275,80,255);
   //line(80,255,10,235);
   //re(10,235,10,275,80,255,5);

//third

   line(10,295,10,335);
   line(10,335,80,315);
   line(80,315,10,295);
   //re(10,295,10,335,80,315,5);
   setcolor(2);
   //rectangle(105,175,370,220);
   //re//ctangle(105,235,370,280);
   //rectangle(105,295,370,340);
   //rectangle(105,176,370,221);
   //rectangle(105,236,370,281);
   //rectangle(105,296,370,341);
   //bar(390,150,395,360);
   //bar(10,350,405,350);
//space craft ##################################################
int poly[100];
   poly[0]=530;
   poly[1]=370-100;

   poly[2]=530+10;
   poly[3]=370-60;

   poly[4]=530+50;
   poly[5]=370-40;

   poly[6]=530;
   poly[7]=370-50;

   poly[8]=530-50;
   poly[9]=370-40;

   poly[10]=530-10;
   poly[11]=370-60;
   setfillstyle(9, getmaxcolor());
   bar(550,305,555,320);
   bar(500,305,505,320);
   fillpoly(6,poly);
   setcolor(4);
   settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
   for(i=0;i<200;i=i+10)
   {
   circle(500,300-i,5);
   circle(550,300-i,5);
   delay(30);
   setcolor(0);
   circle(500,300-i,5);
   circle(550,300-i,5);
   }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	cout<<"Click\n";
settextstyle(TRIPLEX_SCR_FONT, HORIZ_DIR, 9);
while (!ismouseclick(WM_LBUTTONDOWN))
    {
for(int i=1;i<=14;i++)
{
            setcolor(i);
    	    outtextxy(50,15,"CIRCLE THE DOT");
}
    }
int flagg=0;
while(flagg==0)
{

getmouseclick(WM_LBUTTONDOWN, x1,y1);
		x2=x1;
		y2=y1;
		if(x1>=90&&x1<=275&&y1>=300&&y1<=600)
        {
            flagg=1;
            return 0;
        }
}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    int gd=DETECT,gm,i,j,r=35;
 // initgraph(&gd,&gm,"C:\\turboc3\\bgi");
 front();
 initwindow(1000,600);
  setbkcolor(MAGENTA);
  int xMax=getmaxx();
  int yMax=getmaxy();
  time_t t;
//registermousehandler(WM_LBUTTONDBLCLK);
    // Register the function that handles a left mouse click

  //  cout << "The mouse was clicked at: ";
    //cout << "x=" << mousex( );
    //cout << " y=" << mousey( ) << endl;

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  int init_x=30,init_y=30,gap=0,add;
  cout<<xMax<<"\n"<<yMax;
setcolor(WHITE);//by default//to set boundary color
setfillstyle(XHATCH_FILL,GREEN);//used for flood fill
for(j=init_y;j<=yMax-gap-r;j=j+2*r)
{
   for(i=init_x;i<=xMax-gap-r;i=i+2*r)
   {
      circle(i,j,r);
      floodfill(i,j,WHITE);             //till white is found
   }
   /*j=j+2*r;
   for(i=init_x+r;i<=xMax-gap-r;i=i+2*r)
   {
      circle(i,j,r);
     floodfill(i,j,WHITE);
   }*/
}

//circle(100,110,20);
//int x[100],y[100];
//setfillstyle(SOLID_F ILL,RED);//used for flood fill
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	rep(i,20)
	{
		rep(j,2)
		arr[i][j]=-1;
	}
	unsigned int sval;
sval=(unsigned)time(&t);
srand(sval);
rep(i,30)//
{
        int x=rand()%14;
        int y=rand()%8;
        ::arr[i][0]=x;
        ::arr[i][1]=y;
        cout<<arr[i][0]<<" "<<arr[i][1]<<endl;
}
int xspace=getmaxx()/14;
int yspace=getmaxy()/8;
setfillstyle(SOLID_FILL,RED);//used for flood fill
rep(i,10)
{
    int xx=xspace*arr[i][0];
    int yy=yspace*arr[i][1];
    int widthx=getmaxx()/14;
    int widthy=getmaxy()/8;
if((!(getpixel(xx,yy)==BLACK) )&&( !(getpixel(xx,yy)==RED)))
{
    floodfill(xx,yy,WHITE);
}
}
		//now before the game begins, put blockages in the matrix
		rep(i,20)
		if(arr[i][0]!=-1)
			mat[arr[i][1]][arr[i][0]]=-1;   //-1 denotes that no
	int curr_x,curr_y;   //initial curr position will also be decided randomly
    int xx,yy;
setfillstyle(SOLID_FILL,YELLOW);
int inix=getmaxx();
int ansx=inix/2;
int iniy=getmaxy();
int ansy=iniy/2;
if( (!(getpixel(ansx,ansy)==BLACK)))
floodfill(ansx,ansy,WHITE);
//else
//{
    //if(mat[])
   //floodfill(ansx+7,ansy+7,WHITE);
//}
curr_x=7;curr_y=4;
int xxxx,yyyy;
	while(1)//!!!!!!!Do it 1 after wards
	{
    //cout<<"hhheaeef";
    cout<<"cat at-"<<curr_x<<" "<<curr_y<<endl;
   cout<<"Click\n";
  // getmouseclick( WM_LBUTTONDOWN, xxxx,yyyy);
while (!ismouseclick(WM_LBUTTONDOWN))

    {
    }
    getmouseclick(WM_LBUTTONDOWN, xxxx, yyyy);
    if(WM_LBUTTONDOWN==513)
    {
        Beep(1000,1000);
   //delay(500);
   //nosound();
    }
    cout<<"\nbutton"<<WM_LBUTTONDOWN<<"\n";
setfillstyle(SOLID_FILL,RED);
floodfill(xxxx,yyyy,WHITE);
    cout << "The mouse was clicked at: ";

    cout << "x=" << xxxx;

    cout << " y=" << yyyy << endl;
        //int v1=getmaxx()/xxxx;
        //int v2=getmaxy()/yyyy;
        int wid=2*r;
        int v1=xxxx/wid;
        int v2=yyyy/wid;

        cout<<v1<<v2<<endl;
fun(v1,v2);
//registermousehandler(WM_LBUTTONDOWN, click_handler);

		if(curr_x<0 || curr_x > 13 || curr_y<0 || curr_y>7)  //ends..user loses
			break;

/*
    int tempx=xx;
     int tempy=yy;
setfillstyle(SOLID_FILL,YELLOW);
    curr_x,curr_y
    xx=xspace*curr_x;
     yy=yspace*curr_y;
    floodfill(xx-3,yy-3,WHITE);
*/
setfillstyle(   XHATCH_FILL,GREEN);
        int temp_x=(double)(getmaxx()/14)*curr_x;
        int temp_y=(double)(getmaxy()/8)*curr_y;
        floodfill((int)(temp_x-3),(int)(temp_y-3),WHITE);
        int xy=temp_x;int yx=temp_y;
	string opt=calc(curr_x,curr_y); //this call will be made each time the player(user) makes a move and we need to calculate cat ka apt. move

for(int i=0;i<8;i++)
{
    for(int j=0;j<14;j++)
        cout<<mat[i][j]<<" ";
    cout<<"\n";
}

if(opt=="NULLL")
func(mat,xy,yx);
cout<<opt<<" ";
	if(opt=="left")
		curr_x--;
	else if(opt=="right")
		curr_x++;
	else if(opt=="up")
		curr_y--;
	else if(opt=="down")
		curr_y++;
	else if(opt=="upleft")
		{curr_x--;curr_y--;}
	else if(opt=="upright")
		{curr_y--;curr_x++;}
	else if(opt=="bottomleft")
		{curr_x--;curr_y++;}
	else if(opt=="bottomright")
		{curr_x++;curr_y++;}
	else if(opt=="NULL")
         {
             won();
    getch();
	exit(0);

         }

         ////////MY WORK IS DONE...PS:I DON"T NOW NOW IF IT'S WORKING CORRECTLY OR NOT>>>NEEND AA RAHI HAI GN :)
		//break;  //calc will return -1 if no move is possible at all...game ends ...user wins
       //
		double s,t;
        setfillstyle(SOLID_FILL,YELLOW);
        s=(double)(getmaxx()/14)*curr_x;
        t=(double)(getmaxy()/8)*curr_y;
        if(!(getpixel(s,t)==BLACK) && !(getpixel(s,t)==RED))
        floodfill((int)(s),(int)(t),WHITE);
        else if(!(getpixel(s+2*r,t)==BLACK) && !(getpixel(s+2*r,t)==RED))
        floodfill((int)(s+2*r),(int)(t),WHITE);
        else if(!(getpixel(s+2*r,t-2*r)==BLACK) && !(getpixel(s+2*r,t-2*r)==RED))
        floodfill((int)(s+2*r),(int)(t-2*r),WHITE);
        else if(!(getpixel(s,t-2*r)==BLACK) && !(getpixel(s,t-2*r)==RED))
        floodfill((int)(s),(int)(t-2*r),WHITE);
        else if(!(getpixel(s-2*r,t-2*r)==BLACK) && !(getpixel(s-2*r,t-2*r)==RED))
        floodfill((int)(s-2*r),(int)(t-2*r),WHITE);
        else if(!(getpixel(s-2*r,t)==BLACK) && !(getpixel(s-2*r,t)==RED))
        floodfill((int)(s-2*r),(int)(t),WHITE);
        else if(!(getpixel(s-2*r,t+2*r)==BLACK) && !(getpixel(s-2*r,t+2*r)==RED))
        floodfill((int)(s-2*r),(int)(t+2*r),WHITE);
        else if(!(getpixel(s,t+2*r)==BLACK) && !(getpixel(s,t+2*r)==RED))
        floodfill((int)(s),(int)(t+2*r),WHITE);
        else if(!(getpixel(s+2*r,t+2*r)==BLACK) && !(getpixel(s+2*r,t+2*r)==RED))
        floodfill((int)(s+2*r),(int)(t+2*r),WHITE);

	}//WHILE LOOP ENDS
///////////////////////////////////////////////////////////////////

    getch();
  closegraph();
    return 0;
}
