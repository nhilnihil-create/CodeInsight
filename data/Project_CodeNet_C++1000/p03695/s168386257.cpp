#include <bits/stdc++.h>
using namespace std;

int c[9];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;cin>>n;

    for(int i=0;i<n;i++)
    {
        int a;cin>>a;
        int num=min(a/400,8);
        c[num]++;
    }

    int ans=0;

    for(int i=0;i<8;i++)if(c[i]>0)ans++;

    cout<<max(ans,1)<<" "<<ans+c[8]<<"\n";

    return 0;
}
