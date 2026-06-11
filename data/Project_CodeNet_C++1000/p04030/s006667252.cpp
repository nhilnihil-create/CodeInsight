#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, ans;
  cin >> s;
  for (int i=0; i < s.size(); i++){
    if (s.at(i)=='B'){
      for (int j=0; j<i; j++){
        if(s.at(i-j-1)!='B'){
          s.at(i-j-1)='B';
          break;
        }
      }
    }
  }
  for (int i=0; i<s.size();i++){
    if (s.at(i)!='B'){
      ans +=s.at(i);
    }
  }
  cout << ans << endl;
}