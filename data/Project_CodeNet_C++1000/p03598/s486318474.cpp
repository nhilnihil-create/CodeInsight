#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, K;
  cin >> N >> K;
  int ans = 0;
  for(int n = 0; n < N; n++){
    int x;
    int dist_A = 0, dist_B = 0;
    cin >> x;
    dist_A = x * 2;
    dist_B = abs(x - K) * 2;

    if(dist_A >= dist_B){
      ans += dist_B;
    }else{
      ans += dist_A;
    }
  }
  cout << ans << endl;
}