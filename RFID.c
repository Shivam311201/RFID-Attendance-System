#include<reg52.h>							 //including sfr registers for ports of the controller
#include<LCD.h>
void check();

unsigned char tag1[12]={"8234HEY34GH8"};
unsigned char emp1[]={"SHIVAM GARG"};
unsigned char tag2[12]={"2948GFH34IR4"};
unsigned char emp2[]={"SHAURYA WADEHRA"};
unsigned char tag3[12]={"3847DFJI45GK"};
unsigned char emp3[]={"ASHISH GIRDHAR"};
unsigned char attendance[3]={"000"};
unsigned char a[12],x;

//LCD Module Connections
sbit RS = P0^0;                                                                   
sbit EN = P0^1;                            
sbit D0 = P2^0;
sbit D1 = P2^1;
sbit D2 = P2^2;
sbit D3 = P2^3;
sbit D4 = P2^4;
sbit D5 = P2^5;
sbit D6 = P2^6;
sbit D7 = P2^7;
//End LCD Module Connections

void Delay(int a)
{	
    int j;
    int i;
    for(i=0;i<a;i++)
    {
        for(j=0;j<100;j++)
        {
        }
    }
}

void main()
{
	SCON=0X50;
	TMOD=0X20;
	TH1=-3;
	TR1=1;
	Lcd8_init();                                  
  while(1)
  {   
		Lcd8_Set_Cursor(1,1);
	  Lcd8_Write_String("Hello Everyone");		
		for(x=0;x<12;x++)
		{
		while(RI==0);
		a[x]=SBUF;
		SBUF=a[x];
		while(TI==0);
		RI=0;
		TI=0;
		}
		Lcd8_Clear();
		check();
	}
}
void check()
{
		int i;
		if((a[0]=='8')&&(a[1]='2')&&(a[2]=='3')&&(a[3]='4')&&(a[4]=='H')&&(a[5]='E')&&(a[6]=='Y')&&(a[7]='3')&&(a[8]=='4')&&(a[9]='G')&&(a[10]=='H')&&(a[11]='8'))
	{
		if(attendance[0]=='0'){
			Lcd8_Write_String("SHIVAM GARG");
			attendance[0]='1';
			for(i=0;i<7;i++)
			{
		  Delay(500);
			Lcd8_Shift_Left();
			}
			for(i=0;i<7;i++)
			{
			Delay(500);
			Lcd8_Shift_Right();
			}
		}
		else Lcd8_Write_String("Already Marked");
		Delay(2000);
		Lcd8_Clear();
	}
	else if((a[0]=='2')&&(a[1]='9')&&(a[2]=='4')&&(a[3]='8')&&(a[4]=='G')&&(a[5]='F')&&(a[6]=='H')&&(a[7]='3')&&(a[8]=='4')&&(a[9]='I')&&(a[10]=='R')&&(a[11]='4'))
	{
		if(attendance[1]=='0'){
		Lcd8_Write_String("SHAURYA WADEHRA");
			attendance[1]='1';
		for(i=0;i<7;i++)
		{
		  Delay(500);
			Lcd8_Shift_Left();
		}
		for(i=0;i<7;i++)
		{
			Delay(500);
			Lcd8_Shift_Right();
		}
	} else Lcd8_Write_String("Already Marked");
		Delay(2000);
		Lcd8_Clear();
	}
	else if((a[0]=='3')&&(a[1]='8')&&(a[2]=='4')&&(a[3]='7')&&(a[4]=='D')&&(a[5]='F')&&(a[6]=='J')&&(a[7]='I')&&(a[8]=='4')&&(a[9]='5')&&(a[10]=='G')&&(a[11]='K'))
	{   
		if(attendance[2]=='0'){
		Lcd8_Write_String("ASHISH GIRDHAR");
						attendance[2]='1';
		for(i=0;i<7;i++)
		{
		  Delay(500);
			Lcd8_Shift_Left();
		}
		for(i=0;i<7;i++)
		{
			Delay(500);
			Lcd8_Shift_Right();
		}
	}else Lcd8_Write_String("Already Marked");
		Delay(2000);
		Lcd8_Clear();
	}
	else {
		Lcd8_Write_String("USER NOT FOUND");
		for(i=0;i<7;i++)
		{
		  Delay(500);
			Lcd8_Shift_Left();
		}
		for(i=0;i<7;i++)
		{
			Delay(500);
			Lcd8_Shift_Right();
		}
		Delay(1000);
		Lcd8_Clear();
	}
}

