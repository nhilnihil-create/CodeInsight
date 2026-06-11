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

    if (s.size() == 2) {
        if (s[0] == s[1]) {
            put("1 2");
        }
        else {
            put("-1 -1")
        }
        return;
    }

    rep(i, s.size() - 3) {
        char a = s[i];
        char b = s[i+1];
        char c = s[i+2];
        if (a == b || b == c || c == a) {
            std::cout << i + 1 << " " << i + 3 << endl;
            return;
        }
    }

    put("-1 -1")
}
signed main(){ Main();return 0;}