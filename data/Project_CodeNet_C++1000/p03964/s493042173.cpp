#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  
  vector<int> T(n), A(n);
  for (int i = 0; i < n; i++) {
    cin >> T.at(i) >> A.at(i);
  }
  
  int64_t t = 1;
  int64_t a = 1;
  int64_t s, x, y;
  for (int i = 0; i < n; i++) {
    x = (t+(T.at(i)-1)) / T.at(i);
    y = (a+(A.at(i)-1)) / A.at(i);
    s = max(x, y);
    t = s * T.at(i);
    a = s * A.at(i);
  }
  
  cout << t + a << endl;
}
             
 