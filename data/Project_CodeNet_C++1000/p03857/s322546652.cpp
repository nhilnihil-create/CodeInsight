#include <bits/stdc++.h>
 
using namespace std;
 
#define rep(i,n) for(int i=0;i<n;i++)

struct UnionFind {
    vector<int> par; 

    UnionFind(int N) : par(N) { 
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { 
        int rx = root(x);
        int ry = root(y); 
        if (rx == ry) return; 
        par[rx] = ry; 
    }

    bool same(int x, int y) { 
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main(){
 int n,k,l;
   cin >> n >> k >> l;
  
 UnionFind ar(n),br(n);
  
  rep(i,k) {
   int p,q;
    cin >> p >> q;
   p--;
   q--;
    ar.unite(p,q);
  }
  
  rep(i,l) {
   int p,q;
    cin >> p >> q;
   p--;
   q--;
   br.unite(p,q);
  }
  
  map<pair<int,int>,int> mp;
  rep(i,n) mp[make_pair(ar.root(i),br.root(i))]++;
  rep(i,n-1) cout << mp[make_pair(ar.root(i),br.root(i))] << " ";
    cout << mp[make_pair(ar.root(n-1),br.root(n-1))] << endl;

}  