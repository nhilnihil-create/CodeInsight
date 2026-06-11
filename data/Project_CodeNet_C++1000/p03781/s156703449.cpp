#include<bits/stdc++.h>
using namespace std;
int main()
{
long long int x,sum(0);
cin>>x;
for(long long int i=1; i<=1000000000; ++i)
{
sum+=i;
if(sum>=x)
{
cout<<i;
break;
}
}
}