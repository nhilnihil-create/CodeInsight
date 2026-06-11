#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  string s;
  int k;
  cin >> s >> k;
  
  for(int i = 0; i < s.size(); i++){
    if(s.at(i) == 'a') continue;
    if(123 - s.at(i) <= k){
      k -= 123 - s.at(i);
      s.at(i) = 'a';
    }
  }
  
  k %= 26;
  s.at(s.size() - 1) += k;
  if(s.at(s.size() - 1) > 'z') s.at(s.size() - 1) -= 26;
  
  cout << s << '\n';
}