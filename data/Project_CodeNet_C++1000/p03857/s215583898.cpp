#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;
#include <bits/stdc++.h>
using namespace std;
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

// http://dai1741.github.io/maximum-algo-2012/docs/minimum-spanning-tree/
// 素集合データ構造
struct UnionFind
{
 // par[i]：データiが属する木の親の番号。i == par[i]のとき、データiは木の根ノードである
 vector<int> par;
 // sizes[i]：根ノードiの木に含まれるデータの数。iが根ノードでない場合は無意味な値となる
 vector<int> sizes;

 UnionFind(int n) : par(n), sizes(n, 1) {
   // 最初は全てのデータiがグループiに存在するものとして初期化
   rep(i,n) par[i] = i;
 }

 // データxが属する木の根を得る
 int find(int x) {
   if (x == par[x]) return x;
   return par[x] = find(par[x]);  // 根を張り替えながら再帰的に根ノードを探す
 }

 // 2つのデータx, yが属する木をマージする
 void unite(int x, int y) {
   // データの根ノードを得る
   x = find(x);
   y = find(y);

   // 既に同じ木に属しているならマージしない
   if (x == y) return;

   // xの木がyの木より大きくなるようにする
   if (sizes[x] < sizes[y]) swap(x, y);

   // xがyの親になるように連結する
   par[y] = x;
   sizes[x] += sizes[y];
   // sizes[y] = 0;  // sizes[y]は無意味な値となるので0を入れておいてもよい
 }

 // 2つのデータx, yが属する木が同じならtrueを返す
 bool same(int x, int y) {
   return find(x) == find(y);
 }

 // データxが含まれる木の大きさを返す
 int size(int x) {
   return sizes[find(x)];
 }
};

int main() {
    ll n,k,l;
    std::cin >> n>>k>>l;
    UnionFind p(n);
    UnionFind r(n);
    for (int i = 0; i < k; i++) {
        ll a,b;
        std::cin >> a>>b;
        a--;
        b--;
        p.unite(a,b);
    }

    for (int i = 0; i < l; i++) {
        ll a,b;
        std::cin >> a>>b;
        a--;
        b--;
        r.unite(a,b);
    }
    
    std::map<ll, vector<ll>> m;
    for (int i = 0; i < n; i++) {
        m[p.find(i)].push_back(i);
    }
    
    ll result[200010];

    for (auto e : m) {
        unordered_map<ll,vector<ll>> um;
        for (auto ee : e.second) {
            um[r.find(ee)].push_back(ee);
        }
        for (auto ee : e.second) {
            result[ee] = um[r.find(ee)].size();
        }
    }
    
    for (int i = 0; i < n-1; i++) {
        std::cout << result[i]<<" ";
    }
    std::cout << result[n-1] << std::endl;
}
