#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i = 0;i<n;++i)
typedef long long ll;

int main(){
  ll n;
  cin >> n;
  vector<ll> A(n);
  vector<ll> B(n);
  rep(i,n){
    cin >> A[i] >> B[i];
  }
  sort(A.rbegin(),A.rend());
  sort(B.begin(),B.end());
  ll ans = 0;
  rep(i,n-1){
    ans += min(A[i]-A[i+1],B[i+1]-B[i]);
  }
  ans += A[n-1]+B[0];
  cout << ans << endl; 
  return 0;
}
