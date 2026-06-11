//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int n,N;
vector<int> v;

void init(){
    N=1;
    while(N<n) N*=2;
    v.assign(2*N-1,inf); //変更点
}

void init_u(){
    for(int i=N-2;i>=0;i--)
    v[i]=min(v[2*i+1],v[2*i+2]); //変更点
}

void update(int k,int a){
    k+=N-1;
    v[k]=a;
    while(k>0){
        k=(k-1)/2;
        v[k]=min(v[k*2+1],v[k*2+2]); //変更点
    }
}

//query(a,b,0,0,N);
int query(int a,int b,int k,int l,int r){
    if(r<=a || b<=l) return inf; //変更点
    if(a<=l && r<=b) return v[k];
    int vl=query(a,b,k*2+1,l,(l+r)/2);
    int vr=query(a,b,k*2+2,(l+r)/2,r);
    return min(vl,vr); //変更点
}

int main(){
    cin>>n; n+=2;
    init();
    n-=2;
    rep(i,n) cin>>v[i+N];
    v[N-1]=0; v[n+N]=0;
    init_u();
    ll ans=0;
    rep(i,n){
        ll a=v[i+N],L,R;
        int l=0,r=i+1,c;
        while(l!=r){
            c=(l+r+1)/2;
            int d=query(c,i+2,0,0,N);
            if(d<a) l=c;
            else r=c-1;
        }
        L=i+1-l;
        l=i+1; r=n+1;
        while(l!=r){
            c=(l+r)/2;
            int d=query(i+1,c+1,0,0,N);
            if(d<a) r=c;
            else l=c+1;
        }
        R=l-(i+1);
        ans+=L*R*a;
    }
    cout<<ans<<endl;
}