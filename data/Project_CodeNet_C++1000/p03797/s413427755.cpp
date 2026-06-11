#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i<n;i++)
using ll = long long;
using P = pair<ll,ll>;

int main(){
  ll n,m;cin>>n>>m;
  ll sum = 0;
  if (2*n<=m){
    sum+=n;
    m-=2*n;
    sum+=m/4;
    cout << sum << endl;
  }
  else{
    sum+=m/2;
    cout << sum << endl;
  }
  return 0;
}