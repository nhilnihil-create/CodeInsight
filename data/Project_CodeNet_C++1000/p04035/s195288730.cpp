#include<iostream>
using namespace std;
int main()
{
    long long int a[100000],l,p,n,ans,j,i;
    cin>>n>>l;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    ans=a[0]+a[1];
    for(i=1;i<n;i++)
    {
        if(ans<a[i]+a[i+1])
        {
            ans=a[i]+a[i+1];
             p=i;
        }
    }
    if(ans>=l)
    {
        cout<<"Possible"<<endl;
        for(i=1;i<p;i++)
    {
        cout<<i<<endl;
    }
    for(i=n-1;i>=p;i--)
    {
        cout<<i<<endl;
    }
    }
    else
    {
        cout<<"Impossible"<<endl;
    }
}
