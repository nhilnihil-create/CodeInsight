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

#define REP(i, m, n) for(int i=int(m);i<int(n);i++)
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

//ここから編集する


int main() {
    int H,W,N;
    cin >> H >> W >> N;
    map<pair<int,int>,int> mp;
    REP(i,0,N){
        int a,b;
        cin >> a >> b;
        for(int da = -1; da <= 1; ++da){
            for(int db = -1; db <= 1; ++db){
                mp[make_pair(a+da,b+db)]++;
            }
        }
    }
    vector<ll> ans(10,0L);
    for(auto it = mp.begin(); it != mp.end(); it++){
        if( it->first.first >= 2 && it->first.first <= H - 1 && it->first.second >= 2 && it->first.second <= W - 1 ){
            ans[it->second]++;
        }
    }
    ans[0] = 1LL*(H-2)*(W-2);
    REP(j,1,10){
        ans[0] -= ans[j];
    }
    REP(j,0,10){
        cout << ans[j] << endl;
    }
    return 0;
}
