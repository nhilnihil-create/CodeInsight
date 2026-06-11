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
    ll lower_bound(ll X){
        if(sum(N)<X) return -1;
        ll ret=0,memo=1,sum=0;
        while(memo*2<=N) memo*=2;
        while(memo>0){
            if(memo+ret<=N&&sum+bit[memo+ret]<X){
                sum+=bit[memo+ret];
                ret+=memo;
            }
            memo/=2;
        }
        return ret+1;
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
ll dfs(ll X,vector<bool> &F,vi &A,vii &edge){
    ll max=0,min=0;
    F[X]=1;
    if(edge[X].size()==1) return A[X];
    rep(i,0,edge[X].size()){
        ll Y=edge[X][i];
        if(F[Y]) continue;
        ll Z=dfs(Y,F,A,edge);
        if(Z==-1) return -1;
        if(max<Z){
            min=Z-max;
        }
        else if(min>Z){
            min=min-Z;
        }
        else{
            min=Z%2^min%2;
        }
        max+=Z;
    }
    ll memo=A[X]*2-max;
    if(min<=memo&&memo<=max&&memo%2==max%2) return memo;
    return -1;
}
signed main(){
    ll N; cin>>N;
    vii edge(N);
    vi A(N);
    rep(i,0,N) cin>>A[i];
    rep(i,1,N){
        ll X,Y; cin>>X>>Y;
        edge[X-1].pb(Y-1);
        edge[Y-1].pb(X-1);
    }
    string ans="NO";
    if(N==2){
        if(A[0]==A[1]) ans="YES";
    }
    else{
        vector<bool> F(N);
        rep(i,0,N){
            if(edge[i].size()>1){
                if(dfs(i,F,A,edge)==0) ans="YES";
                break;
            }
        }
    }
    cout<<ans<<endl;
}
