#include <iostream>
#include <iomanip>
#include <bitset>
#include <string>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<vector>
#include<tuple>
#include<sstream>
#include<functional>
#include<list>
#include<queue>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<int, int> P;
typedef pair<ll, ll> p;
typedef vector<int> vec;
using Graph = vector<vector<int>>;
using graph = vector<vector<ll>>;

const ll inf = (1LL<<31)-1;
const long long MOD = 1000000007;

struct SegmentTree {
    int n;
    vector<ll> node;

public:
    // 元配列 v をセグメント木で表現する
    SegmentTree(vector<ll> v) {
        // 最下段のノード数は元配列のサイズ以上になる最小の 2 冪 -> これを n とおく
        // セグメント木全体で必要なノード数は 2n-1 個である
        int sz = v.size();
        n = 1; while (n < sz) n *= 2;
        node.assign(2 * n - 1, inf);

        // 最下段に値を入れたあとに、下の段から順番に値を入れる
        // 値を入れるには、自分の子の 2 値を参照すれば良い
        for (int i = 0; i < sz; i++) node[i + n - 1] = v[i];
        for (int i = n - 2; i >= 0; i--) node[i] = min(node[2 * i + 1], node[2 * i + 2]);
    }

    void update(ll x, ll val) {
        // 最下段のノードにアクセスする
        x += (n - 1);

        // 最下段のノードを更新したら、あとは親に上って更新していく
        node[x] = val;
        while (x > 0) {
            x = (x - 1) / 2;
            node[x] = min(node[2 * x + 1], node[2 * x + 2]);
        }
    }

    // 要求区間 [a, b) 中の要素の最小値を答える
// k := 自分がいるノードのインデックス
// 対象区間は [l, r) にあたる

    int getmin(ll a, ll b, ll k = 0, ll l = 0, ll r = -1) {
        // 最初に呼び出されたときの対象区間は [0, n)
        if (r < 0) r = n;

        // 要求区間と対象区間が交わらない -> 適当に返す
        if (r <= a || b <= l) return inf;

        // 要求区間が対象区間を完全に被覆 -> 対象区間を答えの計算に使う
        if (a <= l && r <= b) return node[k];

        // 要求区間が対象区間の一部を被覆 -> 子について探索を行う
        // 左側の子を vl ・ 右側の子を vr としている
        // 新しい対象区間は、現在の対象区間を半分に割ったもの
        ll vl = getmin(a, b, 2 * k + 1, l, (l + r) / 2);
        ll vr = getmin(a, b, 2 * k + 2, (l + r) / 2, r);
        return min(vl, vr);
    }
};

int main() {
    ll n, x;
    cin >> n >> x;
    vector<ll> v(n*2);
    rep(i, n) {
        cin >> v[i];
        v[i + n] = v[i];
    }
    SegmentTree tree(v);
    ll ans = INF;
    vector<ll> V = v;
    rep(i, n ) {
        ll A = 0;
        repd(j, n, n * 2) {
            V[j] = min(V[j], v[j - i]);
            A += V[j];
        }
        A += i * x;
        ans= min(ans, A);
    }
    cout << ans << endl;
    return 0;
}