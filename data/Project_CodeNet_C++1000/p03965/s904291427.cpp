#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  string s;
  cin >> s;
  
  int ans = 0;
  for(int i = 0; i < s.size(); i++){
    if(i % 2 == 0){
      if(s.at(i) == 'p') ans--;
    }
    else{
      if(s.at(i) == 'g') ans++;
    }
  }
  
  cout << ans << '\n';
}