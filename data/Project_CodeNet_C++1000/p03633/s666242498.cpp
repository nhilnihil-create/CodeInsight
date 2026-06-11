#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int t,a[1001],p;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>a[i];
    }
    long long int m=a[0];
    for(int i=1;i<t;i++)
    {
        p=__gcd(m,a[i]);
        m=(m/p)*a[i];
    }
    cout<<m<<endl;
}
