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

const int MOD = 1e9+7;
const LL LINF = 1001002003004005006ll;
const int INF = 1001001001;

//ここから書き始める
int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);	
    int N, T; cin >> N >> T;
    VI A(N);
    VI MAX_A(N);
    VI diff(N);
    REP(i,N)
    {
        cin >> A[i];
    }
    int tmpmax = 0;

    for(int i = N - 1; i >= 0; i--)
    {
        MAX_A[i] = max(tmpmax, A[i]);
        tmpmax = MAX_A[i];
        dump(MAX_A[i])
    }
    REP(i,N-1)
    {
        diff[i] = MAX_A[i+1] - A[i];
        dump(diff[i])
    }
    sort(diff.begin(), diff.end(), greater<int>());
    LL difmax = diff[0];
    int ans = 0;
    REP(i,N-1)
    {
        if(diff[i] == difmax) ans++;
        else break;
    }
    cout << ans << endl;

}
