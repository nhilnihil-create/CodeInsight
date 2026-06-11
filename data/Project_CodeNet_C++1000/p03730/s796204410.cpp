#include<bits/stdc++.h>
using namespace std;
int main()
{
     int a,b,c;
     cin>>a>>b>>c;
     if(c%__gcd(a,b)==0)
     {
         cout<<"YES"<<endl;
         return 0;
     }
     else
     {
         cout<<"NO"<<endl;
     }
}
