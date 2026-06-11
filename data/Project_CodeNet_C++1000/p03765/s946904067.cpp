#include <bits/stdc++.h>
#define pb          emplace_back
#define ll          long long
#define ld          long double
#define fi          first
#define se          second
#define mp          make_pair

using namespace std;

const int N = int(2e5) + 7;
typedef pair<int, int> pii;

string s, t;
int n, m, a[N], b[N], q, ls, rs, lt, rt;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    #define Task        "test"
    if(fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> s >> t;
    n = int(s.size()); s = ' ' + s;
    m = int(t.size()); t = ' ' + t;
    for(int i = 1; i <= n; ++i) {
        a[i] = a[i - 1] + 1;
        if(s[i] == 'B') ++a[i];
    }
    for(int i = 1; i <= m; ++i) {
        b[i] = b[i - 1] + 1;
        if(t[i] == 'B') ++b[i];
    }
    cin >> q;
    while(q --) {
        cin >> ls >> rs >> lt >> rt;
        int x = (a[rs] - a[ls - 1]) % 3;
        int y = (b[rt] - b[lt - 1]) % 3;
        if(x == y) cout << "YES\n";
        else cout << "NO\n";
    }
}
