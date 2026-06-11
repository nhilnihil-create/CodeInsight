#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <algorithm>

using namespace std;

int main() {
  int a,b,c;
  cin >> a >> b >> c;
  if(a == 5) {
    if(b == 5 && c == 7) cout << "YES";
    else if(b == 7 && c == 5) cout << "YES";
    else cout << "NO";
  }
  else if(b == 5) {
    if(a == 5 && c == 7) cout << "YES";
    else if(a == 7 && c == 5) cout << "YES";
    else cout << "NO";
  }
  else if(c == 5) {
    if(a == 5 && b == 7) cout << "YES";
    else if(a == 7 && b == 5) cout << "YES";
    else cout << "NO";
  }

  
  //cout << m << endl;
}