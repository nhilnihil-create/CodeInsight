#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define MIN(a,b) ((a)>(b)? (b): (a))
#define MAX(a,b) ((a)<(b)? (b): (a))

const long long INF = 1LL << 60;

typedef unsigned long long ll;

const long long MOD = 1000000000 + 7;

//For DP
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

//Union-Find tree
struct UnionFind{
    vector<int> par; // par[i]:iの親の番号 (例) par[3] = 2 : 3の親が2

    UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N;  i++) par[i] = i;
    }

    int root(int x) { // データxが属する木の根を再帰で得る : root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }
    
    void unite(int x, int y) { //xとyの木を併合
        int rx = root(x); //xの木の根をrx
        int ry = root(y); //yの木の根をyx
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)ときはそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時 : xの根rxをyの根ryにつける
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};



int main(){
    int N,a,b;
    cin >> N >> a >> b;
    ll x[N+1];
    rep(i,N) cin >> x[i+1];
    ll res = 0;
    for(int i = 1; i < N;i++){
        res += MIN((x[i+1]-x[i])*a,b);
    }
    cout << res << endl;
    return 0;
}
