#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
   int n;
   cin>>n;
   string s , t;
   cin>>s>>t;
   ll ans =2*n;
   for(int i=0;i<n;i++)
   {
       int len = n -i;
       string temp = t.substr( 0 , len);
       string temp2 = s.substr( i ,len);
       if( temp == temp2 )
       {
           ans = ans - len;
           break;
       }
   }
   cout<<ans;
}