#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, n) for (int i = 1; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
int main()
{
    ll n, K;
    cin >> n >> K;

    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];
    
    typedef std::pair<ll, ll> pair;
    vector<pair> p;
    rep(i, n) p.push_back(pair(a[i], b[i]));
    sort(all(p), [](const pair& lhs, const pair& rhs) {
        return lhs.first < rhs.first;
    });

    rep(i, n) {
        ll x = p[i].first;
        ll cnt = p[i].second;
        if (K <= cnt) {
            put(x);
            return 0;
        }
        K -= cnt;
    }

    return 0;
}