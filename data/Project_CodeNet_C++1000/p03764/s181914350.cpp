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

#define rep(i, m, n) for(int i=int(m);i<int(n);i++)
#define EACH(i, c) for (auto &(i): c)
#define all(c) begin(c),end(c)
#define EXIST(s, e) ((s).find(e)!=(s).end())
#define SORT(c) sort(begin(c),end(c))
#define pb emplace_back
#define MP make_pair
#define SZ(a) int((a).size())

//#define LOCAL 0
//#ifdef LOCAL
//#define DEBUG(s) cout << (s) << endl
//#define dump(x)  cerr << #x << " = " << (x) << endl
//#define BR cout << endl;
//#else
//#define DEBUG(s) do{}while(0)
//#define dump(x) do{}while(0)
//#define BR
//#endif


//改造
typedef long long int ll;
using namespace std;
#define INF (1 << 20)
#define INFl (ll)5e15
#define DEBUG 0 //デバッグする時1にしてね
#define dump(x)  cerr << #x << " = " << (x) << endl

//ここから編集する
#define MOD 1000000007

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> x(n), dx;
    vector<ll> y(m), dy;
    rep(i, 0, n) {
        cin >> x[i];
    }
    rep(i, 0, m) {
        cin >> y[i];
    }
    rep(i, 0, n - 1) {
        dx.push_back(x[i + 1] - x[i]);
    }
    rep(i, 0, m - 1) {
//        cin >> y[i];
        dy.push_back(y[i + 1] - y[i]);
    }

    ll sum_x = 0LL;
    rep(i, 0, n - 1) {
        int a1 = i + 1;
        int b1 = dx.size() - i;
//        sum_x = (dx[i] * (i + 1) * (n - 1 - i) + sum_x) % MOD;
        sum_x = ((dx[i] * (i + 1) % MOD) * (n - 1 - i) + sum_x) % MOD;
    }
    ll ans = 0LL;
    rep(i, 0, m - 1) {
//        sum_x = (x[i] * (i + 1) * (n - i) + sum_x) % MOD;
        int a1 = i + 1;
        int b1 = n - i - 1;
        ans = (ans + ((sum_x * dy[i] % MOD) * (i + 1) % MOD) * (m - 1 - i)) % MOD;
    }
    cout << ans << endl;
    return 0;
}
