#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
int n,k,a,b,s=0;
cin>>n>>k>>a>>b;
if(n>k)
{
    s+=k*a+(n-k)*b;
}
else
{
    s+=n*a;
}
cout<<s;
return 0;
}
