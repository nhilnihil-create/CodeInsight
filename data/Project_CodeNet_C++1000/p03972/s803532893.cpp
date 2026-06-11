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


int main() {
    int W, H;
    cin >> W >> H;
    vector<ll> p(W), q(H);
    vector<pair<ll,int> > v;
    rep(i, 0, W) {
        int inp;
        cin >> inp;
        v.emplace_back(inp,0);
    }
    rep(i, 0, H) {
        int inp;
        cin >> inp;
        v.emplace_back(inp,1);
    }

    sort(all(v));
    int a = W+1;
    int b = H+1;

    ll ans = 0ll;
    rep(i,0,v.size()){
        if(v[i].second == 0){
            a--;
            ans += b * v[i].first;
        }else{
            b--;
            ans += a * v[i].first;
        }
    }

    cout << ans << endl;
    return 0;
}
