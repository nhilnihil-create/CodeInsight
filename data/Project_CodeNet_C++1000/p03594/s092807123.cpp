#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
constexpr int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
constexpr int dy[] = {0, -1, 0, 1, 1, -1, -1, 1};

template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){os << "["; for (const auto &v : vec) {os << v << ","; } os << "]"; return os; }
template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) {os << "(" << p.first << ", " << p.second << ")"; return os;}

void solve() {
    ll H, W, d;
    cin >> H >> W >> d;
    string color[] = {"R", "Y", "G", "B"};
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            ll x = i + j;
            ll y = i - j;
            ll cl = (((x + 10000000000LL * d) / d % 2) << 1) | ((y + 10000000000LL * d) / d % 2);
            cout << color[cl];
        }
        cout << endl;
    }
}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(16);
    solve();
    return 0;
}