#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t,m,n,c=0,mn=0x7fffffff;;
    cin>>n;
    long long int v[n+10];
    m=0;
    for(long long int i=1; i<=n; i++)
    {
        cin>>v[i];
        c+=v[i];
    }
    for(long long int i=1; i<n; i++)
    {
        m=m+v[i];
        long long int x=abs(2*m-c);
        mn=min(mn,x);

    }
    cout<<mn<<endl;
    return 0;
}
