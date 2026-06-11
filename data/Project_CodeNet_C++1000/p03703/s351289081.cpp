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

const int siz = 2e5 + 10;
const int SIZ = 2e5 + 10;
const int mod = 1e9 + 7;
const int maxx = 2e9;
const int MAXX = 1e18;
const string file = "data";

int n;
int psum[siz];

void compress() {
    vector <ii> data; /// value, index;
    for (int i = 0; i <= n; i++) {
        data.push_back(ii(psum[i], i));
    }

    sort (all(data));

    int num = 0, prv = MAXX;
    for (auto &x : data) {
        if (x.fi != prv) {
            prv = x.fi;
            num++;
        }
        psum[x.se] = num;
    }
}

int fen[SIZ];

void updatePos(int index, int value) {
    for (int i = index; i < SIZ; i += i & (-i)) {
        fen[i] += value;
    }
}

int getSum(int index) {
    int sum = 0;
    for (int i = index; i > 0; i -= i & (-i)) {
        sum += fen[i];
    }
    return sum;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

//    freopen ((file + ".inp").c_str(), "r", stdin);
//    freopen ((file + ".out").c_str(), "w", stdout);

    int k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;

        psum[i] = psum[i - 1] + a - k;
    }

    compress();

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        ans += getSum(psum[i]);
        updatePos(psum[i], 1);
    }

    cout << ans << "\n";

//    cerr << "Time: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";

    return 0;
}
