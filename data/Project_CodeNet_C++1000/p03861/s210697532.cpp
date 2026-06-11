#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using ld = long double;
const ll ATCODER_AMARI = 1000000007; //10^9 + 7
const ll INF = 10000000000000;

//階乗関数　ATCODER_AMARIに注意
ll factorial(ll k){
  ll sum = 1;
  for(int i = 1 ; i < k + 1; i++) {
    sum *= i;
    //sum = sum % ATCODER_AMARI;
  }
  return sum;
}

int main() {
  ll a,b,x; cin >> a >> b >> x;
  ll ans = 0;
  ll ans_a = 0, ans_b = 0;

  if(a == 0) {
    ans_a = 0;
  }
  else{
    ans_a = (a-1)/x+1;
  }
  ans_b = b/x + 1;

  ans = ans_b - ans_a;

  // ll kosu = b - a + 1;
  // ll syoko = a % x;
  // ll zero_position = INF,tmp = syoko;
  // ll current_pos = 1;
  // 
  // rep(i,x){
  //   if(tmp % x == 0) {
  //     zero_position = current_pos;
  //     break;
  //   }
  //   tmp++;
  //   current_pos++;
  // }
  // 
  // ll number_group = kosu / x;
  // ll rem_kou = kosu % x;
  // ll ans = 0;
  // if(rem_kou >= zero_position) {
  //   ans++;
  // }
  // ans += number_group;

  cout << ans << endl;
}

