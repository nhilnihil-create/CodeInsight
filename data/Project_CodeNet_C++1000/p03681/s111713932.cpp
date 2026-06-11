#include <iostream>
#include <cmath>
using namespace std;

int main(){
  int N, M;
  long long int ans = 1;
  int MOD = 1000000007;
  
  cin >> N >> M;
  
  if(abs(N - M) > 1){
    cout << 0 << endl;
    return 0;
  }
  
  for(int i = 0;i < N;i++) ans = (ans % MOD) * ((i + 1) % MOD);
  for(int i = 0;i < M;i++) ans = (ans % MOD) * ((i + 1) % MOD);
  
  if(abs(N - M)) cout << ans % MOD << endl;
  else cout << (2 * (ans % MOD)) % MOD << endl;
  
  return 0;
}