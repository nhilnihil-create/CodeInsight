#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
 
int main() {
  //input
  int n; cin >> n;
  vector<int> s(n);
  for(int i = 0; i < n; i++)  cin >> s[i];
  
  //compute
  int ans;
  int mint;
  sort(s.begin(), s.end());
  mint = 0;
  ans = 0;

  for(int i = 0; i < n; i++) {
     ans += s[i];
  }

  for(int i = 0; i < n; i++) {
      if(s[i] % 10 != 0){
          mint = s[i];
          break;
      }
  }

  if(ans % 10 == 0){
    ans = ans - mint;
  }

  //output
  if(ans % 10 != 0){
    cout << ans << endl;
  }else{
    cout << 0 << endl;
  }

}
