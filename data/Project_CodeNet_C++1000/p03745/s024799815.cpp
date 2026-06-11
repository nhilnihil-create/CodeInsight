#include <bits/stdc++.h>
using namespace std;

int a[100010];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;cin>>n;

    for(int i=0;i<n;i++)cin>>a[i];

    int ans=1;

    int sn=0;
    int pos=0;

    for(int i=0;i<n;i++)if(a[i]!=a[0]){sn=a[i]>a[0]?1:-1;pos=i;break;}

    if(sn!=0)
    {
        for(int i=pos;i<n;i++)
        {
            if((a[i]-a[i-1])*sn<0)
            {
                for(int j=i;j<n;j++)if(a[j]!=a[i]){sn=a[j]>a[i]?1:-1;i=j;break;}
                ans++;
            }
        }
    }

    cout<<ans<<"\n";

    return 0;
}
