#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

typedef long long ll;

const char nl = '\n' ;


int main()
{
   ios_base::sync_with_stdio(0); cin.tie(0);
   string s; cin >> s;
   map<int, int> m;
   for(int i = 0; i < s.size(); i++)
   {
      m[s[i]]++;
   }
   for(auto it = m.begin(); it!=m.end(); it++)
   {
      if(it->second %2)
      {
         cout << "No" << nl;
         return 0;
      }
   }
   cout << "Yes" << nl;



	return 0;
}
