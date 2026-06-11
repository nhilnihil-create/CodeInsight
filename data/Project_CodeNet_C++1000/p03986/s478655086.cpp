#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pf push_front
#define pii pair <int, int>
#define all(vv) (vv).begin(), (vv).end()
#define rep(ii, jj, ll, ss) for(int ii = jj; ii < ll; ii += ss)
#define time cerr << '\n' << (double)clock()/CLOCKS_PER_SEC << '\n'; return 0;

string x;
vector <char> s;

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> x;
    rep(i, 0, (int)x.length(), 1) {
        if (x[i] == 'S') s.pb(x[i]);
        else {
            if (!s.empty() && s.back() == 'S') s.pop_back();
            else s.pb(x[i]); 
        }
    }
    for(auto it:s) cerr << it << ' ';
    cerr << '\n';
    cout << s.size();
    time;
}