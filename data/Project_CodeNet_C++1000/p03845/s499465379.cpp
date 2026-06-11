#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,total=0;
    cin>>n;
    int a[n]={};
    for(int i=0;i<n;i++)
        {
            cin>>a[i];
            total+=a[i];
        }
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int p,x,ans;
        cin>>p>>x;
        ans = total - a[p-1] + x;
        cout<<ans<<'\n';
    }
    return 0;
}
