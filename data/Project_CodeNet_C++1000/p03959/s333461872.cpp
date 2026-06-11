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

signed main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    VL T(N),A(N);
    VL conf(N,-1);
    REP(i,N){
        cin >> T[i];

        if(i == 0){
            conf[i] = T[i];
            //if(conf[i] > A[i]){
            //    cout << 0 << endl;
            //    return 0;
            //}
            continue;
        }
        if(T[i-1] != T[i]){
            conf[i] = T[i];
            //if(conf[i] > A[i]){
            //    cout << 0 << endl;
            //    return 0;
            //}

        }
    }

    REP(i,N) cin >> A[i];

    REP(i,N){
        dump(i)
        dump(conf[i])
        if(i == N-1){
            if(conf[i] == -1){
                conf[i] = A[i];
            }
            else{
                if(conf[i] != A[i]){
                    cout << 0 << endl;
                    return 0;
                }
            }
        }
        else{
            if(A[i] != A[i+1]){
                if(conf[i] == -1) conf[i] = A[i];
                else{
                    if(conf[i] != A[i]){
                        cout << 0 << endl;
                        return 0;
                    }
                }
            }
        }
    }
    //cout << printVector(conf) << endl;
    REP(i,N){
        if(conf[i] == 1) continue;

        if(min(T[i],A[i]) < conf[i]){
            cout << 0 << endl;
            return 0;
        }
    }

    LL ans = 1;
    REP(i,N){
        if(conf[i] != -1) continue;

        ans = (ans * min(T[i],A[i])) % MOD;
    }
    cout << ans << endl;
}