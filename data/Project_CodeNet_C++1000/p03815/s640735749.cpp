#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int max_n = 100;
int dp[max_n][max_n];
int n,m;
int main(){
  ll x; cin >>x;
  ll k = x/11;
  ll cnt = 0;
  cnt += 2 * k;
  x -= 11 *k;
  if(x>0){
    cnt += x/7 +1;
  }
  cout << cnt << endl;
  return 0;
}
