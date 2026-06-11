#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmin(T&x,const T &y)
{
	if(x>y)x=y;
}
template <typename T> void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}
typedef long long s64;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef pair<int,int> pii;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define rep0(i,l,r) for(int i=l;i<r;++i)
#define gc (c=getchar())
int read()
{
	char c;
	while(gc<'-');
	if(c=='-')
	{
		int x=gc-'0';
		while(gc>='0')x=x*10+c-'0';
		return -x;
	}
	int x=c-'0';
	while(gc>='0')x=x*10+c-'0';
	return x;
}
#undef gc

const int N=1e5+5;
int a[N],w[N],b[N],c[N],ans[N];

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n,l,t;
	cin>>n>>l>>t;
	rep(i,1,n){a[i]=read();w[i]=read();}
	rep(i,1,n)b[i]=((a[i]+((w[i]==1)?t:-t))%l+l)%l;
	rep(i,1,n)c[i]=b[i];
	sort(c+1,c+n+1);
	int dy1=0;
	if(w[1]==1)
	{
		s64 c=0;
		rep(i,1,n)
		if(w[i]==2)c+=((s64)2*t+(l-(a[i]-a[1]))-1)/l;
		dy1=c%n+1;
	}
	else
	{
		s64 c=0;
		rep(i,1,n)
		if(w[i]==1)c+=((s64)2*t+(a[i]-a[1]))/l;
		dy1=(-c%n+n)%n+1;
	}
	int p=lower_bound(c+1,c+n+1,b[1])-c;
	rep(i,0,n-1)ans[(dy1+i)%n+1]=c[(p+i)%n+1];
	rep(i,1,n)printf("%d\n",ans[i]);
}

