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
   vector<char> va, vb, vc;
   for(int i = a.size() - 1; i >= 0; i--)
      va.push_back(a[i]);
   for(int i = b.size() - 1; i >= 0; i--)
      vb.push_back(b[i]);
   for(int i = c.size() - 1; i >= 0; i--)
      vc.push_back(c[i]);
   char ch = 'a';

   while(1)
   {
      if(ch == 'a')
      {
         if(va.empty())
         {
            cout << "A" << nl;
            return 0;
         }
         ch = va.back();
         va.pop_back();
      }
      if(ch == 'b')
      {
         if(vb.empty())
         {
            cout << "B" << nl;
            return 0;
         }
         ch = vb.back();
         vb.pop_back();
      }
      if(ch == 'c')
      {
         if(vc.empty())
         {
            cout << "C" << nl;
            return 0;
         }
         ch = vc.back();
         vc.pop_back();
      }


   }





	return 0;
}
