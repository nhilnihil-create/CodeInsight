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

void solve() {
    int n;
    cin >> n;
    VI a(n);
    REP(i,0,n) cin >> a[i];
    VI pos(n);
    REP(i,0,n) pos[a[i]-1] = i;
    set<int> s;
    LL ans = 0;
    REP(i,0,n) {
        int l,r;
        auto it = s.lower_bound(pos[i]);
        if (it == s.begin()) l = -1;
        else l = *(--it);
        it = s.lower_bound(pos[i]);
        if (it == s.end()) r = n;
        else r = *it;
        ans += 1LL * (i+1) * (pos[i] - l) * (r - pos[i]);
        s.insert(pos[i]);
    }
    cout << ans << endl;
}

signed main() {
    solve();
    
    return 0;
}