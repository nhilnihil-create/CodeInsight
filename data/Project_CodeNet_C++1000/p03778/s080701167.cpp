#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long w,a,b,x,y,r,s;
    cin>>w>>a>>b;
    r=a+w;
    s=b+w;

    x=max(a,b);
    y=min(r,s);

    if(x>=y)
        cout<<x-y;
        else
         cout<<0;
   return 0;
   }



