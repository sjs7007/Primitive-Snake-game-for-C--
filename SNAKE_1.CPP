//This game will work only in older version of C++ like TC++
//A primitive snake game similar to the ones found in old nokia phones!
// Mail me your thoughts at my email address : sjs7007@gmail.com


#include<iostream.h>
#include<dos.h>
#include<stdlib.h>
#include<conio.h>
void waste(int speed); //slows printing
void clear(int len ,int x , int y,int x1,int y1);
void lenyu(int len , int x , int y);
void lenyd(int len , int x , int y);
void lenx(int len);
void main()
{
 clrscr();
 srand((unsigned)time(0));
 int t,x=5,y=5,s=0,len=1,x1,y1,speed;
 long int i;
 cout<<"Enter a,d,w,x to move around the screen."<<endl;
 cout<<"Press any other key to come out."<<endl;
 cout<<"Mail me your thoughts at my email address : sjs7007@gmail.com "<<endl;
 cout<<"Enter the speed from 1-20 : ";
 cin>>speed;
 t=getch();
 clrscr();
 x1=rand()%80;
 y1=rand()%25;
 gotoxy(x1,y1);
 cout<<"#";
 while(1 && t!=13)
    {
	 if (x==1)
	 {
	  clear(len,x,y,x1,y1);
	  x=79;
	 }
	 if(x==80)
	 {
	  clear(len,x,y,x1,y1);
	  x=1;
	 }
	 if(y==0)
	 {
	  clear(len,x,y,x1,y1);
	  y=24;
	 }
	 if(y==25)
	 {
	  clear(len,x,y,x1,y1);
	  y=0;
	 }

	 if(len==5)
	 {
	  clrscr();
	  cout<<"You win!";
	 }
	 if(x==x1 && y==y1)
	 {
	  gotoxy(x,y); cout<<" ";
	  len=len+1;
	  x1=rand()%80;
	  y1=rand()%25;
	  gotoxy(x1,y1);
	  cout<<"#";
	 }

	 if(kbhit())
	{
	    t=getch();
	    if(t!=97 & t!=100 & t!=119 & t!=120) break;
	    else
	    continue;
	}
    while(t!=13 && s!=1)        //s loop ontrol
     {
      //t=getch(); // 97 100 119 120 enter13 space 32 
      waste(speed);
      switch(t)
      {
       case 97 :
       {
	clear(len,x,y,x1,y1);
	gotoxy(x-1,y);
	lenx(len);
	x--;
	s++;
	break;
       }
       case 100:
       {
	clear(len,x,y,x1,y1);
	gotoxy(x+1,y);
	lenx(len);
	x++;
	s++;
	break;
       }
       case 119:
       {
	waste(speed);
	clear(len,x,y,x1,y1);
	lenyu(len,x,y);
	y--;
	s++;
	break;
       }
       case 120:
       {
	waste(speed);
	clear(len,x,y,x1,y1);
	lenyd(len,x,y);
	y++;
	s++;
	break;
       }
      }
     }
     s=0;
    }
}

void waste(int speed)
{
 long int i,junk=0;
 if(speed==1) sleep(1);
 else for(i=1;i<=100000*(21-speed);i++) junk++;          // to waste time
}

void clear(int len,int x ,int y,int x1,int y1)
{
 int i,j;
 for(i=-1;i<=len;i++)
  for(j=1-len;j<=1+len;j++)
  {
    gotoxy(x+i,y+j);
    if((x+i)==x1 && (y+j)==y1) continue;
    cout<<" ";
  }
}

void lenyu(int len,int x, int y)   //to move snake up
{
 int j;
 for(j=1;j<=len;j++)
 {
  gotoxy(x,y+j);
  cout<<"*";
 }
}

void lenyd(int len, int x ,int y) //to move snake down
{
 int j;
 for(j=-len+2;j<=1;j++)
 {
  gotoxy(x,y+j);
  cout<<"*";
 }
}

void lenx(int len) //left right
{
 int i;
 for(i=1;i<=len;i++)
 cout<<"*";
}
