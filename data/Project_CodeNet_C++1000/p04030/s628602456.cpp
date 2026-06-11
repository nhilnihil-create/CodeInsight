#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<char> a;
  string s;
  cin >> s;
  for ( char c:s ) {
    if ( c=='B' ) { if ( a.size() ) a.pop_back() ; }
    else a.push_back(c);
  }
  for ( char c:a ) {
    cout << c;
  }
  return 0;
}
