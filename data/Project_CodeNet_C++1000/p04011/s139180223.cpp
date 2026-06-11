#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n,k,a,b,s;
    cin>>n>>k>>a>>b;
    if(k>=n)
    {
        s=n*a;
    }
    else
    {
        s=k*a+(n-k)*b;
    }
    cout<<s<<endl;
    return 0;
}
