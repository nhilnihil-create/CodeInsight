#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pf push_front
#define pii pair <int, int>
#define get(vv, times) for(int ii = 0; ii < times; ++ii) {int jj; cin >> jj; (vv).pb(jj);}
#define all(vv) (vv).begin(), (vv).end()
#define rep(ii, jj, ll, ss) for(int ii = jj; ii < ll; ii += ss)
#define time cerr << '\n' << (double)clock()/CLOCKS_PER_SEC << '\n'; return 0;

string s;
vector <int> st;

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> s;
    rep(i, 0, (int)s.length(), 1) {
        if (s[i] == '0' || s[i] == '1') st.pb(s[i]);
        if (s[i] == 'B') {
            if (!st.empty()) st.pop_back();
            else continue;
        }
    }
    for (auto it:st) cout << (char)it;
    time;
}