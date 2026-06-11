#include <iostream>
#include <vector>
#include <string.h>
#include <stack>
#include <queue>
#include <algorithm>
#include <climits>
#include <cmath>
#include <map>
#include <set>
#include <assert.h>
#include <sstream>
#define REP(i,n) for(ll i=0;i<(n);i++)
#define MOD 1000000007
#define int long long
#ifdef int
const long long INF = LLONG_MAX / 10;
#else
const int INF = 1010101010;
#endif
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> mat;
typedef pair<int, int> P;
//typedef pair<double, double> P;

#ifdef LOCAL
#define dump(...)                                         \
    do {                                                  \
        std::ostringstream os;                            \
        os << __LINE__ << ":\t" << #__VA_ARGS__ << " = "; \
        print_to(os, ", ", "\n", __VA_ARGS__);            \
        std::cerr << os.str();                            \
    } while (0)
#define dump_(a)                                          \
    do {                                                  \
        std::ostringstream os;                            \
        os << __LINE__ << ":\t" << #a << " = [";          \
        print_to_(os, ", ", "]\n", all(a));               \
        std::cerr << os.str();                            \
    } while (0)
#else
#define dump(...)
#define dump_(...)
#endif

template <typename T>
void print_to(std::ostream &os, const char *, const char *tail, const T &fst) {
    os << fst << tail;
}
template <typename Fst, typename... Rst>
void print_to(std::ostream &os, const char *del, const char *tail, const Fst &fst, const Rst &... rst) {
    os << fst << del;
    print_to(os, del, tail, rst...);
}
template <typename Iter>
void print_to_(std::ostream &os, const char *del, const char *tail, Iter bgn, Iter end) {
    for (Iter it = bgn; it != end;) {
        os << *it;
        if (++it != end) {
            os << del;
        } else {
            os << tail;
        }
    }
}
template <typename Fst, typename... Rst>
void println(const Fst &fst, const Rst &... rst) {
    print_to(std::cout, "\n", "\n", fst, rst...);
}
template <typename Fst, typename... Rst>
void print(const Fst &fst, const Rst &... rst) {
    print_to(std::cout, " ", "\n", fst, rst...);
}
template <typename Iter>
void println_(Iter bgn, Iter end) {
    print_to_(std::cout, "\n", "\n", bgn, end);
}
template <typename Iter>
void print_(Iter bgn, Iter end) {
    print_to_(std::cout, " ", "\n", bgn, end);
}

// const int MOD = 1000000007;
namespace trush {
    int _ = (std::cout.precision(10), std::cout.setf(std::ios::fixed), std::cin.tie(0),
             std::ios::sync_with_stdio(0), 0);
}

struct SegmentTree
{
private:
    int n;
    vector<int> node;

public:
    //元配列v(vector)をセグメント木で表現する
    SegmentTree(vector<int> v)
    {
        //最下段のノード数は元配列のサイズ以上になる最小の２冪→これをnとおく
        //セグメント木全体で必要なノード数は2n-1である
        int sz = v.size();
        n = 1;
        while (n < sz) n *= 2;
        node.resize(2 * n - 1, INF);

        //最下段に値を入れたあとに、下の段から埋めていく
        //値を埋めるときは自分の２つの子を見ればいい
        REP(i,sz) node[i+(n-1)] = v[i];
        for (int i=n-2; i>=0; i--) {
            //★セグ木の処理を書き換えるときはここを書き換える
            node[i] = min(node[2*i+1], node[2*i+2]);
        }
    }

    void update(int x, int val)
    {
        //最下段のノードにアクセスする
        x += n - 1;

        //最下段のノードを更新したら、あとは親に登って更新していく
        node[x] = val;
        while (x > 0) {
            //x=0でないなら親がある
            x = (x - 1) / 2;
            node[x] = min(node[2*x+1], node[2*x+2]);
        }
    }

    //要求区間[a,b)の要素の最小値を答える
    //k:=自分がいるノードのインデックス
    //対象区間は[l,r)にあたる
    int getmin(int a, int b, int k = 0, int l = 0, int r = -1)
    {
        //最初に呼び出されたときの対象区間は[0,n)
        if (r < 0) r = n;

        //要求区間と対象区間が交わらない→答えに影響を与えない値を返す
        //★セグ木の機能によって変える
        if (r <= a || b <= l) return INF;

        //要求区間が対象区間を完全に被覆→対象区間を答えの計算に使う
        if (a <= l && r <= b) return node[k];

        //要求区間が対象区間の一部を被覆→子について探索を行う
        //左の子をvl、右の子をvrとしている
        //新しい対象区間は現在の対象区間を半分にしたもの
        int vl = getmin(a, b, 2 * k + 1, l, (l + r) / 2);
        int vr = getmin(a, b, 2 * k + 2, (l + r) / 2, r);
        return min(vl, vr);
    }
};

int N, T;
vector<int> A;
map<int, int> cnt;
int maxDiff = 0;

signed main()
{
    cin >> N >> T;
    A.resize(N);
    REP(i,N) {
        cin >> A[i];
    }

    int mi = A[0];
    for (int i=1; i<N; i++) {
        int diff = A[i] - mi;
        cnt[diff]++;
        if (maxDiff < diff) {
            maxDiff = diff;
        }
        mi = min(mi, A[i]);
    }
    
    cout << cnt[maxDiff] << endl;
}
