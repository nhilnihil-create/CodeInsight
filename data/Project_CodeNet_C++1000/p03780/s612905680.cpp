#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
long long a[5005];
int main()
{
    int n;
    long long k;
    cin>>n>>k;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int ans=n;
    long long sum=0;
    for (int i=n;i>=1;--i)
    {
        if (sum+a[i]<k)
        {
            sum+=a[i];
        }
        else
        {
            ans=i-1;
        }
    }
    cout<<ans<<endl;
    return 0;
}