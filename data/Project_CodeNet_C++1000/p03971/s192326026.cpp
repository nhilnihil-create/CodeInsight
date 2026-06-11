
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a, b, sum = 0, aa=0,bb = 0;
  string s;
  cin >> n >> a >> b >> s;
  for (int i = 0; i < n; i++) {
    char m = s[i];
    if (m == 'a') {
      if (aa+bb+1 <= a + b) {
        cout << "Yes" << endl;
        aa++;
      } else {
        cout << "No" << endl;
      }
    }
    if (m == 'b') {
      if (aa+bb+1 <= a + b && bb+1  <= b) {
        bb++;
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }

    if (m == 'c') {
      cout << "No" << endl;
    }
  }
}

  

    
