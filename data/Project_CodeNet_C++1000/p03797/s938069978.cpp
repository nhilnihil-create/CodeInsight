#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,m,p;
    cin>>n>>m;
   p=m/2;
   if(p<=n)
        cout<<p<<endl;
   else if(n<p)
   {
       cout<<(n+((p-n)/2))<<endl;
   }
    return 0;

}
