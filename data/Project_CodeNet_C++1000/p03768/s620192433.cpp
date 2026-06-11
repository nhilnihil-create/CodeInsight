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

int n;
vector<int> G[100010];
int ret[100010];
int max_d[100010];
void dfs(int v,int d,int c){
	if(max_d[v] >= d)return;
	max_d[v] = d;
	if(ret[v] == 0)ret[v] = c;
	for(int u: G[v]){
		dfs(u,d-1,c);
	}
}

int main(){
	int m;
	int a[100010],b[100010];
	scanf("%d%d",&n,&m);
	rep1(i,m){
		scanf("%d%d",&a[i],&b[i]);
		G[a[i]].pb(b[i]);
		G[b[i]].pb(a[i]);
	}
	int q;
	int v[100010],d[100010],c[100010];
	scanf("%d",&q);
	rep1(i,q){
		scanf("%d%d%d",&v[i],&d[i],&c[i]);
	}
	
	rep1(i,n){
		ret[i] = 0;
		max_d[i] = -1;
	}
	rrep1(i,q){
		dfs(v[i],d[i],c[i]);
	}
	rep1(i,n){
		printf("%d\n",ret[i]);
	}
}