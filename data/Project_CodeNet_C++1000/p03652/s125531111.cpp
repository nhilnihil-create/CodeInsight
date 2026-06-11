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
    int N,M; cin >> N >> M;
    vector<VI> A(N,VI(M));
    REP(i,N) REP(j,M){
        cin >> A[i][j];
        A[i][j]--;
    }

    VI se(M);
    REP(i,M){
        se[i] = 1;
    }
    int ans = INF;
    if(M==1){
        cout << N << endl;
        return 0;
    }
    REP(i,M-1){
        VI cnt(M);
        REP(j,N){
            REP(k,M){
                if(se[A[j][k]] == 1){
                    cnt[A[j][k]]++;
                    break;
                }
            }
        }
        int tmax = -1;
        int arg = -1;
        REP(j,M){
            if(cnt[j] > tmax){
                arg = j;
                tmax = cnt[j];
            }

        }
        ans = min(tmax, ans);
        se[arg] = 0;
    }
    cout << ans << endl;

}
