#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100005

int n ,k;
vector <int> adj[MAX_N];

int ans = 0;
int dfs(int u ,int p=1){
	int mx = 0;
	for(int v : adj[u]) 
		mx = max(mx ,dfs(v ,u));
	//cout << u << " = " << mx << endl;
	if(mx+1 == k && p != 1){
		ans++;
		return -1;
	}
	return mx+1;
}

int main()
{
	scanf("%d%d",&n,&k);
	for(int p,i=1; i<=n; i++){
		scanf("%d",&p);
		if(i == 1)
			ans += (p != 1);
		else
			adj[p].push_back(i);
	}
	
	dfs(1);
	printf("%d\n",ans);
}
