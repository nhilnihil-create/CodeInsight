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

//改造
typedef long long int ll;
using namespace std;
#define INF (1 << 30) - 1
#define INFl (ll)5e15
#define DEBUG 0 //デバッグする時1にしてね
#define dump(x)  cerr << #x << " = " << (x) << endl
#define MOD 1000000007


//ここから編集する
class Solve {
public:
    int n, N;
    vector<int> a;

    void input() {
        cin >> n;
        N = 2 * n - 1;
        a.resize(N);
        rep(i, 0, N) cin >> a[i];

    }

    bool check(int k) {
        vector<int> b(N);
        rep(i, 0, N) b[i] = a[i] >= k;

        int mid_p = N / 2;
        if (b[mid_p] == b[mid_p - 1] || b[mid_p] == b[mid_p + 1]) {
            return b[mid_p];
        }

        int l = mid_p;
        int r = mid_p;
        while (l > 0 && b[l] ^ b[l - 1]) l--;
        while (r + 1 < N && b[r] ^ b[r + 1]) r++;

        if (r - mid_p > mid_p - l) {
            return b[l];
        } else {
            return b[r];
        }
    }

    void solve() {
        input();
        int lb = 0;
        int ub = N;

        while (ub - lb > 1) {
            int mid = (lb + ub) / 2;
            if (check(mid)) {
                lb = mid;
            } else {
                ub = mid;
            }
        }

        cout << lb << endl;


    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    Solve().solve();


    return 0;
}
