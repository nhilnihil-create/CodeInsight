#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
using vll=vector<ll>;
using vvll=vector<vll>;
using vi=vector<int>;
using vvi=vector<vector<int>>;
using vb=vector<bool>;
using pii=pair<int,int>;
using vpii=vector<pair<int,int>>;

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

//pow(llpow,modpow)
template<class T> ll llpow(ll x,T n){ll ans=1;if(x==0)ans=0;while(n){if(n&1)ans*=x;x*=x;n>>=1;}return ans;}
long long modpow(long long a, long long n, long long mod) {long long res = 1;while (n > 0) {if (n & 1) res = res * a % mod;a = a * a % mod;n >>= 1;}return res;}
//最大公約数
template<class T> inline T gcd(T x,T y){if(y==0)return x; else {return gcd(y,x%y);}}
//最小公倍数
template<class T> inline T lcm(T x,T y){return x/gcd(x,y)*y;}
//逆元
long long modinv(long long a, long long m) {long long b = m, u = 1, v = 0;while (b) {long long t = a / b;a -= t * b; swap(a, b);u -= t * v; swap(u, v);}u %= m;if (u < 0) u += m;return u;}

#define rep(i, begin_i, end_i) for (ll i = (ll)begin_i; i < (ll)end_i; i++)
//試験導入
#define irep(i, end_i, begin_i) for (ll i = (ll)begin_i-1; i >= (ll)end_i; i--)

long long INF = 1LL<<60;
int main( ){
    int n;
    cin>>n;
    using plli=pair<ll,int>;
    vector<plli> costidx[n];
    vll a(n-1),b(n-1);
    vll c(n-1);
    rep(i,0,n-1){
        cin>>a[i]>>b[i]>>c[i];
        a[i]--,b[i]--;
        plli first=make_pair(c[i],a[i]);
        plli second=make_pair(c[i],b[i]);
        costidx[b[i]].push_back(first);
        costidx[a[i]].push_back(second);
    }
    int Q,k;
    cin>>Q>>k;
    k--;
    vll dist(n,INF);
    vi color(n,0);
    priority_queue<plli,vector<plli>,greater<plli>> q;
    plli iniv=make_pair(0,k);
    q.push(iniv);
    while(!q.empty()){
        plli t=q.top();
        q.pop();
        ll cost=t.first;
        int idx=t.second;
        if(color[idx]==2)continue;
        chmin(dist[idx],cost);
        color[idx]=2;
        for(auto e:costidx[idx]){
            if(color[e.second]==2)continue;
            q.emplace(e.first+cost,e.second);
            color[e.second]=1;
        }
    }
    rep(i,0,Q){
        int x,y;
        cin>>x>>y;
        x--,y--;
        cout<<dist[x]+dist[y]<<endl;
    }
    return 0;
}


