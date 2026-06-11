#include <bits/stdc++.h>

using namespace std;

int main()
{

   int n,k,x,y,s;
   cin>>n>>k>>x>>y;
   if(n>k){x=k*x;}
   else{x=n*x; }
   if(n>k){y=(n-k)*y;}
   else{y=0; }
   s=x+y;
   cout<<s<<endl;

    return 0;
}
