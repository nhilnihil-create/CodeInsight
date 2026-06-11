#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  cin >> s;
  
  int n = s.size();
  int64_t ans = 0;
  for(int bit = 0; bit < (1 << (n-1)); bit++){
    int64_t tmp = 0;
    int i = 0;
    for(i = 0; i < n-1; i++){
      tmp *= 10;
      tmp += s[i] - '0';
      if(bit & (1 << i)){
        ans += tmp;
        tmp = 0;
      }//if
    }//for
    
    tmp *= 10;
    tmp += s[i] - '0';
    ans += tmp;
  }//for
  
  cout << ans << endl;
}