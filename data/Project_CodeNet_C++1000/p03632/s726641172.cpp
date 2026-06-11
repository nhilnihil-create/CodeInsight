#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int ans = 0;
  if(a < c){
    ans = min(b, d) - c;
    if(ans < 0) ans = 0;
  }
  else if(c < a){
    ans = min(b, d) - a;
    if(ans < 0) ans = 0;
  }
  else{
    ans = min(b, d) - a;
  }
    
  

  cout << ans << endl;
  return 0;
}