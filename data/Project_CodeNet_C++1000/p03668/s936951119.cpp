#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<stack>
#include<set>
using namespace std ;
using ll = long long ;
using vll = vector<ll> ;
using vvll = vector<vll> ;
using pll = pair<ll,ll> ;
ll INF = 1e15 ;
void chmin(ll &a,ll b){if(a>b) a = b ;}
void chmax(ll &a,ll b){if(a<b) a = b ;}
void YorN(bool a){cout << (a?"YES":"NO") << "\n" ;}

ll DFS(vvll &g,int cur,int pre){
	ll res = 0 ;
	for(int i=0;i<g[cur].size();i++){
		if(pre==g[cur][i]) continue ;
		res ^= DFS(g,g[cur][i],cur)+1 ;
	}
	return res ;
}

int main(){
	ll n ; cin >> n ;
	vvll g(n) ;
	for(int i=1;i<n;i++){
		ll a,b ;
		cin >> a >> b ;
		a-- ; b-- ;
		g[a].push_back(b) ;
		g[b].push_back(a) ;
	}
	cout << (DFS(g,0,-1)?"Alice":"Bob") << endl ;
}