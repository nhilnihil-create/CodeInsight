#include<bits/stdc++.h>
using namespace std;
long long int ar[2000000],ar1[2000000];
int main()
{
    long long int x, n,i,j,ans,a,b,mn=2232434343;
    cin>>n;
    cin>>x;
    ar[0]=x;
    ans=x;
//    cout<<ans<<endl;
    for(i=1;i<n;i++)
    {
        cin>>a;
        ans=ans+a;
        ar[i]=ans;

    }
//    cout<<ans<<endl;
    for(i=0;i<n;i++)
    {
        ar1[i]=ans-ar[i];
    }
    for(i=0;i<n-1;i++)
    {
        b=abs(ar[i]-ar1[i]);
        if(b<mn)
        {
            mn=b;
        }
    }
    cout<<mn<<endl;
}
