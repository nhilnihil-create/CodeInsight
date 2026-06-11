#include <bits/stdc++.h>
using namespace std;

int t[110];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin>>n;

    int sum=0;

    for(int i=0;i<n;i++)
    {
        cin>>t[i];
        sum+=t[i];
    }

    int m;
    cin>>m;

    for(int i=0;i<m;i++)
    {
        int p,x;
        cin>>p>>x;

        cout<<(sum-t[p-1]+x)<<"\n";
    }

    return 0;
}
