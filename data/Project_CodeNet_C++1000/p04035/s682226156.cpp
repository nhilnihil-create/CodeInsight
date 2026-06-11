#include<iostream>
using namespace std;
int main()
{
    long long a[200000],i,n,l,m,j,pos=1,k;
    cin>>n>>l;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    m=a[0]+a[1];
    for(j=1;j<n;j++)
    {
        if(m<(a[j]+a[j+1]))
        {
            m=a[j]+a[j+1];
            pos=j;
        }
    }
    if(m<l)
    {
         cout<<"Impossible"<<endl;
    }
    else
    {
        cout<<"Possible"<<endl;
        for(k=1;k<pos;k++)
        {
            cout<<k<<endl;
        }
        for(k=n-1;k>=pos;k--)
        {
            cout<<k<<endl;
        }
    }
    return 0;
}