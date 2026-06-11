#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n,k,x,y,sum=0;
    cin>>n>>k>>x>>y;
    if(n>k)
    {
        sum+=(x*k);
        sum+=((n-k)*y);
    }
    else
    {
        sum+=(n*x);
    }
    cout<<sum<<endl;
}