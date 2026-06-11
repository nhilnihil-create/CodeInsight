#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pf push_front
#define all(vv) (vv).begin(), (vv).end()
#define rep(ii, jj, ll, ss) for(int ii = jj; ii < ll; ii += ss)
#define time cerr << '\n' << (double)clock()/CLOCKS_PER_SEC << '\n'; return 0;

int n;
deque <char> ch;
deque <char> d;

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    rep(i, 0, n, 1) {
        char c; cin >> c;
        ch.pb(c);
        if (c == '(') d.pb(c);
        else {
            if (!d.empty() && d.back() == '(') d.pop_back();
            else d.pb(c);
        }
    }
    if (d.empty()) {
        for(auto it:ch) {
            cout << it;
        }
        time;
    }
    else {
        int front = 0, back = 0;
        for(auto it:d) {
            if (it == '(') ++back;
            else if (it == ')') ++front;
        }
        rep(i, 0, front, 1) ch.pf('(');
        rep(i, 0, back, 1) ch.pb(')');
    }
    for(auto it:ch) {
        cout << it;
    }
    time;
}

