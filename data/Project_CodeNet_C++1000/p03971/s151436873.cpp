#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,a,b;
  string s;
  cin >> n >> a >> b >> s;
  int cnt1=0,cnt2=0;
  for ( int i=0; i<n; i++ ) {
    if ( s[i]=='a' ) {
      if ( cnt1+cnt2<a+b ) {
        cout << "Yes" << '\n';
        cnt1++;
      } else {
        cout << "No" << '\n';
      }
    }
    else if ( s[i]=='b' ) {
      if ( cnt2<b&&cnt1+cnt2<a+b ) {
        cout << "Yes" << '\n';
        cnt2++;
      } else {
        cout << "No" << '\n';
      } 
    }
    else {
      cout << "No" << '\n';
    } 
  }
  return 0; 
}
