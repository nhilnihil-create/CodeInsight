#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(ll i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

ll n, m;
string s;

int main(){
	cin.tie(0); ios::sync_with_stdio(false);
	
	cin >> s;
	n = s.size();
	ll cnt[30];
	memset(cnt, 0, sizeof(cnt));
	rep(i, 0, n){
		int a = s[i]-'a';
		cnt[a]++;
	}
	ll ans = 1 + n*(n-1)/2;
	
	rep(j, 0, 30){
		ans -= cnt[j]*(cnt[j]-1)/2;
	}
	print(ans)
	return 0;
}