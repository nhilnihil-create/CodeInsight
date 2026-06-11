#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,k;
    cin>>n>>k;

    int ans=0;

    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;

        ans+=min(2*x,2*abs(k-x));
    }

    cout<<ans<<"\n";

    return 0;
}
