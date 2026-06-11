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
   vector<char> v;
   for(int i = 0; i < s.size(); i++)
   {
      if(s[i] != 'B')
         v.push_back(s[i]);
      else if( !v.empty())
         v.pop_back();
   }
   for(auto u : v)
      cout << u;


	return 0;
}
