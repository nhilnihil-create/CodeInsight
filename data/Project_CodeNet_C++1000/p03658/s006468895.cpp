#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,k;
    cin>>n>>k;

    vector<int> l(n);

    for(int i=0;i<n;i++)cin>>l[i];

    sort(l.begin(),l.end(),greater<int>());

    int ans=0;

    for(int i=0;i<k;i++)ans+=l[i];

    cout<<ans<<"\n";

    return 0;
}
