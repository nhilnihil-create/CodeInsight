#include "bits/stdc++.h"
using namespace std;
using ll     = long long;
using pii    = pair<int, int>;
using pll    = pair<ll, ll>;
using vi     = vector<int>;
using vl     = vector<ll>;
using vvi    = vector<vi>;
using vvl    = vector<vl>;
const ll INF = 1LL << 60;
const ll MOD = 1000000007;
template <class T>
bool chmax(T &a, const T &b) {
    return (a < b) ? (a = b, 1) : 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    return (b < a) ? (a = b, 1) : 0;
}
template <class C>
void print(const C &c, std::ostream &os = std::cout) {
    std::copy(std::begin(c), std::end(c), std::ostream_iterator<typename C::value_type>(os, " "));
    os << std::endl;
}

int main() {
    int h, w, d;
    cin >> h >> w >> d;
    vector<string> c(h, string(w, 'x'));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            int x = i + j;
            int y = i - j + max(h, w);
            x /= d;
            y /= d;
            x %= 2;
            y = (y % 2 + 2) % 2;
            if (x == 0 && y == 0)
                c[i][j] = 'R';
            else if (x == 0 && y == 1)
                c[i][j] = 'G';
            else if (x == 1 && y == 0)
                c[i][j] = 'B';
            else
                c[i][j] = 'Y';
        }
    }
    for (int i = 0; i < h; ++i) {
        cout << c[i] << "\n";
    }
    return 0;
}