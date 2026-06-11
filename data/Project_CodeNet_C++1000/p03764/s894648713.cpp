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
#define MOD 1000000007
//ここから編集する


int main() {
    int n,m;
    cin >> n >> m;
    vector<ll> x,y;
    rep(i,0,n){
        ll tmp;
        cin >> tmp;
        x.push_back(tmp);
    }
    rep(i,0,m){
        ll tmp;
        cin >> tmp;
        y.push_back(tmp);
    }
    sort(all(x));
    sort(all(y));
    vector<ll> dx,dy;
    rep(i,1,x.size()){
        dx.push_back(x[i]-x[i-1]);
    }
    rep(i,1,y.size()){
        dy.push_back(y[i]-y[i-1]);
    }
    vector<ll> hx(n-1),hy(m-1);
    hx[0] = n-1;
    hy[0] = m-1;
    for(int i = 0; i < n-2; i++){
        hx[i+1] += hx[i] + ((n-1) - (i+1) * 2);
    }
    for(int i = 0; i < m-2; i++){
        hy[i+1] += hy[i] + ((m-1) - (i+1) * 2);
    }
    for(int i = 0; i < n; i++){
        hx[i] %= MOD;
    }
    for(int i = 0; i < m; i++){
        hy[i] %= MOD;
    }
    ll xx = 0;
    rep(i,0,dx.size()){
        xx += dx[i] * hx[i];
        xx %= MOD;
    }
    ll yy = 0;
    rep(i,0,dy.size()){
        yy += dy[i] * hy[i];
        yy %= MOD;
    }
    ll ans = xx * yy % MOD;

    cout << ans << endl;



    return 0;
}
