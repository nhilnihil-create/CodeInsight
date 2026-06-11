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

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

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

template <typename T>
void print_array(const T &ary, int size){
    REP(i,size){
        cout << ary[i] << " ";
    }
    cout << endl;
}

const int mod = 1e9+7;
const LL LINF = 1001002003004005006ll;
const int INF = 1001001001;
const double EPS = (1e-10);
const long double PI = 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899;

template< typename T >
struct Compress {
    vector< T > xs;

    Compress() = default;

    Compress(const vector< T > &vs) {
        add(vs);
    }

    Compress(const initializer_list< vector< T > > &vs) {
        for(auto &p : vs) add(p);
    }

    void add(const vector< T > &vs) {
        copy(begin(vs), end(vs), back_inserter(xs));
    }

    void add(const T &x) {
        xs.emplace_back(x);
    }

    void build() {
        sort(begin(xs), end(xs));
        xs.erase(unique(begin(xs), end(xs)), end(xs));
    }

    vector< int > get(const vector< T > &vs) const {
        vector< int > ret;
        transform(begin(vs), end(vs), back_inserter(ret), [&](const T &x) {
                return lower_bound(begin(xs), end(xs), x) - begin(xs);
                });
        return ret;
    }

    int get(const T &x) const {
        return lower_bound(begin(xs), end(xs), x) - begin(xs);
    }

    const T &operator[](int k) const {
        return xs[k];
    }
};

template< typename Monoid >
struct SegmentTree {
    using F = function< Monoid(Monoid, Monoid) >;

    int sz;
    vector< Monoid > seg;

    const F f;
    const Monoid M1;

    SegmentTree(int n, const F f, const Monoid &M1) : f(f), M1(M1) {
        sz = 1;
        while(sz < n) sz <<= 1;
        seg.assign(2 * sz, M1);
    }

    void set(int k, const Monoid &x) {
        seg[k + sz] = x;
    }

    void build() {
        for(int k = sz - 1; k > 0; k--) {
            seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
        }
    }

    void update(int k, const Monoid &x) {
        k += sz;
        seg[k] = x;
        while(k >>= 1) {
            seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
        }
    }

    Monoid query(int a, int b) {
        Monoid L = M1, R = M1;
        for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
            if(a & 1) L = f(L, seg[a++]);
            if(b & 1) R = f(seg[--b], R);
        }
        return f(L, R);
    }

    Monoid operator[](const int &k) const {
        return seg[k + sz];
    }
};

signed main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(12);

    LL N,K; cin >> N >> K;
    VL a(N),S(N+1);
    REP(i,N){
        cin >> a[i];
        S[i+1] = S[i] + a[i];
    }
    VL A;
    REP(i,N){
        A.eb(S[i+1]-K*(i+1));
    }
    //REP(i,N){
    //    cout << A[i] << " ";
    //}
    //cout << endl;
    //REP(i,N){
    //    cout << B[i] << " ";
    //}
    //cout << endl;


    Compress<LL> comp;
    comp.add(A);
    comp.add(0);
    comp.build();
    auto f = [](LL a, LL b){return a+b;};
    SegmentTree<LL> seg(N+10,f,0);
    seg.update(comp.get(0),1);
    LL ans = 0;
    REP(i,N){
        ans += seg.query(0,comp.get(A[i])+1);
        seg.update(comp.get(A[i]), seg[comp.get(A[i])]+1);
    }
    cout << ans << endl;


}