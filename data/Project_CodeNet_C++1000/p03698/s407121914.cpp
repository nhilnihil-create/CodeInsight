#include <bits/stdc++.h>
using namespace std;

int main() {
  bool a[256]={};
  string s;
  cin >> s;
  for ( char c:s ) {
    if ( a[c] ) {
      puts("no");
      return 0;
    }
    a[c]=1;
  }
  puts("yes");
  return 0;
}