#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,m;
    cin>>n>>m;

    vector<vector<int>> r(n);

    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;

        r[a-1].push_back(b);
        r[b-1].push_back(a);
    }

    for(int i=0;i<n;i++)
    {
        cout<<r[i].size()<<"\n";
    }

    return 0;
}
