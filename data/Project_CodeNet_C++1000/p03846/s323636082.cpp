#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 1000000007;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  ll ans = 1;
  sort(a.begin(), a.end());
  // if(n == 1 && a[0] == 0){
  //   cout << 1 << endl;
  //   return 0;
  // }
  if(a.size() % 2 == 1){
    if(a[0] == 0) a.erase(a.begin());
    else {
      cout << 0 << endl;
      return 0;
    }
  }

  int cur;
  if(n % 2) cur = 2;
  else cur = 1;

  for(int i = 0; i < a.size() - 1; i += 2){
    if(i + 1 >= a.size()) {
      break;
    }
    if(a[i] == a[i + 1] && a[i] == cur){
      ans *= 2;
      ans %= mod;
      cur += 2;
    } else {
      
      ans = 0;
      break;
    }
  }
  cout << ans << endl;
}