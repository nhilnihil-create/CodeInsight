#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <list>
#include <numeric>
#include <stack>
#include <iomanip>
#include <random>
#include <complex>
#include <functional>
#include <tuple>

using namespace std;

#define Rep(i,a,b) for(ll i = a; i < b; ++i)
#define rep(i,b) Rep(i,0,b)
#define allof(a) (a).begin(), (a).end()

#define Yes(q) ((q) ? "Yes" : "No")
#define YES(q) ((q) ? "YES" : "NO")
#define Possible(q) ((q) ? "Possible" : "Impossible")
#define POSSIBLE(q) ((q) ? "POSSIBLE" : "IMPOSSIBLE")

using ll = long long;

constexpr int inf = 1e9 + 7;
constexpr ll infll = 1ll << 60ll;
constexpr ll mod = 1e9 + 7;
// 0~3までは右左下上 4~7までは斜め
constexpr int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
constexpr int dy[] = { 0, -1, 0, 1, 1, -1, -1, 1 };

namespace {
    template<typename T> void chmax(T& a, T b) { a = std::max(a, b); }
    template<typename T> void chmin(T& a, T b) { a = std::min(a, b); }
    template<typename T> void chadd(T& a, T b) { a = a + b; }

    void Cout(long long x, const char* end = "\n") { std::cout << x << end; }
    template <typename T> void Cout(const T& x, const char* end = "\n") { std::cout << x << end; }
    template <typename T> void Cout(const std::vector<T>& x, const char* sep = " ", const char* end = "\n") { for (std::size_t i = 0, sz = x.size(); i < sz; i++) { std::cout << x[i] << (i == sz - 1 ? end : sep); } }

    // 標準入出力
    struct inp {
        std::size_t sz;
        inp(std::size_t _sz = 1) : sz(_sz) {}
        template <typename T> operator T () const { T a; std::cin >> a; return a; }
        template <typename T> operator std::vector<T>() const { std::vector<T> a(sz); for (std::size_t i = 0; i < sz; i++) std::cin >> a[i]; return a; }
    };

    // 2次元用の標準入出力
    template<typename T>
    struct inpn {
        std::size_t szi, szj;
        inpn(std::size_t _szi, std::size_t _szj) : szi(_szi), szj(_szj) {}
        operator std::vector<std::vector<T>>() const {
            std::vector<std::vector<T>> a(szi, std::vector<T>(szj));
            for (std::size_t i = 0; i < szi; ++i)
                for (std::size_t j = 0; j < szj; ++j) cin >> a[i][j];
            return a;
        }
    };

    inp inp1; // input one
}

int main() {

    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m), c(m);
    rep(i, m) {
        cin >> a[i] >> b[i] >> c[i];
    }

    //　ワーシャルフロイド？
    vector<vector<bool>> cutted(n, vector<bool>(n, false));

    vector<vector<ll>>dist(n, vector<ll>(n, infll));
    rep(i, m) {
        dist[a[i] - 1][b[i] - 1] = c[i];
        dist[b[i] - 1][a[i] - 1] = c[i];
    }
    rep(i, n) dist[i][i] = 0LL;

    rep(k, n) {
        rep(i, n) {
            rep(j, n) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    ll ans = m;
    rep(i, m) {
        // a[i] - 1 to b[i] - 1 は最短経路に含まれる辺か
        bool shortest = false;
        rep(s, n) {
            if (dist[s][a[i] - 1] + c[i] == dist[a[i] - 1][b[i] - 1]) {
                shortest = true;
                break;
            }
        }
        if (shortest) --ans;
    }

    Cout(ans);

    return 0;
}
