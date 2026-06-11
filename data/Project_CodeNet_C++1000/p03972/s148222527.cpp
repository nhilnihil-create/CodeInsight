#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
constexpr int MOD = 1000000007;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
constexpr int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
constexpr int dy[] = {0, -1, 0, 1, 1, -1, -1, 1};

template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){os << "["; for (const auto &v : vec) {os << v << ","; } os << "]"; return os; }
template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p){os << "(" << p.first << ", " << p.second << ")"; return os;}

void solve() {
    int W, H;
    cin >> W >> H;
    vector<ll> P(W), Q(H);
    for (int i = 0; i < W; i++) {
        cin >> P[i];
    }
    for (int i = 0; i < H; i++) {
        cin >> Q[i];
    }
    sort(all(P));
    sort(all(Q));
    int p = 0, q = 0;
    ll ans = 0;
    while(p < W && q < H) {
        if (P[p] < Q[q]) {
            ans += P[p] * (1 + H - q);
            p++;
        } else {
            ans += Q[q] * (1 + W - p);
            q++;
        }
    }
    while(p < W) {
        ans += P[p] * (1 + H - q);
        p++;
    }
    while(q < H) {
        ans += Q[q] * (1 + W - p);
        q++;
    }

    cout << ans << endl;
}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(16);
    solve();
    return 0;
}