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
#define all(x)          (x).begin(), (x).end()
#define SZ(x)           (ll)(x.size())
#define sep             ' '
#define fast_io         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define dbl_io(x)       cout << fixed << setprecision(x);

const int N = 1e5 + 10;
const ll mod = 1e9 + 7;
const ll inf = 1e18 + 10;

ll ans[10], h, w;
map < pll , ll > mp;

void upd(ll x, ll y){
    if (!(1 <= x && x <= h && 1 <= y && y <= w && x + 2 <= h && y + 2 <= w))
        return ;
    ll t = 0;
    for (ll i = 0; i < 3; i ++)
        for (ll j = 0; j < 3; j ++)
            if (mp[make_pair(x + i, y + j)])
                t ++;
    ans[t] ++;
    ans[t - 1] --;
}

int main(){
    fast_io
    //dbl_io(10);
    cin >> h >> w;
    ans[0] = (h - 2) * (w - 2);
    ll q; cin >> q;
    while (q --){
        ll x, y;
        cin >> x >> y;
        mp[make_pair(x, y)] = 1;
        for (ll i = 0; i < 3; i ++)
            for (ll j = 0; j < 3; j ++)
                upd(x - i, y - j);
    }
    for (ll i = 0; i < 10; i ++)
        cout << ans[i] << '\n';
    return 0;
}
