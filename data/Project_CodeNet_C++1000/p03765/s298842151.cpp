#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define yn(x) ((x) ? "YES" : "NO")

typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int siz = 1e5 + 10;
const int SIZ = 1e6 + 10;
const int mod = 1e9 + 7;
const int maxx = 2e9;
const int MAXX = 1e18;
const int offset = 1e9 - 1;
const string file = "1";

int psum1[siz], psum2[siz];

int get(char c) {
    if (c == 'A') {
        return 1;
    }
    return -1;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

//    freopen ((file + ".inp").c_str(), "r", stdin);
//    freopen ((file + ".out").c_str(), "w", stdout);

    string s, t;
    cin >> s >> t;

    for (int i = 1; i <= sz(s); i++) {
        psum1[i] = psum1[i - 1] + get(s[i - 1]);
    }

    for (int i = 1; i <= sz(t); i++) {
        psum2[i] = psum2[i - 1] + get(t[i - 1]);
    }

    int q;
    cin >> q;

    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int sum1 = psum1[b] - psum1[a - 1];
        int sum2 = psum2[d] - psum2[c - 1];

        cout << yn((sum1 - sum2 + offset) % 3 == 0) << "\n";
    }

//    cerr << "Time: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";

    return 0;
}
