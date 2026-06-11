#include <bits/stdc++.h>

#define F first
#define S second
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
 
const int Maxn = 1e5 + 10;
const ll Inf = LONG_LONG_MAX >> 2;
const int Log = 20;
const ll Mod = 10133;

ll a[Maxn];
ll nx[Maxn][Log];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	a[n + 1] = Inf;
	ll L, Q;
	cin >> L >> Q;
	int po = 1;
	for(int i = 1; i <= n; i++){
		while(a[po] - a[i] <= L) po ++;
		nx[i][0] = po - 1;
	}
	for(int j = 1; j < Log; j++)
		for(int i = 1; i <= n; i++) nx[i][j] = nx[nx[i][j - 1]][j - 1];
	ll s, e;
	for(int i = 1; i <= Q; i++){
		cin >> s >> e;
		if(s > e) swap(s, e);
		ll ans = 0;
		for(int j = Log - 1; j >= 0; j--){
			if(nx[s][j] < e){
				ans += (1 << j);
				s = nx[s][j];
			}
		}
		cout << ans + 1 << '\n';
	}
	return 0;
}
