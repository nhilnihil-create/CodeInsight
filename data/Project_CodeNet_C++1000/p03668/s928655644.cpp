#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<deque>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<stdlib.h>
#include<cassert>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
const long long d2=500000004;
const double EPS=1e-6;
const double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
int dp[110000];
vector<int>g[110000];
int dfs(int a,int b){
	for(int i=0;i<g[a].size();i++){
		if(b==g[a][i])continue;
		dfs(g[a][i],a);
	}
	int t=0;
	for(int i=0;i<g[a].size();i++){
		if(b==g[a][i])continue;
		t^=(dp[g[a][i]]+1);
	}
	return dp[a]=t;
}
int main(){
	int a;scanf("%d",&a);
	for(int i=0;i<a-1;i++){
		int p,q;scanf("%d%d",&p,&q);p--;q--;
		g[p].push_back(q);
		g[q].push_back(p);
	}
	int ret=dfs(0,-1);
	if(ret)printf("Alice\n");
	else printf("Bob\n");
}