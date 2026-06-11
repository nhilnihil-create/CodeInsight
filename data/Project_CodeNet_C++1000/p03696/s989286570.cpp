#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int l=0,mi=1000000;
  string t="";
  for ( int i=0; i<n; i++ ) {
    if ( s[i]=='(' ) {
        l++;
    } else {
        l--;
    }
    mi=min(mi,l);
  }
  if ( mi<0 ) {
    for ( int i=0; i<-mi; i++ ) {
        t+='(';
    }
  }
  t+=s;
  if ( mi<0 ) l-=mi;
  for ( int i=0; i<l; i++ ) {
    t+=')';
  }
  cout << t << '\n';
  return 0; 
}
