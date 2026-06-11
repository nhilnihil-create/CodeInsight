//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, ans, x;
string s;

int main(){
	fast_io;
	
	cin >> s;
	n = s.size();
	for(ll i = 0; i < (1ll << (n - 1)); i++){
		x = 0;
		for(ll j = 0; j < n; j++){
			x = (x * 10) + (s[j] - '0');
			if((i >> j) & 1) ans += x, x = 0;
		}
		ans += x;
	}
	cout << ans;
	
	return 0;
}