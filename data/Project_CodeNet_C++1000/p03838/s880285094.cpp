#include<bits/stdc++.h>
using namespace std;
long long a,b,ans;
int main()
{
	cin>>a>>b;
	if(a==0||b==0)
	{
		if(a>b)
		{
			cout<<abs(a-b)+1<<endl;
			exit(0);
		}
		cout<<abs(a-b)<<endl;
		exit(0);
	}
	if(a>0&&b>0)
	{
		if(a<b)//a>b
		cout<<abs(a-b)<<endl;
		else
		cout<<abs(a-b)+2<<endl;
	}
	if(a>0&&b<0||a<0&&b>0)cout<<abs(abs(a)-abs(b))+1<<endl;
	if(a<0&&b<0)
	{
		if(a==b)cout<<0<<endl;
		if(a>b)cout<<abs(abs(a)-abs(b))+2<<endl;
		if(a<b)cout<<abs(abs(a)-abs(b))<<endl;
	}
}