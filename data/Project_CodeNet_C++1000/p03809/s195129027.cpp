#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=100010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, root=1;
int A[MAXN];
vector<int> G[MAXN];

int dfs(int node, int par){
	if (G[node].size()==1) return A[node];
	int res=2*A[node], mx=0;
	for (int v:G[node]) if (v!=par){
		int tmp=dfs(v, node);
		mx=max(mx, tmp);
		res-=tmp;
		if (res<0){
			cout<<"NO\n";
			exit(0);
		}
	}
	mx=max(mx, res);
	if (mx>A[node]){
		cout<<"NO\n";
		exit(0);
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	if (n==2) kill((A[1]==A[2]?"YES":"NO"))
	for (int i=1; i<n; i++){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	while (G[root].size()==1) root++;
	if (dfs(root, 0)) cout<<"NO\n";
	else cout<<"YES\n";
	
	return 0;
}
