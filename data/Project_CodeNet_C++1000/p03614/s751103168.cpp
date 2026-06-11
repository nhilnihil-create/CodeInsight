#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#include<bitset>
#include<map>
using namespace std;
template<typename __T>
inline void read(__T &x)
{
    x=0;
    int f=1;char c=getchar();
    while(!isdigit(c)){if(c=='-')	f=-1;c=getchar();}
    while(isdigit(c))	{x=x*10+c-'0';c=getchar();}
    x*=f;
}
int n;
int x;
int ans=0;
int tmp=0;
int main()
{
	read(n);
	for(int i=1;i<=n;i++)
	{
		read(x);
		if(x==i)
			tmp++;
		else
		{
			ans+=(tmp+1)/2;
			tmp=0;
		}
	}
	ans+=(tmp+1)/2;
	cout<<ans<<endl;
	return 0;
}
