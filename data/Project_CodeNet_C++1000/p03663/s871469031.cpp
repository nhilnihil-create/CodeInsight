#include<iostream>
using namespace std;
main()
{
	long fix=0;
	for(int i=0;i<9;i++)
	{
		int L=0,R=10;
		while(R-L>1)
		{
			int M=L+R>>1;
			long now=fix*10+M;
			cout<<"? "<<now*1000000000<<endl;
			char ans;cin>>ans;
			if(ans=='Y')R=M;
			else L=M;
		}
		fix=fix*10+L;
	}
	fix++;
	while(fix%10==0)fix/=10;
	long now=fix;
	bool flag=true;
	while(now)flag&=now%10==9,now/=10;
	cout<<"? "<<fix+1<<endl;
	char ans;cin>>ans;
	if(ans==(flag?'Y':'N'))
	{
		while(true)
		{
			cout<<"? "<<fix<<1<<endl;
			cin>>ans;
			fix*=10;
			if(ans=='Y')break;
		}
	}
	cout<<"! "<<fix<<endl;
}