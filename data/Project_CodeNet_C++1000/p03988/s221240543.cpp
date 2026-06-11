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
ll inf=1000000000000000000;
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
int main(){
  int n;cin>>n;
  int a[n];
  vector<int> v;
  rep(i,0,n){
    cin>>a[i];
    v.push_back(a[i]);
  }
  if(n==2){
    cout<<"Possible"<<endl;
    return 0;
  }
  sort(v.begin(),v.end());
  int ma=v.back();
  if(ma==1){
    cout<<"Impossible"<<endl;
    return 0;
  }
  if(v[0]<(ma+1)/2){
    cout<<"Impossible"<<endl;
    return 0;
  }
  int cnt[ma+1];
  fill(cnt,cnt+ma+1,0);
  rep(i,0,n)cnt[a[i]]++;
  int t=ma/2+1;
  rep(i,t+1,ma+1){
    if(cnt[i]<=1){
      cout<<"Impossible"<<endl;
      return 0;
    }
  }
  if(ma%2==0){
    if(cnt[t-1]!=1){
      cout<<"Impossible"<<endl;
      return 0;
    }
  }
  else{
    if(cnt[t]!=2){
      cout<<"Impossible"<<endl;
      return 0;
    }
  }
  cout<<"Possible"<<endl;
}

