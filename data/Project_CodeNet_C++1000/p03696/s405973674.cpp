#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
map<string,long>mp;
int main()
{
    long i,j,t,a,b,n,c,temp;
    t=1;
    // cin>>t;
    while(t--)
    {
       string s,sp="",sn="";
       cin>>n;
       cin>>s;
       c=0;
       for(i=0;i<n;i++)
       {
           if(s[i]=='(')
           c++;
           else c--;
           if(c<0)
           {
               sp+='(';
               c=0;
           }
       }
       s=sp+s;
       c=0;
       for(i=0;i<s.length();i++)
       {
           if(s[i]=='(')
           c++;
           else c--;
           if(c<0)
           {
               sn+=')';
               c=0;
           }
       }
        cout<<s<<sn<<string(c,')');
    }
}