#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<string.h>
#include<ctype.h>
#include<stdio.h>
#include<process.h>
#include<stdlib.h>


	class hangman
	{
	 int tlx,tly,brx,bry,mx,my,cx,cy,length,height;

	 public:
	 hangman()
	 {
	    length=350;
	    height=200;
	    mx=getmaxx();
	    my=getmaxy();
	    cx=mx/2;
	    cy=my/2;
	    tlx=cx-length/2;
	    tly=cy-height/2;
	    brx=cx+length/2;
	    bry=cy+height/2;
	 }
	 void welcomepage();
	 void scoreboard();
	 void rules(int,int);
	};

  void hangman::welcomepage()
    {

/*
int x=getmaxx()/2;
int y=getmaxy()/2;
for(int q=1;q<15;q++)  //for loop to draw circles
	     {
		setcolor(q);
		for(int p=400;p>200;p--) //300-200 decides the width of the circle
		{

		   rectangle(tlx,tly,brx,bry);
		   rectangle(tlx-5,tly-5,brx+5,bry+5);

       outtextxy(cx-20,cy-60,"HANGMAN");

       outtextxy(cx-145,cy-20,"Guess the letters,fill up the blanks");
       outtextxy(cx-145,cy-10,"and get the word right. You have six");
       outtextxy(cx-145,cy+0,"tries for each word! Understood?");
       outtextxy(cx-145,cy+10,"Now let's get started!");

		  circle(x,y,p);
		}
	       setcolor(q+2);

	    }*/
       getch();
      cleardevice();
   }
   void hangman:: scoreboard()
    {
      setcolor(RED);
      setlinestyle(0,0,THICK_WIDTH);
      moveto(100,350);
      lineto(100,420);
	lineto(300,420);
	lineto(300,350);
	lineto(100,350);
	setcolor(5);
	settextstyle(0,0,2);
	outtextxy(120,390,"Score:");
	settextstyle(0,0,0);
	outtextxy(5,255,"If you need help, press '*' and the second and sixth");
	outtextxy(5,265," letter will be filled for you");
      }

    void hangman:: rules(int color1,int color2)
     {
       setcolor(color1);
       outtextxy(100,100,"HERE ARE THE RULES!");
       setcolor(color2);
       settextstyle(0,0,1);
       outtextxy(100,120,"1.Choose the category that you prefer");
       outtextxy(100,140,"2.Remember to enter the correct option...!");
       outtextxy(100,160,"3.For Example, if you have chosen the category");
       outtextxy(100,180,",'movies' guess the letters of a movie using");
       outtextxy(100,200,"the clue given");
       outtextxy(100,220,"4.If you enter a letter that matches a letter");
       outtextxy(100,240,"  in the name of the movie, the blank is filled");
       outtextxy(100,260,"5.If you make mistakes, the drawing of the man");
       outtextxy(100,280," begins to complete itself");
       outtextxy(100,300,"6.You have six tries in all");
       outtextxy(100,320,"7.At the end of a word, if you");
       outtextxy(100,340,"have not exhaused all your tries,");
       outtextxy(100,360,"you may try until you have lost all your chances");
       setcolor(6);
       outtextxy(100,380,"8.YOU WILL GAIN 5 POINTS FOR EVERY WORD THAT YOU GUESS CORRCTLY");



       }
	class draw
	  {
		private:
		int midx;
		int midy;
		int startx;
		int starty;
		public:
		int secondpage();
		void drawouter();
		void drawhangmanface(int);
		void drawhangmanneck(int);
		void drawhangmanleftarm(int);
		void drawhangmanrightarm(int);
		void drawhangmanleftleg(int);
		void drawhangmanrightleg(int);
		void updatehangman(int);
		int findindex(char,char[],char[]);


		draw()
		{
		startx=0;
		midx=getmaxx()/2;
		midy=getmaxy()/2;
		starty=0;
		}
	  };

 int draw :: secondpage()
   {

    setfillstyle(SOLID_FILL,YELLOW);
    bar(0,0, getmaxx(),15);
    bar(0,455, getmaxx(),470);
    setcolor(YELLOW);
    settextstyle(0,0,1);
    setcolor(LIGHTMAGENTA);
    int flag=1;

	outtextxy(100,100,"SELECT THE CATEGORY OF YOUR CHOICE");
	outtextxy(100,120,"1.MOVIES");
	outtextxy(100,140,"2.COUNTRIES");
	outtextxy(100,160,"3.GAMES");
		int opt;

	  while(flag!=0)
	       {
			char ch=getch();
			if(ch=='1')
		       {
			opt=1;
			flag=0;
		       }
			else if(ch=='2')
		       {
			opt=2;
			flag=0;
		       }
			else if(ch=='3')
		       {
			opt=3;
			flag=0;
		       }
			else if(ch<0||ch>3) //error message
		       {
			outtextxy(100,180,"Enter correct option!");
		       }
			else
		       {
			flag=0;
		       }

		}

	outtextxy(100,250,"With the help of the clues given and by making");
	outtextxy(100,270," a good guess you an surely win this simple game");
	settextstyle(GOTHIC_FONT,0,3);
	setcolor(LIGHTBLUE);
	outtextxy(50,300,"ALL THE BEST !!");
	return opt;
	cleardevice();
    }

		 void draw:: drawouter()
		{
			setbkcolor(WHITE);
			setcolor(GREEN);
			rectangle(0,0,getmaxx(),getmaxy());
			rectangle(midx+150,0,getmaxx(),getmaxy());
			setcolor(12);
			  moveto(midx+230,20);
			  lineto(midx+230,35);
			  moveto(midx+230,16);
			lineto(midx+280,16);
			lineto(midx+280,100);
		}
		 void draw :: drawhangmanface(int color)
		{
			setlinestyle(SOLID_LINE,2,1000);
			setcolor(color);
			circle(midx+230,50,20);
		}

		void draw::  drawhangmanneck(int color)
		{
		       setcolor(color);
		       line(midx+230,70,midx+230,110);
		}
	       void draw:: drawhangmanleftarm(int color)
	       {
		       setcolor(color);
		       line(midx+230,70,midx+200,100);
	       }
	       void draw:: drawhangmanrightarm(int color)
	     {
		       setcolor(color);
		       line(midx+230,70,midx+260,100);

	     }

	     void draw:: drawhangmanleftleg(int color)
	     {
		      setcolor(color);
		      line(midx+230,110,midx+200,140);
	     }

	     void draw::drawhangmanrightleg(int color)
	     {
		    setcolor(color);
		    line(midx+230,110,midx+260,140);
	     }


      void draw::updatehangman(int errorcode)
      {

	  switch(errorcode)
	    {
		case 5:
		drawhangmanface(RED);
		break;
		case 4:
		drawhangmanneck(RED);
		drawhangmanface(RED);
		break;
		case 3:
		drawhangmanleftarm(RED);
		drawhangmanneck(RED);
		drawhangmanface(RED);
		break;
		case 2:
		drawhangmanrightarm(RED);
		drawhangmanleftarm(RED);
		drawhangmanneck(RED);
		drawhangmanface(RED);
		break;
		case 1:
		drawhangmanleftleg(RED);
		drawhangmanrightarm(RED);
		drawhangmanleftarm(RED);
		drawhangmanneck(RED);
		drawhangmanface(RED);
		break;
		case 0:
		drawhangmanrightleg(RED);
		drawhangmanleftleg(RED);
		drawhangmanrightarm(RED);
		drawhangmanleftarm(RED);
		drawhangmanneck(RED);
		drawhangmanface(RED);
		break;

	    }


      }

       int draw:: findindex(char ch,char unknown1[],char temp1[])
	  {
	      int help=0;
	      int len=strlen(unknown1);
	      for(int i=0;i<len;i++)
	       {
		   if(ch==unknown1[i])
		     {
			 if(temp1[i]==ch)//check whether already entered same text or not.
			 {
			     return 1000;
			 }
			 else
			 {
			     return i;
			 }
			  if(help==1)
			 {
			    return 1001;
			 }
		     }
		}

		   if(ch=='*')
		    {
		    return 1002;
		    help=1;
		    }
		   else
		    {
		     return 999;
		    }
	 }






void main()
{
    int gdriver = DETECT, gmode,midx,midy;
    char path[]="c:\\tc\\bgi";
    int error=6;
    initgraph(&gdriver,&gmode,path);
    cleardevice();
    hangman hg;
    hg.welcomepage();
    getch();
    hg.rules(RED,BLUE);
    getch();
    again:
    cleardevice();

    draw dr;
    int option=dr.secondpage();
    getch();
    char word[4][7];
    int score=0;
    cleardevice();
    settextstyle(0,0,1);

		if(option==1)
			{
			 setcolor(GREEN);
			 outtextxy(10,200,"Clue: This is a Hollywood movie consisting of 7 letters");
			 getch();
			 setcolor(0);
			 outtextxy(10,200,"Clue: This is a Hollywood movie consisting of 7 letters");
			 strcpy(word[0],"quicker");
			 strcpy(word[1],"pirates");
			 strcpy(word[2],"jumpers");
			 strcpy(word[3],"macbeth");


			 }
		else if(option==2)
			{
			  setcolor(GREEN);
			  outtextxy(10,200,"Clue:Its a seven letter word, a name of a country");
			  outtextxy(10,230," belonging to Asia, Europe,Africa or North America");
			  getch();
			  setcolor(0);
			  outtextxy(10,200,"Clue:Its a seven letter word, a name of a country");
			  outtextxy(10,230," belonging to Asia, Europe,Africa or North America");
			  setcolor(GREEN);
			  strcpy(word[0],"iceland");
			  strcpy(word[1],"belgium");
			  strcpy(word[2],"vietnam");
			  strcpy(word[3],"germany");


			}
		else
		      {
			setcolor(GREEN);
			outtextxy(10,200,"Clue:A indoor game or outdoor sport that has 7 letters");
			getch();
			setcolor(0);
			outtextxy(10,200,"Clue:A indoor game or outdoor sport that has 7 letters");
			setcolor(GREEN);
		       //word[5][7]={"fencing","archery","bowling","surfing"};
		      strcpy(word[0],"rafting");
		      strcpy(word[1],"croquet");
		      strcpy(word[2],"bowling");
		      strcpy(word[3],"surfing");

		      }
    char unknown[7];
    int len=0;

    cleardevice();


	midx = getmaxx()/ 2;
	midy = getmaxy() / 2;

	setfillstyle(SOLID_FILL, GREEN);
	bar(0, 0, getmaxx(),15);
	settextstyle(0,0,1);
	outtextxy(midx-30,4,"Hang-Man Game");
	dr.drawouter();
	hg.scoreboard();

	int num,rnd=3;  //a random word is selected out of the set of given words
	randomize();
	num=random(rnd);

char mytemp[28];
char string[10];
strcpy(mytemp,word[num]);
			      for(int i=0;i<7;i++)
				{
				  unknown[i]=mytemp[i];
				}


len=strlen(unknown);



char temp[]="_______";

settextstyle(0,0,2);
outtextxy(10,30,"Enter a letter");
int ccount=0;//ccount is used to keep cont of the number of correct letter entered ny the user
     while(error!=0)
	{


	   char ch=getch();

	    setcolor(0);
	    outtextxy(10,55,temp);

	      int index=dr.findindex(tolower(ch),unknown,temp);
		 if(index==1001)
		   {
		     outtextxy(3,275,"You may use the help button only once");
		   }

		 else if(index==999)
		   {
		      error--;
		      dr.updatehangman(error);
		   }

		 else if(index==1002)
		  {
		    temp[5]=unknown[5];
		    temp[1]=unknown[1];
		    outtextxy(10,55,temp);
		    ccount=ccount+2;//since two letter have already been replaced
		    }

		 else if(index!=1000)
		  {

		     temp[index]=ch;
		     ccount=ccount+1;//since one letter has been guessed correctly
		  }

setcolor(GREEN);
outtextxy(10,55,temp);


	if(ccount==7)//7 letters have been guessed correctly
	   {
		score=score+5;
		setcolor(0);
		outtextxy(210,390,string);
		itoa(score,string,10);//converts int to string type
		setcolor(5);
		outtextxy(210,390,string);

		outtextxy(10,100,"You won!congratulations!");
		getch();
		setcolor(0);
		outtextxy(10,100,"You won!congratulations!");
		setcolor(GREEN);
		outtextxy(10,130,"Do you want to contiue..?");
		char c=getch();
if(c=='y' ||c=='Y')
{
ccount=0;
setcolor(0);
outtextxy(10,55,unknown);
setcolor(GREEN);
for(int k=0;k<strlen(temp);k++)
temp[k]='_';
goto again;
}
else
{
exit(0);

}
setcolor(0);
outtextxy(10,130,"Do you want to contiue..?");
}



}
setcolor(GREEN);
outtextxy(10,150,"You lost all chances!");

outtextxy(10,200,"The correct word is");
outtextxy(10,220,unknown);
outtextxy(10,180,"press any key to exit");
getch();


}