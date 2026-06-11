#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}
#define rep(i,l,r) for(int i=l;i<=r;++i)
const int N=1e5+5;
int a[N],mxd[N],k;vector<int>lk[N];
int ans;

void dfs(int x)
{
	mxd[x]=1;
	for(auto y:lk[x])
	{
		dfs(y);
		chmax(mxd[x],mxd[y]+1);
	}
	if(a[x]!=1&&mxd[x]==k)
	{
		++ans;
		mxd[x]=0;
	}
}

int main()
{
	//freopen("1.in","r",stdin);
	int n;cin>>n>>k;
	rep(i,1,n)scanf("%d",a+i);
	ans=a[1]!=1;
	a[1]=1;
	rep(i,2,n)lk[a[i]].push_back(i);
	dfs(1);
	cout<<ans;
}