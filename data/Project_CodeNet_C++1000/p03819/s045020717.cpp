#pragma GCC target ("avx2")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#include "bits/stdc++.h"
#include <unordered_set>
#include <unordered_map>
#include <random>
using namespace std;
typedef long long ll;
const ll MOD = 1'000'000'007LL; /*998'244'353LL;*/
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
const int dx[4]={ 1,0,-1,0 };
const int dy[4]={ 0,1,0,-1 };

struct RSQ{
private:
    int N;
    vector<long long> node, lazy;
    vector<bool> lazyFlg;
    long long DEFAULT;
public:
    void init(int n, long long def=0LL){
        DEFAULT = def;
        node.clear();
        lazy.clear();
        lazyFlg.clear();
        N = 1;
        while(N < n) N = (N<<1);
        for(int i=0; i<2*N-1; i++){
            node.push_back(DEFAULT);
            lazy.push_back(0LL);
            lazyFlg.push_back(false);
        }
    }
    void eval(int k, int l, int r){
        if(lazyFlg[k]){
            node[k] = lazy[k];
            if(r-l > 1){
                lazy[(k<<1)+1] = lazy[k] >> 1;
                lazyFlg[(k<<1)+1] = true;
                lazy[(k<<1)+2] = lazy[k] >> 1;
                lazyFlg[(k<<1)+2] = true;
            }
            lazy[k] = 0LL;
            lazyFlg[k] = false;
        }
        else{
            node[k] += lazy[k];
            if(r-l > 1){
                lazy[(k<<1)+1] += lazy[k] >> 1;
                lazy[(k<<1)+2] += lazy[k] >> 1;
            }
            lazy[k] = 0LL;
        }
    }
    void update(int a, long long x){
        update(a, a+1, x);
    }
    void update(int a, int b, long long x, int k=0, int l=0, int r=-1){
        if(a >= b) return;
        if(r == -1) r = N;
        eval(k, l, r);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b){
            lazy[k] = x * (r-l);
            lazyFlg[k] = true;
            eval(k, l, r);
        }
        else{
            update(a, b, x, (k<<1)+1, l, (l+r)>>1);
            update(a, b, x, (k<<1)+2, (l+r)>>1, r);
            node[k] = node[(k<<1)+1] + node[(k<<1)+2];
        }
    }
    void add(int a, long long x){
        add(a, a+1, x);
    }
    void add(int a, int b, long long x, int k=0, int l=0, int r=-1){
        if(a >= b) return;
        if(r == -1) r = N;
        eval(k, l, r);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b){
            lazy[k] += x * (r-l);
            eval(k, l, r);
        }
        else{
            add(a, b, x, (k<<1)+1, l, (l+r)>>1);
            add(a, b, x, (k<<1)+2, (l+r)>>1, r);
            node[k] = node[(k<<1)+1] + node[(k<<1)+2];
        }
    }
    long long sum(int a, int b, int k=0, int l=0, int r=-1){
        if(a >= b) 0LL;
        if(r == -1) r = N;
        if(b <= l || r <= a) return 0LL;
        eval(k, l, r);
        if(a <= l && r <= b) return node[k];
        return sum(a, b, (k<<1)+1, l, (l+r)>>1) + sum(a, b, (k<<1)+2, (l+r)>>1, r);
    }
};

int N, M;
vector<pair<int, pair<int, int>>> v;
RSQ rsq;

signed main(){
    cin >> N >> M;
    rep(i, N){
        int l, r;
        cin >> l >> r;
        v.pb({ r-l+1,{l,r} });
    }
    sort(all(v));

    rsq.init(M+1, 0);
    int r = 0;
    for(int d=1; d<=M; d++){
        while(r < v.size() && v[r].first <= d){
            rsq.add(v[r].second.first, v[r].second.second+1, 1);
            r++;
        }
        int ans = N-r;
        for(int i=1; d*i<=M; i++){
            ans += rsq.sum(d*i, d*i+1);
        }
        cout << ans << endl;
    }
}