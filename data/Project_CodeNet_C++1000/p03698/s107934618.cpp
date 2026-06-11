#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

typedef long long ll;

const char nl = '\n' ;
const ll MOD = 1e9 + 7;
int main()
{
   ios_base::sync_with_stdio(0); cin.tie(0);
   string s; cin >> s;
   int a[300] = {};
   for(int i =0; i < s.size(); i++)
   {
      a[s[i]]++;
      if(a[s[i]] == 2)
      {
         cout << "no" << nl;
         return 0;
      }
   }
   cout << "yes" << nl;
   return 0;

}
