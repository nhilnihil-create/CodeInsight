#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string o, e;
  cin >> o >> e;
  
  string ans;
  
  if (o.size() == e.size()) {
    for (int i = 0; i < o.size(); i++) {
      ans += o[i];
      ans += e[i];
    }
  }
  else {
    for (int i = 0; i < e.size(); i++) {
      ans += o[i];
      ans += e[i];
    }
    ans += o[e.size()];
  }
  
  cout << ans;
}