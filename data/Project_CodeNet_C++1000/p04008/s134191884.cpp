#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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

int n, m, k, u, v, x, y, t, a, b, ans;
int par[MAXN], h[MAXN], P[MAXN];
bool mark[MAXN];

int geth(int v){
	if (v==1 || h[v]) return h[v];
	return h[v]=geth(par[v])+1;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k;
	for (int i=1; i<=n; i++) cin>>par[i];
	for (int i=1; i<=n; i++) geth(i), P[i]=i;
	sort(P+1, P+n+1, [](int i, int j){
		return h[i]>h[j];
	});
	for (int i=1; i<=n; i++){
		int v=P[i];
		if (mark[v] || h[v]<=k) continue ;
		int tmp=k-1;
		while (!mark[v] && tmp--){
			mark[v]=1;
			v=par[v];
		}
		if (!mark[v]) mark[v]=1, ans++;
	}
	ans+=(par[1]!=1);
	cout<<ans<<'\n';
	
	return 0;
}
