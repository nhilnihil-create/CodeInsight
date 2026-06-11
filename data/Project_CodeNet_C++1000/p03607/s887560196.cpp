#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;cin>>n;

    vector<int> a;

    for(int i=0;i<n;i++)
    {
        int ia;cin>>ia;

        auto it = remove(a.begin(),a.end(),ia);
        if(it==a.end())a.push_back(ia);
        else a.erase(it,a.end());
    }

    int ans=a.size();

    cout<<ans<<"\n";

    return 0;
}
