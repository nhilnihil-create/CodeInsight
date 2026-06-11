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
int N;
vpint adj[2001];
int d[2001][2001],color[2001][2001];
int dnum[2001][2001]={};
void dijkstra(int st){
	priority_queue<pint> PQ;//辺の長さのオーバーフローに注意！
	rep(i,N){
		d[st][i]=INF;
		color[st][i]=0;
	}
	d[st][st]=0;
	color[st][st]=1;
	PQ.push(mp(0,st));
	while(!PQ.empty()){
		pint f=PQ.top();
		PQ.pop();
		int u=f.second;
		color[st][u]=2;
		if(d[st][u]< -f.first) continue;
		rep(j,adj[u].size()){
			int v=adj[u][j].first;
			if(color[st][v]==2) continue;
			if(d[st][v]>d[st][u]+adj[u][j].second){
				d[st][v]=d[st][u]+adj[u][j].second;
				PQ.push(mp(-d[st][v],v));
				color[st][v]=1;
			}
		}
	}
}
int main(){
	int K;
	scan(N>>K);
	rep(i,N-1){
		int a,b;
		scan(a>>b);
		a--; b--;
		adj[a].push_back({b,1});
		adj[b].push_back({a,1});
	}
	rep(i,N) dijkstra(i);
	if(K%2){
		int ans=INF;
		rep(i,N){
			rep(j,adj[i].size()){
				int overnum=0;
				int v=adj[i][j].first;
				rep(k,N){
					if(min(d[i][k],d[v][k])>(K-1)/2){
						overnum++;
					}
				}
				ans=min(ans,overnum);
			}
		}
		prin(ans);
	}
	else{
		int ans=INF;
		rep(i,N){
			int overnum=0;
			rep(k,N) if(d[i][k]>K/2) overnum++;
			ans=min(ans,overnum);
		}
		prin(ans);
	}
	return 0;
}
