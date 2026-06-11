#include<bits/stdc++.h>
using namespace std;
using ll=long long;


int main(){
  int n;
  cin >> n;
  vector<ll> a(n),t(n);
  for(int i=0;i<n;++i){
    cin >> a[i] >> t[i];
  }
  ll x=1;
  ll y=1;
  ll N=1;
  for(int i=0;i<n;++i){
    if(i==0) N=1;
    else N=max((a[i-1]*N+a[i]-1)/a[i],(t[i-1]*N+t[i]-1)/t[i]);

    x=a[i]*N;
    y=t[i]*N;
  }
  cout << x+y << endl;
  return 0;
}
