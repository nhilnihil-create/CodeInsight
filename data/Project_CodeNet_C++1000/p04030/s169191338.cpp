#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void) {
  char s[11];
  cin >> s;
  char t[11]; int j = 0;
  
  for (int i = 0; i < 11; i++) {
    if(s[i] == 'B') {
      if (j > 0) 
      t[--j] = ' ';
      else 
      ;
    } else {
      t[j++] = s[i];
    }
  }
  cout << t << endl;
}