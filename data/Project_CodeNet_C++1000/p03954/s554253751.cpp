// luogu-judger-enable-o2
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
inline int read()
{
	int r,s=0,c;
	for(;!isdigit(c=getchar());s=c);
	for(r=c^48;isdigit(c=getchar());(r*=10)+=c^48);
	return s^45?r:-r;
}
const int N=200010;
int m,n;
int a[N],b[N];
bool check(int mid)
{
	for(int i=1;i<=n;i++)
		b[i]=(a[i]>=mid);
//.....00.....
// ....00.....
//所以距离中间最近的相邻元素相同的那个数
//若原序列为010101010
	int l=m,r=m;
	while(l>1)
	{
		if(b[l]==b[l-1])return b[l];
		if(b[r]==b[r+1])return b[r];
		l--,r++;
	}
	return b[1];
}
int main()
{
	m=read();
	n=m*2-1;
	for(int i=1;i<=n;i++)a[i]=read();
	int l,r,mid,ans;
	l=1,r=n;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(check(mid))
		{
			l=mid+1;
			ans=mid;
		}
		else
			r=mid-1;
	}	
	printf("%d\n",ans);
	return 0;
}/*
4
7 3 2 1 5 4 6
4
3 1 5 6 4 2 7 
*/