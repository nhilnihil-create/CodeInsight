#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, p, q;
  cin >> a >> b;
  for(int i = 0; i < a; i++){
    bool r = 0;
    for(int j = 0; j < b; j++){
      string s;
      cin >> s;
      if(s == "snuke"){
        p = i + 1;
        q = j;
        r = 1;
        break;
      }
    }
    if(r)
      break;
  }
  char c = 'A' + q;
  cout << c << p << endl;
}
