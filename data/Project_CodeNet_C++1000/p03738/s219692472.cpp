#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 
  
  string a, b;
  cin >> a >> b;

  int m = a.size(), n =  b.size();

  if (m < n) {
    cout << "LESS" << "\n";
    return 0;
  }
  else if (m > n) {
    cout << "GREATER" << "\n";
    return 0;
  }


  for (int i = 0; i < m; ++i) {
    if (a[i] < b[i]) {
      cout << "LESS" << "\n";
      return 0;
    }
    else if (a[i] > b[i]) {
      cout << "GREATER" << "\n";
      return 0;
    }
  }

  cout << "EQUAL" << "\n";
}
