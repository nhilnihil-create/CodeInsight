#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())
#define endl "\n"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    ll a, b;
    cin >> a >> b;
    if ((a == 0) || (b == 0)) {
        cout << "Zero" << endl;
    }
    else if ((a < 0) && (b < 0)) {
        ll cnt = abs(a - b) + 1;
        if (cnt % 2 == 0) cout << "Positive" << endl;
        else cout << "Negative" << endl;
    }
    else if ((a < 0) && (b > 0)) {
        cout << "Zero" << endl;
    }
    else if ((a > 0) && (b > 0)) {
        cout << "Positive" << endl;
    }
    return 0;
}
