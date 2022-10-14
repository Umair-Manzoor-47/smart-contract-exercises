#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
const int size=3;
int result=-1;
int counter=0;
string sign1;
string sign2;
string tik_tak[size] [size]={{"1","2","3"},{"4","5","6"},{"7","8","9"}};
 bool condition=false;
bool condition1=false;
bool condition2=false;
bool condition3=false;
bool condition4=false;
bool condition5=false;
bool condition6=false;
bool condition7=false;
bool condition8=false;
bool condition9=false;
bool draw_condition=false;
void display();
int play();
void sign_enter(int location,string sign);
void updated_display();
void sign();
void game_result();
int main()
{
sign();
while (result==-1)
{
//counter=counter+1;
result=play();
if(result==0)
{break;}
}
}
void display()
{
cout<<"1"<<"|"<<"2"<<"|"<<"3"<<endl;
cout<<"__"<<""<<"__"<<""<<"__"<<endl;
cout<<"4"<<"|"<<"5"<<"|"<<"6"<<endl;
cout<<"__"<<""<<"__"<<""<<"__"<<endl;
cout<<"7"<<"|"<<"8"<<"|"<<"9"<<endl;
}
void sign()
{
system("CLS");
cout<<"PLAYER MUST ENTER THEIR SIGNS==";
cout<<endl;
cout<<"ENTER YOUR SIGN PLAYER 1=";
cin>>sign1;
cout<<endl;
cout<<"ENTER YOUR SIGN PLAYER 2=";
cin>>sign2;
}
int play()
{
int location;
system("CLS");
updated_display();
cout<<"ENTER LOCATION WHERE YOU WANT TO ENTER YOUR MARK PLAYER 1=";
cin>>location;
sign_enter( location, sign1);
game_result();
cout<<endl;
if(result==0)
{return 0;}
cout<<"ENTER LOCATION WHERE YOU WANT TO ENTER YOUR MARK PLAYER 2=";
cin>>location;
sign_enter( location, sign2);
game_result();
return -1;
}
void sign_enter(int location, string sign)
{
counter=counter+1;
if(counter==8)
{draw_condition=true;}
if(location==1 && condition1==false)
{
 tik_tak[0] [0]=sign;   
 condition1=true;
}

if(location==2 && condition2==false)
{
 tik_tak[0] [1]=sign;   
 condition2=true;
}


if(location==3 && condition3==false)
{
 tik_tak[0] [2]=sign;   
 condition3=true;
}

if(location==4 && condition4==false)
{
 tik_tak[1] [0]=sign;   
 condition4=true;
}

if(location==5 && condition5==false)
{
 tik_tak[1] [1]=sign;   
 condition5=true;
}



if(location==6 && condition6==false)
{
 tik_tak[1] [2]=sign;   
 condition6=true;
}



if(location==7 && condition7==false)
{
 tik_tak[2] [0]=sign;   
 condition7=true;
}




if(location==8 && condition8==false)
{
 tik_tak[2] [1]=sign;   
 condition8=true;
}



if(location==9 && condition9==false)
{
 tik_tak[2] [2]=sign;   
 condition9=true; 
}
system("CLS");
updated_display();
}

void updated_display()
{

cout<<tik_tak[0] [0]<<"|"<<tik_tak[0] [1]<<"|"<<tik_tak[0] [2]<<endl;
cout<<"__"<<""<<"__"<<""<<"__"<<endl;
cout<<tik_tak[1] [0]<<"|"<<tik_tak[1] [1]<<"|"<<tik_tak[1] [2]<<endl;
cout<<"__"<<""<<"__"<<""<<"__"<<endl;
cout<<tik_tak[2] [0]<<"|"<<tik_tak[2] [1]<<"|"<<tik_tak[2] [2]<<endl;

}

void game_result()
{
   
  
   
    if(tik_tak[0] [0]== sign1  && tik_tak[1] [1]== sign1 )
  {
    if( tik_tak[2] [2]   == sign1 )
    {   
    cout<<"PLAYER 1 IS THE WINNER WITH="<<sign1<<" SIGN"<<endl;
    result=0;
    condition=true;
    }
  }

   
      if(tik_tak[0] [2]== sign1  && tik_tak[1] [1]== sign1 )
  {
    if( tik_tak[2] [0]   == sign1 )
    {   
    cout<<"PLAYER 1 IS THE WINNER WITH="<<sign1<<" SIGN"<<endl;
    condition=true;
    result=0;
    
    }
  } 
   
   
  
      if(tik_tak[0] [0]== sign1  && tik_tak[0] [1]== sign1 )
  {
    if( tik_tak[0] [2]   == sign1 )
    {   
    cout<<"PLAYER 1 IS THE WINNER WITH="<<sign1<<" SIGN"<<endl;
    condition=true;
    result=0;
    
    }
  } 
   
   
     if(tik_tak[1] [0]== sign1  && tik_tak[1] [1]== sign1 )
  {
    if( tik_tak[1] [2]   == sign1 )
    {   
    cout<<"PLAYER 1 IS THE WINNER WITH="<<sign1<<" SIGN"<<endl;
    condition=true;
    result=0;
    
    }
  } 
    
      if(tik_tak[2] [0]== sign1  && tik_tak[2] [1]== sign1 )
  {
    if( tik_tak[2] [2]   == sign1 )
    {   
    cout<<"PLAYER 1 IS THE WINNER WITH="<<sign1<<" SIGN"<<endl;
    condition=true;
    result=0;
    
    }
  } 
   
   
     if(tik_tak[0] [0]== sign1  && tik_tak[1] [0]== sign1 )
  {
    if( tik_tak[2] [0]   == sign1 )
    {   
    cout<<"PLAYER 1 IS THE WINNER WITH="<<sign1<<" SIGN"<<endl;
    condition=true;
    result=0;
    
    }
  } 
    
   
     if(tik_tak[0] [1]== sign1  && tik_tak[1] [1]== sign1 )
  {
    if( tik_tak[2] [1]   == sign1 )
    {   
    cout<<"PLAYER 1 IS THE WINNER WITH="<<sign1<<" SIGN"<<endl;
    condition=true;
    result=0;
    
    }
  } 
     
   
     if(tik_tak[0] [2]== sign1  && tik_tak[1] [2]== sign1 )
  {
    if( tik_tak[2] [2]   == sign1 )
    {   
    cout<<"PLAYER 1 IS THE WINNER WITH="<<sign1<<" SIGN"<<endl;
    condition=true;
    result=0;
    
    }
  } 
     
 /*--------------------------------------------------------------------------------------------------------------------*/ 
   
   
    if(tik_tak[0] [0]== sign2  && tik_tak[1] [1]== sign2 )
  {
    if( tik_tak[2] [2]   == sign2 )
    {   
    cout<<"PLAYER 2 IS THE WINNER WITH="<<sign2<<" SIGN"<<endl;
    condition=true;
    result=0;
    
    }
  }

   
      if(tik_tak[0] [2]== sign2  && tik_tak[1] [1]== sign2 )
  {
    if( tik_tak[2] [0]   == sign2 )
    {   
    cout<<"PLAYER 2 IS THE WINNER WITH="<<sign2<<" SIGN"<<endl;
    condition=true;
    result=0;
    
    }
  } 
   
   
  
      if(tik_tak[0] [0]== sign2  && tik_tak[0] [1]== sign2 )
  {
    if( tik_tak[0] [2]   == sign2 )
    {   
    cout<<"PLAYER 2 IS THE WINNER WITH="<<sign2<<" SIGN"<<endl;
    condition=true;
    result=0;
    
    }
  } 
   
   
     if(tik_tak[1] [0]== sign2  && tik_tak[1] [1]== sign2 )
  {
    if( tik_tak[1] [2]   == sign2 )
    {   
    cout<<"PLAYER 2 IS THE WINNER WITH="<<sign2<<"  SIGN"<<endl;
    condition=true;
    result=0;
    
    }
  } 
    
      if(tik_tak[2] [0]== sign2  && tik_tak[2] [1]== sign2 )
  {
    if( tik_tak[2] [2]   == sign2 )
    {   
    cout<<"PLAYER 2 IS THE WINNER WITH="<<sign2<<" SIGN"<<endl;
    condition=true;
    result=0;
    
    }
  } 
   
   
     if(tik_tak[0] [0]== sign2  && tik_tak[1] [0]== sign2 )
  {
    if( tik_tak[2] [0]   == sign2 )
    {   
    cout<<"PLAYER 2 IS THE WINNER WITH="<<sign2<<" SIGN"<<endl;
    condition=true;
    result=0;
    
    }
  } 
    
   
     if(tik_tak[0] [1]== sign2  && tik_tak[1] [1]== sign2 )
  {
    if( tik_tak[2] [1]   == sign2 )
    {   
    cout<<"PLAYER 2 IS THE WINNER WITH="<<sign2<<" SIGN"<<endl;
    condition=true;
    result=0;
    
    }
  } 
     
   
     if(tik_tak[0] [2]== sign2  && tik_tak[1] [2]== sign2 )
  {
    if( tik_tak[2] [2]   == sign2 )
    {   
    cout<<"PLAYER 2 IS THE WINNER WITH="<<sign2<<" SIGN"<<endl;
    condition=true;
    result=0;
    
    }
  } 
   
    
  if( draw_condition==true &&  condition==false)
  {
    result=0;
    cout<<"GAME IS DRAW";
  }
 





}