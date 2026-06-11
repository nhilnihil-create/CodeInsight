#include<bits/stdc++.h>
using namespace std;

int main()
{
   string s;
   cin>>s;
   bool ataken = false;
   int len = 0;
   int ans =0;
   for(int i=0;i<s.length();i++)
   {
       if(s[i]=='A' && !ataken )
       {
           len = 0;
           ataken = true;
       }
       if( ataken)
           len++;
       if( s[i] == 'Z')
           ans = len;
   }
   cout<<ans;
}