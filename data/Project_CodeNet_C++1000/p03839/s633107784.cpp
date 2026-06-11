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
    int n,k;
    cin >> n >> k;
    VLL a(n);
    REP(i,0,n) cin >> a[i];
    VLL ru(n+1), ss(n);
    REP(i,0,n) ru[i+1] = ru[i] + max(0LL, a[i]);
    REP(i,0,k) ss[k-1] += a[i];
    REP(i,k,n) ss[i] = ss[i-1] + a[i] - a[i-k];
    LL ans = ru[n-k];
    REP(i,k-1,n) {
        chmax(ans, ru[n]-ru[i+1]+ru[i+1-k] + max(0LL, ss[i]));
    }
    cout << ans << endl;
}

signed main() {
    solve();
    
    return 0;
}