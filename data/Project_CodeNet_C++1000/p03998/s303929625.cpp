#include <bits/stdc++.h>
using namespace std;

int main() {
  string a[3];
  int idx[3]={};
  int crt=0;
  for ( int i=0; i<3; i++ ) cin >> a[i];
  while ( 1 ) {
    if ( idx[crt]>=a[crt].size() ) break;
    int nxt=a[crt][idx[crt]]-'a';
    idx[crt]++;
    crt=nxt;
  }
  cout << "ABC"[crt] << '\n';
  return 0;
}
