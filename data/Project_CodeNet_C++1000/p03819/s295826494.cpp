#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace::std;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
// #include <boost/multiprecision/cpp_dec_float.hpp>
// #include <boost/multiprecision/cpp_int.hpp>
// #include <boost/numeric/interval.hpp>
// #include <boost/numeric/interval/io.hpp>
// #include <boost/intrusive/rbtree.hpp>
// #include <boost/geometry.hpp>
// #include <boost/geometry/geometries/linestring.hpp>
// #include <boost/geometry/geometries/polygon.hpp>
// #include <boost/geometry/geometries/point_xy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds;
using namespace::std;
// namespace mp = boost::multiprecision;
// typedef mp::number<mp::cpp_dec_float<0>> cfloat;
// typedef mp::cpp_int cint;
typedef long long lint;
typedef long long ll;
typedef long double ldouble;
typedef vector<lint> vec;
typedef vector<vector<lint>> mat;
typedef vector<vector<vector<lint>>> mat3;
typedef vector<double> dvec;
typedef vector<vector<double>> dmat;
typedef vector<vector<vector<double>>> dmat3;
typedef vector<string> svec;
typedef vector<vector<string>> smat;
typedef vector<vector<vector<string>>> smat3;
typedef vector<pair<lint,lint>> pvec;
typedef vector<vector<pair<lint,lint>>> pmat;
typedef vector<vector<vector<pair<lint,lint>>>> pmat3;
#define rep(i, n) for(lint i = 0; i < (lint)(n); i++)
#define irep(i) for(lint i = 0;; i++)
#define irep1(i) for(lint i = 1;; i++)
#define irep2(i) for(lint i = 2;; i++)
#define rrep(i, n) for(lint i = (lint)(n-1); i >-1; i--)
#define rrepi(i,a,b) for(lint i = (lint)(b-1); i >a-1; i--)
#define repi(i,a,b) for(lint i=lint(a);i<lint(b);i++)
#define rep2(i,a,b,c) for(lint i=lint(a);i>lint(b);i+=c)
#define all(x) (x).begin(),(x).end()
#define PI 3.141592653589793
#define dist(x1,y1,x2,y2) (pow(pow(x2-x1,2)+pow(y2-y1,2),0.5))
#define output(v) do{bool f=0;for(auto i:v){cout<<(f?" ":"");if(i>INF/2)cout<<"INF";else cout<<i;f=1;}cout<<"\n";}while(0)
#define output2(v) for(auto j:v)output(j);
#define input(a,n) lint n;cin>>n;vector<lint>a(n);rep(i,n)cin>>a[i];
#define SUM(v) accumulate(all(v),0LL)
#define INF (1LL<<60)
#define IINF (1<<30)
#define EPS (1e-10)
#define LINF 9223372036854775807
#define MOD 1000000007
#define endl "\n"
template<typename T=lint>T in(){return *istream_iterator<T>(cin);}
inline lint gcd(lint a,lint b){return b?gcd(b,a%b):a;}
inline lint lcm(lint a,lint b){return a*b/gcd(a,b);}
inline bool chmin(auto& s,const auto& t){bool res=s>t;s=min(s,t);return res;}
inline bool chmax(auto& s,const auto& t){bool res=s<t;s=max(s,t);return res;}
vector<lint> dx={-1,1,0,0,1,1,-1,-1};
vector<lint> dy={0,0,-1,1,1,-1,1,-1};

template<typename T=lint,typename E=T>struct LSEG{
    lint n=1;
    vector<T> node;
    vector<E> lazy;
    T et;
    E ee;
    LSEG(lint size,T et,E ee):et(et),ee(ee){
        while(n<size)n<<=1;
        node.resize(2*n-1,et);
        lazy.resize(2*n-1,ee);
    }
    inline void eval(lint k,lint len){
        if(lazy[k]==ee) return;
        if(k*2+1<n*2-1){
            lazy[k*2+1]=g(lazy[k*2+1],lazy[k]);
            lazy[k*2+2]=g(lazy[k*2+2],lazy[k]);
        }
        node[k]=h(node[k],lazy[k],len);
        lazy[k]=ee;
    }

    //0-indexed [a,b)
    T update(lint a,lint b,E x,lint k=0,lint l=0,lint r=-1){
        if(r<0)r=n;
        eval(k,r-l);
        //区間外
        if(r<=a||b<=l)return node[k];
        //全部区間内
        if(a<=l&&r<=b){
            lazy[k]=g(lazy[k],x);
            return h(node[k],lazy[k],r-l);
        }
        //一部区間内
        return node[k]=f(update(a,b,x,2*k+1,l,(l+r)/2),update(a,b,x,2*k+2,(l+r)/2,r));
    }
    //0-indexed [a,b)
    T get(lint a,lint b,lint k=0,lint l=0,lint r=-1){
        if(r<0)r=n;
        eval(k,r-l);
        //区間外
        if(r<=a||b<=l)return et;
        //全部区間内
        if(a<=l&&r<=b)return node[k];
        //一部区間内
        return f(get(a,b,2*k+1,l,(l+r)/2),get(a,b,2*k+2,(l+r)/2,r));
    }
    T f(T a,T b){
        return a+b;
    }
    T h(T a,E b,lint len){
        return a+b*len;
    }
    E g(E a,E b){
        return a+b;
    }
};

int main(){
    lint n,m;
    cin>>n>>m;
    LSEG<> seg(m+1,0,0);
    vector<tuple<lint,lint,lint>> event(n+m);
    rep(i,m){
        event.emplace_back(i+1,-1,-1);
    }
    rep(i,n){
        lint l,r;
        cin>>l>>r;
        event.emplace_back(r-l,l,r);
    }
    sort(all(event));
    lint nokori=n;
    for(auto d:event){
        lint len,l,r;
        tie(len,l,r)=d;
        if(l==-1&&r==-1){
            lint i=len;
            lint cnt=0;
            for(lint j=0;i*j<m+1;j++){
                cnt+=seg.get(i*j,i*j+1);
            }
            cout<<cnt+nokori<<endl;
        }else{
            nokori--;
            seg.update(l,r+1,1);
        }
    }
}