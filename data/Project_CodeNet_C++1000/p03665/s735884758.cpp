#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,p;cin>>n>>p;

    vector<int> odd,even;
    for(int i=0;i<n;i++)
    {
        int a;cin>>a;

        if(a%2)odd.push_back(a);
        else even.push_back(a);
    }

    int osz=odd.size();
    int esz=even.size();

    ll ans=0;

    if(osz==0)
    {
        if(p)
        {
            cout<<ans<<"\n";
        }
        else
        {
            ans=pow(2,n);
            cout<<ans<<"\n";
        }
        return 0;
    }

    ans=pow(2,n-1);
    cout<<ans<<"\n";

    return 0;
}
