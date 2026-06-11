#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i <= (int)(n); i++)

int main()
{
  int n;
  cin >> n;
  
  int s[n];
  int ans = 0;
  rep(i,n)
  {
    cin >> s[i];
    ans += s[i];
  }
  
  if(ans % 10 != 0)
  {
    cout << ans << endl;
    return 0;
  }
  
  sort(s,s+n);
  
  rep(i,n)
  {
    if((ans - s[i]) % 10 != 0)
    {
      cout << (ans - s[i]) << endl;
      return 0;
    }
  }
  
  cout << 0 << endl; 
}
