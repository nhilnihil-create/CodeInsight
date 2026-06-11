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
    ll x;
    cin >> x;

    ll sum = (x / 11) * 2;
    ll rem = x % 11;
    if (rem != 0) {
        if (rem <= 6) {
            sum += 1;
        }
        else {
            sum += 2;
        }
    }

    put(sum);

}
signed main(){ Main();return 0;}