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

    Int N = -1;

    void init() {
        cin >> N;
    }

    bool query(Int n) {
        string S;
        if (N == -1) {
            cout << "? " << n << endl;
            cin >> S;
        } else {
            bool ret = (n <= N) ^(to_string(n) <= to_string(N));
            if (!ret) {
                S = "Y";
            } else {
                S = "N";
            }
        }

//        cerr << "? " << n << endl;
//        cerr << S << endl;
//        cerr << " --- " << endl;

        return S == "Y";
    }

    void solve() {
        Int d = 11;
        while (d > 0) {
            bool f = query(static_cast<Int>(round(floor(pow(10ll, d - 1)))));
            if (f) {
                break;
            }
            d--;
        }
        if (d == 11) {
            while (d > 0) {
                bool f = query(2 * static_cast<Int>(round(floor(pow(10ll, d - 1)))));
                if (!f) {
                    break;
                }
                d--;
            }
            d++;
            Int ans = static_cast<Int>(round(floor(pow(10ll, d - 1))));
            cout << "! " << ans << endl;
            return;

        }

        Int ub = round(floor(pow(10, d)));
        Int lb = ub / 10;
        while (ub - lb > 1) {
            Int mid = (ub + lb) / 2;
            Int n = static_cast<Int>(mid * round(floor(pow(10, 9))));
            bool f = query(n);
            if (f) {
                ub = mid;
            } else {
                lb = mid;
            }
        }

        cout << "! " << lb + 1 << endl;
    }
};


int main() {
//    cin.tie(0);
//    ios::sync_with_stdio(false);
//    cout << fixed << setprecision(10);

    Solve solve;
//    solve.init();
    solve.solve();

//    Solve().solve();


    return 0;
}
