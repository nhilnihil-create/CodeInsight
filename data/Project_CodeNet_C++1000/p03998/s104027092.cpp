#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

typedef long long ll;

const char nl = '\n' ;


int main()
{
   ios_base::sync_with_stdio(0); cin.tie(0);
   string a, b, c;
   cin >> a >> b >> c;
   reverse(all(a));
   reverse(all(b));
   reverse(all(c));
   char ch = 'a';
   while(1)
   {
      if(ch == 'a')
      {
         if(a.empty())
         {
            cout << "A" << nl;
            return 0;
         }
         ch= a.back();
         a.pop_back();
      }
      if(ch == 'c')
      {
         if(c.empty())
         {
            cout << "C" << nl;
            return 0;
         }
         ch= c.back();
         c.pop_back();
      }
      if(ch == 'b')
      {
         if(b.empty())
         {
            cout << "B" << nl;
            return 0;
         }
         ch= b.back();
         b.pop_back();
      }
   }






	return 0;
}
