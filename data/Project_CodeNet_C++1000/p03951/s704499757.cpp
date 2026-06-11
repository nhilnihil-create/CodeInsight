#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;

const ll INF = 1001001001;

int main()
{
    int n;
    string s, t;
    cin >> n;
    cin >> s;
    cin >> t;
    rep(i, n) {
        bool x = true;
        repl(j, i, n) {
            if(s[j] != t[j - i]) x = false;
        }
        if(x) {
            cout << 2 * n - (n - i) << endl;
            return 0;
        }
    }
    cout << 2 * n << endl;
    return 0;
}
