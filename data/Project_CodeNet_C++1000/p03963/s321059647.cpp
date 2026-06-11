#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll n,k;
  cin >> n >> k;
  ll ans=k;
  for(ll i=0;i<n-1;i++){
    ans*=(k-1);
  }
  cout << ans;
}
    
  