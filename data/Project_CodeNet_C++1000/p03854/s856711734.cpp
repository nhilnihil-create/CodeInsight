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
    string S;
    cin >> S;

    vector<string> tokens = {
        "dream",
        "dreamer",
        "erase",
        "eraser",
    };

    while (S.size() > 0) {
        bool hit = false;
        rep(i, tokens.size()) {
            string t = tokens[i];
            if (S.size() >= t.size() && S.substr(S.size() - t.size(), t.size()) == t) {
                S = S.substr(0, S.size() - t.size());
                hit = true;
                break;
            }
        }
        if (!hit) {
            put("NO");
            return;
        }
    }

    put("YES")
}
signed main(){ Main();return 0;}