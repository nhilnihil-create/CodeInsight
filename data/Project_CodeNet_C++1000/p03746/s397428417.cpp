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

#define DEBUG_ //!!提出時にコメントアウト!!
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

VI adj[112345];


signed main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,M; cin >> N >> M;
    REP(i,M){
        int a,b; cin >> a >> b;
        a--; b--;
        adj[a].eb(b);
        adj[b].eb(a);
    }
    int sa,sb;
    sa = 0;
    sb = adj[sa][0];

    VI ans1,ans2;
    ans1.eb(sa);
    ans2.eb(sb);
    int contain[112345] = {};
    contain[sa] = 1;
    contain[sb] = 1;
    int ta = sa;

    while(1){
        bool flag = 0;
        for(auto i : adj[ta]){
            if(contain[i] == 0){
                contain[i] = 1;
                ta = i;
                flag = 1;
                ans1.eb(i);
                break;
            }
        }
        if(!flag){
            break;
        }
    }
    ta = sb;

    while(1){
        bool flag = 0;
        for(auto i : adj[ta]){
            if(contain[i] == 0){
                contain[i] = 1;
                ta = i;
                flag = 1;
                ans2.eb(i);
                break;
            }
        }
        if(!flag){
            break;
        }
    }
    cout << ans1.size() + ans2.size() << endl;
    reverse(ans1.begin(),ans1.end());
    for(int i : ans1){
        cout << i+1 << " ";
    }
    for(int i : ans2){
        cout << i+1 << " ";
    }
    cout << endl;



}
