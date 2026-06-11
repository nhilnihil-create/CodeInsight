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
    ll n, m ;
    cin >> n >> m;

    if (n >= m / 2) {
        put(m / 2);
        return;
    }

    ll sum = n;
    ll rem = m - 2 * n;
    sum += rem / 4;

    put(sum);
    
}
signed main(){ Main();return 0;}