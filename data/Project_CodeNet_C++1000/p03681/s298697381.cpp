#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

const int mod = 1'000'000'007;

ll Factorial(int n){
  if (n == 1){
    return 1;
  }
  ll sum = 1;
  sum = n * Factorial(n-1);
  return sum % mod;
}

int main(){
  int n, m;
  cin >> n >> m;

  if (abs(n-m)>1){
    cout << 0 << endl;
    return 0;
  }

  ll ans = Factorial(n) * Factorial(m) % mod;
  if (n == m){
    ans = ans * 2 % mod;
  }
  cout << ans << endl;
}
