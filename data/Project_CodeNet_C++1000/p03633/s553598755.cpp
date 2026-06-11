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


ll gcd(ll a, ll b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main()
{
    int n;
    cin >> n;
    vector<ll> T(n);
    rep(i, n) cin >> T[i];

    ll res = T[0];
    rep(i, n) {
        ll div = gcd(res, T[i]);
        
        ll div2 = gcd(T[i], div);
        ll div1 = div / div2;

        res = (res / div1) * (T[i] / div2);
    }

    put(res);

    return 0;
}