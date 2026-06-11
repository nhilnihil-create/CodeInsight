#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  string t = s;
  int n = s.size();
  reverse(s.begin(), s.end());
  for(int i = 0; i < n; i++){
    if(s[i] == 'b'){
      s[i] = 'd';
      continue;
    }
    else if(s[i] == 'd'){
      s[i] = 'b';
      continue;
    }
    else if(s[i] == 'p'){
      s[i] = 'q';
      continue;
    }
    else if(s[i] == 'q'){
      s[i] = 'p';
      continue;
    }
  }
  if(s == t) cout << "Yes" << endl;
  else cout << "No" << endl;
}
