#include <bits/stdc++.h>
#define ll long long int
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
    int n, m;
    cin >> n >> m;
    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];
    vector<ll> c(m), d(m);
    rep(i, m) cin >> c[i] >> d[i];
    
    rep(i, n) {
        ll best = 1e12;
        int idx = 0;
        rep(j, m) {
            ll dist = abs(c[j] - a[i]) + abs(d[j] - b[i]);
            if (best > dist) {
                best = dist;
                idx = j;
            }
        }
        put(idx + 1);
    }
    
    return 0;
}