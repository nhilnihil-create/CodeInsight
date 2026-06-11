// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
 
#define N (ll)(1e6+3)
#define INF (ll)(1e18+3)
#define MOD (ll)(1e9+7)
 
#define ll long long
#define rep(i,a,n) for(ll i = a; i < n; i++)
#define per(i,a,n) for(ll i = n-1; i >= a; i--)
 
//using namespace __gnu_pbds;
using namespace std;
 
// typedef
// tree<
//     pair<ll,ll>,
//     null_type,
//     less<pair<ll,ll>>,
//     rb_tree_tag,
//     tree_order_statistics_node_update>
// ordered_set;

ll ones[11], nines[11];
bool ores[11], nres[11];
ll n;

bool check(ll ans, ll guess) {
    bool b1 = ans > guess && to_string(ans) > to_string(guess);
    bool b2 = ans <= guess && to_string(ans) <= to_string(guess);
    return b1 || b2;
}

bool input(ll cur) {
    char ch;
    cin >> ch;

    bool b = ch == 'Y';
    // b = check(n,cur);
    // if (b) cout << 'Y' << endl;
    // else cout << 'N' << endl;
    return b;
}


void solve() {
    //cin >> n;
    ll cur = 1;
    rep(i,0,11) {
        ones[i] = cur;
        cur *= 10;
        nines[i] = cur-1;
    }

    // ll n; cin >> n;
    // rep(i,0,10) {
    //     cout << check(n,ones[i]) << " " << check(n,nines[i]) << endl;
    // }



    rep(i,0,11) {
        cout << "? " << ones[i] << endl;
        ores[i] = input(ones[i]);
        cout << "? " << nines[i] << endl;
        nres[i] = input(nines[i]);
    }

    ll nd = 0;
    rep(i,0,11) {
        if (ores[i] && nres[i])
            nd = i+1;
    }
    if (nd == 11) {
        rep(i,0,11) {
            if (ores[i] && nres[i]) {
                nd = i+1;
                break;
            }
        }
    }

    ll l = ones[nd-1], r = nines[nd-1]+1;
    while (l < r) {
        ll mid = (l+r)/2; mid *= 10;
        cout << "? " << mid << endl;
        bool b = input(mid);
        if (b) {
            r = (l+r)/2;
        }
        else {
            l = 1+(l+r)/2;
        }
    }
    cout << "! " << l << endl;
}
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}