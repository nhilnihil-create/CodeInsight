#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
  
  int n,i,l,j,k,p;

   string s,t="";
   cin>>s;
   n=s.size();
   for(i=0;i<n;i++)
   {
       if(s[i]=='B')
       {if(!t.empty()) t.pop_back();}
       
       else t+=s[i];
   }

cout<<t;
}