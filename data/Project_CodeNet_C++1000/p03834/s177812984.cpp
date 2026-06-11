

#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1000000007 ;
bool prime(ll n)
{
  bool cnt = 0;
  for(ll i=2; i*i<=n; i++)
  {
      if(n%i==0)
      {
          return 0;
      }
  }
  return 1 ;
}

    int main()
{
    string s;
    getline(cin,s);
    for(int i=0; i<s.size(); i++)
    {
        if(s[i] == ',')s[i] = ' ' ;
    }
    cout << s << endl;





    }
