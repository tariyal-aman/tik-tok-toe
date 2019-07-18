#include<iostream>
#include<unistd.h>
using namespace::std;
int input(int ar[3][3])
{
	int z,k=0,l=0;;
	cin>>z;
	int i,j;
	
	
		
		if(z==0||z==1)
		k=501;
		else 
		{
		for(i=0;i<3;++i)
		for(j=0;j<3;++j)
		if(z==ar[i][j])
		{
		l=90;
		break;
		}
		}
		if(l==90)
		k=101;
		else k=501;
		int a=z;;
		if(k==501)
		{
		puts("You have entered a worng number,please enter that place which is not occupied by anyone or which exist in game\n");
		a=input(ar);
		}
		return a;
		
	}
void printstrt()
{
	puts("\t\t\tITS  TIC-TAC-TOE");
	puts("Tic-Tac-Toe is a game for two players,X and 0 ,who take turns marking \nthe spaces in a 3X3 grid.The player who succedes in placing three of their\nmarks in a horizontal,vertical, or diagonal row wins the game or you can play it with dAnGeR(system) also\n");
}
int win(int ar[3][3],int z)
{
	int i,j,a=0;
	for(j=0;j<3;++j)
	if(ar[j][a]==z&&ar[j][a+1]==z&&ar[j][a+2]==z)	
		return 101;
	for(j=0;j<3;++j)
	if(ar[a][j]==z&&ar[a+1][j]==z&&ar[a+2][j]==z)
		return 101;
	if(ar[0][0]==z&&ar[1][1]==z&&ar[2][2]==z)
	return 101;
	j=0;
	a=2;
	if(ar[j][a]==z&&ar[j+1][a-1]==z&&ar[j+2][a-2]==z)
	return 101;
	return 501;
		
		
}
void oneg(int ar[3][3],int z)
{
	int i,j;
	for(i=0;i<3;++i)
	for(j=0;j<3;++j)
	if(ar[i][j]==z)
	 ar[i][j]=0;
}
void twog(int ar[3][3],int z)
{
	int i,j;
	for(i=0;i<3;++i)
	for(j=0;j<3;++j)
	if(ar[i][j]==z)
	 ar[i][j]=1;
	

}
void printgame(int ar[3][3])
{
system("CLS");
printstrt();
	int i,j;
	for(i=0;i<3;++i)
	{
		for(j=0;j<3;++j)
		{
			if(ar[i][j]==0)
			cout<<"0"<<"  ";
			else if(ar[i][j]==1)
			cout<<"X"<<"  ";
			else
			cout<<ar[i][j]<<"  ";
		}
			cout<<"\n";
	}
cout<<"\n";
}
void nameinput(char br[100],char cr[100])
{
	cin.ignore();
	puts("player 1\n\t ENTER YOUR NAME\n");
	gets(br);
	puts("player 2\n\tENTER YOUR NAME\n");
	gets(cr);
	cout<<"player 1-"<<br<<" your mark is 0\n";
	cout<<"player 2-"<<cr<<" your mark is X\n";
}
void player(int ar[3][3])
{
char br[100],cr[100];
nameinput(br,cr);
int z,a,k=2,q;
for(a=0;a<9;++a)
{
printgame(ar);
if(k%2==0)
cout<<"It's "<<br<<"'s turn\n";
else
cout<<"It's "<<cr<<"'s turn\n";
z=input(ar);
if(k%2==0)
{
	oneg(ar,z);
}
else
{
	twog(ar,z);
}
if(a>=4)
{
	q=win(ar,k%2);
	if(q==101)
	{
		printgame(ar);
		cout<<"winner is ' ";
		if(k%2==0)
		cout<<br<<" '\n";
		else
		cout<<cr<<" '\n";
		
		cout<<"\n\t\tGAME OVER";
		break;
	}
	
}
if(a==8)
{
puts("game over!!");
puts("Its tie!! try again!!");
}
++k;
}
}
int aichk(int z,int ar[3][3])
{
	int i,j,k;
	if(z==0||z==1)
		return 501;
		else 
		{
		for(i=0;i<3;++i)
		for(j=0;j<3;++j)
			if(z==ar[i][j])
				return 101;
		}

}
int aick(int ar[3][3],int m,int &x,int &y)
{
	int i,j,k,t=m%2,br[3][3],q;
		
		for(i=0;i<3;++i)
		for(j=0;j<3;++j)
			br[i][j]=ar[i][j];
			
		for(i=0;i<3;++i)
		{
		for(j=0;j<3;++j)
			{
				if(br[i][j]!=0&&br[i][j]!=1)
				{
					q=br[i][j];
						br[i][j]=t;
						k=win(br,t);
						if(k==101)
						{
							x=i;
							y=j;
							return 101;
						}
						else
						br[i][j]=q;
						}
				}	

}
return 501;
}
void aismt(int ar[3][3],int m)
{
	int i,j,k,z=555,p=101,x=0,y=0;
		for(i=0;i<3;++i)
		{
		
		for(j=0;j<3;++j)
			if(ar[i][j]==1)
			{
			p=501;
			break;
			}
		if(p==501)
		break;	
		}
		int w=aick(ar,m+1,x,y);
		if(w==101)
		{
			twog(ar,ar[x][y]);
			
		}
		else
		{
		
	  if(i==0&&j==0)
		{
			k=aichk(3,ar);
			if(k==101)
			{
				z=aichk(4,ar);
				if(z==101)
				{
				k=99;	
				twog(ar,3);
				}
				else
				k=501;
			}
				
			 if(k==501)
			{
				k=aichk(5,ar);
			}
			else if(k==101)
			{
				z=aichk(8,ar);
				if(z==101)
				{
					k=99;
					twog(ar,5);
				
				}
				else
				k=501;
			}
			if(k==501)
			k=aichk(6,ar);
			if(k==101)
			twog(ar,6);
		}
	else if(i==2&&j==0)
	{
		
			k=aichk(5,ar);
			if(k==101)
			{
				z=aichk(2,ar);
				if(z==101)
				{
				twog(ar,5);
				k=55;
				}	
				else
				k=501;
			}
			if(k==501)
			k=aichk(9,ar);
			if(k==101)
			{
				z=aichk(10,ar);
				if(z==101)
				{
				k=55;
				twog(ar,9);
				}
				else
				k=501;
			}
			 if(k==501)
			k=aichk(6,ar);
			if(k==101)
			twog(ar,6);
	}
}
}
void ai2smt(int ar[3][3],int m)
{
	int i,j,k,p=501,l,q,x,y;
	
		int w=aick(ar,m,x,y);
		if(w==101)
		{
			twog(ar,ar[x][y]);
			
		}
		else 
		{
			w=aick(ar,m+1,x,y);
			if(w==101)
			twog(ar,ar[x][y]);
			else
			{
														
					for(i=0;i<3;++i)
							{
								for(j=0;j<3;++j)
								{
									if(ar[i][j]!=0&&ar[i][j]!=1)
										{
											twog(ar,ar[i][j]);
											p=101;
											break;
										}
								}
								if(p==101)
								break;
							}
				}
		}
	
}
void ali2(int ar[3][3])
{
	int i,j,k,p;
	if(ar[1][1]==0)
	{
		twog(ar,10);
	}
	else
	twog(ar,6);	
}
void ali3(int ar[3][3],int m)
{
	int x,y;
		int w=aick(ar,m,x,y);
		if(w==101)
		{
			
		}
		else
		{
		int w=aick(ar,m+1,x,y);
		if(w==101)
		{
			twog(ar,ar[x][y]);
			
		}
		else
		{
			if(ar[1][1]==1)
		    {	
		    	if(aichk(2,ar)==101)
		    		twog(ar,2);
		    	else
		    	twog(ar,7);
			}
			else
			{
				if(aichk(8,ar)==101)
				twog(ar,8);
				else
				twog(ar,7);
			}
		
		}
}
}
void lev2(char arr[1000])
{
	system("cls");
	int i,j,p,x=0,y,a,z=2,m=2;
	int ar[3][3];
	printstrt();
	for(i=0;i<3;++i)
		for(j=0;j<3;++j)
			{
				ar[i][j]=z;
				++z;
			}
			for(a=0;a<9;++a)
			{
			printgame(ar);
			if(a==0)
	puts("\t\t\tLEVEL II");
			if(m%2==0)
			{
				cout<<"its "<<arr<<"'s turn\n";
				z=input(ar);
				oneg(ar,z);
			}
			else
			{
				cout<<"its dAnGeR's (system) turn\n";
				sleep(1);
				if(x==0)
			ali2(ar);
			else if(x==1)
			ali3(ar,m);
			else
			ai2smt(ar,m);
			++x;
			}
			int q;
		if(a>=4)
		{
				q=win(ar,m%2);
				cout<<"hi";
				if(q==101)
					{
					printgame(ar);
					if(m%2==0)
						{
							cout<<"this time Winner is "<<arr<<"\n you r really champion..!!\n";
									//lev2(arr);
						}
									else
										cout<<"winner is dAnGeR...";
							break;
					}
			
		
				
		}
			++m;
			
			}
}
void system(int ar[3][3])
{
	int t=1,z,m,a,q=0,k=0,az=0;
	//cin>>t;
	puts("there are two levels ,first one is level 1 which is for begginers and second one is level 2 which is for experts...");
	puts("if u will make System(dAnGeR) lose..then u will get to play level two...");
	puts("\t\t\t LEVEL 1");
	if(t==1)
	m=2;
	else 
	m=1;
	puts("please enter your name");
	char arr[1000];
	cin.ignore();
	gets(arr);
for(a=0;a<9;++a)
{

	printgame(ar);
	if(m%2==0)
	{
		cout<<"its "<<arr<<"'s turn\n";
		z=input(ar);	
		oneg(ar,z);
	}
	else
	{
		puts("its system's turn");
		sleep(1);
		if(a==0||a==1)
		{
			int y=aichk(2,ar);
			if(y==101)
			twog(ar,2);
			else
			twog(ar,8);
		}
		else
		{	if(az==1)
			aismt(ar,m);
			else if(az==2)
			ai2smt(ar,m);
			else
			ai2smt(ar,m);
		}
			++az;
		}
if(a>=4)
{
	q=win(ar,m%2);
	if(q==101)
	{
		printgame(ar);
		if(m%2==0)
		{
		cout<<"this time Winner is "<<arr<<". see u in second round!!\n";
		sleep(3);
		lev2(arr);
		}
		else
		cout<<"winner is dAnGeR...";
		cout<<"\n\t\tGAME OVER";
		break;
		}
}
++m;
if(a==8)
{
puts("game over!!");
puts("Its tie!! try again!!");
}
}
}
void virmain()
{
	
int m=2,i,j,ar[3][3];
for(i=0;i<3;++i)
{
	for(j=0;j<3;++j)
{
	  	  ar[i][j]=m;
	  	  ++m;
}
}
printstrt();
puts("enter your choice:\n1.With System(dAnGeR)\n2.With your freind");
int t;
cin>>t;
if(t==2)
player(ar);
else if(t==1)
system(ar);
else
puts("wrong choice baby!!");

}
int main()
{
	virmain();
puts("\n\nif u want to play it again then press 1 otherwise press any key");
int y=1;
while(y==1)
{

cin>>y;
if(y==1)
{
system("cls");
virmain();

}
}
cout<<"Fattu kahi ka!!!\n\n";

system("pause");
}
