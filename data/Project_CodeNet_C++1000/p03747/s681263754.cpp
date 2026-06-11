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
#define INF (1 << 30)
#define INFl (ll)5e15
#define DEBUG 0 //デバッグする時1にしてね
#define dump(x)  cerr << #x << " = " << (x) << endl
#define MOD 1000000007
//ここから編集する
ll L, T;

ll calc(ll a, ll b) {
//    ll ret = T / L * 2;
//    ll t = (T % L) * 2;
//
//    if (((b - a) % L + L) % L <= 2 * (T % L) && a != b) {
////        ret++;
//        ll diff = ((b - a) % L + L) % L;
//        if(t > diff){
//            ret++;
//            t -= diff;
//        }
//        if(t >= L) ret++;
////        if (t > L) ret++;
//    }
//    return ret;
    ll t = T * 2;
    ll diff = ((b - a) % L + L) % L;
    ll ret = 0;
    ret += t / L;
    t %= L;
    if (a != b && t >= diff) ret++;
    return ret;

}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N >> L >> T;
    vector<ll> x(N), w(N), y(N), z(N);
    rep(i, 0, N) {
        cin >> x[i] >> w[i];
    }
    ll diff = 0;

    rep(i, 0, N) {
        if (w[i] == 1) {
            y[i] = (x[i] + T) % L;
        } else {
            y[i] = (x[i] - T) % L;
            if (y[i] < 0) y[i] += L;
        }
    }

    if (w[0] == 1) {
        rep(i, 0, N) {
            if (w[0] != w[i]) {
                diff += calc(x[0], x[i]);
                diff %= N;
            }
        }
    } else {
        rep(i, 0, N) {
            if (w[0] != w[i]) {
                diff -= calc(x[i], x[0]);
                diff %= N;
                diff += N;
                diff %= N;
            }
        }
    }
    if (DEBUG) {
        cout << diff << endl;
    }
    ll ini_p = y[0];
    sort(all(y));
    int start = upper_bound(all(y), ini_p) - y.begin() - 1;
    if (w[0] == 2) start = lower_bound(all(y), ini_p) - y.begin();
    if (start < 0) start += N;
    rep(i, 0, N) {
//        z[i] = y[(i + diff + N) % N];
        z[(i + diff) % N] = y[(i + start) % N];
    }
    rep(i, 0, N) {
        cout << z[i] << endl;
    }
//    cout << "--" << endl;
//    cout << start << endl;
//    cout << diff << endl;

    return 0;
}
