#include<bits/stdc++.h>
#define pb push_back

using namespace std;
typedef long long ll;

const int N=100005;

int n,a[N],m;
vector<int>e[N];

ll dfs(int x,int fa){
	ll r=a[x];
	if(e[x].size()>1)r+=a[x];
	for(int v:e[x])if(v!=fa){
		ll c=dfs(v,x);
		if(c>a[x])puts("NO"),exit(0);
		r-=c;
	}
	if(r<0||r>a[x])puts("NO"),exit(0);
	return r;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(n==2){
		if(a[1]==a[2])puts("YES");else puts("NO");
		exit(0);
	}
	for(int i=1,u,v;i<n;i++)scanf("%d%d",&u,&v),e[u].pb(v),e[v].pb(u);
	for(int i=1;i<=n;i++)if(e[i].size()>1)m=i;
	if(dfs(m,0))puts("NO");else puts("YES");
	return 0;
}