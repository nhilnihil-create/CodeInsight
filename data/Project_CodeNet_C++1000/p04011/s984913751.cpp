#include<bits/stdc++.h>
using namespace std;

int main(void){
  int N, K, X, Y, ans;
  cin >> N >> K >> X >> Y;
  if(N >= K)
    ans = K * X + (N - K) * Y;
  else
    ans = N * X;
  cout << ans << "\n";
  return 0;
}
