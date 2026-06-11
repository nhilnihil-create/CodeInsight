#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,x,i;
    cin>>n;
    x=1;
    for(i=1;i<=n;i++)
    {
        x=(x*i)%(1000000007);
    }
    cout<<x<<endl;
    return 0;
}
