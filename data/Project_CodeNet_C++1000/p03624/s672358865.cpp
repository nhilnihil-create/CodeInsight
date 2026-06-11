#include<bits/stdc++.h>
using namespace std;

int main()
{
   string s;
   cin>>s;
   int* a = new int[26]();
   for(int i=0;i<s.length();i++)
   {
       a[s[i] -'a' ] ++;
   }
   char  ans = '1';
   for(int i=0;i<26;i++)
   {
       if( a[i] ==0 )
       {
           ans = i+'a';
           break;
       }
   }
   if( ans == '1' )
   {
       cout<<"None";
   }
   else
   {
       cout<<ans;
   }
}
