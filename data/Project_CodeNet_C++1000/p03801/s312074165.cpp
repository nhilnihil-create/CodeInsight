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

#define EPS (1e-10)
#define equals(a,b) (fabs((a)-(b)) < EPS)
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

signed main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N; cin >> N;
    VI a(N);
    map<int,LL> mpcnt;
    map<int,LL> mparg;
    LL sum = 0;
    REP(i,N){
        cin >> a[i];
        mpcnt[a[i]]++;
        if(mparg[a[i]] != 0){
            mparg[a[i]] = min(mparg[a[i]],LL(i+1));
        }else{
            mparg[a[i]] = i+1;
        }
        sum += a[i];
    }
    VL ans(N+1);

    for(auto itr = mpcnt.end(); itr != next(mpcnt.begin(),1); itr--){
        auto pitr = prev(itr,1);
        auto qitr = prev(itr,2);
        dump(pitr->first)
        dump(pitr->second)
        dump(qitr->first)
        dump(qitr->second)


        ans[mparg[pitr->first]] += pitr->second * (pitr->first - qitr->first);
        //cout << "num:" << mparg[pitr->first] << endl;
        //cout << "add:" << pitr->second * (pitr->first - qitr->first) << endl;


        qitr->second += pitr->second ;
        mparg[qitr->first] = min(mparg[qitr->first],mparg[pitr->first]);


        //if(itr == next(mpcnt.begin(),2)){

        //}
    }
    FOR(i,1,N+1){
        sum -= ans[i];
    }
    ans[1] += sum;

    FOR(i,1,N+1){
        cout << ans[i] << endl;
    }



}
