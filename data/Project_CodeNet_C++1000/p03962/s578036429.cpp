#include<bits/stdc++.h>
using namespace std;
int main()
{
   int a,b,c;
   cin>>a>>b>>c;
   if(a!=b && b!=c && c!=a)
    cout<<3<<endl;
   else if(a==b & a!=c || a==c & a!=b ||c==b & c!=a)
    cout<<2<<endl;
   else
     cout<<1<<endl;
    return 0;
}


