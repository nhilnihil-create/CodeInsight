#include<bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N=2e5+5;
int n,k,x[N],y[N];
ll tree[N],ans;
inline int lowbit(int x){return x&(-x);}
void update(int x){for(;x<=n;x+=lowbit(x))tree[x]++;}
int ask(int x){int res=0;for(;x;x-=lowbit(x))res+=tree[x];return res;}
signed main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>x[i],x[i]-=k;
	for(int i=1;i<=n;i++)x[i]+=x[i-1],y[i]=x[i],ans+=(x[i]>=0);
	sort(y+1,y+n+1);
	for(int i=1;i<=n;i++)x[i]=lower_bound(y+1,y+n+1,x[i])-y;
	for(int i=1;i<=n;i++)ans+=ask(x[i]),update(x[i]);
	cout<<ans<<"\n";
	return 0;
}