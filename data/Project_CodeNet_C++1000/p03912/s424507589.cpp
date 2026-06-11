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
    int cnt[112345] = {};
    int add[112345] = {};
    int dat[112345] = {};

	for(int i=0;i<N;i++)
	{
		int z;
        cin >> z;
		cnt[z%M]++;
		dat[z]++;
	}
	for(int i=0;i<=100000;i++)
	{
		add[i%M]+=dat[i]/2;
	}

    int ans = 0;
    for(int i = 0; i+i <= M; i++){
        if(i == 0 || i+i == M){
            ans += cnt[i] / 2;
        }else{
            int s = cnt[i];
            int t = cnt[M-i];
            if(s < t) ans += s + min((t-s)/2,add[M-i]);
            else ans += t + min((s-t)/2, add[i]);
        }
    }
    cout << ans << endl;

}
