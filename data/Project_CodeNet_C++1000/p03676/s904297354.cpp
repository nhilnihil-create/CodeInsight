#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define rer(i, a, b) for(int i = int(a) - 1; i >= int(b); i--)
#define sz(v) (int)(v).size()
#define pb push_back
#define sc second
#define fr first
#define sor(v) sort(v.begin(),v.end())
#define rev(s) reverse(s.begin(),s.end())
#define lb(vec,a) lower_bound(vec.begin(),vec.end(),a)
#define ub(vec,a) upper_bound(vec.begin(),vec.end(),a)
#define uniq(vec) vec.erase(unique(vec.begin(),vec.end()),vec.end())
using namespace std;
typedef long long int ll;
typedef pair <int, int> P;
const ll MOD=1e9+7;
const int MAX_N=1e5+10;
ll extgcd(ll a, ll b, ll& x, ll&y){
    ll d=a;
    if(b!=0){
        d=extgcd(b, a%b, y, x);
        y-=(a/b)*x;
    }
    else {
        x=1; y=0;
    }
    return d;
}

ll mod_inverse(ll a, ll m){
    ll x,y;
    extgcd(a,m,x,y);
    return (m+x%m)%m;
}
ll fact[MAX_N];//0<=n<pについてn! modpのテーブルO(p)

//n!=a p＾eとした時のa modpを求める。O(log_p n)
ll mod_fact(ll n, ll p, ll& e){
    e=0;
    if(n==0) return 1;
    
    //pの倍数の部分を計算
    ll res=mod_fact(n/p,p,e);
    e+=n/p;
    
    //(p-1)!≡-1なので(p-1)!^(n/p)はn/pの偶奇だけで計算できる
    if(n/p%2!=0) return res*(p-fact[n%p])%p;
    return res*fact[n%p]%p;
}

//nCk modpを求める。O(log_p n)
ll mod_comb(ll n, ll k, ll p){
    if(n<0||k<0||n<k) return 0;
    ll e1, e2, e3;
    ll a1=mod_fact(n,p,e1), a2=mod_fact(k,p,e2), a3=mod_fact(n-k,p,e3);
    if(e1>e2+e3) return 0;
    return a1*mod_inverse(a2*a3%p,p)%p;
}
bool c[100001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int a[n+1];
    int d;
    rep(i,0,n+1){
        cin>>a[i];
        if(c[a[i]]) d=i;
        c[a[i]]=1;
    }
    int s=0, t=0, u=0;
    int i=0;
    while(a[i]!=a[d]){
        s++;
        i++;
    }
    i++;
    while(a[i]!=a[d]){
        t++;
        i++;
    }
    i++;
    u=n-i+1;
    fact[1]=1;
    rep(i,2,MAX_N){
        fact[i]=fact[i-1]*i;
        fact[i]%=MOD;
    }
    rep(j,1,n+2){
        if(j==1) cout <<n<<"\n";
        else if(j==n+1) cout <<1<<"\n";
        else{
            cout << ((s+t+u>=j?mod_comb(s+t+u,j, MOD):0)+(s+t+u>=j-2?mod_comb(s+t+u, j-2, MOD):0)+(s+u>=j-1?mod_comb(s+u, j-1, MOD):0)+((s+t+u>=j-1?mod_comb(s+t+u, j-1, MOD):0)-(s+u>=j-1?mod_comb(s+u, j-1, MOD):0)+MOD)*2)%MOD<<"\n";
        }
    }
}