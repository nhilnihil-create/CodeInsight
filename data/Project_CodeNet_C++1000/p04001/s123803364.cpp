//In The Name of Allah
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template < class T > using Tree = tree < T , null_type , less < T > , rb_tree_tag , tree_order_statistics_node_update >;

typedef long long            ll;
typedef long double          ld;
typedef string               str;
typedef pair < ll , ll >     pll;

#define X               first
#define Y               second
#define pb              push_back
#define all(x)			(x).begin(), (x).end()
#define SZ(x) 			(ll)(x.size())
#define sep             ' '
#define fast_io         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define dbl_io(x)       cout << fixed << setprecision(x);

const int N = 1e5 + 10;
const ll mod = 1e9 + 7;
const ll inf = 1e18 + 10;

string s;
ll ans = 0, a[20];

void f(ll n){
	if (n == s.size()){
		ll res = 0;
		for (ll i = 0; i < s.size(); i ++){
			res = res * 10 + (s[i] - '0');
			if (a[i + 1])
				ans += res, res = 0;
		}
		ans += res;
		return ;
	}
	a[n] = 1;
	f(n + 1);
	a[n] = 0;
	f(n + 1);
}

int main(){
    fast_io
    //dbl_io(10);
    cin >> s;
    f(1);
    cout << ans;
    return 0;
}
