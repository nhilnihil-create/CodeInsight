#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;cin>>n;

    vector<int> s(n);
    int sum=0;

    for(int i=0;i<n;i++)
    {
        cin>>s[i];
        sum+=s[i];
    }

    sort(s.begin(),s.end());

    int ans=sum;

    int i=0;

    if(ans%10==0)for(;i<n;i++)
    {
        if(s[i]%10)
        {
            ans-=s[i];
            break;
        }
    }

    if(i==n)ans=0;

    cout<<ans<<"\n";

    return 0;
}
