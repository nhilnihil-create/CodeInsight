#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

#define pb push_back
#define fr first
#define sc second

static ll N;
static vector<P> G[100010];

static P par[100010];
vector<ll> vs;
void dfs(ll v,P p){
	par[v] = p;
	for(int i = 0 ; i < G[v].size() ; i ++){
		if(G[v][i] == p)continue;
		dfs(G[v][i].sc,P(G[v][i].fr,v));
	}
	vs.pb(v);
}

int main(){
	static ll A[100010];
	static ll a[100010],b[100010];
	scanf("%d",&N);
	for(int i = 1 ; i <= N ; i ++){
		scanf("%lld",&A[i]);
	}
	for(int i = 1 ; i <= N-1 ; i ++){
		scanf("%lld%lld",&a[i],&b[i]);
	}
	
	for(int i = 1 ; i <= N-1 ; i ++){
		G[a[i]].pb(P(i,b[i]));
		G[b[i]].pb(P(i,a[i]));
	}
	static ll root = 0;
	for(int i = 1 ; i <= N ; i ++){
		if(G[i].size() >= 2)root = i;
	}
	if(root == 0){
		if(A[1] == A[2])puts("YES");
		else puts("NO");
		return 0;
	}
	dfs(root,P(0,0));
	
	static ll c[100010];
	static ll d_ha = 0;
	for(int i = 0 ; i < vs.size() ; i ++){
		ll v = vs[i];
		if(G[v].size() == 1){
			c[par[v].fr] = A[v];
			d_ha += A[v];
		}
		else if(v != root){
			c[par[v].fr] = 2*A[v];
			for(int j = 0 ; j < G[v].size() ; j ++){
				if(G[v][j].fr == par[v].fr)continue;
				c[par[v].fr] -= c[G[v][j].fr];
			}
		}
		else {
			ll cnt = 0;
			for(int j = 0 ; j < G[v].size() ; j ++){
				cnt += c[G[v][j].fr];
			}
			if(cnt != 2*A[v]){
				puts("NO");
				return 0;
			}
		}
	}
	if(d_ha%2 != 0){
		puts("NO");
		return 0;
	}
	
	for(int i = 0 ; i < N ; i ++){
		for(int j = 0 ; j < G[i].size() ; j ++){
			if(A[i] < c[G[i][j].fr] || c[G[i][j].fr] < 0){
				puts("NO");
				return 0;
			}
		}
	}
	puts("YES");
}

