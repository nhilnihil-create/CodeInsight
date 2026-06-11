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
    string ok = "Possible";
    string ng = "Impossible";

    VI a(N);
    int cnt[200] = {};
    REP(i,N){
        cin >> a[i];
        cnt[a[i]]++;
    }
    sort(a.begin(),a.end(),greater<int>());
    dump(a[0])

    if(a[0]%2 == 0){
        for(int i = a[0]; i >= a[0]/2 + 1; i--){
            if(cnt[i] < 2){
                cout << ng << endl;
                return 0;
            }else{
                cnt[i] -= 2;
            }
        }
        if(cnt[a[0]/2] == 0){
            cout << ng << endl;
            return 0;
        }else{
            cnt[a[0]/2]--;
        }
    }else{
        for(int i = a[0]; i >= (a[0]+1)/2; i--){
            dump(i)
            if(cnt[i] < 2){
                cout << ng << endl;
                return 0;
            }else{
                cnt[i] -= 2;
            }
        }
    }
    dump("check")

    for(auto i : a){
        if(cnt[i] == 0) continue;

        dump(i)
        dump(cnt[i])

        if(a[0]%2 == 0){
            if((i-1) > a[0] || (i-1) < a[0]/2){
                cout << ng << endl;
                return 0;
            }
        }else{
            if((i-1) > a[0] || (i-1) < (a[0]+1)/2){
                cout << ng << endl;
                return 0;
            }

        }
    }
    cout << ok << endl;


}
