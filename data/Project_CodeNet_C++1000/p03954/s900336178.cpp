#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
template <class T>
inline void read(T &x)
{
	x=0; char c=getchar(); int f=1;
	while(!isdigit(c)){if(c=='-')f=-1; c=getchar();}
	while(isdigit(c)) x=x*10-'0'+c,c=getchar(); x*=f;
}
const int N=2e5+10;
int a[N],b[N],n;
bool che(int x)
{
	for(int i=1;i<=n;++i) b[i]=a[i]>=x;
//	for(int i=1;i<=n;++i) cout<<b[i]<<' '; cout<<endl;
	int l=(n+1)/2,r=l;
	while(l>1)
	{
		if(b[l-1]==b[l]) return b[l];
		if(b[r+1]==b[r]) return b[r];
		l--,r++;
	}
	return b[1];
}
int main()
{
	read(n),n=n*2-1;
	for(int i=1;i<=n;++i) read(a[i]);
	int lb=1,rb=n,ans;
	while(lb<=rb)
	{
		int mid=lb+rb>>1;
		if(che(mid)) ans=mid,lb=mid+1;
		else rb=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}