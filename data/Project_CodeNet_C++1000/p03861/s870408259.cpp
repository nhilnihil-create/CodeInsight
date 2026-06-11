#include<bits/stdc++.h>
using namespace std;
int main()
{
   long long int a,b,x,flag=0;
   cin>>a>>b>>x;
   flag=b/x;
   flag-=(a/x);
   if(a%x==0)
       flag++;
   cout<<flag<<endl;
   return 0;
}
