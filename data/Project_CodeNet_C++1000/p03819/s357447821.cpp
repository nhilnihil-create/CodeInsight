#include<iomanip>
#include<limits>
#include<thread>
#include<utility>
#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<numeric>
#include<cassert>
#include<random>
#include<chrono>
#include<unordered_set>
#include<unordered_map>
#include<fstream>
#include<list>
#include<functional>
#include<bitset>
#include<complex>
#include<tuple>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pi;
typedef pair<double,double> pd;
typedef pair<double,ll> pdl;
#define F first
#define S second
const ll E=1e18+7;
const ll MOD=1000000007;

template <typename T,typename E>
struct SegmentTree{
    using F = function<T(T,T)>;
    using G = function<T(T,E)>;
    using H = function<E(E,E)>;
    int n,height;
    F f;
    G g;
    H h;
    T ti;
    E ei;
    vector<T> dat;
    vector<E> laz;
    SegmentTree(F f,G g,H h,T ti,E ei):
    f(f),g(g),h(h),ti(ti),ei(ei){}
    
    void init(int n_){
        n=1;height=0;
        while(n<n_) n<<=1,height++;
        dat.assign(2*n,ti);
        laz.assign(2*n,ei);
    }
    void build(const vector<T> &v){
        int n_=v.size();
        init(n_);
        for(int i=0;i<n_;i++) dat[n+i]=v[i];
        for(int i=n-1;i;i--)
            dat[i]=f(dat[(i<<1)|0],dat[(i<<1)|1]);
    }
    inline T reflect(int k){
        return laz[k]==ei?dat[k]:g(dat[k],laz[k]);
    }
    inline void eval(int k){
        if(laz[k]==ei) return;
        laz[(k<<1)|0]=h(laz[(k<<1)|0],laz[k]);
        laz[(k<<1)|1]=h(laz[(k<<1)|1],laz[k]);
        dat[k]=reflect(k);
        laz[k]=ei;
    }
    inline void thrust(int k){
        for(int i=height;i;i--) eval(k>>i);
    }
    inline void recalc(int k){
        while(k>>=1)
            dat[k]=f(reflect((k<<1)|0),reflect((k<<1)|1));
    }
    void update(int a,int b,E x){
        thrust(a+=n);
        thrust(b+=n-1);
        for(int l=a,r=b+1;l<r;l>>=1,r>>=1){
            if(l&1) laz[l]=h(laz[l],x),l++;
            if(r&1) --r,laz[r]=h(laz[r],x);
        }
        recalc(a);
        recalc(b);
    }
    void set_val(int a,T x){
        thrust(a+=n);
        dat[a]=x;laz[a]=ei;
        recalc(a);
    }
    T query(int a,int b){
        thrust(a+=n);
        thrust(b+=n-1);
        T vl=ti,vr=ti;
        for(int l=a,r=b+1;l<r;l>>=1,r>>=1) {
            if(l&1) vl=f(vl,reflect(l++));
            if(r&1) vr=f(reflect(--r),vr);
        }
        return f(vl,vr);
    }
};


int main(){
    ll n,m;
    cin>>n>>m;
    priority_queue<pair<ll,pll>,vector<pair<ll,pll>>,greater<pair<ll,pll>>> Q;
    for(int i=0;i<n;i++){
        ll l,r;
        cin>>l>>r;
        Q.push({r-l+1,{l,r}});
    }
    auto f=[](ll a,ll b){return max(a,b);};
    auto g=[](ll a,ll b){return a+b;};
    auto h=[](ll a,ll b){return a+b;};
    SegmentTree<ll,ll> T(f,g,h,0,0);
    T.init(m+1);
    vector<ll> ans(m+1,0);
    for(ll i=1;i<=m;i++){
        while(!Q.empty() && Q.top().F<i){
            pair<ll,pll> A=Q.top(); Q.pop();
            T.update(A.S.F,A.S.S+1,1);
        }
        ans[i]=Q.size();
        for(ll t=0;t<=m;t+=i){ans[i]+=T.query(t,t+1);}
        cout<<ans[i]<<endl;
    }
    
    
    return 0;
}
