#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,M;
  long long ans=1;
  cin >> N >> M;
  if (abs(N-M) >= 2){
    cout << 0 << endl;
  }else if (abs(N-M) == 1){
    for (int i = 1; i < min(N,M)+1; i++){
      ans *= i;
      ans = ans % ((long)pow(10,9.0)+7);
    }
    ans = ans * ans;
    ans = ans % ((long)pow(10,9.0)+7);
    ans = ans * max(N,M);
    ans = ans % ((long)pow(10,9.0)+7);
    cout << ans << endl;
  }else if (abs(N-M) == 0){
    for (int i = 1; i < N+1; i++){
      ans *= i;
      ans = ans % ((long)pow(10,9.0)+7);
    }
    ans = ans * ans * 2;
    ans = ans % ((long)pow(10,9.0)+7);
    cout << ans << endl;
  }
}