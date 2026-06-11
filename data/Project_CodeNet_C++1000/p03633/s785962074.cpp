#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;  
  cin >> N;
  int64_t ans;
  cin >> ans;
  for (int i = 1; i < N; i++) {
    int64_t T;
    cin >> T;
    ans = lcm(ans, T);
  }
  cout << ans << endl;
}