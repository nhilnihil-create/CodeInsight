#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef pair<int,int>P;

int a[200000];
P h[200000];
vector<int>E[200000];
bool used[200000];

void dfs(int v){
	for(auto u:E[v]){
		h[u].first=h[v].first+1;
		dfs(u);
	}
}
void dfs2(int v){
	used[v]=true;
	for(auto u:E[v]){
		if(used[u])continue;
		dfs2(u);
	}
}
int main(){
	int n,k;scanf("%d%d",&n,&k);
	int ans=0;
	rep(i,n){
		scanf("%d",&a[i]);a[i]--;
		if(i==0){
			if(a[i]!=i)ans++;
			a[i]=0;
		}
		else E[a[i]].push_back(i);
		h[i].second=i;
	}
	dfs(0);
	sort(h,h+n,greater<>());
	rep(i,n){
		if(used[h[i].second])continue;
		int v=h[i].second;
		rep(j,k-1){
			v=a[v];
			if(a[v]==0)break;
		}
		if(a[v]==0)break;
		ans++;dfs2(v);
	}
	cout<<ans<<endl;
}