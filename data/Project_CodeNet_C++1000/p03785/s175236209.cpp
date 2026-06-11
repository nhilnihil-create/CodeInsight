#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,c,k;cin>>n>>c>>k;
    vector<int> t(n);
    for(int i=0;i<n;i++)cin>>t[i];

    sort(t.begin(),t.end());

    int ans=0;

    for(int i=0;i<n;i++)
    {
        int cnt=c-1;
        for(int j=0;j<c;j++)
        {
            if(j+i>=n)
            {
                cnt=j-1;
                break;
            }
            if(t[j+i]-t[i]>k)
            {
                cnt=j-1;
                break;
            }
        }
        i+=cnt;
        ans++;
    }

    cout<<ans<<"\n";

    return 0;
}
