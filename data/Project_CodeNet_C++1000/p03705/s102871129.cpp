#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,a,b,i,j;
    scanf("%lld%lld%lld",&n,&a,&b);
    if(a==b)
    {
        cout<<1<<endl;
    }
    else if(b<a)
    {
        cout<<0<<endl;
    }
    else if(n==1)
    {
        cout<<0<<endl;
    }
    else
    {
        long long int c=((b-a)*(n-2))+1;
        cout<<c<<endl;
    }
    return 0;
}
