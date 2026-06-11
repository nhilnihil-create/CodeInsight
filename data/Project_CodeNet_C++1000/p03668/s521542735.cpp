#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<string>
#include<stack>
#include<cstdio>
#include<cmath>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<int,P> P1;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define rep(i,x) for(int i=0;i<x;i++)
#define rep1(i,x) for(int i=1;i<=x;i++)
#define rrep(i,x) for(int i=x-1;i>=0;i--)
#define rrep1(i,x) for(int i=x;i>0;i--)
#define sor(v) sort(v.begin(),v.end())
#define rev(s) reverse(s.begin(),s.end())
#define lb(vec,a) lower_bound(vec.begin(),vec.end(),a)
#define ub(vec,a) upper_bound(vec.begin(),vec.end(),a)
#define uniq(vec) vec.erase(unique(vec.begin(),vec.end()),vec.end())
#define mp1(a,b,c) P1(a,P(b,c))

const int INF=1000000000;
const int dir_4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
const int dir_8[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};

struct Tree{
	int V;
	vector<int> G[100010];
	int dp[100010];
	int dfs(int v,int p){
		dp[v] = 0;
		for(int u: G[v]){
			if(u == p)continue;
			dp[v] ^= dfs(u,v);
		}
		return dp[v]+1;
	}
}tree;

int main(){
	static int n;
	static int x[100010],y[100010];
	scanf("%d",&n);
	rep1(i,n-1)scanf("%d%d",&x[i],&y[i]);
	
	tree.V = n;
	rep1(i,n-1){
		tree.G[x[i]].pb(y[i]);
		tree.G[y[i]].pb(x[i]);
	}
	tree.dfs(1,0);
	if(tree.dp[1] == 0)puts("Bob");
	else puts("Alice");
}

