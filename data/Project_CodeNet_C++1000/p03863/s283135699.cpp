#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin>>s;
  int n = s.length();
  bool ok = true;
  for (int i=0; i<n; i++) {
    if (i % 2 == 0) {
      if (s[i] != s[0]) {
        ok = false;
        break;
      }
    } else {
      if (s[i] != s[1]) {
        ok = false;
        break;
      }
    }
  }
  if (ok) {
    cout<<"Second"<<endl;
    return 0;
  }
  if (s[0] == s[n-1]) {
    if (n % 2 == 0) {
      cout<<"First"<<endl;
    } else {
      cout<<"Second"<<endl;
    }
  } else {
    if (n % 2 == 0) {
      cout<<"Second"<<endl;
    } else {
      cout<<"First"<<endl;
    }
  }
}