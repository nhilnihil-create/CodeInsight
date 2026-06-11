#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
const ll Mod = 1e9 + 7;
const ll Inf = 2242545357980376863LL;
const ll Log = 20;
const ll N = 1ll << Log;
const int Maxn = 1e5 + 10;
const int Base = 101;

ll ps1[Maxn], ps2[Maxn];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	str s, t;
	cin >> s >> t;
	ll n = s.size();
	ll m = t.size();
	s = '!' + s;
	t = '!' + t;
	for(int i = 1; i <= n; i++) ps1[i] = ps1[i - 1] + (s[i] == 'A' ? 1 : -1);
	for(int i = 1; i <= m; i++) ps2[i] = ps2[i - 1] + (t[i] == 'A' ? 1 : -1);
	ll q;
	cin >> q;
	ll a, b, c, d, v;
	for(int i = 0; i < q; i++){
		cin >> a >> b >> c >> d;
		v = (ps1[b] - ps1[a - 1]) - (ps2[d] - ps2[c - 1]);
		cout << (v % 3 == 0 ? "YES" : "NO") << '\n';
	}
	return 0;
}
