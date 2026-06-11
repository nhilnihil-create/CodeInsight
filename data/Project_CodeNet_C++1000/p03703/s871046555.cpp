#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define cinf(n,x) for(int i=0;i<(n);i++)cin>>x[i];
#define ft first
#define sc second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(),(v).end()
#define mod 1000000007
#define FS fixed<<setprecision(15)
using namespace std;
typedef long long ll;
template<class T> using V=vector<T>;
using Graph = vector<vector<int>>;
using P=pair<ll,ll>;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const ll INF=1e18;

const ll MAX_N=(1<<19);

ll n,N,dat[2*MAX_N-1];//n...segmenttreeの葉の大きさ,N...与えられた数列等の大きさ
ll b[1000000];

ll unit(){
    return 0;//単位元
}

ll calc(ll a,ll b){
    return a+b;//演算
}

//初期化
void init(){
    n=1;
    while(n<N) n*=2;//座標とかであれば n<N ではなく n<(座標の最大値)　下も同様
    //for(int i=0;i<N;i++) dat[i+n-1]=a[i];
    //for(int i=N;i<n;i++) dat[i]=unit();//単位元で埋める
}

void update(ll k,ll s){
    k+=n-1;
    dat[k]=s;//変更する式
    while(k>0){
        k=(k-1)/2;
        dat[k]=calc(dat[2*k+1],dat[2*k+2]);//条件
    }
}

ll query(ll a,ll b,ll k,ll l,ll r){
    if(r<=a||b<=l) return unit();//単位元
    if(a<=l&&r<=b) return dat[k];

    ll m=(l+r)/2;
    ll u=query(a,b,2*k+1,l,m);
    ll v=query(a,b,2*k+2,m,r);
    return calc(u,v);//条件
}

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    ll k;
    cin>>N>>k;
    V<ll> a(N),s(N+1),t(N+1);
    rep(i,N){
        cin>>a[i];
        s[i+1]=s[i]+a[i];
    }
    ll ans=0;
    V<P> p;
    for(ll i=1;i<=N;i++){
        t[i]=s[i]-k*i;
        p.emplace_back(t[i],i);
    }
    p.emplace_back(0LL,0LL);
    sort(all(p));
    init();
    rep(i,N) update(i,1);
    rep(i,N){
        ans+=query(p[i].sc,N,0,0,n);
        update(p[i].sc-1,0);
    }
    cout<<ans<<endl;
}