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
#include<tuple>
#include<bitset>
#include<iomanip>
#define rep(index,num) for(int index=0;index<num;index++)
#define rep1(index,num) for(int index=1;index<=num;index++)
#define scan(argument) cin>>argument
#define prin(argument) cout<<argument<<endl
#define kaigyo cout<<endl
#define eps 1e-15
#define mp(a1,a2) make_pair(a1,a2)
typedef long long ll;
using namespace std;
typedef pair<ll,ll> pll;
typedef pair<int,int> pint;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<pint> vpint;
typedef vector<pll> vpll;
ll INFl=1e+18+1;
int INF=1e+9+1;
int main(){
	int N,M,Q;
	vint adj[100001];
	int v[100001],d[100001],c[100001];
	scan(N);scan(M);
	rep(i,M){
		int a,b;
		scan(a);scan(b);
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	scan(Q);
	rep(q,Q){
		scan(v[q]);scan(d[q]);scan(c[q]);
		v[q]--;
	}
	int color[100001];
	fill(color,color+N,-1);
	rep(t,11){
		int colorb[100001];
		rep(i,N) colorb[i]=color[i];
		rep(u,N){
			rep(j,adj[u].size()){
				int u2=adj[u][j];
				colorb[u2]=max(colorb[u2],color[u]);
			}
		}
		rep(i,N) color[i]=colorb[i];
		rep(q,Q){
			if(d[q]+t==10){
				color[v[q]]=max(color[v[q]],q);
			}
		}
	}
	rep(u,N){
		if(color[u]==-1) prin(0);
		else prin(c[color[u]]);
	}
	return 0;
}
