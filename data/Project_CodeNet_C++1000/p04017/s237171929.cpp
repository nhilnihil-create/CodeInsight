#include<bits/stdc++.h>
//ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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
ll inf=1000000000;
double pi=2*acos(0);
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
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    ll n;cin>>n;
    vector<ll> v(n);rep(i,0,n)cin>>v[i];
    ll l;cin>>l;
    ll d[n+1][20];
    rep(i,0,n){
        ll y=upper_bound(v.begin(),v.end(),v[i]+l)-v.begin();
        y--;
        d[i][0]=y;
    }
    d[n][0]=n;
    rep(j,1,20){
        rep(i,0,n+1){
            d[i][j]=d[d[i][j-1]][j-1];
            //cout<<d[i][j]<<" ";
        }
        //cout<<endl;
    }
    ll q;cin>>q;
    rep(i,0,q){
        ll a,b;cin>>a>>b;
        if(a>b)swap(a,b);
        a--;
        b--;
        ll u=n,dd=0;
        while(u-dd>1){
            ll mid=(u+dd)/2;
            ll y=mid;
            ll now=a;
            ll cn=0;
            while(y>0){
                if(y%2){
                    now=d[now][cn];
                }
                y/=2;
                cn++;
            }
            if(now>=b){
                u=mid;
            }
            else dd=mid;
        }
        cout<<u<<endl;
    }
}
