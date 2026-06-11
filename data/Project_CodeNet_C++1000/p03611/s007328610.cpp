#include <bits/stdc++.h>
using namespace std;

int b[100010];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;cin>>n;

    for(int i=0;i<n;i++)
    {
        int a;cin>>a;

        b[a]++;
        b[a+1]++;
        b[a+2]++;
    }

    int ans=0;

    for(int i=0;i<100010;i++)ans=max(ans,b[i]);

    cout<<ans<<"\n";

    return 0;
}
