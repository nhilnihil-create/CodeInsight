#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define RFOR(i,l,r) for(long long i=(l);i>=(r);--i)
#define RREP(i,n) RFOR(i,n-1,0)
#define RREPS(i,n) RFOR(i,n,1)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
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
const int INF=1e18;
const int MOD=1e9+7;
// Binary Indexed Tree (Fenwick Tree)
template <typename T>
struct BIT {
    int n,p;
    vector<T> d;
    BIT(int n=0) :n(n), d(n+1) {
        p = 1;
        while(p < n)p *= 2;
    }
    //更新
    void add(int i,T x=1){
        for(i++;i <= n;i += i&-i) d[i] += x;
    }
    //[0,i)の和
    T sum(int i){
        T res = 0;
        for(;i;i -= i&-i) res += d[i];
        return res;
    }
    //[l,r)の和
    T sum(int l,int r){ return sum(r) - sum(l);}
    //v0+v1+…vx>=mを満たすmin(x)を返す
    int lower_bound(T w){
        if(w <= 0) return 0;
        T x = 0;
        for ( int i=p;i;i/=2){
            if(i+x <=n &&d[i+x] < w){
                w -= d[i+x];
                x += i;
            }
        }
        return x;
    }
};

signed main(){
    int n,k;cin>>n>>k;
    int b[n+1];
    b[0]=0;
    REP(i,n){
        int a;cin>>a;
        b[i+1]=b[i]+a-k;
    }
  	
    //press
    {
    map<int,int>p;
    map<int,int>c;
    REP(i,n+1)p[b[i]]++;
    int i=0;
    for(auto v:p){
        c[v.first]=i;
        i++;
    }
    REP(i,n+1)b[i]=c[b[i]];
    }
  
    BIT<int> bit(n+1);
    int ans=0;
    for(int i=n;i>=0;i--){
        ans += bit.sum(b[i],n+1);
        bit.add(b[i]);
    }
    cout<<ans<<endl;
}