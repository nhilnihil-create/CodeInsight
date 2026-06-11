#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

typedef long long ll;

const char nl = '\n' ;


int main()
{
   ios_base::sync_with_stdio(0); cin.tie(0);
   int ans = 0;
   int n; cin >>n;
   string s; cin >> s;
   int tmp = 0;
   for(int i =0; i < s.size(); i++)
   {
      if(s[i] == 'I')
      {
         tmp++;
         ans = max(ans, tmp);
      }
      else
      {
         tmp--;
      }
   }
   cout << ans << nl;
}
