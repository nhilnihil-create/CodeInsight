#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> join(vector<ll> a,vector<ll> b){
  //if(a.size()>b.size())swap(a,b);
  vector<ll> ret;
  for(ll itr=0;itr<a.size();itr++){
    ll now=a[itr];
    ll x=lower_bound(b.begin(),b.end(),now)-b.begin();
    ll y=upper_bound(b.begin(),b.end(),now)-b.begin();
    if(x!=y)ret.push_back(now);
  }
  return ret;
}
int main(){
 
  ll n,k;cin>>n>>k;
  vector<ll> st[30];
  ll a[n],b[n];
  for(ll i=0;i<n;i++){
    cin>>a[i]>>b[i];
    ll m=a[i];
    for(ll j=0;j<30;j++){
      ll t=m%2;
      if(t==0)st[j].push_back(i);
      m/=2;
    }
  }
  //for(ll i=0;i<n;i++){
    //for(auto j=st[i].begin();j!=st[i].end();j++)cout<<*j<<" ";
    //cout<<endl;
 // }
 // return 0;
 // set<ll> o=join(st[0],st[1]);
  //for(auto j=o.begin();j!=o.end();j++)cout<<*j<<" ";
  //return 0;
  
  ll ans=0;
  vector<ll> re;
  for(ll i=0;i<n;i++)re.push_back(i);
  for(ll i=29;i>=0;i--){
    if((k>>i)%2==0){
      re=join(st[i],re);
    }
    else{
      vector<ll> ni=join(st[i],re);
      ll sum=0;
      for(ll j=0;j<ni.size();j++){
        sum+=b[ni[j]];
      }
      ans=max(ans,sum);
    }
  }
  ll summ=0;
  for(ll i=0;i<re.size();i++){
    summ+=b[re[i]];
  }
  ans=max(ans,summ);
  cout<<ans<<endl;
}

