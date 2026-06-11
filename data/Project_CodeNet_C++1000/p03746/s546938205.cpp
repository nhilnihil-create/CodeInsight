#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define a first
#define b second
#define sz(x) (ll)((x).size())
#define pb push_back
#define mp make_pair 
#define bg begin()
#define ed end()
#define all(x) (x).bg,(x).ed
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rrep1(i,n) for(ll i=(n);i>=1;i--)
#define rep1(i,n) for(ll i=1;i<=(n);i++)
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)

vector<ll> G[100001]; //隣接リスト
bool used[100001];
vector<ll> ansL;
vector<ll> ansR;

void dfsL(ll x){
	used[x]=true;
	ansL.pb(x);

	rep(i,sz(G[x])){
		if(!used[G[x][i]]){
			dfsL(G[x][i]);
			return;
		}
	}
}
void dfsR(ll x){
	used[x]=true;
	ansR.pb(x);

	rep(i,sz(G[x])){
		if(!used[G[x][i]]){
			dfsR(G[x][i]);
			return;
		}
	}
}

int main(){
	//input
	ll N,M; cin>>N>>M;
	//初期化
	rep(i,100001) used[i]=false;

    rep(i,M){
		ll A,B; cin>>A>>B;
		G[A].pb(B);
		G[B].pb(A);
	}

	dfsL(1);
	dfsR(1);

	cout<<sz(ansL)+sz(ansR)-1<<endl;
	rrep1(i,sz(ansL)-1) cout<<ansL[i]<<" ";
	rep(i,sz(ansR)) cout<<ansR[i]<<" ";
}