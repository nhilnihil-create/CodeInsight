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

using namespace std;

//#define DEBUG_ //!!提出時にコメントアウト!!
#ifdef DEBUG_
	#define dump(x)  cerr << #x << " = " << (x) << endl;
#else
	#define dump(x)  ; //何もしない文
#endif

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define SZ(x) ((int)(x).size()) //unsignedのサイズをint型に変換
#define pb push_back
#define eb emplace_back

//#define int long long

typedef long long LL;
typedef vector<int> VI;
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

const LL MOD = 1e9+7;
const LL LINF = 1001002003004005006ll;
const int INF = 1001001001;

inline LL add(LL x,LL y)
{
    return (x + y)%MOD;
}

inline LL sub(LL x,LL y)
{
    return (x+MOD-y)%MOD;
}

inline int mul(int x,int y)
{
    return (LL)x*y%MOD;
}

signed main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    LL n,m; cin>>n>>m;
    vector<LL> x(n),y(m);
    REP(i,n) cin>>x[i];
    REP(j,m) cin>>y[j];

    LL el1=0,el2=0;
    REP(k,n)
    {
        //if(k*x[k] > 0){
            el1 = add(el1, k*x[k]);
        //}
        //else el1 = sub(el1,k*x[k]);

        //if(el1 < 0) el1 += MOD;
        //if((n-k-1LL)*x[k] > 0){
            el1 = sub(el1, (n-k-1LL)*x[k]);
        //}
        //else el1 = add(el1,(n-k-1LL)*x[k]);
        //if(el1 < 0) el1 += MOD;
    }
    dump(el1)
    REP(k,m)
    {
        //if(k*y[k] > 0){
            el2 = add(el2, k*y[k]);
        //}
        //else el2 = sub(el1,k*y[k]);


        el2 = sub(el2, (m-k-1LL)*y[k]);
        //if(el2 < 0) el2 += MOD;

    }
    dump(el2)
    LL ans = el1 * el2 % MOD;
    //if(ans < 0) ans += MOD;
    cout << ans << endl;

}