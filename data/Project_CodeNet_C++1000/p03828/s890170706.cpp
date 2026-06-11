#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define sort(A) sort(A.begin(),A.end())
#define reverse(A) reverse(A.begin(),A.end())
#define vecmin(A) *min_element(A.begin(),A.end())
#define vecmax(A) *max_element(A.begin(),A.end())
typedef long long ll;

bool isPrime(ll a){
  if(a == 1) return false;
  if(a == 2) return true;
  if(a%2 == 0) return false;
  for(ll i=3;i*i<=a;i += 2){
    if(a%i == 0) return false;
  }
  return true;
}

int howdiv(int n,int d){
  if(n%d) return 0;
  else return 1+howdiv(n/d,d);
}

int main(){
  int n;
  cin >> n;
  vector<ll> primes(0);
  for(ll i=2;i<1000;i++){
    if(isPrime(i))primes.push_back(i);
  }
  int m = primes.size();
  ll dp[1001][m] = {0};
  rep1(i,1000){
    rep(j,m){
      dp[i][j] = dp[i-1][j] + howdiv(i,primes[j]);
    }
  }
  ll ans = 1;
  rep(j,m){
    ans *= (dp[n][j]+1);
    ans %= 1000000007;
  }
  cout << ans << endl;
}