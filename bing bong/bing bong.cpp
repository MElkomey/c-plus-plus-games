#include<iostream>
#include<conio.h>
#include<windows.h>

using namespace std;
enum Ball_Direction{TOP,DOWN,TOPRIGHT,TOPLEFT,DOWNRIGHT,DOWNLEFT};
struct Map{	int lenght, width,ballx,bally; Ball_Direction bdir; Ball_Direction prev_dir;};
struct Player{ int  centerx,centery,leftx,lefty,rightx,righty;bool loose; };
Map map1;  Player player_top;  Player player_bot;
void Setup(){
	map1.lenght=20;
	map1.width=40;
	map1.ballx=map1.width/2;
	map1.bally=map1.lenght-2;
	map1.bdir=TOP;
	map1.prev_dir=DOWN;
	player_bot.centerx=map1.width/2;
	player_bot.centery=map1.lenght-1;
	player_bot.leftx=player_bot.centerx-1;
	player_bot.lefty=player_bot.centery;
	player_bot.rightx=player_bot.centerx+1;
	player_bot.righty=player_bot.centery;
	player_bot.loose=false;
    player_top.centerx=map1.width/2;
    player_top.centery=map1.lenght-18;
    player_top.leftx=player_top.centerx-1;
    player_top.lefty=player_top.centery;
    player_top.rightx=player_top.centerx+1;
    player_top.righty=player_top.centery;
    player_top.loose=false;
}

void Draw(){
	system("cls");
	cout<<"ELKOMEY BING BONG GAME\n";
	for(int line=1;line<=map1.lenght;line++){
	   cout<<"#";
	   for(int col=2;col<=map1.width-1;col++)
	   {
	   	if(line==1||line==map1.lenght)
	   		cout<<"#";
		  else if(line==map1.bally&&col==map1.ballx)
		  cout<<"0";
		  else if((player_top.centerx==col&&player_top.centery==line)||(player_top.leftx==col&&player_top.lefty==line)||(player_top.rightx==col&&player_top.righty==line)
		  ||(player_bot.centerx==col&&player_bot.centery==line)||(player_bot.leftx==col&&player_bot.lefty==line)||(player_bot.rightx==col&&player_bot.righty==line)
		  )
		  cout<<"~";
		  else
		   	cout<<" ";
	   }     
     	cout<<"#\n";
	 }
}

void Input(){
	if(_kbhit()){
		char c=_getch();
		switch(c){
			case 'd':
				if(player_bot.rightx !=map1.width-1){
				player_bot.centerx=player_bot.centerx+1;
				player_bot.leftx=player_bot.leftx+1;
				player_bot.rightx=player_bot.rightx+1;
				}
				break;
			case 'a':
				if(player_bot.leftx !=2){
				player_bot.centerx=player_bot.centerx-1;
				player_bot.leftx=player_bot.leftx-1;
				player_bot.rightx=player_bot.rightx-1;
				}
			break;
		    case '3':
				if(player_top.rightx !=map1.width-1){
				player_top.centerx=player_top.centerx+1;
				player_top.leftx=player_top.leftx+1;
				player_top.rightx=player_top.rightx+1;
				}
				break;
			case '1':
					if(player_top.leftx !=2){
				player_top.centerx=player_top.centerx-1;
				player_top.leftx=player_top.leftx-1;
				player_top.rightx=player_top.rightx-1;
				}
			break;
			case 'x':
			exit(0);	
		}
	}
}



void ball_move(){
	
	if((map1.bally==player_top.centery+1)&&(map1.ballx==player_top.centerx)){
		map1.bdir=DOWN;
	}
    if((map1.bally==player_bot.centery-1)&&(map1.ballx==player_bot.centerx)){
    	map1.bdir=TOP;
	}
	
	  if((map1.bally==player_bot.righty-1)&&(map1.ballx==player_bot.rightx)){
    	map1.bdir=TOPRIGHT;
    	map1.prev_dir=TOPRIGHT;
	}
	 if((map1.bally==player_bot.lefty-1)&&(map1.ballx==player_bot.leftx)){
    	map1.bdir=TOPLEFT;
    	map1.prev_dir=TOPLEFT;
	}
	
	 if((map1.bally==player_top.righty+1)&&(map1.ballx==player_top.rightx)){
    	map1.bdir=DOWNRIGHT;
    	map1.prev_dir=DOWNRIGHT;
	}
	 if((map1.bally==player_top.lefty+1)&&(map1.ballx==player_top.leftx)){
    	map1.bdir=DOWNLEFT;
    	map1.prev_dir=DOWNLEFT;
	}
	
	if(map1.ballx==2 && map1.prev_dir==TOPLEFT){
		map1.bdir=TOPRIGHT;
	}
		if(map1.ballx==2 && map1.prev_dir==DOWNLEFT){
		map1.bdir=DOWNRIGHT;
	}
	if((map1.ballx==map1.width-2)&& (map1.prev_dir==DOWNRIGHT)){
		map1.bdir=DOWNLEFT;
	}
		if((map1.ballx==map1.width-2)&& (map1.prev_dir==TOPRIGHT)){
		map1.bdir=TOPLEFT;
	}
	
	if(map1.bally==1){
		player_top.loose=true;
	}
	if(map1.bally==map1.lenght){
		player_bot.loose=true;
	}
	
	
	
	
	
	////////////////////////////////move details respect to ball direction///////////////////
	if(map1.bdir==DOWN)
	{
		map1.bally++;
	}
	 if(map1.bdir==TOP)
	{
		map1.bally--;
	}
	 if(map1.bdir==TOPRIGHT)
	{
	    map1.ballx+=2;
		map1.bally--;
		
	}
	 if(map1.bdir==TOPLEFT)
	{
		map1.bally--;
		map1.ballx-=2;
	}
	 if(map1.bdir==DOWNRIGHT)
	{
		map1.bally++;
		map1.ballx+=2;
	}
   	if(map1.bdir==DOWNLEFT)
	{
		map1.bally++;
		map1.ballx-=2;
	}
	
}




int main()
{
	Setup();
	while(!player_top.loose&&!player_bot.loose){
	Input();
	ball_move();
	Draw();
	
	Sleep(50);
  cout<<" Top player play by  1 for <--   and 3 for -->\n";
  cout<<" Bottotm player play by  a for <--   and d for -->\n\n";

   }
   
   if(player_top.loose){
   	cout<<". .. ...Top player loose... .. .\n\n";
   }
      if(player_bot.loose){
   	cout<<". .. ...Bottom player loose... .. .\n\n";
   }
}
