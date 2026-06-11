#include<cmath>
#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define rep(i,x,y) for(int i=x;i<=y;++i)

const int INF=1<<30;
using namespace std;

const int maxn=100000+10;
typedef long long ll;

ll h[maxn],t[maxn];

priority_queue<int>pq;

int n;ll a,b;
int check(int ans)
{
	int c=0;
	rep(i,1,n) {
		t[i]=max(h[i]-1ll*ans*b,0ll);
		if(t[i]>0) c+=(int)ceil(t[i]/1.0/(a-b));
		if(c>ans) return 0;
	}
	return 1;
}

int main()
{
	cin>>n>>a>>b;

	int M=0;
	rep(i,1,n) scanf("%lld",h+i),M=max(M,(int)(h[i]/b+1));
	int l=1,r=M,ans,mid;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(check(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<ans<<endl;
	return 0;
}
