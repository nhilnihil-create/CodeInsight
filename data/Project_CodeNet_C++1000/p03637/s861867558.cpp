#include<iostream>
#include<string>
using namespace std;
int d,t,n,s;

int main()
{
	d=0;t=0;cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s;
		if(s%4==0)t++;
		else if(s%2==0)d++;
	}
	if(2*t+d>=n)cout<<"Yes";
	else if(d==0&&2*t+1>=n)cout<<"Yes";
	else cout<<"No";
}