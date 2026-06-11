#include <bits/stdc++.h>
using namespace std;

int main() {
  string w;
  cin >> w;
  vector<int> V(26, 0);
  for (int i=0; i<w.size(); i++) {
    V[w[i]-'a']++;
  }
  
  string ans="Yes";
  for (int i=0; i<V.size(); i++) {
    if (V[i]%2==1) {
      ans = "No";
      break;
    }
  }
  cout << ans << endl;
}