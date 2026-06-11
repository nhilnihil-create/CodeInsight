#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll n,a,b;
  cin>>n>>a>>b;
  if(n==1&&a!=b){
    cout<<0<<endl;
    return 0;
  }
  if(a>b){
    cout<<0<<endl;
    return 0;
  }
  if(n==2){
    cout<<a+b<<endl;
    return 0;
  }
  ll min_s,max_s;
  min_s=a*(n-1)+b;
  max_s=b*(n-1)+a;
  ll ans=max_s-min_s+1;
  cout<<ans<<endl;
}