#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{

  ll a,b,x;
  cin >> a >> b >> x ;
  ll l = a/x;
  ll r = b/x ;

   if (a % x == 0)
     cout << ((b / x) - (a / x) + 1) << endl;

    else
    cout << ( (b / x) - (a / x) ) << endl ;





  }
