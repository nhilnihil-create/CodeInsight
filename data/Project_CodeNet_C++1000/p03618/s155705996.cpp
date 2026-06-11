//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;



int main() {
    string s;
    cin >> s;
    vector<ll> vv(26);
    rep(i, s.size()) {
        vv[s[i]-'a']++;
    }

    ll ans = 0LL;
    rep(i, 26) {
        ans += (s.size()-vv[i])*vv[i];
    }
    ans /= 2LL;
    ++ans;

    cout << ans << endl;
}