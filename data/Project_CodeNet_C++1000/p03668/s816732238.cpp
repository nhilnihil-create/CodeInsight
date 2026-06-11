#include <bits/stdc++.h>
using namespace std;
const int N=300010;
vector<int>e[N]; int n,dp[N];
void dfs(int x,int fa){ for (int i=0;i<e[x].size();i++) if (e[x][i]!=fa){ dfs(e[x][i],x); dp[x]^=dp[e[x][i]]+1; } }
int main(){
	scanf("%d",&n); for (int i=1;i<n;i++){ int x,y; scanf("%d%d",&x,&y); e[x].push_back(y);e[y].push_back(x); }
	dfs(1,-1); printf("%s\n",dp[1]?"Alice":"Bob"); return 0;
}