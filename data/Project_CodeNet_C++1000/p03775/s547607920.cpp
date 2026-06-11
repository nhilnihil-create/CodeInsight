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


int digit(ll n) {
    int x = 0;
    while (n > 0) {
        n /= 10;
        x++;
    }
    return max(1, x);
}

void Main()
{
    ll n;
    cin >> n;

    int res = 1e8;
    for (ll i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            ll A = i;
            ll B = n / i;
            int dA = digit(A);
            int dB = digit(B);
            res = min(res, max(dA, dB));
        }
    }

    put(res)
}
signed main(){ Main();return 0;}