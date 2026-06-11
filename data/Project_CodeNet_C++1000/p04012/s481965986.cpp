#include <bits/stdc++.h>
using namespace std;

int main() {
  int a[26]={};
  string s;
  cin >> s;
  for ( char c:s ) {
    a[c-'a']++;
  }
  for ( int i=0; i<26; i++ ) {
    if ( a[i]%2 ) {
      cout << "No" << '\n';
      return 0;
    }
  }
  cout << "Yes" << '\n';
  return 0; 
}