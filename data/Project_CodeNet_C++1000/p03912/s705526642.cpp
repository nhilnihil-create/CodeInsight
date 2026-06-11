#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <climits>
#include <cstring>

#define rep(i, m, n) for(int i=int(m);i<int(n);i++)
#define all(c) begin(c),end(c)

template<typename T1, typename T2>
inline void chmin(T1 &a, T2 b) { if (a > b) a = b; }

template<typename T1, typename T2>
inline void chmax(T1 &a, T2 b) { if (a < b) a = b; }

typedef long long int ll;
using ll = long long int;
using ull = long long unsigned int;
using Int = long long int;
using namespace std;
#define INF (1 << 30) - 1
#define INFl (ll)5e15
#define DEBUG 0
#define dump(x)  cerr << #x << " = " << (x) << endl
#define MOD 1000000007


//edit
class Solve {
public:
    Int N, M;
    vector<Int> X;
    vector<vector<Int>> Y;

    Int func(Int m) {
        if ((m + m) % M == 0) {
            Int ret = static_cast<Int>(Y[m].size() / 2);
            return ret;
        }

        Int ret = 0ll;
        Int n = M - m;
        if (Y[m].size() == Y[n].size()) {
            return static_cast<Int>(Y[m].size());
        } else if (Y[m].size() < Y[n].size()) {
            ret += Y[m].size();
            map<Int, Int> neri;
            for (int i = 0; i < Y[n].size(); ++i) {
                neri[Y[n][i]]++;
            }

            Int tmp = 0;
            for (auto e : neri) {
                tmp += e.second / 2;
            }
            ret += min<Int>(tmp, static_cast<const Int &>((Y[n].size() - Y[m].size()) / 2));
        } else {
            swap(n, m);
            ret += Y[m].size();
            map<Int, Int> neri;
            for (int i = 0; i < Y[n].size(); ++i) {
                neri[Y[n][i]]++;
            }

            Int tmp = 0;
            for (auto e : neri) {
                tmp += e.second / 2;
            }
            ret += min<Int>(tmp, static_cast<const Int &>((Y[n].size() - Y[m].size()) / 2));
        }

        return ret;
    }

    void solve() {
        cin >> N >> M;
        X.resize(N);
        for (auto &x : X) cin >> x;

        Y.resize(M);
        for (int i = 0; i < X.size(); ++i) {
            Y[X[i] % M].push_back(X[i]);
        }
        for (int i = 0; i < M; ++i) {
            sort(all(Y[i]));
        }

        Int ans = 0;
        for (int i = 0; 2 * i <= M; ++i) {
            ans += func(i);
        }

        cout << ans << endl;

    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    Solve().solve();


    return 0;
}
