#include<bits/stdc++.h>
//using namespace std;
#define rep(i,j,n) for(ll i=(ll)(j);i<(ll)(n);i++)
#define REP(i,j,n) for(ll i=(ll)(j);i<=(ll)(n);i++)
#define per(i,j,n) for(ll i=(ll)(j);(ll)(n)<=i;i--)
#define ll long long
#define ALL(a) (a).begin(),(a).end()
#define disup(A,key) distance(A.begin(),upper_bound(ALL(A),(ll)(key)))
#define dislow(A,key) distance(A.begin(),lower_bound(ALL(A),(ll)(key)))
#define pb push_back
#define mp std::make_pair
#define endl "\n"
using std::cin;
using std::cout;
using std::vector;
using std::string;
using std::upper_bound;
using std::lower_bound;
using vi=vector<ll>;
using vii=vector<vi>;
using pii=std::pair<ll,ll>;
const ll MOD=1e9+7;
//const ll MOD=998244353;
//const ll MOD=100000;
const ll MAX=1e7;
const ll INF=(1ll<<60);
template<class T>
class prique :public std::priority_queue<T, std::vector<T>, std::greater<T>> {};
struct Binary_indexed_tree{
    int N;
    vi bit;
    Binary_indexed_tree(int n):N(n){
        bit.resize(N+1,0);
    }
    void add(int x,int a){
        for(x;x<=N;x+=(x&-x)) bit[x]+=a;
    }
    ll sum(int x){
        ll ret=0;
        for(x;x>0;x-=(x&-x)) ret+=bit[x];
        return ret;
    }
};
struct Union_Find{
    ll N;
    vi par;
    vi siz;
    Union_Find(int n):N(n){
        par.resize(N);
        siz.resize(N,1);
        rep(i,0,N) par[i]=i;
    }
    ll root(ll X){
        if(par[X]==X) return X;
        return par[X]=root(par[X]);
    }
    bool same(ll X,ll Y){
        return root(X)==root(Y);
    }
    void unite(ll X,ll Y){
        X=root(X);
        Y=root(Y);
        if(X==Y) return;
        par[X]=Y;
        siz[Y]+=siz[X];
        siz[X]=0;
    }
    ll size(ll X){
        return siz[root(X)];
    }
};
ll modpow(ll X,ll Y){
    ll sum=X,cnt=1;
    vi A;
    while(cnt<=Y){
        A.pb(sum);
        sum*=sum;
        sum%=MOD;
        cnt*=2;
    }
    int M=A.size();
    ll ret=1;
    REP(i,1,M){
        if(Y>=(1ll<<M-i)){
            Y-=(1ll<<M-i);
            ret*=A[M-i];
            ret%=MOD;
        }
    }
    return ret;
}
ll fac[MAX],finv[MAX],inv[MAX];
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
ll COM(ll n,ll r){
    if(n<r||n<0||r<0) return 0;
    return fac[n]*finv[r]%MOD*finv[n-r];
}
signed main(){
    ll N; cin>>N;
    if(N==1){
        cout<<1<<endl;
        return 0;
    }
    vi dp(N+1);
    vi sum(N+1);
    dp[1]=sum[1]=1;
    ll ans=(dp[1]*(N-1)%MOD*(N-1)%MOD+dp[1]*std::min(2ll,N-1))%MOD;
    rep(i,2,N){
        dp[i]=sum[i-1]-dp[i-2];
        dp[i]=(dp[i]+MOD)%MOD;
        ans+=dp[i]*(N-1)%MOD*(N-1)%MOD;
        ans+=dp[i]*std::min(N-1,i+1)%MOD;
        ans%=MOD;
        sum[i]=(sum[i-1]+dp[i])%MOD;
    }
    dp[N]=sum[N-1]-dp[N-2];
    dp[N]=(dp[N]+MOD)%MOD;
    ans+=dp[N]*N%MOD;
    ans%=MOD;
    cout<<ans<<endl;
}
