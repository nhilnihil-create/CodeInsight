#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<map>
#include<iomanip>
#include<set>
#include<bitset>
#define rep(index,num) for(int index=0;index<num;index++)
#define rep1(index,num) for(int index=1;index<=num;index++)
#define brep(index,num) for(int index=num-1;index>=0;index--)
#define brep1(index,num) for(int index=num;index>0;index--)
#define scan(argument) cin>>argument
#define prin(argument) cout<<argument<<endl
#define kaigyo cout<<endl
#define eps 1e-7
#define mp(a1,a2) make_pair(a1,a2)
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef long double ld;
using namespace std;
typedef pair<ll,ll> pll;
typedef pair<int,int> pint;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<pint> vpint;
typedef vector<pll> vpll;
ll INFl=1e+18+1;
int INF=1e+9+1;
vint adj[100001];
int p[100001];
bool visited[100001]={};
vint ko[100001];
int depthmax=0;
vint edgedepth[100001];
void dfs(int u,int depth){
	visited[u]=1;
	edgedepth[depth].push_back(u);
	depthmax=max(depthmax,depth);
	int flag=0;
	rep(i,adj[u].size()){
		int v=adj[u][i];
		if(visited[v]==0){
			flag=1;
			p[v]=u;
			ko[u].push_back(v);
			dfs(v,depth+1);
		}
	}
}
int main(){
	int N;
	int a[100001],b[100001];
	scan(N);
	rep(i,N-1){
		scan(a[i]>>b[i]);
		a[i]--; b[i]--;
		adj[a[i]].push_back(b[i]);
		adj[b[i]].push_back(a[i]);
	}
	p[0]=-1;
	dfs(0,0);
	int grundy[100001];
	brep(d,depthmax+1){
		rep(i,edgedepth[d].size()){
			int v=edgedepth[d][i];
			grundy[v]=0;
			rep(j,ko[v].size()){
				int u=ko[v][j];
				grundy[v]^=(grundy[u]+1);
			}
		}
	}
	if(grundy[0]==0) prin("Bob");
	else prin("Alice");
	return 0;
}
