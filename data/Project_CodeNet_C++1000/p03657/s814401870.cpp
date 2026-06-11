#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

typedef long long ll;

const char nl = '\n' ;
const ll MOD = 1e9 + 7;

bool check(string s)
{
   int k = s.size()/2;
   for(int i = 0; i <k; i++)
   {
      if(s[i] != s[i+k])
         return false;
   }
   return true;
}
int main()
{
   ios_base::sync_with_stdio(0); cin.tie(0);
   int a, b; cin >> a >> b;
   (a+b)%3 && a%3 && b%3 ? cout << "Impossible" : cout << "Possible";
   return 0;
}
