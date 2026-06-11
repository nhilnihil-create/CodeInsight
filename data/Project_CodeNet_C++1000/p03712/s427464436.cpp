#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int h, w, i;
  string s;
  cin >> h >> w;
  
  string header(w + 2, '#');
  cout << header << endl;
  for(i=0; i<h; i++){
    cin >> s;
    s.insert(0, "#");
    s.insert(w+1, "#");
    cout << s << endl;
  }
  cout << header << endl;

  return 0;
}