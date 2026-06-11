#include<bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vector<int> >
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>
#define vc vector<char>
#define vs vector<string>
using ll = long long;
using ld =long double;
//#define int ll
#define INF 1e9
#define EPS 0.0000000001
#define rep(i,n) for(int i=0;i<n;i++)
#define loop(i,s,n) for(int i=s;i<n;i++)
#define all(in) in.begin(), in.end()
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
#define MAX 9999999
using namespace std;
typedef pair<int, int> pii;
typedef pair<int,pii> piii;
class unionfind {
    vector<int> par, rank, size_;//速度ではなくメモリ効率を考えるならrankのかわりにsizeを使う
public:
    unionfind(int n) :par(n), rank(n), size_(n, 1) {
        iota(all(par), 0);
    }
    int find(int x) {
        if (par[x] == x)return x;
        return par[x] = find(par[x]);
    }
    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y)return;
        if (rank[x] < rank[y])swap(x, y);
        par[y] = x;
        size_[x] += size_[y];
        if (rank[x] == rank[y])rank[x]++;
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    int size(int x) {
        return size_[find(x)];
    }
};
signed main(){
    int n,k,l; cin>>n>>k>>l;
    unionfind u(n+1);
    unionfind v(n+1);
    rep(i,k){
        int a,b;cin>>a>>b;
        u.unite(a, b);
    }
    rep(i,l){
        int a,b;cin>>a>>b;
        v.unite(a, b);
    }
    map<pii,int>parent;
    for(int i=1;i<=n;i++){
        parent[make_pair(u.find(i),v.find(i))]++;
    }
    for(int i=1;i<=n;i++){
        if(i!=1)cout<<" ";
        cout<<parent[make_pair(u.find(i),v.find(i))];
    }
    cout<<endl;
}
