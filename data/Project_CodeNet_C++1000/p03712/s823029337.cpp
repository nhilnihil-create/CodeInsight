#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
  int h, w;
  string s;
  cin >> h >> w;
  for(int i=0; i<h+2; i++) {
    for(int j=0; j<w+2; j++) {
      if(i==0) {
        cout << "#";
        if(j==w+1) cout << endl;
      }
      else if(i==h+1) {
        cout << "#";
        if(j==w+1) cout << endl;
      }
      else {
        cin >> s;
        cout << "#" << s << "#" << endl;
        break;
      }
    }
  }
  return 0;
}