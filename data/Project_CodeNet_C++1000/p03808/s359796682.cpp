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
    LL N; cin >> N;
    VL A(N);
    LL sum = 0;
    REP(i,N) {
        cin >> A[i];
        sum += A[i];
    }

    if(sum % (N*(N+1)/2) != 0){
        cout << "NO" << endl;
        return 0;
    }
    LL loop = sum / (N*(N+1)/2);
    VL dif(N);

    REP(i,N-1){
        dif[i] = A[i+1] - A[i];
    }
    dif[N-1] = A[0] - A[N-1];
    LL acc = 0;
    dump(loop)
    REP(i,N){
        dump(dif[i])
        if((dif[i] - loop) % (-N) != 0 || (dif[i]-loop) > 0){
            cout << "NO" << endl;
            return 0;
        }

        dump((dif[i] - loop) / (-N))
        acc += (dif[i] - loop) / (-N);
    }
    if(acc != loop){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
    }



}