#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (ll i = m; i < (n); i++)

using ll = long long;
using pii = pair<int, int>;
using Vi = vector<int>;


void Prime_factorization (int N, vector<int> &vec){
  for(int i = 2;i<= N;i++){
    while(N%i==0){
      N /= i;
      vec[i]++;
    }
  }
}
  
  
int main() {
  int N;
  cin >> N;
  vector<int> V(N+1);
  for(int i = 2; i<=N; i++){
    Prime_factorization(i,V);
  }
  long long ans = 1;
  for(int i = 2;i<= N;i++){
    ans *= V[i]+1;
    ans %= 1000000007;
  }
  /*
  rep(i,N+1){
    cout << V[i] << endl;
  }
  */
  cout << ans << endl;
}
      