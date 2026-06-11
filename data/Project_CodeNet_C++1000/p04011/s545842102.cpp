#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n,k,x,y,s;
   cin>>n>>k>>x>>y;
   if(n<=k)
   {
       cout<<x*n<<"\n";
   }
   else
   {
       s=(k*x)+(n-k)*y;
       cout<<s<<"\n";

   }
return 0;}
