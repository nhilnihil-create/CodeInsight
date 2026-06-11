#include <bits/stdc++.h>
#define rep(i, z, n) for(int i = z; i < n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
//const int INF = 1<<29;
using namespace std;
struct UnionFind {
    vector<int> par;
    
    UnionFind(int N) : par(N){
        for (int i = 0; i < N; i++) par[i] = i;
    }
    
    int root (int x){
        if (par[x] == x) return x;
        else return par[x] = root(par[x]);
    // 再帰しつつpar[x]を大親に貼り直し
    }
    
    void unite(int x, int y){
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        par[rx] = ry;
    }
    
    bool same (int x, int y){
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main(){
    int x, y;
    cin >> x >> y;
    UnionFind tree(12);
    tree.unite(1, 3);
    tree.unite(3, 5);
    tree.unite(5, 7);
    tree.unite(7, 8);
    tree.unite(8, 10);
    tree.unite(10, 12);
    tree.unite(4, 6);
    tree.unite(6, 9);
    tree.unite(9, 11);
    
    if (tree.same(x, y)) cout << "Yes" << endl;
    else cout << "No" << endl;
}