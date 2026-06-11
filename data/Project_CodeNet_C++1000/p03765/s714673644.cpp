#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl; 
#define INF 1000000000
#define mod 1000000007
using ll=long long;
const ll LINF = 1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }


//monoid,結合律が成り立ち,単位元が存在するものに対しての演算をクエリに対してO(logn)で
//1-indexed  n(親)->2n,2n+1(子)  k(子)->k/2(親)
template<typename Monoid>
struct SegmentTree{
    using F = function< Monoid(Monoid, Monoid) >;
    //sz:size->完全二分木なのでszはnよりも大きい最小の2のべき乗数
    int sz;
    vector<Monoid> seg;
 
    const F f;
    const Monoid M1;
    SegmentTree(int n,const F f,const Monoid &M1) : f(f), M1(M1) {

    sz=1;
    while(sz<n) sz<<=1;
    seg.assign(2*sz, M1);
    }
 
    void set(int k, const Monoid &x){
        seg[k+sz] = x;
    }
 
    void build(){
        for(int k=sz-1;k>0;k--){
        seg[k]=f(seg[2*k+0], seg[2*k+1]);
        }
    }
 
    void update(int k,const Monoid &x){
        k+=sz;
        seg[k]=x;
        
    while(k>>=1){
        seg[k]=f(seg[2*k+0],seg[2*k+1]);
        }
    }
    //query聞くときは区間は[a,b)で(a<=x<b)
    Monoid query(int a, int b) {
        Monoid L=M1,R=M1;
        for(a+=sz,b+=sz;a<b;a>>=1,b>>=1){
            if(a&1) L=f(L, seg[a++]);
            if(b&1) R=f(seg[--b], R);
        }
        return f(L,R);
    }   
    Monoid operator[](const int &k) const{
        return seg[k+sz];
    }
};


ll f(ll a,ll b){return (a+b);}


signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    string S,T;cin>>S>>T;
    SegmentTree<ll> S_seg(S.size(),f,0),T_seg(T.size(),f,0);
    rep(i,S.size()){
        if(S[i]=='A') S_seg.set(i,1);
    }
    rep(i,T.size()){
        if(T[i]=='A') T_seg.set(i,1);
    }
    S_seg.build();T_seg.build();

    int q;cin>>q;
    while(q--){
        int a,b,c,d;cin>>a>>b>>c>>d;
        a--,c--;
        int Sa_cnt=S_seg.query(a,b);
        int Sb_cnt=b-a-Sa_cnt;
        int Ta_cnt=T_seg.query(c,d);
        int Tb_cnt=d-c-Ta_cnt;
        int numS=(Sa_cnt+2*Sb_cnt)%3;
        int numT=(Ta_cnt+2*Tb_cnt)%3;
        if(numS==numT)  cout<<"YES"<<endl;
        else            cout<<"NO"<<endl;
    }
    return 0;
}
