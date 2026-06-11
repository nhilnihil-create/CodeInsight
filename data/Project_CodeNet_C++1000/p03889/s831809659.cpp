#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

int main(){
  string s;
  cin >> s;
  string t = s;
  reverse(s.begin(),s.end());
  for(char &c : s) {
    if(c == 'b') c = 'd';
    else if(c == 'd') c = 'b';
    else if(c == 'p') c = 'q';
    else if(c == 'q') c = 'p' ;
  }
  cout << (s == t ? "Yes" : "No") << endl;
  return 0;
}
