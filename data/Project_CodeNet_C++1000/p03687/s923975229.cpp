#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  
  int l = s.size();
  int ans = 1000;
  for(int i = 0; i < 26; i++){
    char now = 'a' + i;
    int cnt, tl = l;
    string test = s;
    for(int j = 0; j < 150; j++){
      bool ok = true;
      for(int k = 0; k < tl-1; k++){
        if(test.at(k) != now) ok = false;
        if(test.at(k+1) == now) test.at(k) = now;
      }
      if(tl > 0) if(test.at(tl-1) != now) ok = false;
      if(ok){
        cnt = j;
        break;
      }
      test.pop_back();
      tl = test.size();
    }
    ans = min(ans, cnt);
  }
  
  cout << ans << endl;
}