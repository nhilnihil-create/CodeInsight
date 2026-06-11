#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int n,a,b;
bool check(ll k,vector<ll> x){
  //bool ok;
  ll ti=0;
  for(int i=0;i<n;++i){
    x[i]-=b*k;
    if(x[i]>0){
      if(x[i]%(a-b)==0) ti+=x[i]/(a-b);
      else ti+=x[i]/(a-b)+1;
    }
  }
  if(ti>k) return 0;
  else return 1;
}

int main(){
  cin >> n >> a >> b;
  vector<ll> h(n);
  for(int i=0;i<n;++i) cin >> h[i];

  sort(h.rbegin(),h.rend());
  //int diff=a-b;
  ll l=-1;
  ll r=h[0]/b+10;
  //cout << r << endl;
  //cout << l << endl;
  while(r-l>0){
    ll mod=(l+r)/2;
    //cout << check << endl;
    if(check(mod,h)) r=mod;
    else l=mod+1;
  }
  if(!check(l,h)) l=r;
  cout << l << endl;
  return 0;
}
