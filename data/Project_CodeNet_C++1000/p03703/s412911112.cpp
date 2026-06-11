#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout << (x) << '\n'
#define Int int64_t
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
 
Int INF = 1e18;
Int inf = 1e9;
Int mod = 1e9+7;

typedef long long ll;

ll merge_cnt(vector<Int> &a) {
    Int n = a.size();
    if (n <= 1) { return 0; }

    ll cnt = 0;
    vector<Int> b(a.begin(), a.begin()+n/2);
    vector<Int> c(a.begin()+n/2, a.end());

    cnt += merge_cnt(b);
    cnt += merge_cnt(c);

    Int ai = 0, bi = 0, ci = 0;
    // merge の処理
    while (ai < n) {
        if ( bi < b.size() && (ci == c.size() || b[bi] <= c[ci]) ) {
            a[ai++] = b[bi++];
        } else {
            cnt += n / 2 - bi;
            a[ai++] = c[ci++];
        }
    }
    return cnt;
}

int main() {
    Int n, k;
    cin >> n >> k;
    vector<Int> a(n);
    for (Int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] -= k;
    }
    vector<Int> b(n + 1, 0);
    for (Int i = 0; i < n; i++) {
        b[i + 1] = b[i] + a[i];
    }
    dump(n * (n + 1) / 2 - merge_cnt(b));
    return 0;
}