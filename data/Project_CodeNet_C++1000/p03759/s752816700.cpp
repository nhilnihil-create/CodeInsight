#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x=0;
	char ch=getchar();
	bool f=0;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			f=1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	if(f==0)
		return x;
	return ~(x-1);
}
int main()
{
	int a,b,c;
	a=read();
	b=read();
	c=read();
	if(b-a==c-b)
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}