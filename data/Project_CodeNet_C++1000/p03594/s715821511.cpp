#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
inline int read()
{
	int neg=1,num=0;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')neg=-1;
	for(;isdigit(c);c=getchar())num=(num<<1)+(num<<3)+c-'0';
	return neg*num;
}
int n,m,d;
string str;
char c[505][505];
int main()
{
	n=read();m=read();d=read();
	str="RYGB";
	for(int i=0;i<=n-1;i++,putchar('\n'))
		for(int j=0;j<=m-1;j++)
		{
			int x=i+j+m;
			int y=i-j+m;
			putchar(str[((x/d)&1)*2+((y/d)&1)]);
		}
	return 0;
}
