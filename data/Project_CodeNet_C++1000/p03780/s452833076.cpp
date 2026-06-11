#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[5020],f[5020],s;
int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        a[i]=min(a[i],k);
        s+=a[i];
    }
    sort(a,a+1+n);
    f[0]=1;
    for(int i=n;i>=0;i--)
    {
        bool flag=1;
        for(int j=k-1;j>=k-s&&j>=0;j--)
            if(f[j]) flag=0;
        if(flag)
        {
            cout<<i;
            return 0;
        }
        for(int j=k;j>=a[i];j--)
            f[j]|=f[j-a[i]];
        s-=a[i];
    }
    return 0;
}
