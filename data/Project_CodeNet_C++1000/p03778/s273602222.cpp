#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long w,i,j,x,y,r,s;
    cin>>w>>i>>j;
    r=i+w;
    s=j+w;
 
    x=max(i,j);
    y=min(r,s);
 
    if(x>=y)
        cout<<x-y;
        else
         cout<<0;
   return 0;
   }