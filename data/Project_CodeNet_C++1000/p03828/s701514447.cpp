#include <bits/stdc++.h>
#define rep2(i,m,n) for (int i = (int)(m); i < (int)(n); i++)
#define rep(i,n) rep2(i,0,n)
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
using namespace std;
using ll = long long;
template <typename T>
T sq(T x){
  return x * x;
}
const int mod = 1e9 + 7;
const int Max_N = 1e5 + 1;
int vis[Max_N];

void div(int x) {
  for (int i = 2; i * i <= x; i++){
    while (x % i == 0) {
      vis[i]++;
      x /= i;
    }
  }
  if (x > 1) vis[x]++;
}

bool isPrime(int n){
  for(int i = 2; i <= sqrt(n); i++)
    if (n % i == 0)
      return false;
  return true;
}
ll cnt[Max_N];
signed main (){
  int N;
  cin >> N;

  rep2(i,2,N + 1) div(i);
  ll ans = 1;
  rep2(i,2,1e3+1){
    if(vis[i]>0){
      ans *= (vis[i] + 1);
      ans %= mod;
    }
  }
  cout << ans <<endl;
  return 0;
}
