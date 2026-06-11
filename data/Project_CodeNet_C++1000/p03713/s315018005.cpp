#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define len(v) ll(v.size())
#define fi first
#define se second

template <class T>
void cout_vec(const vector<T> &vec){
  for(auto itr:vec) cout<<itr<<' ';
  cout<<endl;
}

typedef pair<ll,ll> P;
const ll mod=1e9+7;
const ll inf=1e15;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int h,w;
  cin>>h>>w;
  ll ans=inf;
  FOR(i,1,h){
    ll x=h-i;
    ll sum1=i*w;
    ll sum2=x*(w/2);
    ll sum3=x*(w-w/2);
    ll cnt1=min({sum1,sum2,sum3});
    ll cnt2=max({sum1,sum2,sum3});
    ans=min(ans,cnt2-cnt1);
  }
  FOR(i,1,h){
    ll x=h-i;
    ll sum1=i*w;
    ll sum2=x/2*(w);
    ll sum3=(x-x/2)*(w);
    ll cnt1=min({sum1,sum2,sum3});
    ll cnt2=max({sum1,sum2,sum3});
    ans=min(ans,cnt2-cnt1);
  }
  swap(h,w);
  FOR(i,1,h){
    ll x=h-i;
    ll sum1=i*w;
    ll sum2=x*(w/2);
    ll sum3=x*(w-w/2);
    ll cnt1=min({sum1,sum2,sum3});
    ll cnt2=max({sum1,sum2,sum3});
    ans=min(ans,cnt2-cnt1);
  }
  FOR(i,1,h){
    ll x=h-i;
    ll sum1=i*w;
    ll sum2=x/2*(w);
    ll sum3=(x-x/2)*(w);
    ll cnt1=min({sum1,sum2,sum3});
    ll cnt2=max({sum1,sum2,sum3});
    ans=min(ans,cnt2-cnt1);
  }
  cout<<ans<<endl;
}