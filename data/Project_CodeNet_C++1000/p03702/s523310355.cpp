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
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 100010, LOG=20;

ll n, A, B, u, v, x, y, t, a, b, ans;
ll H[MAXN];

bool check(ll x){
	ll res=0;
	for (int i=1; i<=n; i++) res+=(max(0ll, H[i]-x*B)+A-B-1)/(A-B);
	return res<=x;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>A>>B;
	for (int i=1; i<=n; i++) cin>>H[i];
	ll dwn=0, up=inf;
	while (up-dwn>1){
		ll mid=(dwn+up)>>1;
		if (check(mid)) up=mid;
		else dwn=mid;
	}
	cout<<up<<'\n';
	
	
	return 0;
}
