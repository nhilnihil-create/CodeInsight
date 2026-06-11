#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(x) x.begin(), x.end()
#define mod 1000000007
typedef long long ll;

int main() {
  ll n, x;
  cin >> n >> x;
  vector<ll> vec(n);
  rep(i, n) cin >> vec[i];
  ll ans = 0;
  rep(i, n-1){
    ll sum = vec[i]+vec[i+1];
    if(sum > x){
      if(sum-x <= vec[i+1]){
        vec[i+1] -= sum-x;
        ans += sum-x;
      }else{
        vec[i] -= sum-x-vec[i+1];
        vec[i+1] = 0;
        ans += sum-x;
      }
    }
  }
  cout << ans << endl;
  return 0;
}