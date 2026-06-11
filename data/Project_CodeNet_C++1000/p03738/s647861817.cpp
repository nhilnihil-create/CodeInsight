#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < n; i++) 
using namespace std;
typedef long long ll;

int main() {
  
  string a, b;
  cin >> a >> b;
  
  
  if (a.size() > b.size()) cout << "GREATER" << endl;
  else if (a.size() < b.size()) cout << "LESS" << endl;
  else {
    REP(i,a.size()) {
      if (a[i] > b[i]) {
        cout << "GREATER" << endl;
        break;
      }
      else if (a[i] < b[i]) {
        cout << "LESS" << endl;
        break;
      }
      if (i == a.size() - 1 && a[i] == b[i]) {
        cout << "EQUAL" << endl;
      }
    }
  }
}