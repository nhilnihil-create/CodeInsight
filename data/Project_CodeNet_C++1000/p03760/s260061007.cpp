#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 
  
  string o, e;
  cin >> o >> e;

  string res;

  int i = 0, j = 0;
  while (i < o.size() || j < e.size()) {
    if (i < o.size()) {
      res += o[i++];
    }
    if (j < e.size()) {
      res += e[j++];
    }
  }

  cout << res << "\n";
}
