#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
struct UnionFind{
    vector<int> d;
    UnionFind(int n) : d(n,-1) {}
    //根なら、-サイズを格納それ以外は、親を格納
    int find(int x){
        if(d[x] < 0) return x;
        return d[x] = find(d[x]); //経路縮約
    }
    bool unite(int x,int y){
        //二つ頂点を持ってくる
        x = find(x);
        y = find(y);
        if(x == y) return false;//根が一致するなら何もしない
        if(d[x] > d[y]) swap(x,y);
        //ex:d[x]=-5,d[y]=-2
        //小さい方が、大きい方に引っ付く
        d[x] += d[y];//この場合、yがxにくっつく
        d[y] = x;
        return true;
    }
    bool same(int x,int y) {return find(x) == find(y);}
    int size(int x) {return -d[find(x)];}
};
int main(){
    cout << fixed << setprecision(10);
    UnionFind uf(12);
    uf.unite(0,2);
    uf.unite(0,4);
    uf.unite(0,6);
    uf.unite(0,7);
    uf.unite(0,9);
    uf.unite(0,11);

    uf.unite(3,5);
    uf.unite(3,8);
    uf.unite(3,10);

    int x,y;

    cin >> x >> y;
    x--; y--;
    if(uf.same(x,y) == 1) cout << "Yes" << endl;
    else cout << "No" << endl;  
    return 0;
}