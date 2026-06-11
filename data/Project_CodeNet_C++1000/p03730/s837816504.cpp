#include<bits/stdc++.h>
using namespace std;
int main()
{
   int a,b,c;cin>>a>>b>>c;
   for(int i=a;i<10000;i+=a)
   {
       if(i%b==c)
       {
           cout<<"YES\n";
           return 0;
       }
   }
   cout<<"NO\n";
}
