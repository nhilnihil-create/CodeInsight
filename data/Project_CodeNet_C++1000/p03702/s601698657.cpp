/* Quick Note :
 * Jangan Mikir Lama - lama, sampahin dulu aja kalo OI
 * Always Try to reset
*/
#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define debug(val) cerr << "The value of " << #val << " is = " << val << '\n';
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9 + 7;
const ll inf = 922337203685477;
const ll nax = 1e5 + 5;

ll n, a, b;
ll h[nax];

ll cek(ll x){
	ll dif = a - b;
	ll cnt = 0;
	for(ll i = 1; i <= n; i++){
		ll res = b * x;
		if(res >= h[i]){
			continue;
		}
		else{
			ll need = (h[i] - res + dif - 1) / dif;
			cnt += need;
		}
	}
	return cnt <= x;
}

int main(){ 
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    
    cin >> n >> a >> b;
    for(ll i = 1; i <= n; i++){
		cin >> h[i];
	}
	sort(h + 1, h + 1 + n);
	ll ans = inf;
	ll l = 1, r = 1e9;
	while(l <= r){
		ll mid = (l + r) / 2;
		if(cek(mid)){
			ans = min(ans, mid);
			r = mid - 1;
		}
		else{
			l = mid + 1;
		}
	}
	cout << ans << '\n';
}
