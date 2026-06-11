#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=1;i<=n;i++) cin>>arr[i];
    int m;
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        int p,x,ans=0,temp;
        cin>>p>>x;
        temp=arr[p];
        arr[p]=x;
        for(int j=1;j<=n;j++)ans+=arr[j];
        cout<<ans<<endl;
        arr[p]=temp;
    }
}
