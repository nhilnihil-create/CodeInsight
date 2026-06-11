#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,a=0,b=0;
  string s;
  cin >> n >> s;
  for(long i=0;i<n;i++) {
    if(s[i]=='(') {
      b++;
    } else {
      if(b>0) {
        b--;
      } else {
        a++;
      }
    }
  }
  for(long i=0;i<a;i++) cout << "(";
  cout << s;
  for(long i=0;i<b;i++) cout << ")";
  cout << endl;
}