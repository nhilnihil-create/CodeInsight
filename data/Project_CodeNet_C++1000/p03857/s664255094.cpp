#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
#define rep(i,n) for(int i=0;i<n;i++)
#define all(in) in.begin(), in.end()
#define INF (sizeof(int) == 4 ? (int)1e9:(int)1e18)
#define EPS 0.0000000001
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<typename Head, typename Value> auto vectors(const Head &head, const Value &v) { return vector<Value>(head, v); }
template<typename Head, typename... Tail> auto vectors(Head x, Tail... tail) { auto inner = vectors(tail...); return vector<decltype(inner)>(x, inner); }
using ld  = long double;
using pii = pair<int,int>;
using piii = pair<int,pii>;
int W,H;
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
bool valid(int x,int y){return (0<=x&&x<W)&&(0<=y&&y<H);}
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
    int N,K,L;
    cin >> N >> K >> L;
    auto t = unionfind(N);
    auto c = unionfind(N);
    for(int i = 0; i < K; ++i){
        int a,b; cin >> a >> b;
        --a,--b;
        t.unite(a,b);
    }
    for(int j = 0; j < L; ++j){
        int a,b; cin >> a >> b;
        --a,--b;
        c.unite(a,b);
    }
    map<pair<int,int>,int>cnt;
    for(int i = 0; i < N; ++i){
        cnt[make_pair(t.find(i), c.find(i))] += 1;
    }
    for(int i = 0; i < N; ++i)
        cout << cnt[make_pair(t.find(i),c.find(i))]<< endl;
}
