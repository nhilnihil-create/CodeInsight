#include<bits/stdc++.h>
//ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef pair<int,int> pii;
typedef pair<pii,int> ppii;
typedef pair<int,pii> pipi;
typedef pair<ll,ll> pll;
typedef pair<pll,ll> ppll;
typedef pair<ll,pll> plpl;
typedef tuple<ll,ll,ll> tl;
ll mod=1000000007;
ll mod2=998244353;
ll mod3=1000003;
ll mod4=998244853;
ll inf=1000000000000000000;
long double pi=3.14159265358979323846L;
#define rep(i,m,n) for(ll i=m;i<n;i++)
#define rrep(i,n,m) for(ll i=n;i>=m;i--)
int dh[4]={1,-1,0,0};
int dw[4]={0,0,1,-1};
int ddh[8]={-1,-1,-1,0,0,1,1,1};
int ddw[8]={-1,0,1,-1,1,-1,0,1};
ll lmax(ll a,ll b){
    if(a<b)return b;
    else return a;
}
ll lmin(ll a,ll b){
    if(a<b)return a;
    else return b;
}
ll gcd(ll a,ll b){
    if(a<b)swap(a,b);
    if(b==0)return a;
    if(a%b==0)return b;
    return gcd(b,a%b);
}
ll Pow(ll n,ll k){
    ll ret=1;
    ll now=n;
    while(k>0){
        if(k&1)ret*=now;
        now*=now;
        k/=2;
    }
    return ret;
}
ll beki(ll n,ll k,ll md){
  ll ret=1;
  ll now=n;
  while(k>0){
    if(k%2==1){
      ret*=now;
      ret%=md;
    }
    now*=now;
    now%=md;
    k/=2;
  }
  return ret;
}
ll gyaku(ll n,ll md){
  return beki(n,md-2,md);
}
ll bit[800010];
ll u;
void bitinit(ll n){
    ll y=1;
    rep(i,0,69){
        
        if(y>=n){
            u=y;
            break;
        }
        y*=2;
    }
    fill(bit,bit+u+10,0);
}
void add(ll n,ll x){
    ll i=n;
    bit[i]+=x;
    bit[i]%=mod;
    while(i<u){
        i+=i&(-i);
        bit[i]+=x;
        bit[i]%=mod;
    }
}
ll sum(ll n){
    ll i=n;
    ll ret=0;
    while(i>0){
        ret+=bit[i];
        i-=i&(-i);
        ret%=mod;
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    ll n,m;cin>>n>>m;
    bitinit(m+1);
    vector<int> v[m+1];
    int l[n],r[n];
    rep(i,0,n){
        cin>>l[i]>>r[i];
        v[r[i]-l[i]+1].push_back(i);
    }
    ll cnt=0;
    rep(i,1,m+1){
        ll ans=n-cnt;
        for(int j=i;j<=m;j+=i){
            ans+=sum(j);
        }
        cout<<ans<<endl;
        rep(j,0,v[i].size()){
            int num=v[i][j];
            add(l[num],1);
            add(r[num]+1,-1);
        }
        cnt+=v[i].size();
    }
    
}

