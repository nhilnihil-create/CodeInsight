#include <bits/stdc++.h>

#define show(x) cerr << #x << " = " << x << endl

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
    os << "sz:" << v.size() << "\n[";
    for (const auto& p : v) {
        os << p << ",";
    }
    os << "]\n";
    return os;
}

template <typename S, typename T>
ostream& operator<<(ostream& os, const pair<S, T>& p)
{
    os << "(" << p.first << "," << p.second
       << ")";
    return os;
}


constexpr ll MOD = (ll)1e9 + 7LL;

template <typename T>
constexpr T INF = numeric_limits<T>::max() / 100;

constexpr char color[4] = {'R', 'Y', 'G', 'B'};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int H, W;
    cin >> H >> W;
    int d;
    cin >> d;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            const int x = (i + j) / d;
            const int y = (W - j + i - 1) / d;
            if (y % 2 == 0) {
                cout << color[x % 4];
            } else {
                cout << color[(x + 2) % 4];
            }
        }
        cout << endl;
    }
    return 0;
}
