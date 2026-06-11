#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<stack>
#define LL long long
using namespace std;
stack<int> b;
string a; 
int read()
{
	int _=0,__=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')__=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){_=_*10+ch-'0';ch=getchar();}
	return _*__;
}
int main()
{
	cin>>a;
	int x;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]=='S')
		x=1;
		else if(a[i]=='T')
		x=2;
		if(!b.empty()&&b.top()==1&&x==2)
		b.pop();
		else
		b.push(x);
	}
	printf("%d\n",b.size());
	return 0;
}
