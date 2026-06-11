#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  ll n,i,a,b;
  cin >> n >> a >> b;
  vector<ll> x(n);
  for(i=0;i<n;++i){
    cin >> x[i];
  }
  ll hi=0;
  for(i=0;i<n-1;++i){
    if((x[i+1]-x[i])*a<b){
      hi+=(x[i+1]-x[i])*a;
    }else{
      hi+=b;
    }
  }
  cout << hi << endl;
  return 0;
}
