#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,k,x,y,a;
cin>>n>>k>>x>>y;
if((n-k)>=0)
a=k*x+(n-k)*y;
else if((n-k)<0)
a=n*x;
cout<<a<<endl;
return 0;
}