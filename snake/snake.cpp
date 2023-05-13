#include<iostream>
#include<ctime>
#include <stdlib.h>
#include<conio.h>
#include<windows.h>
using namespace std;
enum Direction {Top=1,Down,Right,Left};
struct map{int height,width,fruit_x,fruit_y;};
struct snake{int head_x,head_y,tail_n,tailx[50],taily[50]; Direction dir;};
struct player{int score; bool loose;};

map map1; snake snake1 ; player player1;
void shift_right(int arr[],int size)
{
	for(int i=size-2;i>=0;i--)
	{
		arr[i+1]=arr[i];
	}
}

void generate_fruit(){

	srand(time(NULL));
	map1.fruit_x=rand()%(map1.width-2)+1;
	map1.fruit_y=rand()%(map1.height-2)+1;
	if(map1.fruit_x>=20||map1.fruit_x<=0||map1.fruit_y>=40||map1.fruit_y<=0||map1.fruit_x==NULL||map1.fruit_y==NULL)
	{
	map1.fruit_x=rand()%(map1.width-2)+1;
	map1.fruit_y=rand()%(map1.height-2)+1;
	}
	

}
void setup(){
	map1.height=40;
	map1.width=20;
	generate_fruit();
	snake1.head_x=map1.width/2;
	snake1.head_y=map1.height/2;
	snake1.tail_n=0;
	player1.score=0;
	player1.loose=false;	
}
void draw(){
	system("cls");
for(int line=1;line<=map1.width;line++)
 {
 	cout<<"#";
 	for(int col=2;col<=map1.height-1;col++)
 	{
 		if(line==1||line==map1.width)
 		cout<<"#";
 		else if(line==map1.fruit_x&&col==map1.fruit_y)
 		cout<<"$";
 		else if(line==snake1.head_x&&col==snake1.head_y)
 		cout<<"O";
 		else 
 		{
 		bool printed=false;
 		for(int z=0;z<snake1.tail_n;z++){
		 
 		if(snake1.tailx[z]==line&&snake1.taily[z]==col){
		
 		cout<<"o";
 		printed=true;
 		break;
		  }
}
 		if(!printed)
 			cout<<" ";
		 
}	}
	cout<<"#";
 	cout<<"\n";
 }
 cout<<"player score is: "<<player1.score<<endl;
 

}
void input(){
	if(_kbhit()){
		char c=_getch();
		switch(c){
			case 'w':
				snake1.dir=Top;
				break;
			case 'a':
				snake1.dir=Left;
				break;
			case 's':
				snake1.dir=Down;
				break;
			case 'd':
				snake1.dir=Right;
				break;
			case 'x':
			    exit(0);	
		}
	}
}
void move(){
	shift_right(snake1.tailx,50);
	shift_right(snake1.taily,50);
	snake1.tailx[0]=snake1.head_x;
	snake1.taily[0]=snake1.head_y;
	
for(int z=1;z<snake1.tail_n;z++)
{
	if(snake1.tailx[0]==snake1.tailx[z]&&snake1.taily[0]==snake1.taily[z])
	{
		exit(0);
	}
}

switch( snake1.dir){
	case Top:
		snake1.head_x--;
		break;
	case Down:
		snake1.head_x++;
		break;
	case Right:
		snake1.head_y++;
		break;
	case Left:
		snake1.head_y--;
		break;
}


if(snake1.head_x<=0||snake1.head_x>=map1.width||snake1.head_y<=0||snake1.head_y>=map1.height)
{
cout<<"\nyou loose.....\n";
exit(0);
	
}

if(snake1.head_x==map1.fruit_x&&snake1.head_y==map1.fruit_y)
{	generate_fruit();
    player1.score+=1;
	snake1.tail_n+=1;
	generate_fruit();

}
}




int main(){
    setup();
	while(!player1.loose){
	input();
	move();
	draw();
	Sleep(50);
}
}
