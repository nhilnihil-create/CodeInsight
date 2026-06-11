#include<cstdio>
#include<iostream>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<sys/time.h>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
inline int ri()
{
	register int x=0;register bool f=0;register char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();};
	return f?-x:x;
}
void wi(int x)
{
	if(x<0)	x=-x,putchar('-');
	if(x>9)	wi(x/10);
	putchar('0'+x%10);
}
const int N=1e5+7;
int a[N];
int main()
{
	int n=ri(),i,last=0,ans=0;
	for(i=1;i<=n;i++)
	{
		a[i]=ri();
		if(a[i]==i)
		{
			if(!last)	last=i;
		}
		else
		{
			if(last)
			{
				ans+=(i-last+1)/2;
				last=0;
			}
		}
	}
	if(last)
	{
		ans+=(n-last+2)/2;
	}
	wi(ans);
	return 0;
}
