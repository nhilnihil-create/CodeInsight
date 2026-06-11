#include <bits/stdc++.h>
using namespace std;

int main() {
  string s; cin >> s;
  vector<char> alpha(26);
  for(int i=0;i<26;i++){
    alpha.at(i) = 'a' + i;
  }
  vector<int> cnt(26,0);
  for(int i = 0; i <s.size();i++){
    for(int j = 0; j < 26;j++){
      if(s.at(i) == alpha.at(j)){
        cnt.at(j)++;
      }
    }
  }
  bool ans = true;
  for(int i = 0; i < 26;i++){
    if(cnt.at(i)>1) ans = false;
  }
  if(ans) cout << "yes" << endl;
  else cout << "no" << endl;
}
