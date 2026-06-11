#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  string s;
  cin >> s;
  int ans = 0, cnt = 0;
  int a = 0, z = 0;
  rep(i, s.size()){
    if(s[i] == 'A'){
      a = i;
      break;
    }
  }
  for(int i = s.size() - 1; i >= 0; i--) {
    if(s[i] == 'Z'){
      z = i;
      break;
    }
  }
  
  ans =  z - a + 1;
  if(ans < 0) ans = 0;
    
  cout << ans << endl;

  return 0;
}