#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

//template
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(a);i>(b);i--)
#define ALL(v) (v).begin(),(v).end()
typedef long long int ll; typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename A,size_t N,typename T>void Fill(A(&array)[N],const T &val){fill((T*)array, (T*)(array+N), val);}
const int inf = 0x3fffffff; const ll INF = 0x3fffffffffffffff;
//template end

template<typename M,typename O=M>
struct LazySegmentTree{
    using F=function<M(M,M)>; using G=function<M(M,O)>; using H=function<O(O,O)>;
    int sz,height; vector<M> data; vector<O> lazy;
    const F f;const G g; const H h; const M m1; const O o1;
    LazySegmentTree(int n,const F f,const G g,const H h,const M &m1,const O o1):f(f),g(g),h(h),m1(m1),o1(o1){
        sz=1,height=0; while(sz<n)sz<<=1,height++;
        data.assign(2*sz,m1); lazy.assign(2*sz,o1);
    }
    void set(int k,M x){data[k+sz]=x;}
    void build(){rrep(k,sz-1,0)data[k]=f(data[2*k],data[2*k+1]);}
    M ref(int k){return lazy[k]==o1?data[k]:g(data[k],lazy[k]);}
    void recalc(int k){while(k>>=1)data[k]=f(ref(2*k),ref(2*k+1));}
    void thrust(int k){rrep(i,height,0)eval(k>>i);}
    void eval(int k){
        if(lazy[k]!=o1){
            lazy[2*k]=h(lazy[2*k],lazy[k]); lazy[2*k+1]=h(lazy[2*k+1],lazy[k]);
            data[k]=ref(k); lazy[k]=o1;
        }
    }
    void update(int a,int b,O x){
        thrust(a+=sz); thrust(b+=sz-1);
        for(int l=a,r=b+1;l<r;l>>=1,r>>=1){
            if(l&1)lazy[l]=h(lazy[l],x),++l;
            if(r&1)--r,lazy[r]=h(lazy[r],x);
        }
        recalc(a); recalc(b);
    }
    M query(int a,int b){
        thrust(a+=sz); thrust(b+=sz-1);
        M L=m1,R=m1;
        for(int l=a,r=b+1;l<r;l>>=1,r>>=1){
            if(l&1)L=f(L,ref(l++)); if(r&1)R=f(ref(--r),R);
        } return f(L,R);
    }
};

int main(){
    int n,k; scanf("%d%d",&n,&k);
    vector<ll> a(n),b(n+1,0),idx(n+1);
    rep(i,0,n)scanf("%lld",&a[i]),a[i]-=k;
    rep(i,0,n)b[i+1]=b[i]+a[i];
    vector<ll> val;
    rep(i,0,n+1)val.push_back(b[i]);
    sort(ALL(val)); val.erase(unique(ALL(val)),val.end());
    rep(i,0,n+1)idx[i]=lower_bound(ALL(val),b[i])-val.begin();
    LazySegmentTree<ll> seg(200010,[](ll a,ll b){return a+b;},[](ll a,ll b){return a+b;},[](ll a,ll b){return a+b;},0,0);
    seg.build();
    ll ans=0;
    rep(i,0,n+1){
        ans+=seg.query(0,idx[i]+1);
        seg.update(idx[i],idx[i]+1,1);
    }
    printf("%lld\n",ans);
    return 0;
}