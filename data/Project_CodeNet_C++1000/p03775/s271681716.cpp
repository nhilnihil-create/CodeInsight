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
  ll n;
  cin >> n;

  ll baisu_max = ceil(sqrt(n));

  ll ans_min = INF;

  rep(i,baisu_max + 1) {
    if(i == 0) continue;
    
    if(n % i == 0) {
      ll tmp = floor(log(i) / log(10)) + 1;
      ll tmp2 = floor(log(n / i) / log(10)) + 1;
      ll tmp_ans = max(tmp,tmp2);

      ans_min = min(ans_min,tmp_ans);
    }
  }

  cout << ans_min << endl;
}
