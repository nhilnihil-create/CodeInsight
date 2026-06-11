#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
struct UnionFind {
    vector<int> par;
    
    UnionFind(int n) : par(n, -1) {}
    void init(int n) { par.assign(n, -1);}
    
    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
    
    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    
    int size(int x) {
        return -par[root(x)];
    }
};
main(){
    int N,K,L;
    cin >> N >> K >> L;
    vector<int> A(K),B(K),C(L),D(L);
    rep(i,0,K){
        cin >> A[i] >> B[i];
        A[i]--,B[i]--;
    }
    rep(i,0,L){
        cin >> C[i] >> D[i];
        C[i]--,D[i]--;
    }
    UnionFind uf1(N),uf2(N);
    rep(i,0,K)uf1.merge(A[i], B[i]);
    rep(i,0,L)uf2.merge(C[i], D[i]);
    vector<int> r1(N),r2(N);
    rep(i,0,N)r1[i] = uf1.root(i);
    rep(i,0,N)r2[i] = uf2.root(i);
    map<pair<int,int>, int>mp;
    rep(i,0,N)mp[make_pair(r1[i], r2[i])]++;
    rep(i,0,N){
        cout << mp[make_pair(r1[i], r2[i])] << " \n"[i==N-1];
    }

}