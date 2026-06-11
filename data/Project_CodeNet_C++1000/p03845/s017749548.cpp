#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  vector<int> T(n);
  for (int i = 0; i < n; i++) {
    cin >> T.at(i);
  }
  
  int m;
  cin >> m;
  vector<int> P(m);
  vector<int> X(m);
  for (int i = 0; i < m; i++) {
    cin >> P.at(i) >> X.at(i);
  }
  
  for (int i = 0; i < m; i++) {
    vector<int> S(n);
    for (int i = 0; i < n; i++) {
      S.at(i) = T.at(i);
    }
    
    int ans = 0;
    int sr = P.at(i) - 1;
    S.at(sr) = X.at(i);
    ans = accumulate(S.begin(), S.end(), 0);
    
    cout << ans << endl;
  }

}