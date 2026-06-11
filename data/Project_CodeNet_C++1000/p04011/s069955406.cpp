#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n,k,x,y,sum=0;
   cin>>n;
   cin>>k;
   cin>>x;
   cin>>y;
   sum=0;
   if(n>k)
   {
       for(int i=1;i<=k;i++)
       {
           sum+=x;
       }
       for(int j=1;j<=n-k;j++)
       {
           sum+=y;
       }
       cout<<sum<<endl;
   }
   else if(k>=n)
   {
       cout<<n*x<<endl;
   }
}
