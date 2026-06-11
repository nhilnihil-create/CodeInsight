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
void add(int s, int t, vector<ll> &imos) {
    if (s < t) {
        imos[s + 1]++;
        imos[t]--;
    } else {
        imos[s + 1]++;
        imos.back()--;
        imos[1]++;
        imos[t]--;
    }
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }
    vector<ll> fueru(m + 1), imos(m + 2);

    rep(i, 0, n - 1) {
        add(a[i], a[i + 1], imos);
        fueru[a[i + 1]] += (a[i + 1] - a[i] + m) % m - 1;
    }
    rep(i, 0, m + 1) {
        imos[i + 1] += imos[i];
    }
    ll ans = 0;
    ll cnt = 0;
    rep(i, 0, n-1) {
        ans += min((a[i + 1] - a[i] + m) % m, 1 + (a[i + 1] - 1 + m) % m);
    }
    cnt = ans;
    rep(c,1,m){
        cnt -= imos[c];
        cnt += fueru[c];
        ans = min(ans,cnt);
    }
    cout << ans << endl;


    return 0;
}
