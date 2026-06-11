#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,K;
  cin >> N >> K;
  
  int ans = 0;
  
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    
    if (K - x < x)
      ans += K - x;
    else
      ans += x;
  }
  cout << ans * 2 << endl;
}