#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
#define dbg(x) cout<<#x<<":"<<x<<endl
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> PP;

int main(){
  ll n;
  cin>>n;
  vector<ll> v;
  ll cnt=0;
  ll t=n;
  while(t){
    v.pb(t%2);
    cnt+=t%2;
    t/=2;
  }
  reverse(all(v));

  // cout<<v.size()<<endl;
  vector<ll> ans;

  ll k=v.size()+cnt-2;
  for(ll i=0;i<cnt-1;i++)ans.pb(v.size()+i);
  for(ll i=1;i<v.size();i++)ans.pb(i);

  for(int i=1;i<v.size();i++){
    ans.pb(i);
    if(v[i])ans.pb(k--);
  }
  
  ans.pb(100);
  ans.pb(100);
  cout<<ans.size()<<endl;
  for(int i=0;i<ans.size();i++){
    if(i)cout<<" ";
    cout<<ans[i];
  }
  cout<<endl;
  return 0;
}

