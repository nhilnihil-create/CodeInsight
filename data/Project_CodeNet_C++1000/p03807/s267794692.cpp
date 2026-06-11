#include <bits/stdc++.h>
#define rep(i,n); for (ll i = 0; i < n ;++i )
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  ll n,a;
  cin >> n;
  vector<ll> A(n);
  rep(i,n){
    cin >> A[i];
    if(A[i] % 2 == 1){
      ++a;
    }
  }
  if(a%2 == 0) puts("YES");
  else puts("NO");
  return 0;
}
