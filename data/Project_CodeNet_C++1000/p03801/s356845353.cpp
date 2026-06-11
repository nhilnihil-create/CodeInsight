#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(ll i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

ll n, buf, ans[100008];
string s;

int main(){
	cin.tie(0); ios::sync_with_stdio(false);
	
	cin >> n;
	vector<P> a;
	
	a.push_back(P(0, 0));
	rep(i, 1, n){
		cin >> buf;
		a.push_back(P(buf, i));
	}
	sort(a.begin(), a.end());
	
	memset(ans, 0, sizeof(ans));
	ll mi = n;
	rrep(i, n, 1){
		mi = min(a[i].second, mi);
		ans[mi] += (a[i].first-a[i-1].first)*(n-i+1);
	}
	
	rep(i, 1, n){
		print(ans[i])
	}
	return 0;
}