#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(int i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(int i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(int i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define uniq(x) (x).erase(unique((x).begin(), (x).end()), (x).end())

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string a;
    cin >> a;
    map<char, ll> m;
    ll al = a.length();
    rep(i, al) m[a[i]]++;
    ll ans = al * (al - 1) / 2 + 1;
    for(auto x : m) ans -= x.second * (x.second - 1) / 2;
    cout << ans << endl;
    return 0;
}
