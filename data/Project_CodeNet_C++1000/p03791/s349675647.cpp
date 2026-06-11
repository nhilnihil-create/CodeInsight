#include <iostream>
#include <algorithm>

#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

using ll = long long;

const int mod = 1e9 + 7;

int n;
int x[100000];

int mul(int a, int b){
  return ll(a) * b % mod;
}
int fact(int k){
  return k ? mul(fact(k - 1), k) : 1;
}

int main(){
  cin >> n;
  rep(i, n){
    cin >> x[i];
  }
  int ans = 1;
  int p = 0;
  int k = 0;
  while(true){
    while(p < n && x[p] > 2 * k){
      ++p;
      ++k;
    }
    if(p == n){
      ans = mul(ans, fact(k));
      break;
    }
    ans = mul(ans, k + 1);
    ++p;
  }
  cout << ans << endl;
  return 0;
}