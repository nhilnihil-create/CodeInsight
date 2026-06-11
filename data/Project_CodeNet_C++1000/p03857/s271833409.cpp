#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0;i < n;i++)
#define rev(i, n) for(int i = n;i >= 0;i--)
#define Rep(i, m, n) for(int i = m;i < n;i++)
#define repeatrev(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define ll long long
#define pb(a) push_back(a)
#define INF 999999999
#define itn int
const int MAX = 510000;


using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;
typedef priority_queue<int> Pr;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

//UnionFind(重みなし, sizeあり）
//UnionFind
class UnionFind {
    vector<int>par, sz;
public:
    UnionFind() {}
    UnionFind(int n) {
        par = sz = vector<int>(n);
        for (int i = 0; i < n; i++) {
            par[i] = i;
            sz[i] = 1;
        }
    }
    int find(int x) {
        if (par[x] == x)return x;
        return par[x] = find(par[x]);
    }
    void merge(int x, int y) {
        x = find(x); y = find(y);
        if (x == y)return;
        if (sz[x] > sz[y]) {
            par[y] = x;
            sz[x] += sz[y];
        }
        else {
            par[x] = y;
            sz[y] += sz[x];
        }
    }
    bool issame(int x, int y) {
        return find(x) == find(y);
    }
    int size(int x) {
        return sz[find(x)];
    }
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, l;
    cin >> n >> k >> l;
    UnionFind uf_1(n), uf_2(n);
    rep(i, k){
        int p, q;
        cin >> p >> q;
        uf_1.merge(p - 1, q - 1);
    }
    rep(i, l){
        int r, s;
        cin >> r >> s;
        uf_2.merge(r - 1, s - 1);
    }
    map<P, int> M;
    rep(i, n){
        M[P(uf_1.find(i), uf_2.find(i))]++;
    }
    rep(i, n)cout << M[P(uf_1.find(i), uf_2.find(i))] << " ";
    cout << endl;

}