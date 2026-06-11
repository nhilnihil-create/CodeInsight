#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  int f = 0;
  for(int i = 0; i < s.size(); i++){
    for(int j = i + 1; j < s.size(); j++){
      if (s.at(i) == s.at(j)) f = 1;
    }
  }
  if (f == 0) cout << "yes" << endl;
  else cout << "no" << endl;
  return 0;
}