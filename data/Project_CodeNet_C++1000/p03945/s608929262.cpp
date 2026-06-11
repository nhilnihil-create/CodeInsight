# include <bits/stdc++.h>
# define rep(i, n) for (ll i = 0; i < (n); i++)
# define reps(i, n) for (ll i = 1; i <= (n); i++)
# define foreps(i, m, n) for (ll i = (m); i < (n); i++)
# define len(x) ((int)(x).size())
# define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
const long long mod = 1e9 + 7;
const long long inf = 1e18;

int main() {
    string S; cin >> S;

    ll cnt = 0;
    char t = S[0];
    reps(i, len(S) - 1) {
        if (t != S[i]) ++cnt;
        t = S[i];
    }
    cout << cnt << endl;
}