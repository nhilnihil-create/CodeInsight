#include<bits/stdc++.h>
using namespace std;

int32_t main()
{
    int n;
    cin>>n;
    int sum=0;

    int a[n];
    int ans=INT_MAX;
    
    for(int i=0;i<n;i++)
{    cin>>a[i];sum+=a[i];if(a[i]%10!=0)ans=min(ans,a[i]);
}



    if(sum%10!=0)
    cout<<sum<<endl;
    else if(sum%10==0 && ans==INT_MAX)
    cout<<0<<endl;
    else
    cout<<sum-ans<<endl;
   
}