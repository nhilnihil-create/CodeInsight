#include<bits/stdc++.h>
using namespace std;
int main()
{
   string s;
   int a[26]={};
   cin>>s;
   int x=s.size();
   for(int i=0;i<x;i++)
   {
       int j=0;
       j=s[i]-'a';
       a[j]++;
   }
   bool ok=true;
   for(int i=0;i<26;i++)
   {
       if(a[i]%2!=0)
       {
         ok=false;
       }
   }
   if(ok==true)
   {
       cout<<"Yes";
   }
   else
   {
       cout<<"No";
   }

return 0;

}
