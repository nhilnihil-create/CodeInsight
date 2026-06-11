#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, n) for (ll i = 1; i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
void Main()
{
    string n;
    ll K;
    cin >> n >> K;

    vector<ll> _D(K);
    rep(i, K) cin >> _D[i];

    vector<ll> use(10, 1);
    rep(i, K) use[_D[i]] = 0;
    
    ll minUse = 0;
    rep(i, 10) {
        if (use[i]) {
            minUse = i;
            break;
        }
    }

    for (ll i = atoi(n.c_str()); ; i++) {
        bool ok = true;
        ll t = i;
        while (t > 0) {
            if (use[t % 10] == 0) {
                ok = false;
                break;
            }
            t /= 10;
        }
        if (ok) {
            put(i);
            break;
        }
    }

    // ll p = 0;
    // reverse(all(n));
    // rep(_i, n.size()) {
    //     ll v = n[_i] - '0' + p;
    //     p = v / 10;
    //     v = v % 10;

    //     bool ok = false;
    //     for (int i = v; i <= 9; i++) {
    //         if (use[i]) {
    //             n[_i] = '0' + i;
    //             ok = true;
    //             break;
    //         }
    //     }

    //     if (!ok) {
    //         n[_i] = minUse + '0';
    //         p += 1;
    //     }
    // }

    // if (p >= 1) {
    //     for (int i = p; i <= 9; i++) {
    //         if (use[i]) {
    //             n.push_back('0' + i);
    //             break;
    //         }
    //     }
    // }

    // reverse(all(n));
    // put(n);

}
signed main(){ Main();return 0;}