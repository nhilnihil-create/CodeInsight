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
   string a, b; cin >> a >> b;
   if(a.size() > b.size())
   {
      cout << "GREATER" << nl;
      return 0;
   }
   else if(a.size() < b.size())
   {
      cout << "LESS" << nl;
      return 0;
   }
   else
   {
      for(int i = 0; i < a.size(); i++)
      {
         if(a[i] < b[i])
         {
            cout << "LESS" << nl;
            return 0;
         }
         if(a[i] > b[i])
         {
            cout << "GREATER" << nl;
            return 0;
         }


      }
   }
   cout << "EQUAL" << nl;
   return 0;

}
