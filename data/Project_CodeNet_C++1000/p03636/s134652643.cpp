#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main()
{
    long i,j,t,a,b,n,c,temp,m;
    t=1;
    // cin>>t;
    while(t--)
    {
       string s;
       cin>>s;
       for(i=0;i<s.length();i++)
       {
           if(s[i]=='i')
           {
               a=i;
               break;
           }
       }
        for(i=s.length()-1;i>=0;i--)
       {
           if(s[i]=='n')
           {
               b=i;
               break;
           }
       }
       cout<<s[0]<<s.length()-2<<s[s.length()-1];
    }
}