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
    Int N, K;
    vector<Int> A, B;

    Int calc(Int n) {
        if (n < 0) {
            Int mask = K;

            Int ret = 0;
            for (int i = 0; i < N; ++i) {
                if ((mask | A[i]) == mask) {
                    ret += B[i];
                }
            }
            return ret;
        }

        if (!(K >> n & 1)) {
            Int ret = 0;
            for (int i = 0; i < N; ++i) {
                if (A[i] == 0) {
                    ret += B[i];
                }
            }
            return ret;
        }

        Int mask = ((K >> (n + 1)) << 1);
        for (int i = 0; i < n; ++i) {
            mask <<= 1;
            mask++;
        }

        Int ret = 0;
        for (int i = 0; i < N; ++i) {
            if ((mask | A[i]) == mask) {
                ret += B[i];
            }
        }
        return ret;
    }

    void solve() {
        cin >> N >> K;
        A.resize(N);
        B.resize(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i] >> B[i];
        }

        Int ans = 0;
        for (int i = -1; i <= 30; ++i) {
            chmax(ans, calc(i));
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
