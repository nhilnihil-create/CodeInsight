#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long n,a,b,yp=0,bp=0;
  string s;
  cin >> n >> a >> b >> s;
  for(long i=0;i<n;i++) {
    if(yp<a+b) {
      if(s[i]=='a') {
        cout << "Yes" << endl;
        yp++;
      } else if(s[i]=='b'&&bp<b) {
        cout << "Yes" << endl;
        yp++,bp++;
      } else {
        cout << "No" << endl;
      }
    } else {
      cout << "No" << endl;
    }
  }
}