#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
   ll a , b , c ,d,mx  = 0;
   cin >> a ;
   string s;
   cin >> s;
   ll cnt = 0;
   for(int i=0; i<s.size(); i++)
   {
       if(s[i]=='I')cnt++;
       else cnt--;
       mx = max(mx,cnt);
   }
   cout << mx << endl;

}
