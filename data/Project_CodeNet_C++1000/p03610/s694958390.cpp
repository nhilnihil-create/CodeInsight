#include <bits/stdc++.h>
using namespace std;
     
int main() {
  string s, answer = "";  
  cin >> s;
 
  int a = s.size();
  for (int i = 1; i <= a; i++) {
    if (i%2 == 1) {
      answer = answer + s[i-1];
    }
  }
  
  cout << answer << endl;
}