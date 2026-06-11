#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
  ll a,b,h;
  cin>>a>>b>>h;
  
  ll ans=0;
  ans+=(h*(a+b))/2;
  cout<<ans<<endl;
  
  return 0;
}