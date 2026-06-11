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
 
#define REP(i,m,n) for(int i=int(m);i<int(n);i++)
#define RREP(i,m,n) for(int i=int(n)-1;i>=int(m);--i)
#define EACH(i,c) for (auto &(i): c)
#define all(c) begin(c),end(c)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort(begin(c),end(c))
#define pb emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
 
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
using LL = long long int;
using ULL = unsigned long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using VS = vector<string>;
using PII = pair<int,int>;
using VP = vector<PII>;
 
//struct edge {int from, to, cost;};
 
constexpr double EPS = 1e-10;
//constexpr double PI  = acos(-1.0);
//constexpr int INF = INT_MAX;
constexpr int MOD = 1'000'000'007;
//inline void modAdd(LL &l, LL &r) {l = (l + r) % MOD;}
 
template<class T> inline T sqr(T x) {return x*x;}
 
void solve() {
    int n,m;
    cin >> n >> m;
    vector<VP> d(m);
    map<int,int> cnt;
    int in;
    REP(i,0,n) {
        cin >> in;
        cnt[in]++;
    }
    for (auto p: cnt) {
        int key = p.first, value = p.second;
        d[key%m].pb(key, value);
    }
    REP(i,0,m) sort(all(d[i]), [](auto &l, auto &r) {
        return l.second % 2 > r.second % 2;
    });
    LL ans = 0;
    REP(i,1,(m+1)/2) {
        LL tmp = 0;
        LL sum1 = 0, sum2 = 0;
        REP(j,0,d[i].size()) sum1 += d[i][j].second;
        REP(j,0,d[m-i].size()) sum2 += d[m-i][j].second;
        //dump(sum1);
        //dump(sum2);
        int n = abs(sum1 - sum2);
        if (sum1 <= sum2) {
            tmp += sum1;
            RREP(j,0,d[m-i].size()) {
                if (d[m-i][j].second <= n) {
                    tmp += d[m-i][j].second / 2;
                    n -= (d[m-i][j].second / 2) * 2;
                } else {
                    tmp += n / 2;
                    break;
                }
            }
        } else {
            tmp += sum2;
            RREP(j,0,d[i].size()) {
                if (d[i][j].second <= n) {
                    tmp += d[i][j].second / 2;
                    n -= (d[i][j].second / 2) * 2;
                } else {
                    tmp += n / 2;
                    break;
                }
            }
        }
        ans += tmp;
        //dump(i);
        //dump(tmp);
    }
    if (m % 2 == 0) {
        LL tmp = 0;
        REP(i,0,d[m/2].size()) tmp += d[m/2][i].second;
        ans += tmp / 2;
    }
    LL tmp = 0;
    REP(i,0,d[0].size()) tmp += d[0][i].second;
    ans += tmp / 2;
    cout << ans << endl;
}
 
int main() {
    solve();
    
    return 0;
}