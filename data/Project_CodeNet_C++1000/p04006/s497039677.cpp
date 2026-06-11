#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <memory>
#include <complex>
#include <numeric>
#include <cstdio>
#include <iomanip>
#include <random>

#define REP(i,m,n) for(int i=int(m);i<int(n);i++)
#define RREP(i,m,n) for(int i=int(n)-1;i>=int(m);--i)
#define EACH(i,c) for (auto &(i): c)
#define all(c) begin(c),end(c)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort(begin(c),end(c))
#define pb emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
//#define int long long

#ifdef LOCAL
#define DEBUG(s) cout << (s) << endl
#define dump(x)  cerr << #x << " = " << (x) << endl
#define BR cout << endl;
#else
#define DEBUG(s) do{}while(0)
#define dump(x) do{}while(0)
#define BR 
#endif
using namespace std;

using UI = unsigned int;
using UL = unsigned long;
using LL = long long;
using ULL = unsigned long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using VS = vector<string>;
using PII = pair<int,int>;
using VP = vector<PII>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

void solve() {
    LL n,x;
    cin >> n >> x;
    VLL a(n);
    REP(i,0,n) cin >> a[i];
    LL ans = 0;
    REP(i,0,n) ans += a[i];

    VVLL dp(n,VLL(n));
    REP(i,0,n) {
        dp[i][0] = a[i];
        REP(j,1,n) {
            int t = (i - j + n) % n;
            dp[i][j] = min(dp[i][j-1], a[t]);
        }
    }
    REP(j,1,n) {
        LL sum = 0;
        REP(i,0,n) sum += dp[i][j];
        chmin(ans, sum + x * j);
        dump(sum);
    }

    cout << ans << endl;
}

signed main() {
    solve();
    
    return 0;
}