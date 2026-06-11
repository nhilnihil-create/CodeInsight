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
ll inf=1LL<<60;
long double pi=3.14159265358979323846L;
double eps=1e-12;
#define rep(i,m,n) for(ll i=m;i<n;i++)
#define rrep(i,n,m) for(ll i=n;i>=m;i--)
#define srep(itr,st) for(auto itr=st.begin();itr!=st.end();itr++)
int dh[4]={1,-1,0,0};
int dw[4]={0,0,1,-1};
int ddh[8]={-1,-1,-1,0,0,1,1,1};
int ddw[8]={-1,0,1,-1,1,-1,0,1};
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
ll gya[1000010];
ll kai[1000010];
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
void nckinit(ll n,ll md){
  kai[0]=1;
  kai[1]=1;
  for(int i=2;i<=n;i++){
    kai[i]=kai[i-1]*i;
    kai[i]%=md;
  }
  gya[n]=gyaku(kai[n],md);
  for(int i=n-1;i>=1;i--){
    gya[i]=gya[i+1]*(i+1);
    gya[i]%=md;
  }
  gya[0]=1;
}
ll nck(ll n,ll k,ll md){
  if(k<0)return 0;
  if(k==0||n==k)return 1;
  ll ret=kai[n];
  ret*=gya[n-k];
  ret%=md;
  ret*=gya[k];
  ret%=md;
  return ret;
}
ll npk(ll n,ll k,ll md){
  if(k<0)return 0;
  if(k==0)return 1;
  ll ret=kai[n];
  ret*=gya[n-k];
  ret%=md;
  return ret;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll n,m;cin>>n>>m;
    ll a[n];
    ll cost[m];
    fill(cost,cost+m,0);
    ll cnt[m];
    fill(cnt,cnt+m,0);
    ll cnt2[m];
    fill(cnt2,cnt2+m,0);
    rep(i,0,n){
        cin>>a[i];
        a[i]--;
        if(i>0){
            cnt[a[i-1]]++;
            ll co=a[i]-a[i-1];
            if(a[i]<a[i-1])co+=m;
            cost[a[i]]+=co;
            cnt2[a[i]]++;
        }
    }
    ll ans=0;
    ll now=0;
    rep(i,1,n){
        if(a[i]<a[i-1]){
            now++;
            ans+=1+a[i];
        }
        else{
            ans+=a[i]-a[i-1];
            if(a[i-1]==0)now++;
        }
    }
    ll mi=ans;
    rep(i,1,m){
        //cout<<ans<<" "<<now<<endl;
        now-=cnt2[i-1];
        ans-=now;
        ans+=cnt[i-1];
        ans+=cost[i-1];
        ans-=cnt2[i-1];
        mi=min(mi,ans);
        now+=cnt[i];
        //cout<<ans<<endl;
    }
    cout<<mi<<endl;
}





