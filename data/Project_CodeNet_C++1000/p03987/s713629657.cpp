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

template<typename T = long long>
class SegmentTree {
public:
    std::vector<T> ary;
    int n;
    const T default_value = std::numeric_limits<T>::max() / 4;
    SegmentTree(int n) {
        this->n = 1;
        while (this->n < n) this->n *= 2;
        ary.resize(this->n * 2 - 1, 1<<30);
    }
    T ope(T l, T r) {
        return std::min(l, r);
    }
    void update(int k, T d) {
        k += n - 1;
        ary[k] = d;
        while (k > 0) {
            k = (k - 1) / 2;
            ary[k] = ope(ary[2 * k + 1], ary[2 * k + 2]);
        }
    }
    T query(int a, int b) {
        return query(a, b, 0, n, 0);
    }
    T query(int a, int b, int l, int r, int i) {
        if (a <= l && b >= r) return ary[i];
        if (a >= r || b <= l) return default_value; // min
        int m = (l + r) / 2;
        T vl = query(a, b, l, m, 2 * i + 1);
        T vr = query(a, b, m, r, 2 * i + 2);
        return ope(vl, vr);
    }
};

void solve() {
    int n;
    cin >> n;
    VLL a(n);
    REP(i,0,n) cin >> a[i];
    SegmentTree<> seg(n);
    REP(i,0,n) seg.update(i,a[i]);
    LL ans = 0;
    REP(i,0,n) {
        int l, r;
        {
            int ok = i, ng = -1;
            while (abs(ok - ng) > 1) {
                int mid = (ok + ng) / 2;
                if (seg.query(mid,i+1) == a[i]) ok = mid;
                else ng = mid;
            }
            l = abs(i - ok) + 1;
        }
        {
            int ok = i, ng = n;
            while (abs(ok - ng) > 1) {
                int mid = (ok + ng) / 2;
                if (seg.query(i,mid+1) == a[i]) ok = mid;
                else ng = mid;
            }
            r = abs(i - ok) + 1;
        }
        ans += a[i] * (1LL * l * r);
    }
    cout << ans << endl;
}

signed main() {
    solve();
    
    return 0;
}