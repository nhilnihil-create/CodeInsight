#include <iostream>

#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include<cstdio>
#include<iomanip>
#include<stack>
#include<queue>
#include<string>
#include <cstdlib>
#include <typeinfo>
#include <math.h>
#include <list>

#define REP(i, n) for(int i=0;i<n;i++)
#define REP2(i, s, n) for(int i=s;i<n;i++)
#define REP_1(i, n) for(int i=1;i<n+1;i++)
#define bitSearch(bit, n) for(int bit = 0; bit < (1 << n); bit++)
using namespace std;

template<class T>
void print(const T &value) {
    std::cout << value << std::endl;
}

void yesno(bool a) { if (a)cout << "yes" << endl; else cout << "no" << endl; }

void YesNo(bool a) { if (a)cout << "Yes" << endl; else cout << "No" << endl; }

void YESNO(bool a) { if (a)cout << "YES" << endl; else cout << "NO" << endl; }

typedef long long ll;
typedef unsigned long ul;
typedef long double ld;

template<class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

ll INF = 10000000;
ll mod = 1000000007;//10^9+7
int dx[8] = {-1, 0, 0, 1, -1, -1, 1, 1};
int dy[8] = {0, -1, 1, 0, -1, 1, -1, 1};
using Graph = vector<vector<int>>;//隣接リスト:G[i]にはiと隣接する頂点が入るよ。
using GraphW = vector<vector<pair<int, int>>>;//重み付きの隣接リスト
using P = pair<int, int>;//BFSで利用。queueに入れる。
using lP = pair<ll, ll>;
using PP = pair<int, P>; //dijkstraで利用,priority_queueに入れる。
using p_queue = priority_queue<int, vector<int>, greater<int>>;//小さい順
//struct edge{int to, cost};

class UnionFindTree {

public:
    UnionFindTree(int size) : memberSize(size) {
        par.resize(size * sizeof(ll));
        rnk.resize(size * sizeof(ll));
        diff_weight.resize(size * sizeof(ll));
        REP(i, size) {
            par[i] = i;
            rnk[i] = 0;
            diff_weight[i] = 0;
        }
    }

    int memberSize;

    vector<int> par;
    vector<int> rnk;
    vector<ll> diff_weight;

//n個のnodeで初期化する関数
    void init(ll n) {
        REP(i, n) {
            par[i] = i;
            rnk[i] = 1;
        }
    }

//木の根を求める。この際，親は根に更新される。
    int find(ll x) {
        if (par[x] == x) { return x; }
        else {
            int r = find(par[x]);
            diff_weight[x] += diff_weight[par[x]];
            return par[x] = r;
        }
    }

//xとyが同じ集合に属するか判定
    bool same(ll x, ll y) {
        return find(x) == find(y);
    }

//xとyの属する集合を融合
    void unite(ll x, ll y) {
        x = find(x);
        y = find(y);
        if (x == y) { return; }

        if (rnk[x] < rnk[y]) {
            par[x] = y;
        } else {
            par[y] = x;
            if (rnk[x] == rnk[y]) { rnk[x]++; }
        }
    }

    //xの重み
    ll weight(ll x) {
        find(x);
        return diff_weight[x];
    }

    ll diff(ll x, ll y) {
        return weight(y) - weight(x);
    }

    //重みごと更新。weight(y)-weight(x)=wとなるようにする
    void merge(int x, int y, int w) {
        w += weight(x);
        w -= weight(y);
        x = find(x);
        y = find(y);
        if (x == y) { return; }
        if (rnk[x] < rnk[y]) {
            par[x] = y;
            diff_weight[x] = -w;
        } else {
            par[y] = x;
            diff_weight[y] = w;
            if (rnk[x] == rnk[y]) { rnk[x]++; }
        }
    }
};


//番号ズレ注意！！
int main() {
    int N;
    cin >> N;
    ll T[N], A[N];
    REP(i, N) { cin >> T[i]; }
    REP(i, N) { cin >> A[i]; }
    if (T[0] > A[0]) { print(0);return 0; }
    if (T[N - 1] < A[N - 1]) { print(0);return 0; }
    if (T[N-1] != A[0]) { print(0);return 0; }
    ll ans = 1;
    for (int i = 1; i < N - 1; i++) {
        if (T[i] != T[i - 1]) {
            if (T[i] > A[i]) { print(0);return 0; }
            continue;
        }
        if (A[i] != A[i + 1]) {
            if (A[i] > T[i]) { print(0);return 0; }
            continue;
        }
        ans *= min(T[i], A[i]);
        ans %= mod;
    }
    print(ans);
}
