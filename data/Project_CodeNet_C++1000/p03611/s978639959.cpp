#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  int a;
  vector<int> b(100000);
  for(int i=0; i<n; i++) {
    cin >> a;
    b[a]++;
  }
  
  int sum = b[0]+b[1]+b[2];
  int ans = sum;
  for(int i=3; i<100000; i++) {
    sum += b[i];
    sum -= b[i-3];
    ans = max(ans, sum);
  }
  
  cout << ans << endl;
  return 0;
}