#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    int ans=0;
    if(a[0]==a[n-1])
        cout<<"0"<<endl;
    else{
    for(int i=a[0];i<=a[n-1];i++)
    {
        int ans1=0;
        for(int j=0;j<n;j++)
        {
            ans1+=abs(a[j]-i)*abs(a[j]-i);
        }
        if(i==a[0])
            ans=ans1;
        else
            ans=min(ans,ans1);
    }
    cout<<ans<<endl;
    }
    return 0;
}
