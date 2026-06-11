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
  int ans = 0;
  string a, b;
  for(int i = s.size() - 2; i > 0; i -= 2){
    a = s.substr(0, i / 2);
    b = s.substr(i / 2, i / 2);
    if(a == b){
      ans = i;
      break;
    }
  }
  
    
  

  cout << ans << endl;
  return 0;
}
