#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,x,y,sum=0,i,j,k;
    cin>>n>>k>>x>>y;
    if(n<=k)
    {
        sum=n*x;
        cout<<sum<<endl;
        return 0;
    }
    i=n-k;
    j=k*x;
    long long p=i*y;
    sum=p+j;
    cout<<sum<<endl;


}
