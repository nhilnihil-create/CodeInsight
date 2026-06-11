#include <bits/stdc++.h>
// #include <atcoder/all>
#define ll long long int
#define ld long double
#define yorn(f) std::cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) std::cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, n) for (ll i = 1; i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) std::cout << x << endl;
#define println(x) std::cout << x << endl;
using namespace std;
// using namespace atcoder;
void Main()
{
    string s;
    cin >> s;

    // gpgpgpが最善
    ll res = 0;
    rep(i, s.size()) {
        if (i % 2 == 0) {
            // こちらはg
            res += s[i] == 'g' ? 0 : -1;
        }
        else {
            // こちらはp
            res += s[i] == 'g' ? 1 : 0;
        }
    }
    put(res);
}
signed main(){ Main();return 0;}