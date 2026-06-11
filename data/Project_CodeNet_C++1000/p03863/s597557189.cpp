#include <bits/stdc++.h>
using namespace std;
 
int main(){
  string s; cin >> s;
  if((s[0]==s[(int)s.length()-1]) == (s.length()%2 == 1)) cout << "Second" << endl;
  else cout << "First" << endl;
  return 0;
}