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
   string s; cin >> s;
   int pos1, pos2;
   for(int i = 0; i < s.size(); i++)
   {
      if(s[i] == 'A')
      {
         pos1 = i;
         break;
      }
   }

   for(int i = s.size() - 1; i >= 0; i--)
   {
      if(s[i] == 'Z')
      {
         pos2 = i;
         break;
      }
   }
   cout << pos2 - pos1 +1 << nl;
}
