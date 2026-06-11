#include <iostream>
#include <bits/c++io.h>

using namespace std;

int main()
{
 int x,t=0,maxi=0;

 cin>>x;
  char s[x];
  for(int i=0;i<x;i++)
 {
     cin>>s[i];
 }
 for(int i=0;i<x;i++)
 {
     if(s[i]=='I')
        t++;
     else if(s[i]=='D')
        t--;
     if(t>maxi)
        maxi=t;
 }
 cout<<maxi<<endl;
}
