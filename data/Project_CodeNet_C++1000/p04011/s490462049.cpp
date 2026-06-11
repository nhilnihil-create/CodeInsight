#include<iostream>
using namespace std;
int main()
{
     long long n,k,x,y,l;
     cin>>n>>k>>x>>y;
     if(n>=k)
     {
         cout<<((k*x)+((n-k)*y))<<endl;
     }
     else
     {
         cout<<((n*x))<<endl;
     }
     return 0;
}