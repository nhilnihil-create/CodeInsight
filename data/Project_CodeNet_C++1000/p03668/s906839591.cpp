#include <bits/stdc++.h>
#define MOD 100000007LL
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

int n;
vector<int> G[100001];
int dp[100001];
bool used[100001];
int cnt[100001];

int dfs(int v,int p){
	int res=0;
	for(int i=0;i<G[v].size();i++){
		if(G[v][i]!=p){
			res^=(dfs(G[v][i],v)+1);
		}
	}
	return res;
}

int main(void){
	scanf("%d",&n);
	for(int i=0;i<n-1;i++){
		int f,t;
		scanf("%d%d",&f,&t);
		f--;
		t--;
		G[f].push_back(t);
		G[t].push_back(f);
	}
	memset(dp,-1,sizeof(dp));
	memset(used,false,sizeof(used));
	printf("%s\n",dfs(0,-1)!=0?"Alice":"Bob");
	return 0;
}