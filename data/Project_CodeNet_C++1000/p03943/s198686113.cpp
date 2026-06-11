#include <bits/stdc++.h>
using namespace std;
int main()
{
   int a,b,c,d,e,f,g,h,i,j,k;
    cin>>a>>b>>c;
    d=max(a,max(b,c));
    e=a+b+c-d;
    if(e==d)
       cout<<"Yes";

    else
      cout<<"No";
}