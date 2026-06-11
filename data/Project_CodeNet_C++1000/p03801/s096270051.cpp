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

template <typename T=int>
struct BIT {
    const int n;
    vector<T> v;

    BIT(int n): n(n), v(n+1,0) {}

    void add(int i, int x) {
        i += 1;
        while (i <= n) {
            v[i] += x;
            i += i & -i;
        }
    }
    T sum(int i) {
        i += 1;
        T ret = 0;
        while (i > 0) {
            ret += v[i];
            i -= i & -i;
        }
        return ret;
    }
    T sum(int l, int r) {
        return sum(r) - sum(l-1);
    }
};

void solve() {
    int n;
    cin >> n;
    VI a(n);
    REP(i,0,n) cin >> a[i];

    VP ps(n);
    REP(i,0,n) ps[i] = MP(a[i],i);
    ps.pb(0,-1);
    sort(all(ps));
    reverse(all(ps));

    VLL ans(n);

    int mini = n;
    REP(i,0,n) {
        int idx = ps[i].second;
        chmin(mini, idx);
        ans[mini] += (1LL + i) * (ps[i].first - ps[i+1].first);
    }

    REP(i,0,n) cout << ans[i] << endl;
}

signed main() {
    solve();
    
    return 0;
}