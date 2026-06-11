#include<bits/stdc++.h>
using namespace std;
#define nl '\n'
int main()
{
   int a[101]={0},cnt=0,t=3,p;
   while(t--)
   {
      cin>>p;
      a[p]=1;
   }
   for(int i=1;i<101;i++)
   {
      if(a[i]==1)
         cnt++;
   }
   cout<<cnt<<nl;
    return 0;
}
