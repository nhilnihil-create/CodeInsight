#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define f first
#define s second
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define pb push_back

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b); i >= (a); i--)
#define R0F(i, a) ROF(i, 0, a-1)
#define trav(x, a) for (auto& x: a)

const int MX  = 2e5+5;
const int MOD = 1e9+7;
const ll  INF = 1061109567; // 4557430888798830399LL
const ld  EPS = 1e-9;
const ld  PI  = acos(-1);

bool perm[MX];

ll qpow(ll b, ll e) {
    if (!e) return 1;
    if (e&1) return (qpow(b, e-1)*b)%MOD;
    ll res = qpow(b, e/2)%MOD;
    return (res*res)%MOD;
}

ll invmod(ll a) {
    return qpow(a, MOD-2);
}

ll divide (ll a, ll b) {
    return (a*invmod(b))%MOD;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll n; cin >> n;

    multiset<int> ms;
    F0R(i, n) {
        int x; cin >> x;
        ms.insert(x);
    }

    if (1) {
        bool ok = true;
        FOR(i, 1, n+1) {
            if (perm[i]) continue;
            int x = ms.count(abs((i-1)-(n-i)));

            if (abs((i-1)-(n-i)) == 0) {
                ok = n&1;
                if (x > 1) {
                    ok = false;
                } else {
                    perm[i] = 1;
                    ms.erase(abs((i-1)-(n-i)));
                }
            } else {
                if (x != 2) {
                    ok = false;
                } else {
                    perm[i] = perm[n-i+1] = 1;
                    ms.erase(abs((i-1)-(n-i)));
                }
            }

            if (!ok) break;
        }

        FOR(i, 1, n+1) if (!perm[i]) ok = false;

        if (!ok) {
            cout << "0\n";
        } else {
            cout << qpow(2, n/2) << "\n";
        }
    }
}
