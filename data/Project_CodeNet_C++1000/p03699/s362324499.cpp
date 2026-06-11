#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;

int main()
{
    int n;
    cin >> n;
    vector<int> s(n);
    rep(i, n) cin >> s[i];
    sort(s.begin(), s.end());
    int sum = 0;
    rep(i, n) sum += s[i];
    if(sum % 10 != 0) {
        cout << sum << endl;
        return 0;
    }
    rep(i, n) {
        if(s[i] % 10 != 0) {
            sum -= s[i];
            cout << sum << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}
