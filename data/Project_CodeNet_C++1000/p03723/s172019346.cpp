#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define reps(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; --i)
#define rreps(i, n) for (int i = ((int)(n)); i > 0; --i)
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int)(v).size())
const int INF = 1e9;
const int MOD = 1e9 + 7;
const double PI = acos(-1);



int main(void) {
    ll a, b, c;
    cin >> a >> b >> c;
    ll count = 0;
    while (1) {
        if (a % 2 == 1) break;
        if (b % 2 == 1) break;
        if (c % 2 == 1) break;
        ll na, nb, nc;
        na = (b + c) / 2;
        nb = (a + c) / 2;
        nc = (b + a) / 2;
        if (na == a && nb == b && nc == c) {
            cout << -1 << endl;
            return 0;
        }
        a = na;
        b = nb;
        c = nc;
        count++;
    }
    cout << count << endl;
    return 0;
}