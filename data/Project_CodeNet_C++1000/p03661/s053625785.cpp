#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t,m,n,c=0;
    cin>>n;
    long long int v[n+10],u[n+10];
    u[0]=0;
    for(long long int i=1; i<=n; i++)
    {
        cin>>v[i];
        u[i]=u[i-1]+v[i];
        c+=v[i];
    }
    long long int mn=0x7fffffff;
    for(long long int i=1;i<n;i++)
    {
        mn=min(mn,abs(2*u[i]-c));
    }
    cout<<mn<<endl;
    return 0;
}
