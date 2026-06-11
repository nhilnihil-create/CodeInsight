#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
ll mod= 1e9 + 7;



int main() {
  int n;
  cin >>n;
  ll ans=100000000;
  int a[n];
  rep(i,n){
    cin >> a[i];
  }
  for(int i=-100;i<=100;i++){
    ll sum=0;
    rep(r,n){
      int g=a[r]-i;
      sum+=g*g;
    }
    ans=min(ans,sum);
  }
  cout << ans << endl;
}