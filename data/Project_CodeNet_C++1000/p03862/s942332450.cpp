#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n, x;
  cin >> n >> x;
  
  vector<int> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A.at(i);
  }
  
  int64_t ans = 0;
  int64_t c = 0;
  
  if(A.at(0) > x) {
    ans = abs(x - A.at(0));
    A.at(0) = x;
  }

  
  for (int i = 0; i < n-1; i++) {
    if (A.at(i) + A.at(i+1) > x) {
      c = A.at(i+1);
      A.at(i+1) = abs(x - A.at(i));
      ans += abs(c- A.at(i+1));

    }
  }
      


  
  cout << ans << endl;

  
 
}
             
 