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

    // Combination Table
    ll C[51][51]; // C[n][k] -> nCk

    void COMInitNoMod(int n) {
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (j == 0 || j == i) C[i][j] = 1LL;
                else C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]);
            }
        }
    }

    ll COM(int n, int k) {
        if (n < 0 || k < 0) return 0LL;

        return C[n][k];
    }
}

int main() {

    int n, a, b;
    cin >> n >> a >> b;
    vector<ll> v = inp(n);

    // A個以上 B個以下選ぶ

    COMInitNoMod(n);

    sort(allof(v));

    ll sum = 0LL;
    rep(i, a) sum += v[n - 1 - i];

    cout << fixed << setprecision(-7) << (double)sum / a << endl;

    // 次に何通りか

    ll ans = 0LL;

    // 境界の値
    ll boader = v[n - a];

    // この値がいくつ選ばれて，いくつ残っているか
    ll boader_num = 0LL;
    ll used_num = 0LL;
    rep(i, n) {
        if (v[i] == boader) {
            ++boader_num;
            if (i >= n - a) ++used_num;
        }
    }

    if (sum == boader * a) { // すべて同じ値で構成されている
        // 何個選ぶか
        for (int i = a; i <= b; ++i) {
            // i個選ぶ
            if (i > boader_num) break;
            ans += COM(boader_num, i);
        }
    }
    else {
        ans = COM(boader_num, used_num);
    }

    Cout(ans);

    return 0;
}
