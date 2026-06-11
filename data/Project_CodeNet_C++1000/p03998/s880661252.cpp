#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pf push_front
#define pii pair <int, int>
#define all(vv) (vv).begin(), (vv).end()
#define rep(ii, jj, ll, ss) for(int ii = jj; ii < ll; ii += ss)
#define time cerr << '\n' << (double)clock()/CLOCKS_PER_SEC << '\n'; return 0;

string A, B, C;
deque <char> a;
deque <char> b;
deque <char> c;
char pre;

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> A >> B >> C;
    rep(i, 0, (int)A.length(), 1) a.pb(A[i]);
    rep(i, 0, (int)B.length(), 1) b.pb(B[i]);
    rep(i, 0, (int)C.length(), 1) c.pb(C[i]);
    pre = 'a';
    while (true) {
        if (pre == 'a') {
            if (a.empty()) {
                cout << 'A';
                time
            }
            pre = a.front();
            a.pop_front();
        }
        else if (pre == 'b') {
            if (b.empty()) {
                cout << 'B';
                time
            }
            pre = b.front();
            b.pop_front();
        }
        else if (pre == 'c') {
            if (c.empty()) {
                cout << 'C';
                time
            }
            pre = c.front();
            c.pop_front();
        }
    }
}