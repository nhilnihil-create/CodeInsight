#include<cstdio>
#include<iostream>
#include<cstring>
#define RG register
using namespace std;
const int N=2e5+10;
int n,m,a[N],ans,b[N];
template<typename I> inline void read(I &ot){
	I ch=getchar(), x=0, f=1;
	while(ch<'0' || ch>'9'){if(ch=='-') f=-1; ch=getchar();	}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0'; ch=getchar();	}
	ot=x*f;}
template<typename I, typename... U> inline void read(I &x,U&... y){read(x); read(y...);}
inline bool chck(int x)
{
	for(RG int i=1;i<=m;i++) b[i]= a[i]>=x;
	for(RG int i=0;i<n;i++)
	 if(b[n-i]==b[n-i-1]) return b[n-i];
	 else if(b[n+i]==b[n+i+1]) return b[n+i];
	return b[1];
}
int main()
{
//	freopen("Median Pyramid Hard.in","r",stdin);
	read(n); m=n*2-1;
	for(RG int i=1;i<=m;i++) read(a[i]);
	int l=1, r=m;
	while(l<=r)
	{
		int mid=l+(r-l)/2;
		if(chck(mid)) ans=mid, l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}