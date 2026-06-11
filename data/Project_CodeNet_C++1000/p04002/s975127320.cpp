#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <tuple>
#include <cstdio>
#include <bitset>
#include <sstream>
#include <iterator>
#include <numeric>
#include <map>
#include <cstring>
#include <set>
#include <functional>
#include <iomanip>

using namespace std;

//#define DEBUG_ //!!提出時にコメントアウト!!
#ifdef DEBUG_
	#define dump(x)  cerr << #x << " = " << (x) << endl;
#else
	#define dump(x)  ;
#endif

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define SZ(x) ((int)(x).size())
#define pb push_back
#define eb emplace_back

//#define int long long

typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

template <typename T>
std::string printVector(const std::vector<T> &data)
{
    std::stringstream ss;
    std::ostream_iterator<T> out_it(ss, ", ");
    ss << "[";
    std::copy(data.begin(), data.end() - 1, out_it);
    ss << data.back() << "]";
    return ss.str();
}

const int MOD = 1e9+7;
const LL LINF = 1001002003004005006ll;
const int INF = 1001001001;

vector<PLL> point;
vector<PLL> area;

bool exist(LL x, LL y){
    int pos = lower_bound(point.begin(),point.end(),PLL(x,y)) - point.begin();
    if(pos < point.size() && point[pos] == PLL(x,y)) return true;
    else return false;
}

signed main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    LL H,W,N; cin >> H >> W >> N;
    dump("inp")
    REP(i,N){
        LL a,b; cin >> a >> b;
        a--; b--;
        dump("ok")
        point.eb(PLL(a,b));
        for(LL j = a-2; j <= a; j++){
            for(LL k = b-2; k <= b; k++){
                if(0 <= j && j+2 < H && 0 <= k && k+2 < W){
                    area.pb(PLL(j,k));
                }
            }
        }
    }
    dump("input")
    VL cnt(10,0);
    sort(area.begin(),area.end());
    area.erase(unique(area.begin(),area.end()),area.end());
    sort(point.begin(),point.end());
    cnt[0] = (H-2)*(W-2)-area.size();
    for(LL i = 0; i < area.size(); i++){
        LL x = area[i].first;
        LL y = area[i].second;
        int num = 0;
        for(LL j = x; j <= x+2; j++){
            for(LL k = y; k <= y+2; k++){
                if(exist(j,k)) num++;
            }
        }
        cnt[num]++;
    }
    REP(i,10){
        cout << cnt[i] << endl;
    }


}