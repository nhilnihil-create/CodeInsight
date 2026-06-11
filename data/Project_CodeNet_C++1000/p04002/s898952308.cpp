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

ll h, w, n, c[20];
map<pll, ll> a;

int main(){
	fast_io;
	ll x, y;
	cin >> h >> w >> n;
	c[0] = (h - 2) * (w - 2);
	for(ll i = 0; i < n; i++){
		cin >> x >> y;
		for(ll j = 0; j < 3; j++){
			for(ll k = 0; k < 3; k++){
				if(x - j < 1 || y - k < 1 || x - j + 2 > h || y - k + 2 > w) continue;
				c[a[Mp(x - j, y - k)]++]--;
				c[a[Mp(x - j, y - k)]]++;
			}
		}
	}
	for(ll i = 0; i < 10; i++){
		cout << c[i] << '\n';
	}
	
	
	return 0;
}