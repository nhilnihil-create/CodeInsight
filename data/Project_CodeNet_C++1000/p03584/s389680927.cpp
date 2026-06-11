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

int nth_bit(int x, int n){
    return (x >> n) & 1;
}

signed main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,K; cin >> N >> K;
    vector<string> c;
    VI A(N);
    VL B(N);
    REP(i,N) cin >> A[i] >> B[i];

    string ck;
    REP(_,32){
        ck += char('0'+K%2);
        K /= 2;
    }
    reverse(ck.begin(),ck.end());
    c.eb(ck);
    int ck_len = ck.length();

    FOR(i,0,ck_len){
        if(ck[i] == '1'){
            string tmp = ck.substr(0,i);
            tmp += '0';
            tmp += string(ck_len-1-i,'1');
            c.eb(tmp);
        }
    }

    LL ans = 0;
    for(auto s : c){
        reverse(s.begin(),s.end());
        LL tmp = 0;
        REP(i,N){
            bool ok = 1;
            REP(j,32){
                if(nth_bit(A[i],j) == 0 || s[j] == '1'){

                }else{
                    ok = 0;
                }
            }
            if(ok) tmp += B[i];
        }
        ans = max(ans,tmp);
    }
    cout << ans << endl;




}
