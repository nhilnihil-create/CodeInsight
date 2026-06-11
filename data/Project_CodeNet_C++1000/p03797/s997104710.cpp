#include<bits/stdc++.h>

using namespace std;
#define ll long long
ll mod = 1000000007 ;

int main()
{
 ll s,c;
 cin >> s >> c;
 ll ans = 0;
 if(s*2<=c)
 {
     ans += s ;
     c -= s*2;
     ans += c/4 ;
     cout << ans << endl;
 }
 else
 {
   ll d = c/2;
   ans += min(s,d);
   c-=d*2;
   ans += c/4 ;
   cout << ans << endl;
 }






}
