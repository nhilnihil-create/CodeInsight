#include<iostream>
#define _USE_MATH_DEFINES
#include<math.h>
#include<vector>
#include<array>
#include<algorithm>
#include<numeric>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vector<ll>> mat;
typedef pair<ll,ll> P;
typedef map<ll,ll> MP;
typedef priority_queue<ll> PQ;
#define pb push_back
#define st first
#define nd second
#define SZ(x) ((int)(x).size())
#define FOR(i,s,n) for(int i=(int)(s); i< (int)(n); i++)
#define rep(i,n) FOR(i,0,n)
#define all(x) (x).begin(),(x).end()
#define each(x,c) for(auto x: (c))
#define LB(x,a) lower_bound(all(x), a)
#define UB(x,a) upper_bound(all(x), a)
const ll mod=1e9+7;
const ll INF=1e18;
const double EPS=1.0e-10;
const double PI=M_PI;

struct Seg{
    vec dat;
    //要素数
    int n;

    Seg(int n_){
        n=1;
        while(n<n_)n*=2;
        dat.resize(2*n);

        for(int i=0;i<2*n-1;i++)
            dat[i]=INF;
    }

    //k番目の値をaに変更
    void update(int k,ll a){
        k+=n-1;
        dat[k]=a;
        while(k>0){
            k=(k-1)/2;
            dat[k]=min(dat[2*k+1],dat[2*k+2]);
        }
    }

    //[a,b)の最小値を求める
    //kは節点の番号、[l,r)はその区間
    ll query(int a,int b,int k,int l,int r){
        if(r<=a || b<=l)return INF;
        if(a<=l && r<=b)return dat[k];
        else{
            ll vl=query(a,b,2*k+1,l,(l+r)/2);
            ll vr=query(a,b,2*k+2,(l+r)/2,r);
            return min(vl,vr);
        }
    }
};

vec A;
Seg seg(200010);
int BS0(int i,int l,int r){
    if(r-l==1) return r;
    int m=(l+r)/2;
    if(seg.query(m,i+1,0,0,seg.n)==A[i]) return BS0(i,l,m);
    else return BS0(i,m,r);
}
int BS1(int i,int l,int r){
    if(r-l==1) return l-1;
    int m=(l+r)/2;
    if(seg.query(i,m,0,0,seg.n)==A[i]) return BS1(i,m,r);
    else return BS1(i,l,m);
}

int main(){
    int N; scanf("%d",&N);
    A.resize(N);
    rep(i,N){
        scanf("%lld",&A[i]);
        seg.update(i,A[i]);
    }
    ll ans=0;
    rep(i,N){
        int l,r;
        if(seg.query(0,i+1,0,0,seg.n)==A[i]) l=0;
        else l=BS0(i,0,i);
        if(seg.query(i,N,0,0,seg.n)==A[i]) r=N-1;
        else r=BS1(i,i,N);
        ans+=A[i]*(i-l+1)*(r-i+1);
    }
    printf("%lld\n",ans);
    return 0;
}